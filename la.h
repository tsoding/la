#ifndef LA_H_
#define LA_H_

#include <math.h>

float lerpf(float a, float b, float t);
double lerp(double a, double b, double t);

typedef struct { float x, y; } V2f;
#define V2f_Fmt "v2f(%f, %f)"
#define V2f_Arg(v) v.c[0], v.c[1]
V2f v2f(float x, float y);
V2f v2fs(float x);
V2f v2f_sum(V2f a, V2f b);
V2f v2f_sub(V2f a, V2f b);
V2f v2f_mul(V2f a, V2f b);
V2f v2f_div(V2f a, V2f b);
V2f v2f_sqrt(V2f a);
V2f v2f_pow(V2f base, V2f exp);
V2f v2f_sin(V2f a);
V2f v2f_cos(V2f a);
V2f v2f_min(V2f a, V2f b);
V2f v2f_max(V2f a, V2f b);
V2f v2f_lerp(V2f a, V2f b, V2f t);
V2f v2f_floor(V2f a);
V2f v2f_ceil(V2f a);
float v2f_sqrlen(V2f a);
float v2f_len(V2f a);

typedef struct { double x, y; } V2d;
#define V2d_Fmt "v2d(%lf, %lf)"
#define V2d_Arg(v) v.c[0], v.c[1]
V2d v2d(double x, double y);
V2d v2ds(double x);
V2d v2d_sum(V2d a, V2d b);
V2d v2d_sub(V2d a, V2d b);
V2d v2d_mul(V2d a, V2d b);
V2d v2d_div(V2d a, V2d b);
V2d v2d_sqrt(V2d a);
V2d v2d_pow(V2d base, V2d exp);
V2d v2d_sin(V2d a);
V2d v2d_cos(V2d a);
V2d v2d_min(V2d a, V2d b);
V2d v2d_max(V2d a, V2d b);
V2d v2d_lerp(V2d a, V2d b, V2d t);
V2d v2d_floor(V2d a);
V2d v2d_ceil(V2d a);
double v2d_sqrlen(V2d a);
double v2d_len(V2d a);

typedef struct { int x, y; } V2i;
#define V2i_Fmt "v2i(%d, %d)"
#define V2i_Arg(v) v.c[0], v.c[1]
V2i v2i(int x, int y);
V2i v2is(int x);
V2i v2i_sum(V2i a, V2i b);
V2i v2i_sub(V2i a, V2i b);
V2i v2i_mul(V2i a, V2i b);
V2i v2i_div(V2i a, V2i b);
int v2i_sqrlen(V2i a);

typedef struct { float x, y, z; } V3f;
#define V3f_Fmt "v3f(%f, %f, %f)"
#define V3f_Arg(v) v.c[0], v.c[1], v.c[2]
V3f v3f(float x, float y, float z);
V3f v3fs(float x);
V3f v3f_sum(V3f a, V3f b);
V3f v3f_sub(V3f a, V3f b);
V3f v3f_mul(V3f a, V3f b);
V3f v3f_div(V3f a, V3f b);
V3f v3f_sqrt(V3f a);
V3f v3f_pow(V3f base, V3f exp);
V3f v3f_sin(V3f a);
V3f v3f_cos(V3f a);
V3f v3f_min(V3f a, V3f b);
V3f v3f_max(V3f a, V3f b);
V3f v3f_lerp(V3f a, V3f b, V3f t);
V3f v3f_floor(V3f a);
V3f v3f_ceil(V3f a);
float v3f_sqrlen(V3f a);
float v3f_len(V3f a);

typedef struct { double x, y, z; } V3d;
#define V3d_Fmt "v3d(%lf, %lf, %lf)"
#define V3d_Arg(v) v.c[0], v.c[1], v.c[2]
V3d v3d(double x, double y, double z);
V3d v3ds(double x);
V3d v3d_sum(V3d a, V3d b);
V3d v3d_sub(V3d a, V3d b);
V3d v3d_mul(V3d a, V3d b);
V3d v3d_div(V3d a, V3d b);
V3d v3d_sqrt(V3d a);
V3d v3d_pow(V3d base, V3d exp);
V3d v3d_sin(V3d a);
V3d v3d_cos(V3d a);
V3d v3d_min(V3d a, V3d b);
V3d v3d_max(V3d a, V3d b);
V3d v3d_lerp(V3d a, V3d b, V3d t);
V3d v3d_floor(V3d a);
V3d v3d_ceil(V3d a);
double v3d_sqrlen(V3d a);
double v3d_len(V3d a);

