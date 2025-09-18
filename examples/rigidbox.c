#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>

#define LA_IMPLEMENTATION
#include "../la.h"

typedef enum {
    BACK = 0,
    FORE = 1,
    PIXEL_N,
} Pixel;

#define WIDTH 80
#define HEIGHT 80
static_assert(HEIGHT % 2 == 0, "HEIGHT must be even for double-row compression");
static Pixel display[WIDTH * HEIGHT];

static void fill(Pixel p)
{
	Pixel *ptr = display;
	size_t n = WIDTH*HEIGHT;
	while (n-- > 0) *ptr++ = p;
}

static void show(void)
{
	static char row[WIDTH];
	static char *table = " _^C";
	for (int y = 0; y < HEIGHT/2; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			Pixel t = display[(2*y + 0)*WIDTH + x];
			Pixel b = display[(2*y + 1)*WIDTH + x];
			assert(0 <= t && t < PIXEL_N);
			assert(0 <= b && b < PIXEL_N);
			row[x] = table[(t<<1)|b];
		}
		fwrite(row, WIDTH, 1, stdout);
		fputc('\n', stdout);
	}
}

static void back(void)
{
	printf("\x1b[%dD", WIDTH);
	printf("\x1b[%dA", HEIGHT/2);
}

typedef struct {
    V3f position;
    V3f linearVelocity;
    R3f orientation;     // rotor
    V3f angularVelocity; // body-space axis scaled by rad/s
} RigidBody;

static inline R3f r3f_from_axis_angle_compat(V3f axis, float angle)
{
    V3f n = v3f_normalize(axis);
    V3f bv = v3f(n.z, n.y, n.x); // plane bivector mapping
    return r3f_from_plane_angle(bv, angle);
}

static void integrate(RigidBody *rb, float dt)
{
    float omega = v3f_len(rb->angularVelocity);
    if (omega > 0.0f) {
        V3f axis = v3f_normalize(rb->angularVelocity);
        R3f r_dt = r3f_from_axis_angle_compat(axis, omega * dt);
        rb->orientation = r3f_mul(r_dt, rb->orientation);
    }
    // Position update
    rb->position = v3f_sum(rb->position, v3f_mul(rb->linearVelocity, v3f(dt, dt, dt)));
}

static M3x3f lookat_R(V3f eye, V3f target, V3f up)
{
    V3f f = v3f_normalize(v3f_sub(target, eye));
    V3f r = v3f_normalize(v3f_cross(f, up));
    V3f u = v3f_cross(r, f);
    return m3x3f(
        r.x, r.y, r.z,
        u.x, u.y, u.z,
       -f.x,-f.y,-f.z
    );
}

static int project_point(V3f p_world, V3f eye, M3x3f R, int W, int H, float focal, int *outx, int *outy)
{
    V3f p = v3f_sub(p_world, eye);
    V3f pc = m3x3f_mul_v3f(R, p);
    if (pc.z >= -0.1f) return 0; // behind camera or too close
    float xndc = (focal * pc.x / -pc.z);
    float yndc = (focal * pc.y / -pc.z);
    int sx = (int)(W * 0.5f + xndc * (W * 0.5f));
    int sy = (int)(H * 0.5f - yndc * (H * 0.5f));
    if (sx < 0 || sx >= W || sy < 0 || sy >= H) return 0;
    *outx = sx; *outy = sy; return 1;
}

