// This is a small example on how to use la.h
// Just a simple simulation of a bouncing ball with ASCII Art rendering in the terminal
// cc -o ball ball.c -lm && ./ball
#define _XOPEN_SOURCE 500
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>

#define LA_IMPLEMENTATION
#include "./la.h"

typedef enum {
    BACK = 0,
    FORE = 1,
    PIXEL_N,
} Pixel;

#define WIDTH 64
#define HEIGHT 32
static_assert(HEIGHT % 2 == 0, "If the amount of display rows is not divisible by 2 we can't properly compress it. See show(void) function");
static Pixel display[WIDTH * HEIGHT];

static void fill(Pixel p)
{
    Pixel *ptr = display;
    size_t n = WIDTH*HEIGHT;
    while (n-- > 0) *ptr++ = p;
}

// ..............................
// ..............................
// ..........@@@@@@@.............
// ..........@.***.@.............
// ..........@*****@.............
// ..........@**c**@.............
// ..........@*****@.............
// ..........@.***.@.............
// ..........@@@@@@@.............
// ..............................
// x^2 + y^2 <= r^2
static void circle(V2f c, float r)
{
    V2i b = v2i2f(v2f_floor(v2f_sub(c, v2ff(r))));
    V2i e = v2i2f(v2f_ceil(v2f_sum(c, v2ff(r))));

    for (int y = b.y; y <= e.y; ++y) {
        for (int x = b.x; x <= e.x; ++x) {
            V2f p = v2f_sum(v2f2i(v2i(x, y)), v2ff(0.5f));
            V2f d = v2f_sub(c, p);
            if (v2f_sqrlen(d) <= r*r) {
                if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT) {
                    display[y*WIDTH + x] = FORE;
                }
            }
        }
    }
}

// Double Row Pixel compression
//
// |..**...***...|
// |**....****...|
//       |
//       V
// |__^^  _CCC   |
//
static void show(void)
{
    static char row[WIDTH];
    static char *table = " _^C";
    for (int y = 0; y < HEIGHT/2; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Pixel t = display[(2*y + 0)*WIDTH + x];
            Pixel b = display[(2*y + 1)*WIDTH + x];
            assert(0 <= t);
            assert(t < PIXEL_N);
            assert(0 <= b);
            assert(b < PIXEL_N);
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

#define FPS 30
#define RADIUS (HEIGHT/4.0f)
#define GRAVITY 200.0f
#define DT (1.0f/FPS)
#define DAMPER 0.65f

static V2f pos;
static V2f vel;

static void reset(void)
{
    pos = v2ff(-RADIUS);
    vel = v2f(50.0f, 0.0f);
}

int main(void)
{
    reset();
    while (1) {
        vel = v2f_sum(vel, v2f(0.0f, GRAVITY*DT));
        pos = v2f_sum(pos, v2f_mul(vel, v2ff(DT)));

        if (pos.y > HEIGHT - RADIUS) {
            pos.y = HEIGHT - RADIUS;
            vel.y *= -DAMPER;
        }

        if (pos.x >= WIDTH + RADIUS + RADIUS * 2.0f) {
            reset();
        }

        fill(BACK);
        circle(pos, RADIUS);
        show();
        back();

        usleep(1000 * 1000 / FPS);
    }
    return 0;
}
