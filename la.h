#ifndef LA_H_
#define LA_H_

#include <math.h>

float lerpf(float a, float b, float t);
double lerp(double a, double b, double t);

typedef struct { float c[2]; } V2f;
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

typedef struct { double c[2]; } V2d;
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

typedef struct { int c[2]; } V2i;
#define V2i_Fmt "v2i(%d, %d)"
#define V2i_Arg(v) v.c[0], v.c[1]
V2i v2i(int x, int y);
V2i v2is(int x);
V2i v2i_sum(V2i a, V2i b);
V2i v2i_sub(V2i a, V2i b);
V2i v2i_mul(V2i a, V2i b);
V2i v2i_div(V2i a, V2i b);
int v2i_sqrlen(V2i a);

typedef struct { float c[3]; } V3f;
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

typedef struct { double c[3]; } V3d;
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

typedef struct { int c[3]; } V3i;
#define V3i_Fmt "v3i(%d, %d, %d)"
#define V3i_Arg(v) v.c[0], v.c[1], v.c[2]
V3i v3i(int x, int y, int z);
V3i v3is(int x);
V3i v3i_sum(V3i a, V3i b);
V3i v3i_sub(V3i a, V3i b);
V3i v3i_mul(V3i a, V3i b);
V3i v3i_div(V3i a, V3i b);
int v3i_sqrlen(V3i a);

typedef struct { float c[4]; } V4f;
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

typedef struct { double c[4]; } V4d;
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

