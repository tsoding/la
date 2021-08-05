#ifndef LA_H_
#define LA_H_

#include <math.h>
float lerpf(float x0, float x1, float x2);
double lerp(double x0, double x1, double x2);
typedef struct { float c[2]; } V2f;
V2f v2f(float x0, float x1);
V2f v2fs(float x0);
V2f v2f_sum(V2f v0, V2f v1);
V2f v2f_sub(V2f v0, V2f v1);
V2f v2f_mul(V2f v0, V2f v1);
V2f v2f_div(V2f v0, V2f v1);
V2f v2f_sqrt(V2f v0);
V2f v2f_pow(V2f v0, V2f v1);
V2f v2f_sin(V2f v0);
V2f v2f_cos(V2f v0);
V2f v2f_min(V2f v0, V2f v1);
V2f v2f_max(V2f v0, V2f v1);
V2f v2f_lerp(V2f v0, V2f v1, V2f v2);
float v2f_sqrlen(V2f v0);
typedef struct { double c[2]; } V2d;
V2d v2d(double x0, double x1);
V2d v2ds(double x0);
V2d v2d_sum(V2d v0, V2d v1);
V2d v2d_sub(V2d v0, V2d v1);
V2d v2d_mul(V2d v0, V2d v1);
V2d v2d_div(V2d v0, V2d v1);
V2d v2d_sqrt(V2d v0);
V2d v2d_pow(V2d v0, V2d v1);
V2d v2d_sin(V2d v0);
V2d v2d_cos(V2d v0);
V2d v2d_min(V2d v0, V2d v1);
V2d v2d_max(V2d v0, V2d v1);
V2d v2d_lerp(V2d v0, V2d v1, V2d v2);
double v2d_sqrlen(V2d v0);
typedef struct { int c[2]; } V2i;
V2i v2i(int x0, int x1);
V2i v2is(int x0);
V2i v2i_sum(V2i v0, V2i v1);
V2i v2i_sub(V2i v0, V2i v1);
V2i v2i_mul(V2i v0, V2i v1);
V2i v2i_div(V2i v0, V2i v1);
int v2i_sqrlen(V2i v0);
typedef struct { float c[3]; } V3f;
V3f v3f(float x0, float x1, float x2);
V3f v3fs(float x0);
V3f v3f_sum(V3f v0, V3f v1);
V3f v3f_sub(V3f v0, V3f v1);
V3f v3f_mul(V3f v0, V3f v1);
V3f v3f_div(V3f v0, V3f v1);
V3f v3f_sqrt(V3f v0);
V3f v3f_pow(V3f v0, V3f v1);
V3f v3f_sin(V3f v0);
V3f v3f_cos(V3f v0);
V3f v3f_min(V3f v0, V3f v1);
V3f v3f_max(V3f v0, V3f v1);
V3f v3f_lerp(V3f v0, V3f v1, V3f v2);
float v3f_sqrlen(V3f v0);
typedef struct { double c[3]; } V3d;
V3d v3d(double x0, double x1, double x2);
V3d v3ds(double x0);
V3d v3d_sum(V3d v0, V3d v1);
V3d v3d_sub(V3d v0, V3d v1);
V3d v3d_mul(V3d v0, V3d v1);
V3d v3d_div(V3d v0, V3d v1);
V3d v3d_sqrt(V3d v0);
V3d v3d_pow(V3d v0, V3d v1);
V3d v3d_sin(V3d v0);
V3d v3d_cos(V3d v0);
V3d v3d_min(V3d v0, V3d v1);
V3d v3d_max(V3d v0, V3d v1);
V3d v3d_lerp(V3d v0, V3d v1, V3d v2);
double v3d_sqrlen(V3d v0);
typedef struct { int c[3]; } V3i;
V3i v3i(int x0, int x1, int x2);
V3i v3is(int x0);
V3i v3i_sum(V3i v0, V3i v1);
V3i v3i_sub(V3i v0, V3i v1);
V3i v3i_mul(V3i v0, V3i v1);
V3i v3i_div(V3i v0, V3i v1);
int v3i_sqrlen(V3i v0);
typedef struct { float c[4]; } V4f;
V4f v4f(float x0, float x1, float x2, float x3);
V4f v4fs(float x0);
V4f v4f_sum(V4f v0, V4f v1);
V4f v4f_sub(V4f v0, V4f v1);
V4f v4f_mul(V4f v0, V4f v1);
V4f v4f_div(V4f v0, V4f v1);
V4f v4f_sqrt(V4f v0);
V4f v4f_pow(V4f v0, V4f v1);
V4f v4f_sin(V4f v0);
V4f v4f_cos(V4f v0);
V4f v4f_min(V4f v0, V4f v1);
V4f v4f_max(V4f v0, V4f v1);
V4f v4f_lerp(V4f v0, V4f v1, V4f v2);
float v4f_sqrlen(V4f v0);
typedef struct { double c[4]; } V4d;
V4d v4d(double x0, double x1, double x2, double x3);
V4d v4ds(double x0);
V4d v4d_sum(V4d v0, V4d v1);
V4d v4d_sub(V4d v0, V4d v1);
V4d v4d_mul(V4d v0, V4d v1);
V4d v4d_div(V4d v0, V4d v1);
V4d v4d_sqrt(V4d v0);
V4d v4d_pow(V4d v0, V4d v1);
V4d v4d_sin(V4d v0);
V4d v4d_cos(V4d v0);
V4d v4d_min(V4d v0, V4d v1);
V4d v4d_max(V4d v0, V4d v1);
V4d v4d_lerp(V4d v0, V4d v1, V4d v2);
double v4d_sqrlen(V4d v0);
typedef struct { int c[4]; } V4i;
V4i v4i(int x0, int x1, int x2, int x3);
V4i v4is(int x0);
V4i v4i_sum(V4i v0, V4i v1);
V4i v4i_sub(V4i v0, V4i v1);
V4i v4i_mul(V4i v0, V4i v1);
V4i v4i_div(V4i v0, V4i v1);
int v4i_sqrlen(V4i v0);
#endif // LA_H_