static void draw_line(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;
	for (;;) {
		if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT) display[y0 * WIDTH + x0] = FORE;
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

static int obb_obb_mtv(
	V3f cA, V3f eA, V3f a0, V3f a1, V3f a2,
	V3f cB, V3f eB, V3f b0, V3f b1, V3f b2,
	V3f *outNormal, float *outPen)
{
	const float EPS = 1e-5f;
	float Rm[3][3] = {
		{ v3f_dot(a0,b0), v3f_dot(a0,b1), v3f_dot(a0,b2) },
		{ v3f_dot(a1,b0), v3f_dot(a1,b1), v3f_dot(a1,b2) },
		{ v3f_dot(a2,b0), v3f_dot(a2,b1), v3f_dot(a2,b2) },
	};
	float AbsR[3][3];
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) AbsR[i][j] = fabsf(Rm[i][j]) + EPS;

	V3f t = v3f_sub(cB, cA);
	float tA[3] = { v3f_dot(t, a0), v3f_dot(t, a1), v3f_dot(t, a2) };

    float bestOverlap = INFINITY;
    V3f bestNormal = v3f(0.0f, 0.0f, 0.0f);

    #define UPDATE_AXIS(axisWorld_expr, overlap_val) do { \
        V3f axisWorld = (axisWorld_expr); \
        float sign = v3f_dot(axisWorld, t) < 0.0f ? -1.0f : 1.0f; \
        V3f n_ = v3f_mul(v3f_normalize(axisWorld), v3f(sign, sign, sign)); \
        float ov_ = (overlap_val); \
        if (ov_ < bestOverlap) { bestOverlap = ov_; bestNormal = n_; } \
    } while (0)

	{
		float ra, rb, L;
		ra = eA.x;
		rb = eB.x*AbsR[0][0] + eB.y*AbsR[0][1] + eB.z*AbsR[0][2];
		L = fabsf(tA[0]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(a0, (ra + rb) - L);
		ra = eA.y;
		rb = eB.x*AbsR[1][0] + eB.y*AbsR[1][1] + eB.z*AbsR[1][2];
		L = fabsf(tA[1]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(a1, (ra + rb) - L);
		ra = eA.z;
		rb = eB.x*AbsR[2][0] + eB.y*AbsR[2][1] + eB.z*AbsR[2][2];
		L = fabsf(tA[2]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(a2, (ra + rb) - L);
	}

	{
		float ra, rb, L;
		float tB[3] = {
			tA[0]*Rm[0][0] + tA[1]*Rm[1][0] + tA[2]*Rm[2][0],
			tA[0]*Rm[0][1] + tA[1]*Rm[1][1] + tA[2]*Rm[2][1],
			tA[0]*Rm[0][2] + tA[1]*Rm[1][2] + tA[2]*Rm[2][2],
		};
		ra = eA.x*AbsR[0][0] + eA.y*AbsR[1][0] + eA.z*AbsR[2][0];
		rb = eB.x;
		L = fabsf(tB[0]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(b0, (ra + rb) - L);
		ra = eA.x*AbsR[0][1] + eA.y*AbsR[1][1] + eA.z*AbsR[2][1];
		rb = eB.y;
		L = fabsf(tB[1]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(b1, (ra + rb) - L);
		ra = eA.x*AbsR[0][2] + eA.y*AbsR[1][2] + eA.z*AbsR[2][2];
		rb = eB.z;
		L = fabsf(tB[2]);
        if (L > ra + rb) return 0; else UPDATE_AXIS(b2, (ra + rb) - L);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int i1 = (i+1)%3, i2 = (i+2)%3;
			int j1 = (j+1)%3, j2 = (j+2)%3;
			float ra = (&eA.x)[i1]*AbsR[i2][j] + (&eA.x)[i2]*AbsR[i1][j];
			float rb = (&eB.x)[j1]*AbsR[i][j2] + (&eB.x)[j2]*AbsR[i][j1];
			float L = fabsf(tA[i2]*Rm[i1][j] - tA[i1]*Rm[i2][j]);
			if (L > ra + rb) return 0;
			V3f Ai = i == 0 ? a0 : (i == 1 ? a1 : a2);
			V3f Bj = j == 0 ? b0 : (j == 1 ? b1 : b2);
			V3f axis = v3f_cross(Ai, Bj);
			float len2 = v3f_dot(axis, axis);
			if (len2 <= 1e-8f) continue; // nearly parallel -> skip for MTV
            UPDATE_AXIS(axis, (ra + rb) - L);
		}
	}

	*outNormal = bestNormal;
	*outPen = bestOverlap;
    #undef UPDATE_AXIS
	return 1;
}


int main(void)
{
	RigidBody A = {0};
	RigidBody B = {0};
	A.position = v3f(-1.5f, 0.0f, 0.0f);
	B.position = v3f( 1.5f, 0.0f, 0.0f);
	A.linearVelocity = v3f(0.6f, 0.0f, 0.0f);
	B.linearVelocity = v3f(-0.6f, 0.0f, 0.0f);
	A.orientation = r3f_identity();
	B.orientation = r3f_identity();
	A.angularVelocity = v3f(0.3f, 0.0f, 0.0f);
	B.angularVelocity = v3f(0.0f, 0.2f, 0.0f);

	V3f eye = v3f(0.0f, 0.5f, 4.0f);
	V3f target = v3f(0.0f, 0.0f, 0.0f);
	V3f up = v3f(0.0f, 1.0f, 0.0f);
	M3x3f Rcam = lookat_R(eye, target, up);

	const float focal = 1.2f; // simple focal length scale

	V3f corners[8] = {
		{{-0.5f,-0.5f,-0.5f}}, {{ 0.5f,-0.5f,-0.5f}}, {{ 0.5f, 0.5f,-0.5f}}, {{-0.5f, 0.5f,-0.5f}},
		{{-0.5f,-0.5f, 0.5f}}, {{ 0.5f,-0.5f, 0.5f}}, {{ 0.5f, 0.5f, 0.5f}}, {{-0.5f, 0.5f, 0.5f}},
	};
	int edges[12][2] = {
		{0,1},{1,2},{2,3},{3,0}, // bottom
		{4,5},{5,6},{6,7},{7,4}, // top
		{0,4},{1,5},{2,6},{3,7}, // verticals
	};

	#define FPS 30
	const float dt = 1.0f/FPS;
	const float restitution = 0.5f;
	const V3f halfExtents = v3f(0.5f, 0.5f, 0.5f);

	for (;;) {
		integrate(&A, dt);
		integrate(&B, dt);

		{
			V3f a0 = r3f_rotate_v3f(A.orientation, v3f(1.0f, 0.0f, 0.0f));
			V3f a1 = r3f_rotate_v3f(A.orientation, v3f(0.0f, 1.0f, 0.0f));
			V3f a2 = r3f_rotate_v3f(A.orientation, v3f(0.0f, 0.0f, 1.0f));
			V3f b0 = r3f_rotate_v3f(B.orientation, v3f(1.0f, 0.0f, 0.0f));
			V3f b1 = r3f_rotate_v3f(B.orientation, v3f(0.0f, 1.0f, 0.0f));
			V3f b2 = r3f_rotate_v3f(B.orientation, v3f(0.0f, 0.0f, 1.0f));
			V3f n; float pen;
			if (obb_obb_mtv(A.position, halfExtents, a0,a1,a2, B.position, halfExtents, b0,b1,b2, &n, &pen)) {
				// positional correction (split)
				V3f mtv = v3f_mul(n, v3f(pen*0.5f, pen*0.5f, pen*0.5f));
				A.position = v3f_sub(A.position, mtv);
				B.position = v3f_sum(B.position, mtv);
				// velocity response (impulse along normal)
				float rel = v3f_dot(v3f_sub(B.linearVelocity, A.linearVelocity), n);
				if (rel < 0.0f) {
					float j = -(1.0f + restitution) * rel / 2.0f; // masses=1
					V3f J = v3f_mul(n, v3f(j, j, j));
					A.linearVelocity = v3f_sub(A.linearVelocity, J);
					B.linearVelocity = v3f_sum(B.linearVelocity, J);
				}
			}
		}

		fill(BACK);
		for (int which = 0; which < 2; ++which) {
			RigidBody *R = which == 0 ? &A : &B;
			V3f world[8];
			for (int i = 0; i < 8; ++i) {
				V3f p = r3f_rotate_v3f(R->orientation, corners[i]);
				world[i] = v3f_sum(R->position, p);
			}
			int sx[8], sy[8], vis[8];
			for (int i = 0; i < 8; ++i) vis[i] = project_point(world[i], eye, Rcam, WIDTH, HEIGHT, focal, &sx[i], &sy[i]);
			for (int e = 0; e < 12; ++e) {
				int a = edges[e][0], b = edges[e][1];
				if (vis[a] && vis[b]) draw_line(sx[a], sy[a], sx[b], sy[b]);
			}
		}

		show();
		back();
		usleep(1000 * 1000 / FPS);
	}

	return 0;
}