typedef struct { int x, y, z; } V3i;
#define V3i_Fmt "v3i(%d, %d, %d)"
#define V3i_Arg(v) v.c[0], v.c[1], v.c[2]
V3i v3i(int x, int y, int z);
V3i v3is(int x);
V3i v3i_sum(V3i a, V3i b);
V3i v3i_sub(V3i a, V3i b);
V3i v3i_mul(V3i a, V3i b);
V3i v3i_div(V3i a, V3i b);
int v3i_sqrlen(V3i a);

typedef struct { float x, y, z, w; } V4f;
#define V4f_Fmt "v4f(%f, %f, %f, %f)"
#define V4f_Arg(v) v.c[0], v.c[1], v.c[2], v.c[3]
V4f v4f(float x, float y, float z, float w);
V4f v4fs(float x);
V4f v4f_sum(V4f a, V4f b);
V4f v4f_sub(V4f a, V4f b);
V4f v4f_mul(V4f a, V4f b);
V4f v4f_div(V4f a, V4f b);
V4f v4f_sqrt(V4f a);
V4f v4f_pow(V4f base, V4f exp);
V4f v4f_sin(V4f a);
V4f v4f_cos(V4f a);
V4f v4f_min(V4f a, V4f b);
V4f v4f_max(V4f a, V4f b);
V4f v4f_lerp(V4f a, V4f b, V4f t);
V4f v4f_floor(V4f a);
V4f v4f_ceil(V4f a);
float v4f_sqrlen(V4f a);
float v4f_len(V4f a);

typedef struct { double x, y, z, w; } V4d;
#define V4d_Fmt "v4d(%lf, %lf, %lf, %lf)"
#define V4d_Arg(v) v.c[0], v.c[1], v.c[2], v.c[3]
V4d v4d(double x, double y, double z, double w);
V4d v4ds(double x);
V4d v4d_sum(V4d a, V4d b);
V4d v4d_sub(V4d a, V4d b);
V4d v4d_mul(V4d a, V4d b);
V4d v4d_div(V4d a, V4d b);
V4d v4d_sqrt(V4d a);
V4d v4d_pow(V4d base, V4d exp);
V4d v4d_sin(V4d a);
V4d v4d_cos(V4d a);
V4d v4d_min(V4d a, V4d b);
V4d v4d_max(V4d a, V4d b);
V4d v4d_lerp(V4d a, V4d b, V4d t);
V4d v4d_floor(V4d a);
V4d v4d_ceil(V4d a);
double v4d_sqrlen(V4d a);
double v4d_len(V4d a);

typedef struct { int x, y, z, w; } V4i;
#define V4i_Fmt "v4i(%d, %d, %d, %d)"
#define V4i_Arg(v) v.c[0], v.c[1], v.c[2], v.c[3]
V4i v4i(int x, int y, int z, int w);
V4i v4is(int x);
V4i v4i_sum(V4i a, V4i b);
V4i v4i_sub(V4i a, V4i b);
V4i v4i_mul(V4i a, V4i b);
V4i v4i_div(V4i a, V4i b);
int v4i_sqrlen(V4i a);

#endif // LA_H_

#ifdef LA_IMPLEMENTATION