#ifdef LA_IMPLEMENTATION

float lerpf(float x0, float x1, float x2)
{
    return x0 + (x1 - x0) * x2;
}
double lerp(double x0, double x1, double x2)
{
    return x0 + (x1 - x0) * x2;
}
V2f v2f(float x0, float x1)
{
    V2f result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}
V2f v2fs(float x0)
{
    return v2f(x0, x0);
}
V2f v2f_sum(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V2f v2f_sub(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V2f v2f_mul(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V2f v2f_div(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V2f v2f_sqrt(V2f v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = sqrtf(v0.c[i]);
    return v0;
}
V2f v2f_pow(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = powf(v0.c[i], v1.c[i]);
    return v0;
}
V2f v2f_sin(V2f v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = sinf(v0.c[i]);
    return v0;
}
V2f v2f_cos(V2f v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = cosf(v0.c[i]);
    return v0;
}
V2f v2f_min(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = fminf(v0.c[i], v1.c[i]);
    return v0;
}
V2f v2f_max(V2f v0, V2f v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = fmaxf(v0.c[i], v1.c[i]);
    return v0;
}
V2f v2f_lerp(V2f v0, V2f v1, V2f v2)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = lerpf(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
float v2f_sqrlen(V2f v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1];
}
V2d v2d(double x0, double x1)
{
    V2d result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}
V2d v2ds(double x0)
{
    return v2d(x0, x0);
}
V2d v2d_sum(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V2d v2d_sub(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V2d v2d_mul(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V2d v2d_div(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V2d v2d_sqrt(V2d v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = sqrt(v0.c[i]);
    return v0;
}
V2d v2d_pow(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = pow(v0.c[i], v1.c[i]);
    return v0;
}
V2d v2d_sin(V2d v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = sin(v0.c[i]);
    return v0;
}
V2d v2d_cos(V2d v0)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = cos(v0.c[i]);
    return v0;
}
V2d v2d_min(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = fmin(v0.c[i], v1.c[i]);
    return v0;
}
V2d v2d_max(V2d v0, V2d v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = fmax(v0.c[i], v1.c[i]);
    return v0;
}
V2d v2d_lerp(V2d v0, V2d v1, V2d v2)
{
    for (int i = 0; i < 2; ++i) v0.c[i] = lerp(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
double v2d_sqrlen(V2d v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1];
}
V2i v2i(int x0, int x1)
{
    V2i result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}
V2i v2is(int x0)
{
    return v2i(x0, x0);
}
V2i v2i_sum(V2i v0, V2i v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V2i v2i_sub(V2i v0, V2i v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V2i v2i_mul(V2i v0, V2i v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V2i v2i_div(V2i v0, V2i v1)
{
    for (int i = 0; i < 2; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
int v2i_sqrlen(V2i v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1];
}
V3f v3f(float x0, float x1, float x2)
{
    V3f result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}
V3f v3fs(float x0)
{
    return v3f(x0, x0, x0);
}
V3f v3f_sum(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V3f v3f_sub(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V3f v3f_mul(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V3f v3f_div(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V3f v3f_sqrt(V3f v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = sqrtf(v0.c[i]);
    return v0;
}
V3f v3f_pow(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = powf(v0.c[i], v1.c[i]);
    return v0;
}
V3f v3f_sin(V3f v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = sinf(v0.c[i]);
    return v0;
}
V3f v3f_cos(V3f v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = cosf(v0.c[i]);
    return v0;
}
V3f v3f_min(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = fminf(v0.c[i], v1.c[i]);
    return v0;
}
V3f v3f_max(V3f v0, V3f v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = fmaxf(v0.c[i], v1.c[i]);
    return v0;
}
V3f v3f_lerp(V3f v0, V3f v1, V3f v2)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = lerpf(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
float v3f_sqrlen(V3f v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2];
}
V3d v3d(double x0, double x1, double x2)
{
    V3d result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}
V3d v3ds(double x0)
{
    return v3d(x0, x0, x0);
}
V3d v3d_sum(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V3d v3d_sub(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V3d v3d_mul(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V3d v3d_div(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V3d v3d_sqrt(V3d v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = sqrt(v0.c[i]);
    return v0;
}
V3d v3d_pow(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = pow(v0.c[i], v1.c[i]);
    return v0;
}
V3d v3d_sin(V3d v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = sin(v0.c[i]);
    return v0;
}
V3d v3d_cos(V3d v0)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = cos(v0.c[i]);
    return v0;
}
V3d v3d_min(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = fmin(v0.c[i], v1.c[i]);
    return v0;
}
V3d v3d_max(V3d v0, V3d v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = fmax(v0.c[i], v1.c[i]);
    return v0;
}
V3d v3d_lerp(V3d v0, V3d v1, V3d v2)
{
    for (int i = 0; i < 3; ++i) v0.c[i] = lerp(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
double v3d_sqrlen(V3d v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2];
}
V3i v3i(int x0, int x1, int x2)
{
    V3i result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}
V3i v3is(int x0)
{
    return v3i(x0, x0, x0);
}
V3i v3i_sum(V3i v0, V3i v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V3i v3i_sub(V3i v0, V3i v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V3i v3i_mul(V3i v0, V3i v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V3i v3i_div(V3i v0, V3i v1)
{
    for (int i = 0; i < 3; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
int v3i_sqrlen(V3i v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2];
}
V4f v4f(float x0, float x1, float x2, float x3)
{
    V4f result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    result.c[3] = x3;
    return result;
}
V4f v4fs(float x0)
{
    return v4f(x0, x0, x0, x0);
}
V4f v4f_sum(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V4f v4f_sub(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V4f v4f_mul(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V4f v4f_div(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V4f v4f_sqrt(V4f v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = sqrtf(v0.c[i]);
    return v0;
}
V4f v4f_pow(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = powf(v0.c[i], v1.c[i]);
    return v0;
}
V4f v4f_sin(V4f v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = sinf(v0.c[i]);
    return v0;
}
V4f v4f_cos(V4f v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = cosf(v0.c[i]);
    return v0;
}
V4f v4f_min(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = fminf(v0.c[i], v1.c[i]);
    return v0;
}
V4f v4f_max(V4f v0, V4f v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = fmaxf(v0.c[i], v1.c[i]);
    return v0;
}
V4f v4f_lerp(V4f v0, V4f v1, V4f v2)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = lerpf(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
float v4f_sqrlen(V4f v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2] + v0.c[3]*v0.c[3];
}
V4d v4d(double x0, double x1, double x2, double x3)
{
    V4d result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    result.c[3] = x3;
    return result;
}
V4d v4ds(double x0)
{
    return v4d(x0, x0, x0, x0);
}
V4d v4d_sum(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V4d v4d_sub(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V4d v4d_mul(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V4d v4d_div(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
V4d v4d_sqrt(V4d v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = sqrt(v0.c[i]);
    return v0;
}
V4d v4d_pow(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = pow(v0.c[i], v1.c[i]);
    return v0;
}
V4d v4d_sin(V4d v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = sin(v0.c[i]);
    return v0;
}
V4d v4d_cos(V4d v0)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = cos(v0.c[i]);
    return v0;
}
V4d v4d_min(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = fmin(v0.c[i], v1.c[i]);
    return v0;
}
V4d v4d_max(V4d v0, V4d v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = fmax(v0.c[i], v1.c[i]);
    return v0;
}
V4d v4d_lerp(V4d v0, V4d v1, V4d v2)
{
    for (int i = 0; i < 4; ++i) v0.c[i] = lerp(v0.c[i], v1.c[i], v2.c[i]);
    return v0;
}
double v4d_sqrlen(V4d v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2] + v0.c[3]*v0.c[3];
}
V4i v4i(int x0, int x1, int x2, int x3)
{
    V4i result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    result.c[3] = x3;
    return result;
}
V4i v4is(int x0)
{
    return v4i(x0, x0, x0, x0);
}
V4i v4i_sum(V4i v0, V4i v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] += v1.c[i];
    return v0;
}
V4i v4i_sub(V4i v0, V4i v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] -= v1.c[i];
    return v0;
}
V4i v4i_mul(V4i v0, V4i v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] *= v1.c[i];
    return v0;
}
V4i v4i_div(V4i v0, V4i v1)
{
    for (int i = 0; i < 4; ++i) v0.c[i] /= v1.c[i];
    return v0;
}
int v4i_sqrlen(V4i v0)
{
    return v0.c[0]*v0.c[0] + v0.c[1]*v0.c[1] + v0.c[2]*v0.c[2] + v0.c[3]*v0.c[3];
}
#endif // LA_IMPLEMENTATION