typedef struct { int c[4]; } V4i;
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
    V2f result;
    result.c[0] = x;
    result.c[1] = y;
    return result;
}
V2f v2fs(float x)
{
    return v2f(x, x);
}
V2f v2f_sum(V2f a, V2f b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    return a;
}
V2f v2f_sub(V2f a, V2f b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    return a;
}
V2f v2f_mul(V2f a, V2f b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    return a;
}
V2f v2f_div(V2f a, V2f b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    return a;
}
V2f v2f_sqrt(V2f a)
{
    a.c[0] = sqrtf(a.c[0]);
    a.c[1] = sqrtf(a.c[1]);
    return a;
}
V2f v2f_pow(V2f base, V2f exp)
{
    base.c[0] = powf(base.c[0], exp.c[0]);
    base.c[1] = powf(base.c[1], exp.c[1]);
    return base;
}
V2f v2f_sin(V2f a)
{
    a.c[0] = sinf(a.c[0]);
    a.c[1] = sinf(a.c[1]);
    return a;
}
V2f v2f_cos(V2f a)
{
    a.c[0] = cosf(a.c[0]);
    a.c[1] = cosf(a.c[1]);
    return a;
}
V2f v2f_min(V2f a, V2f b)
{
    a.c[0] = fminf(a.c[0], b.c[0]);
    a.c[1] = fminf(a.c[1], b.c[1]);
    return a;
}
V2f v2f_max(V2f a, V2f b)
{
    a.c[0] = fmaxf(a.c[0], b.c[0]);
    a.c[1] = fmaxf(a.c[1], b.c[1]);
    return a;
}
V2f v2f_lerp(V2f a, V2f b, V2f t)
{
    a.c[0] = lerpf(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerpf(a.c[1], b.c[1], t.c[1]);
    return a;
}
V2f v2f_floor(V2f a)
{
    a.c[0] = floorf(a.c[0]);
    a.c[1] = floorf(a.c[1]);
    return a;
}
V2f v2f_ceil(V2f a)
{
    a.c[0] = ceilf(a.c[0]);
    a.c[1] = ceilf(a.c[1]);
    return a;
}
float v2f_sqrlen(V2f a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1];
}
V2d v2d(double x, double y)
{
    V2d result;
    result.c[0] = x;
    result.c[1] = y;
    return result;
}
V2d v2ds(double x)
{
    return v2d(x, x);
}
V2d v2d_sum(V2d a, V2d b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    return a;
}
V2d v2d_sub(V2d a, V2d b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    return a;
}
V2d v2d_mul(V2d a, V2d b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    return a;
}
V2d v2d_div(V2d a, V2d b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    return a;
}
V2d v2d_sqrt(V2d a)
{
    a.c[0] = sqrt(a.c[0]);
    a.c[1] = sqrt(a.c[1]);
    return a;
}
V2d v2d_pow(V2d base, V2d exp)
{
    base.c[0] = pow(base.c[0], exp.c[0]);
    base.c[1] = pow(base.c[1], exp.c[1]);
    return base;
}
V2d v2d_sin(V2d a)
{
    a.c[0] = sin(a.c[0]);
    a.c[1] = sin(a.c[1]);
    return a;
}
V2d v2d_cos(V2d a)
{
    a.c[0] = cos(a.c[0]);
    a.c[1] = cos(a.c[1]);
    return a;
}
V2d v2d_min(V2d a, V2d b)
{
    a.c[0] = fmin(a.c[0], b.c[0]);
    a.c[1] = fmin(a.c[1], b.c[1]);
    return a;
}
V2d v2d_max(V2d a, V2d b)
{
    a.c[0] = fmax(a.c[0], b.c[0]);
    a.c[1] = fmax(a.c[1], b.c[1]);
    return a;
}
V2d v2d_lerp(V2d a, V2d b, V2d t)
{
    a.c[0] = lerp(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerp(a.c[1], b.c[1], t.c[1]);
    return a;
}
V2d v2d_floor(V2d a)
{
    a.c[0] = floor(a.c[0]);
    a.c[1] = floor(a.c[1]);
    return a;
}
V2d v2d_ceil(V2d a)
{
    a.c[0] = ceil(a.c[0]);
    a.c[1] = ceil(a.c[1]);
    return a;
}
double v2d_sqrlen(V2d a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1];
}
V2i v2i(int x, int y)
{
    V2i result;
    result.c[0] = x;
    result.c[1] = y;
    return result;
}
V2i v2is(int x)
{
    return v2i(x, x);
}
V2i v2i_sum(V2i a, V2i b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    return a;
}
V2i v2i_sub(V2i a, V2i b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    return a;
}
V2i v2i_mul(V2i a, V2i b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    return a;
}
V2i v2i_div(V2i a, V2i b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    return a;
}
int v2i_sqrlen(V2i a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1];
}
V3f v3f(float x, float y, float z)
{
    V3f result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    return result;
}
V3f v3fs(float x)
{
    return v3f(x, x, x);
}
V3f v3f_sum(V3f a, V3f b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    return a;
}
V3f v3f_sub(V3f a, V3f b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    return a;
}
V3f v3f_mul(V3f a, V3f b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    return a;
}
V3f v3f_div(V3f a, V3f b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    return a;
}
V3f v3f_sqrt(V3f a)
{
    a.c[0] = sqrtf(a.c[0]);
    a.c[1] = sqrtf(a.c[1]);
    a.c[2] = sqrtf(a.c[2]);
    return a;
}
V3f v3f_pow(V3f base, V3f exp)
{
    base.c[0] = powf(base.c[0], exp.c[0]);
    base.c[1] = powf(base.c[1], exp.c[1]);
    base.c[2] = powf(base.c[2], exp.c[2]);
    return base;
}
V3f v3f_sin(V3f a)
{
    a.c[0] = sinf(a.c[0]);
    a.c[1] = sinf(a.c[1]);
    a.c[2] = sinf(a.c[2]);
    return a;
}
V3f v3f_cos(V3f a)
{
    a.c[0] = cosf(a.c[0]);
    a.c[1] = cosf(a.c[1]);
    a.c[2] = cosf(a.c[2]);
    return a;
}
V3f v3f_min(V3f a, V3f b)
{
    a.c[0] = fminf(a.c[0], b.c[0]);
    a.c[1] = fminf(a.c[1], b.c[1]);
    a.c[2] = fminf(a.c[2], b.c[2]);
    return a;
}
V3f v3f_max(V3f a, V3f b)
{
    a.c[0] = fmaxf(a.c[0], b.c[0]);
    a.c[1] = fmaxf(a.c[1], b.c[1]);
    a.c[2] = fmaxf(a.c[2], b.c[2]);
    return a;
}
V3f v3f_lerp(V3f a, V3f b, V3f t)
{
    a.c[0] = lerpf(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerpf(a.c[1], b.c[1], t.c[1]);
    a.c[2] = lerpf(a.c[2], b.c[2], t.c[2]);
    return a;
}
V3f v3f_floor(V3f a)
{
    a.c[0] = floorf(a.c[0]);
    a.c[1] = floorf(a.c[1]);
    a.c[2] = floorf(a.c[2]);
    return a;
}
V3f v3f_ceil(V3f a)
{
    a.c[0] = ceilf(a.c[0]);
    a.c[1] = ceilf(a.c[1]);
    a.c[2] = ceilf(a.c[2]);
    return a;
}
float v3f_sqrlen(V3f a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2];
}
V3d v3d(double x, double y, double z)
{
    V3d result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    return result;
}
V3d v3ds(double x)
{
    return v3d(x, x, x);
}
V3d v3d_sum(V3d a, V3d b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    return a;
}
V3d v3d_sub(V3d a, V3d b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    return a;
}
V3d v3d_mul(V3d a, V3d b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    return a;
}
V3d v3d_div(V3d a, V3d b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    return a;
}
V3d v3d_sqrt(V3d a)
{
    a.c[0] = sqrt(a.c[0]);
    a.c[1] = sqrt(a.c[1]);
    a.c[2] = sqrt(a.c[2]);
    return a;
}
V3d v3d_pow(V3d base, V3d exp)
{
    base.c[0] = pow(base.c[0], exp.c[0]);
    base.c[1] = pow(base.c[1], exp.c[1]);
    base.c[2] = pow(base.c[2], exp.c[2]);
    return base;
}
V3d v3d_sin(V3d a)
{
    a.c[0] = sin(a.c[0]);
    a.c[1] = sin(a.c[1]);
    a.c[2] = sin(a.c[2]);
    return a;
}
V3d v3d_cos(V3d a)
{
    a.c[0] = cos(a.c[0]);
    a.c[1] = cos(a.c[1]);
    a.c[2] = cos(a.c[2]);
    return a;
}
V3d v3d_min(V3d a, V3d b)
{
    a.c[0] = fmin(a.c[0], b.c[0]);
    a.c[1] = fmin(a.c[1], b.c[1]);
    a.c[2] = fmin(a.c[2], b.c[2]);
    return a;
}
V3d v3d_max(V3d a, V3d b)
{
    a.c[0] = fmax(a.c[0], b.c[0]);
    a.c[1] = fmax(a.c[1], b.c[1]);
    a.c[2] = fmax(a.c[2], b.c[2]);
    return a;
}
V3d v3d_lerp(V3d a, V3d b, V3d t)
{
    a.c[0] = lerp(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerp(a.c[1], b.c[1], t.c[1]);
    a.c[2] = lerp(a.c[2], b.c[2], t.c[2]);
    return a;
}
V3d v3d_floor(V3d a)
{
    a.c[0] = floor(a.c[0]);
    a.c[1] = floor(a.c[1]);
    a.c[2] = floor(a.c[2]);
    return a;
}
V3d v3d_ceil(V3d a)
{
    a.c[0] = ceil(a.c[0]);
    a.c[1] = ceil(a.c[1]);
    a.c[2] = ceil(a.c[2]);
    return a;
}
double v3d_sqrlen(V3d a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2];
}
V3i v3i(int x, int y, int z)
{
    V3i result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    return result;
}
V3i v3is(int x)
{
    return v3i(x, x, x);
}
V3i v3i_sum(V3i a, V3i b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    return a;
}
V3i v3i_sub(V3i a, V3i b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    return a;
}
V3i v3i_mul(V3i a, V3i b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    return a;
}
V3i v3i_div(V3i a, V3i b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    return a;
}
int v3i_sqrlen(V3i a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2];
}
V4f v4f(float x, float y, float z, float w)
{
    V4f result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    result.c[3] = w;
    return result;
}
V4f v4fs(float x)
{
    return v4f(x, x, x, x);
}
V4f v4f_sum(V4f a, V4f b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    a.c[3] += b.c[3];
    return a;
}
V4f v4f_sub(V4f a, V4f b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    a.c[3] -= b.c[3];
    return a;
}
V4f v4f_mul(V4f a, V4f b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    a.c[3] *= b.c[3];
    return a;
}
V4f v4f_div(V4f a, V4f b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    a.c[3] /= b.c[3];
    return a;
}
V4f v4f_sqrt(V4f a)
{
    a.c[0] = sqrtf(a.c[0]);
    a.c[1] = sqrtf(a.c[1]);
    a.c[2] = sqrtf(a.c[2]);
    a.c[3] = sqrtf(a.c[3]);
    return a;
}
V4f v4f_pow(V4f base, V4f exp)
{
    base.c[0] = powf(base.c[0], exp.c[0]);
    base.c[1] = powf(base.c[1], exp.c[1]);
    base.c[2] = powf(base.c[2], exp.c[2]);
    base.c[3] = powf(base.c[3], exp.c[3]);
    return base;
}
V4f v4f_sin(V4f a)
{
    a.c[0] = sinf(a.c[0]);
    a.c[1] = sinf(a.c[1]);
    a.c[2] = sinf(a.c[2]);
    a.c[3] = sinf(a.c[3]);
    return a;
}
V4f v4f_cos(V4f a)
{
    a.c[0] = cosf(a.c[0]);
    a.c[1] = cosf(a.c[1]);
    a.c[2] = cosf(a.c[2]);
    a.c[3] = cosf(a.c[3]);
    return a;
}
V4f v4f_min(V4f a, V4f b)
{
    a.c[0] = fminf(a.c[0], b.c[0]);
    a.c[1] = fminf(a.c[1], b.c[1]);
    a.c[2] = fminf(a.c[2], b.c[2]);
    a.c[3] = fminf(a.c[3], b.c[3]);
    return a;
}
V4f v4f_max(V4f a, V4f b)
{
    a.c[0] = fmaxf(a.c[0], b.c[0]);
    a.c[1] = fmaxf(a.c[1], b.c[1]);
    a.c[2] = fmaxf(a.c[2], b.c[2]);
    a.c[3] = fmaxf(a.c[3], b.c[3]);
    return a;
}
V4f v4f_lerp(V4f a, V4f b, V4f t)
{
    a.c[0] = lerpf(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerpf(a.c[1], b.c[1], t.c[1]);
    a.c[2] = lerpf(a.c[2], b.c[2], t.c[2]);
    a.c[3] = lerpf(a.c[3], b.c[3], t.c[3]);
    return a;
}
V4f v4f_floor(V4f a)
{
    a.c[0] = floorf(a.c[0]);
    a.c[1] = floorf(a.c[1]);
    a.c[2] = floorf(a.c[2]);
    a.c[3] = floorf(a.c[3]);
    return a;
}
V4f v4f_ceil(V4f a)
{
    a.c[0] = ceilf(a.c[0]);
    a.c[1] = ceilf(a.c[1]);
    a.c[2] = ceilf(a.c[2]);
    a.c[3] = ceilf(a.c[3]);
    return a;
}
float v4f_sqrlen(V4f a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2] + a.c[3]*a.c[3];
}
V4d v4d(double x, double y, double z, double w)
{
    V4d result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    result.c[3] = w;
    return result;
}
V4d v4ds(double x)
{
    return v4d(x, x, x, x);
}
V4d v4d_sum(V4d a, V4d b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    a.c[3] += b.c[3];
    return a;
}
V4d v4d_sub(V4d a, V4d b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    a.c[3] -= b.c[3];
    return a;
}
V4d v4d_mul(V4d a, V4d b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    a.c[3] *= b.c[3];
    return a;
}
V4d v4d_div(V4d a, V4d b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    a.c[3] /= b.c[3];
    return a;
}
V4d v4d_sqrt(V4d a)
{
    a.c[0] = sqrt(a.c[0]);
    a.c[1] = sqrt(a.c[1]);
    a.c[2] = sqrt(a.c[2]);
    a.c[3] = sqrt(a.c[3]);
    return a;
}
V4d v4d_pow(V4d base, V4d exp)
{
    base.c[0] = pow(base.c[0], exp.c[0]);
    base.c[1] = pow(base.c[1], exp.c[1]);
    base.c[2] = pow(base.c[2], exp.c[2]);
    base.c[3] = pow(base.c[3], exp.c[3]);
    return base;
}
V4d v4d_sin(V4d a)
{
    a.c[0] = sin(a.c[0]);
    a.c[1] = sin(a.c[1]);
    a.c[2] = sin(a.c[2]);
    a.c[3] = sin(a.c[3]);
    return a;
}
V4d v4d_cos(V4d a)
{
    a.c[0] = cos(a.c[0]);
    a.c[1] = cos(a.c[1]);
    a.c[2] = cos(a.c[2]);
    a.c[3] = cos(a.c[3]);
    return a;
}
V4d v4d_min(V4d a, V4d b)
{
    a.c[0] = fmin(a.c[0], b.c[0]);
    a.c[1] = fmin(a.c[1], b.c[1]);
    a.c[2] = fmin(a.c[2], b.c[2]);
    a.c[3] = fmin(a.c[3], b.c[3]);
    return a;
}
V4d v4d_max(V4d a, V4d b)
{
    a.c[0] = fmax(a.c[0], b.c[0]);
    a.c[1] = fmax(a.c[1], b.c[1]);
    a.c[2] = fmax(a.c[2], b.c[2]);
    a.c[3] = fmax(a.c[3], b.c[3]);
    return a;
}
V4d v4d_lerp(V4d a, V4d b, V4d t)
{
    a.c[0] = lerp(a.c[0], b.c[0], t.c[0]);
    a.c[1] = lerp(a.c[1], b.c[1], t.c[1]);
    a.c[2] = lerp(a.c[2], b.c[2], t.c[2]);
    a.c[3] = lerp(a.c[3], b.c[3], t.c[3]);
    return a;
}
V4d v4d_floor(V4d a)
{
    a.c[0] = floor(a.c[0]);
    a.c[1] = floor(a.c[1]);
    a.c[2] = floor(a.c[2]);
    a.c[3] = floor(a.c[3]);
    return a;
}
V4d v4d_ceil(V4d a)
{
    a.c[0] = ceil(a.c[0]);
    a.c[1] = ceil(a.c[1]);
    a.c[2] = ceil(a.c[2]);
    a.c[3] = ceil(a.c[3]);
    return a;
}
double v4d_sqrlen(V4d a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2] + a.c[3]*a.c[3];
}
V4i v4i(int x, int y, int z, int w)
{
    V4i result;
    result.c[0] = x;
    result.c[1] = y;
    result.c[2] = z;
    result.c[3] = w;
    return result;
}
V4i v4is(int x)
{
    return v4i(x, x, x, x);
}
V4i v4i_sum(V4i a, V4i b)
{
    a.c[0] += b.c[0];
    a.c[1] += b.c[1];
    a.c[2] += b.c[2];
    a.c[3] += b.c[3];
    return a;
}
V4i v4i_sub(V4i a, V4i b)
{
    a.c[0] -= b.c[0];
    a.c[1] -= b.c[1];
    a.c[2] -= b.c[2];
    a.c[3] -= b.c[3];
    return a;
}
V4i v4i_mul(V4i a, V4i b)
{
    a.c[0] *= b.c[0];
    a.c[1] *= b.c[1];
    a.c[2] *= b.c[2];
    a.c[3] *= b.c[3];
    return a;
}
V4i v4i_div(V4i a, V4i b)
{
    a.c[0] /= b.c[0];
    a.c[1] /= b.c[1];
    a.c[2] /= b.c[2];
    a.c[3] /= b.c[3];
    return a;
}
int v4i_sqrlen(V4i a)
{
    return a.c[0]*a.c[0] + a.c[1]*a.c[1] + a.c[2]*a.c[2] + a.c[3]*a.c[3];
}

#endif // LA_IMPLEMENTATION