float lerpf(float a, float b, float t)
{
    return a + (b - a) * t;
}
double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}
V2f v2f(float x, float y)
{
    V2f v;
    v.x = x;
    v.y = y;
    return v;
}
V2f v2fs(float x)
{
    return v2f(x, x);
}
V2f v2f_sum(V2f a, V2f b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
V2f v2f_sub(V2f a, V2f b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
V2f v2f_mul(V2f a, V2f b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
V2f v2f_div(V2f a, V2f b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
V2f v2f_sqrt(V2f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return a;
}
V2f v2f_pow(V2f base, V2f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    return base;
}
V2f v2f_sin(V2f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    return a;
}
V2f v2f_cos(V2f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    return a;
}
V2f v2f_min(V2f a, V2f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    return a;
}
V2f v2f_max(V2f a, V2f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    return a;
}
V2f v2f_lerp(V2f a, V2f b, V2f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    return a;
}
V2f v2f_floor(V2f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return a;
}
V2f v2f_ceil(V2f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return a;
}
float v2f_sqrlen(V2f a)
{
    return a.x*a.x + a.y*a.y;
}
float v2f_len(V2f a)
{
    return sqrtf(v2f_sqrlen(a));
}
V2d v2d(double x, double y)
{
    V2d v;
    v.x = x;
    v.y = y;
    return v;
}
V2d v2ds(double x)
{
    return v2d(x, x);
}
V2d v2d_sum(V2d a, V2d b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
V2d v2d_sub(V2d a, V2d b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
V2d v2d_mul(V2d a, V2d b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
V2d v2d_div(V2d a, V2d b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
V2d v2d_sqrt(V2d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    return a;
}
V2d v2d_pow(V2d base, V2d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    return base;
}
V2d v2d_sin(V2d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    return a;
}
V2d v2d_cos(V2d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    return a;
}
V2d v2d_min(V2d a, V2d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    return a;
}
V2d v2d_max(V2d a, V2d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    return a;
}
V2d v2d_lerp(V2d a, V2d b, V2d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    return a;
}
V2d v2d_floor(V2d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    return a;
}
V2d v2d_ceil(V2d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    return a;
}
double v2d_sqrlen(V2d a)
{
    return a.x*a.x + a.y*a.y;
}
double v2d_len(V2d a)
{
    return sqrt(v2d_sqrlen(a));
}
V2i v2i(int x, int y)
{
    V2i v;
    v.x = x;
    v.y = y;
    return v;
}
V2i v2is(int x)
{
    return v2i(x, x);
}
V2i v2i_sum(V2i a, V2i b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
V2i v2i_sub(V2i a, V2i b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
V2i v2i_mul(V2i a, V2i b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
V2i v2i_div(V2i a, V2i b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
int v2i_sqrlen(V2i a)
{
    return a.x*a.x + a.y*a.y;
}
V3f v3f(float x, float y, float z)
{
    V3f v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
V3f v3fs(float x)
{
    return v3f(x, x, x);
}
V3f v3f_sum(V3f a, V3f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
V3f v3f_sub(V3f a, V3f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
V3f v3f_mul(V3f a, V3f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
V3f v3f_div(V3f a, V3f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
V3f v3f_sqrt(V3f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    return a;
}
V3f v3f_pow(V3f base, V3f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    return base;
}
V3f v3f_sin(V3f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    return a;
}
V3f v3f_cos(V3f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    return a;
}
V3f v3f_min(V3f a, V3f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    return a;
}
V3f v3f_max(V3f a, V3f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    return a;
}
V3f v3f_lerp(V3f a, V3f b, V3f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    return a;
}
V3f v3f_floor(V3f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    return a;
}
V3f v3f_ceil(V3f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    return a;
}
float v3f_sqrlen(V3f a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}
float v3f_len(V3f a)
{
    return sqrtf(v3f_sqrlen(a));
}
V3d v3d(double x, double y, double z)
{
    V3d v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
V3d v3ds(double x)
{
    return v3d(x, x, x);
}
V3d v3d_sum(V3d a, V3d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
V3d v3d_sub(V3d a, V3d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
V3d v3d_mul(V3d a, V3d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
V3d v3d_div(V3d a, V3d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
V3d v3d_sqrt(V3d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    return a;
}
V3d v3d_pow(V3d base, V3d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    return base;
}
V3d v3d_sin(V3d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    return a;
}
V3d v3d_cos(V3d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    return a;
}
V3d v3d_min(V3d a, V3d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    return a;
}
V3d v3d_max(V3d a, V3d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    return a;
}
V3d v3d_lerp(V3d a, V3d b, V3d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    return a;
}
V3d v3d_floor(V3d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    return a;
}
V3d v3d_ceil(V3d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    return a;
}
double v3d_sqrlen(V3d a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}
double v3d_len(V3d a)
{
    return sqrt(v3d_sqrlen(a));
}
V3i v3i(int x, int y, int z)
{
    V3i v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
V3i v3is(int x)
{
    return v3i(x, x, x);
}
V3i v3i_sum(V3i a, V3i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
V3i v3i_sub(V3i a, V3i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
V3i v3i_mul(V3i a, V3i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
V3i v3i_div(V3i a, V3i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
int v3i_sqrlen(V3i a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}
V4f v4f(float x, float y, float z, float w)
{
    V4f v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}
V4f v4fs(float x)
{
    return v4f(x, x, x, x);
}
V4f v4f_sum(V4f a, V4f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
V4f v4f_sub(V4f a, V4f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
V4f v4f_mul(V4f a, V4f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
V4f v4f_div(V4f a, V4f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
V4f v4f_sqrt(V4f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    a.w = sqrtf(a.w);
    return a;
}
V4f v4f_pow(V4f base, V4f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    base.w = powf(base.w, exp.w);
    return base;
}
V4f v4f_sin(V4f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    a.w = sinf(a.w);
    return a;
}
V4f v4f_cos(V4f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    a.w = cosf(a.w);
    return a;
}
V4f v4f_min(V4f a, V4f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    a.w = fminf(a.w, b.w);
    return a;
}
V4f v4f_max(V4f a, V4f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    a.w = fmaxf(a.w, b.w);
    return a;
}
V4f v4f_lerp(V4f a, V4f b, V4f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    a.w = lerpf(a.w, b.w, t.w);
    return a;
}
V4f v4f_floor(V4f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    a.w = floorf(a.w);
    return a;
}
V4f v4f_ceil(V4f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    a.w = ceilf(a.w);
    return a;
}
float v4f_sqrlen(V4f a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}
float v4f_len(V4f a)
{
    return sqrtf(v4f_sqrlen(a));
}
V4d v4d(double x, double y, double z, double w)
{
    V4d v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}
V4d v4ds(double x)
{
    return v4d(x, x, x, x);
}
V4d v4d_sum(V4d a, V4d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
V4d v4d_sub(V4d a, V4d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
V4d v4d_mul(V4d a, V4d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
V4d v4d_div(V4d a, V4d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
V4d v4d_sqrt(V4d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    a.w = sqrt(a.w);
    return a;
}
V4d v4d_pow(V4d base, V4d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    base.w = pow(base.w, exp.w);
    return base;
}
V4d v4d_sin(V4d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    a.w = sin(a.w);
    return a;
}
V4d v4d_cos(V4d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    a.w = cos(a.w);
    return a;
}
V4d v4d_min(V4d a, V4d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    a.w = fmin(a.w, b.w);
    return a;
}
V4d v4d_max(V4d a, V4d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    a.w = fmax(a.w, b.w);
    return a;
}
V4d v4d_lerp(V4d a, V4d b, V4d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    a.w = lerp(a.w, b.w, t.w);
    return a;
}
V4d v4d_floor(V4d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    a.w = floor(a.w);
    return a;
}
V4d v4d_ceil(V4d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    a.w = ceil(a.w);
    return a;
}
double v4d_sqrlen(V4d a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}
double v4d_len(V4d a)
{
    return sqrt(v4d_sqrlen(a));
}
V4i v4i(int x, int y, int z, int w)
{
    V4i v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}
V4i v4is(int x)
{
    return v4i(x, x, x, x);
}
V4i v4i_sum(V4i a, V4i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
V4i v4i_sub(V4i a, V4i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
V4i v4i_mul(V4i a, V4i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
V4i v4i_div(V4i a, V4i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
int v4i_sqrlen(V4i a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

#endif // LA_IMPLEMENTATION
