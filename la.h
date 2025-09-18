#ifndef LA_H_
#define LA_H_

#include <stddef.h>
#include <math.h>

#ifndef LADEF
#define LADEF static inline
#endif // LADEF

LADEF float lerpf(float a, float b, float t);
LADEF double lerp(double a, double b, double t);
LADEF int mini(int a, int b);
LADEF int maxi(int a, int b);
LADEF unsigned int minu(unsigned int a, unsigned int b);
LADEF unsigned int maxu(unsigned int a, unsigned int b);
LADEF float clampf(float x, float a, float b);
LADEF double clampd(double x, double a, double b);
LADEF int clampi(int x, int a, int b);
LADEF unsigned int clampu(unsigned int x, unsigned int a, unsigned int b);

typedef union {
    struct { float x, y; };
    float c[2];
} V2f;
typedef union {
    struct { double x, y; };
    double c[2];
} V2d;
typedef union {
    struct { int x, y; };
    int c[2];
} V2i;
typedef union {
    struct { unsigned int x, y; };
    unsigned int c[2];
} V2u;
typedef union {
    struct { float x, y, z; };
    float c[3];
} V3f;
typedef union {
    struct { double x, y, z; };
    double c[3];
} V3d;
typedef union {
    struct { int x, y, z; };
    int c[3];
} V3i;
typedef union {
    struct { unsigned int x, y, z; };
    unsigned int c[3];
} V3u;
typedef union {
    struct { float x, y, z, w; };
    float c[4];
} V4f;
typedef union {
    struct { double x, y, z, w; };
    double c[4];
} V4d;
typedef union {
    struct { int x, y, z, w; };
    int c[4];
} V4i;
typedef union {
    struct { unsigned int x, y, z, w; };
    unsigned int c[4];
} V4u;

typedef union {
    float rc[2][2];
    float c[4];
} M2x2f;
typedef union {
    double rc[2][2];
    double c[4];
} M2x2d;
typedef union {
    int rc[2][2];
    int c[4];
} M2x2i;
typedef union {
    unsigned int rc[2][2];
    unsigned int c[4];
} M2x2u;
typedef union {
    float rc[2][3];
    float c[6];
} M2x3f;
typedef union {
    double rc[2][3];
    double c[6];
} M2x3d;
typedef union {
    int rc[2][3];
    int c[6];
} M2x3i;
typedef union {
    unsigned int rc[2][3];
    unsigned int c[6];
} M2x3u;
typedef union {
    float rc[2][4];
    float c[8];
} M2x4f;
typedef union {
    double rc[2][4];
    double c[8];
} M2x4d;
typedef union {
    int rc[2][4];
    int c[8];
} M2x4i;
typedef union {
    unsigned int rc[2][4];
    unsigned int c[8];
} M2x4u;
typedef union {
    float rc[3][2];
    float c[6];
} M3x2f;
typedef union {
    double rc[3][2];
    double c[6];
} M3x2d;
typedef union {
    int rc[3][2];
    int c[6];
} M3x2i;
typedef union {
    unsigned int rc[3][2];
    unsigned int c[6];
} M3x2u;
typedef union {
    float rc[3][3];
    float c[9];
} M3x3f;
typedef union {
    double rc[3][3];
    double c[9];
} M3x3d;
typedef union {
    int rc[3][3];
    int c[9];
} M3x3i;
typedef union {
    unsigned int rc[3][3];
    unsigned int c[9];
} M3x3u;
typedef union {
    float rc[3][4];
    float c[12];
} M3x4f;
typedef union {
    double rc[3][4];
    double c[12];
} M3x4d;
typedef union {
    int rc[3][4];
    int c[12];
} M3x4i;
typedef union {
    unsigned int rc[3][4];
    unsigned int c[12];
} M3x4u;
typedef union {
    float rc[4][2];
    float c[8];
} M4x2f;
typedef union {
    double rc[4][2];
    double c[8];
} M4x2d;
typedef union {
    int rc[4][2];
    int c[8];
} M4x2i;
typedef union {
    unsigned int rc[4][2];
    unsigned int c[8];
} M4x2u;
typedef union {
    float rc[4][3];
    float c[12];
} M4x3f;
typedef union {
    double rc[4][3];
    double c[12];
} M4x3d;
typedef union {
    int rc[4][3];
    int c[12];
} M4x3i;
typedef union {
    unsigned int rc[4][3];
    unsigned int c[12];
} M4x3u;
typedef union {
    float rc[4][4];
    float c[16];
} M4x4f;
typedef union {
    double rc[4][4];
    double c[16];
} M4x4d;
typedef union {
    int rc[4][4];
    int c[16];
} M4x4i;
typedef union {
    unsigned int rc[4][4];
    unsigned int c[16];
} M4x4u;

typedef struct {
    float a;
    float b01;
} R2f;
typedef struct {
    float a;
    float b01;
    float b02;
    float b12;
} R3f;
typedef struct {
    double a;
    double b01;
} R2d;
typedef struct {
    double a;
    double b01;
    double b02;
    double b12;
} R3d;

#define V2f_Fmt "v2f(%f, %f)"
#define V2f_Arg(v) (v).x, (v).y
LADEF V2f v2f(float x, float y);
LADEF V2f v2ff(float x);
LADEF V2f v2f2d(V2d a);
LADEF V2f v2f2i(V2i a);
LADEF V2f v2f2u(V2u a);
LADEF V2f v2f3f(V3f a);
LADEF V2f v2f3d(V3d a);
LADEF V2f v2f3i(V3i a);
LADEF V2f v2f3u(V3u a);
LADEF V2f v2f4f(V4f a);
LADEF V2f v2f4d(V4d a);
LADEF V2f v2f4i(V4i a);
LADEF V2f v2f4u(V4u a);
LADEF V2f v2f_sum(V2f a, V2f b);
LADEF V2f v2f_sub(V2f a, V2f b);
LADEF V2f v2f_mul(V2f a, V2f b);
LADEF V2f v2f_div(V2f a, V2f b);
LADEF V2f v2f_mod(V2f a, V2f b);
LADEF V2f v2f_sqrt(V2f a);
LADEF V2f v2f_pow(V2f base, V2f exp);
LADEF V2f v2f_sin(V2f a);
LADEF V2f v2f_cos(V2f a);
LADEF V2f v2f_min(V2f a, V2f b);
LADEF V2f v2f_max(V2f a, V2f b);
LADEF V2f v2f_lerp(V2f a, V2f b, V2f t);
LADEF V2f v2f_floor(V2f a);
LADEF V2f v2f_ceil(V2f a);
LADEF V2f v2f_clamp(V2f x, V2f a, V2f b);
LADEF float v2f_sqrlen(V2f a);
LADEF float v2f_len(V2f a);
LADEF V2f v2f_normalize(V2f a);
LADEF float v2f_dot(V2f a, V2f b);

#define V2d_Fmt "v2d(%lf, %lf)"
#define V2d_Arg(v) (v).x, (v).y
LADEF V2d v2d(double x, double y);
LADEF V2d v2dd(double x);
LADEF V2d v2d2f(V2f a);
LADEF V2d v2d2i(V2i a);
LADEF V2d v2d2u(V2u a);
LADEF V2d v2d3f(V3f a);
LADEF V2d v2d3d(V3d a);
LADEF V2d v2d3i(V3i a);
LADEF V2d v2d3u(V3u a);
LADEF V2d v2d4f(V4f a);
LADEF V2d v2d4d(V4d a);
LADEF V2d v2d4i(V4i a);
LADEF V2d v2d4u(V4u a);
LADEF V2d v2d_sum(V2d a, V2d b);
LADEF V2d v2d_sub(V2d a, V2d b);
LADEF V2d v2d_mul(V2d a, V2d b);
LADEF V2d v2d_div(V2d a, V2d b);
LADEF V2d v2d_mod(V2d a, V2d b);
LADEF V2d v2d_sqrt(V2d a);
LADEF V2d v2d_pow(V2d base, V2d exp);
LADEF V2d v2d_sin(V2d a);
LADEF V2d v2d_cos(V2d a);
LADEF V2d v2d_min(V2d a, V2d b);
LADEF V2d v2d_max(V2d a, V2d b);
LADEF V2d v2d_lerp(V2d a, V2d b, V2d t);
LADEF V2d v2d_floor(V2d a);
LADEF V2d v2d_ceil(V2d a);
LADEF V2d v2d_clamp(V2d x, V2d a, V2d b);
LADEF double v2d_sqrlen(V2d a);
LADEF double v2d_len(V2d a);
LADEF V2d v2d_normalize(V2d a);
LADEF double v2d_dot(V2d a, V2d b);

#define V2i_Fmt "v2i(%d, %d)"
#define V2i_Arg(v) (v).x, (v).y
LADEF V2i v2i(int x, int y);
LADEF V2i v2ii(int x);
LADEF V2i v2i2f(V2f a);
LADEF V2i v2i2d(V2d a);
LADEF V2i v2i2u(V2u a);
LADEF V2i v2i3f(V3f a);
LADEF V2i v2i3d(V3d a);
LADEF V2i v2i3i(V3i a);
LADEF V2i v2i3u(V3u a);
LADEF V2i v2i4f(V4f a);
LADEF V2i v2i4d(V4d a);
LADEF V2i v2i4i(V4i a);
LADEF V2i v2i4u(V4u a);
LADEF V2i v2i_sum(V2i a, V2i b);
LADEF V2i v2i_sub(V2i a, V2i b);
LADEF V2i v2i_mul(V2i a, V2i b);
LADEF V2i v2i_div(V2i a, V2i b);
LADEF V2i v2i_mod(V2i a, V2i b);
LADEF V2i v2i_min(V2i a, V2i b);
LADEF V2i v2i_max(V2i a, V2i b);
LADEF V2i v2i_clamp(V2i x, V2i a, V2i b);
LADEF int v2i_sqrlen(V2i a);
LADEF int v2i_dot(V2i a, V2i b);

#define V2u_Fmt "v2u(%u, %u)"
#define V2u_Arg(v) (v).x, (v).y
LADEF V2u v2u(unsigned int x, unsigned int y);
LADEF V2u v2uu(unsigned int x);
LADEF V2u v2u2f(V2f a);
LADEF V2u v2u2d(V2d a);
LADEF V2u v2u2i(V2i a);
LADEF V2u v2u3f(V3f a);
LADEF V2u v2u3d(V3d a);
LADEF V2u v2u3i(V3i a);
LADEF V2u v2u3u(V3u a);
LADEF V2u v2u4f(V4f a);
LADEF V2u v2u4d(V4d a);
LADEF V2u v2u4i(V4i a);
LADEF V2u v2u4u(V4u a);
LADEF V2u v2u_sum(V2u a, V2u b);
LADEF V2u v2u_sub(V2u a, V2u b);
LADEF V2u v2u_mul(V2u a, V2u b);
LADEF V2u v2u_div(V2u a, V2u b);
LADEF V2u v2u_mod(V2u a, V2u b);
LADEF V2u v2u_min(V2u a, V2u b);
LADEF V2u v2u_max(V2u a, V2u b);
LADEF V2u v2u_clamp(V2u x, V2u a, V2u b);
LADEF unsigned int v2u_sqrlen(V2u a);
LADEF unsigned int v2u_dot(V2u a, V2u b);

#define V3f_Fmt "v3f(%f, %f, %f)"
#define V3f_Arg(v) (v).x, (v).y, (v).z
LADEF V3f v3f(float x, float y, float z);
LADEF V3f v3ff(float x);
LADEF V3f v3f2f(V2f a);
LADEF V3f v3f2d(V2d a);
LADEF V3f v3f2i(V2i a);
LADEF V3f v3f2u(V2u a);
LADEF V3f v3f3d(V3d a);
LADEF V3f v3f3i(V3i a);
LADEF V3f v3f3u(V3u a);
LADEF V3f v3f4f(V4f a);
LADEF V3f v3f4d(V4d a);
LADEF V3f v3f4i(V4i a);
LADEF V3f v3f4u(V4u a);
LADEF V3f v3f_sum(V3f a, V3f b);
LADEF V3f v3f_sub(V3f a, V3f b);
LADEF V3f v3f_mul(V3f a, V3f b);
LADEF V3f v3f_div(V3f a, V3f b);
LADEF V3f v3f_mod(V3f a, V3f b);
LADEF V3f v3f_sqrt(V3f a);
LADEF V3f v3f_pow(V3f base, V3f exp);
LADEF V3f v3f_sin(V3f a);
LADEF V3f v3f_cos(V3f a);
LADEF V3f v3f_min(V3f a, V3f b);
LADEF V3f v3f_max(V3f a, V3f b);
LADEF V3f v3f_lerp(V3f a, V3f b, V3f t);
LADEF V3f v3f_floor(V3f a);
LADEF V3f v3f_ceil(V3f a);
LADEF V3f v3f_clamp(V3f x, V3f a, V3f b);
LADEF float v3f_sqrlen(V3f a);
LADEF float v3f_len(V3f a);
LADEF V3f v3f_normalize(V3f a);
LADEF float v3f_dot(V3f a, V3f b);
LADEF V3f v3f_cross(V3f a, V3f b);
LADEF V3f v3f_normal_from_points(V3f a, V3f b, V3f c);

#define V3d_Fmt "v3d(%lf, %lf, %lf)"
#define V3d_Arg(v) (v).x, (v).y, (v).z
LADEF V3d v3d(double x, double y, double z);
LADEF V3d v3dd(double x);
LADEF V3d v3d2f(V2f a);
LADEF V3d v3d2d(V2d a);
LADEF V3d v3d2i(V2i a);
LADEF V3d v3d2u(V2u a);
LADEF V3d v3d3f(V3f a);
LADEF V3d v3d3i(V3i a);
LADEF V3d v3d3u(V3u a);
LADEF V3d v3d4f(V4f a);
LADEF V3d v3d4d(V4d a);
LADEF V3d v3d4i(V4i a);
LADEF V3d v3d4u(V4u a);
LADEF V3d v3d_sum(V3d a, V3d b);
LADEF V3d v3d_sub(V3d a, V3d b);
LADEF V3d v3d_mul(V3d a, V3d b);
LADEF V3d v3d_div(V3d a, V3d b);
LADEF V3d v3d_mod(V3d a, V3d b);
LADEF V3d v3d_sqrt(V3d a);
LADEF V3d v3d_pow(V3d base, V3d exp);
LADEF V3d v3d_sin(V3d a);
LADEF V3d v3d_cos(V3d a);
LADEF V3d v3d_min(V3d a, V3d b);
LADEF V3d v3d_max(V3d a, V3d b);
LADEF V3d v3d_lerp(V3d a, V3d b, V3d t);
LADEF V3d v3d_floor(V3d a);
LADEF V3d v3d_ceil(V3d a);
LADEF V3d v3d_clamp(V3d x, V3d a, V3d b);
LADEF double v3d_sqrlen(V3d a);
LADEF double v3d_len(V3d a);
LADEF V3d v3d_normalize(V3d a);
LADEF double v3d_dot(V3d a, V3d b);
LADEF V3d v3d_cross(V3d a, V3d b);
LADEF V3d v3d_normal_from_points(V3d a, V3d b, V3d c);

#define V3i_Fmt "v3i(%d, %d, %d)"
#define V3i_Arg(v) (v).x, (v).y, (v).z
LADEF V3i v3i(int x, int y, int z);
LADEF V3i v3ii(int x);
LADEF V3i v3i2f(V2f a);
LADEF V3i v3i2d(V2d a);
LADEF V3i v3i2i(V2i a);
LADEF V3i v3i2u(V2u a);
LADEF V3i v3i3f(V3f a);
LADEF V3i v3i3d(V3d a);
LADEF V3i v3i3u(V3u a);
LADEF V3i v3i4f(V4f a);
LADEF V3i v3i4d(V4d a);
LADEF V3i v3i4i(V4i a);
LADEF V3i v3i4u(V4u a);
LADEF V3i v3i_sum(V3i a, V3i b);
LADEF V3i v3i_sub(V3i a, V3i b);
LADEF V3i v3i_mul(V3i a, V3i b);
LADEF V3i v3i_div(V3i a, V3i b);
LADEF V3i v3i_mod(V3i a, V3i b);
LADEF V3i v3i_min(V3i a, V3i b);
LADEF V3i v3i_max(V3i a, V3i b);
LADEF V3i v3i_clamp(V3i x, V3i a, V3i b);
LADEF int v3i_sqrlen(V3i a);
LADEF int v3i_dot(V3i a, V3i b);
LADEF V3i v3i_cross(V3i a, V3i b);

#define V3u_Fmt "v3u(%u, %u, %u)"
#define V3u_Arg(v) (v).x, (v).y, (v).z
LADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z);
LADEF V3u v3uu(unsigned int x);
LADEF V3u v3u2f(V2f a);
LADEF V3u v3u2d(V2d a);
LADEF V3u v3u2i(V2i a);
LADEF V3u v3u2u(V2u a);
LADEF V3u v3u3f(V3f a);
LADEF V3u v3u3d(V3d a);
LADEF V3u v3u3i(V3i a);
LADEF V3u v3u4f(V4f a);
LADEF V3u v3u4d(V4d a);
LADEF V3u v3u4i(V4i a);
LADEF V3u v3u4u(V4u a);
LADEF V3u v3u_sum(V3u a, V3u b);
LADEF V3u v3u_sub(V3u a, V3u b);
LADEF V3u v3u_mul(V3u a, V3u b);
LADEF V3u v3u_div(V3u a, V3u b);
LADEF V3u v3u_mod(V3u a, V3u b);
LADEF V3u v3u_min(V3u a, V3u b);
LADEF V3u v3u_max(V3u a, V3u b);
LADEF V3u v3u_clamp(V3u x, V3u a, V3u b);
LADEF unsigned int v3u_sqrlen(V3u a);
LADEF unsigned int v3u_dot(V3u a, V3u b);
LADEF V3u v3u_cross(V3u a, V3u b);

#define V4f_Fmt "v4f(%f, %f, %f, %f)"
#define V4f_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4f v4f(float x, float y, float z, float w);
LADEF V4f v4ff(float x);
LADEF V4f v4f2f(V2f a);
LADEF V4f v4f2d(V2d a);
LADEF V4f v4f2i(V2i a);
LADEF V4f v4f2u(V2u a);
LADEF V4f v4f3f(V3f a);
LADEF V4f v4f3d(V3d a);
LADEF V4f v4f3i(V3i a);
LADEF V4f v4f3u(V3u a);
LADEF V4f v4f4d(V4d a);
LADEF V4f v4f4i(V4i a);
LADEF V4f v4f4u(V4u a);
LADEF V4f v4f_sum(V4f a, V4f b);
LADEF V4f v4f_sub(V4f a, V4f b);
LADEF V4f v4f_mul(V4f a, V4f b);
LADEF V4f v4f_div(V4f a, V4f b);
LADEF V4f v4f_mod(V4f a, V4f b);
LADEF V4f v4f_sqrt(V4f a);
LADEF V4f v4f_pow(V4f base, V4f exp);
LADEF V4f v4f_sin(V4f a);
LADEF V4f v4f_cos(V4f a);
LADEF V4f v4f_min(V4f a, V4f b);
LADEF V4f v4f_max(V4f a, V4f b);
LADEF V4f v4f_lerp(V4f a, V4f b, V4f t);
LADEF V4f v4f_floor(V4f a);
LADEF V4f v4f_ceil(V4f a);
LADEF V4f v4f_clamp(V4f x, V4f a, V4f b);
LADEF float v4f_sqrlen(V4f a);
LADEF float v4f_len(V4f a);
LADEF V4f v4f_normalize(V4f a);
LADEF float v4f_dot(V4f a, V4f b);

#define V4d_Fmt "v4d(%lf, %lf, %lf, %lf)"
#define V4d_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4d v4d(double x, double y, double z, double w);
LADEF V4d v4dd(double x);
LADEF V4d v4d2f(V2f a);
LADEF V4d v4d2d(V2d a);
LADEF V4d v4d2i(V2i a);
LADEF V4d v4d2u(V2u a);
LADEF V4d v4d3f(V3f a);
LADEF V4d v4d3d(V3d a);
LADEF V4d v4d3i(V3i a);
LADEF V4d v4d3u(V3u a);
LADEF V4d v4d4f(V4f a);
LADEF V4d v4d4i(V4i a);
LADEF V4d v4d4u(V4u a);
LADEF V4d v4d_sum(V4d a, V4d b);
LADEF V4d v4d_sub(V4d a, V4d b);
LADEF V4d v4d_mul(V4d a, V4d b);
LADEF V4d v4d_div(V4d a, V4d b);
LADEF V4d v4d_mod(V4d a, V4d b);
LADEF V4d v4d_sqrt(V4d a);
LADEF V4d v4d_pow(V4d base, V4d exp);
LADEF V4d v4d_sin(V4d a);
LADEF V4d v4d_cos(V4d a);
LADEF V4d v4d_min(V4d a, V4d b);
LADEF V4d v4d_max(V4d a, V4d b);
LADEF V4d v4d_lerp(V4d a, V4d b, V4d t);
LADEF V4d v4d_floor(V4d a);
LADEF V4d v4d_ceil(V4d a);
LADEF V4d v4d_clamp(V4d x, V4d a, V4d b);
LADEF double v4d_sqrlen(V4d a);
LADEF double v4d_len(V4d a);
LADEF V4d v4d_normalize(V4d a);
LADEF double v4d_dot(V4d a, V4d b);

#define V4i_Fmt "v4i(%d, %d, %d, %d)"
#define V4i_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4i v4i(int x, int y, int z, int w);
LADEF V4i v4ii(int x);
LADEF V4i v4i2f(V2f a);
LADEF V4i v4i2d(V2d a);
LADEF V4i v4i2i(V2i a);
LADEF V4i v4i2u(V2u a);
LADEF V4i v4i3f(V3f a);
LADEF V4i v4i3d(V3d a);
LADEF V4i v4i3i(V3i a);
LADEF V4i v4i3u(V3u a);
LADEF V4i v4i4f(V4f a);
LADEF V4i v4i4d(V4d a);
LADEF V4i v4i4u(V4u a);
LADEF V4i v4i_sum(V4i a, V4i b);
LADEF V4i v4i_sub(V4i a, V4i b);
LADEF V4i v4i_mul(V4i a, V4i b);
LADEF V4i v4i_div(V4i a, V4i b);
LADEF V4i v4i_mod(V4i a, V4i b);
LADEF V4i v4i_min(V4i a, V4i b);
LADEF V4i v4i_max(V4i a, V4i b);
LADEF V4i v4i_clamp(V4i x, V4i a, V4i b);
LADEF int v4i_sqrlen(V4i a);
LADEF int v4i_dot(V4i a, V4i b);

#define V4u_Fmt "v4u(%u, %u, %u, %u)"
#define V4u_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w);
LADEF V4u v4uu(unsigned int x);
LADEF V4u v4u2f(V2f a);
LADEF V4u v4u2d(V2d a);
LADEF V4u v4u2i(V2i a);
LADEF V4u v4u2u(V2u a);
LADEF V4u v4u3f(V3f a);
LADEF V4u v4u3d(V3d a);
LADEF V4u v4u3i(V3i a);
LADEF V4u v4u3u(V3u a);
LADEF V4u v4u4f(V4f a);
LADEF V4u v4u4d(V4d a);
LADEF V4u v4u4i(V4i a);
LADEF V4u v4u_sum(V4u a, V4u b);
LADEF V4u v4u_sub(V4u a, V4u b);
LADEF V4u v4u_mul(V4u a, V4u b);
LADEF V4u v4u_div(V4u a, V4u b);
LADEF V4u v4u_mod(V4u a, V4u b);
LADEF V4u v4u_min(V4u a, V4u b);
LADEF V4u v4u_max(V4u a, V4u b);
LADEF V4u v4u_clamp(V4u x, V4u a, V4u b);
LADEF unsigned int v4u_sqrlen(V4u a);
LADEF unsigned int v4u_dot(V4u a, V4u b);

#define M2x2f_Fmt "m2x2f(%f, %f, %f, %f)"
#define M2x2f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1]
LADEF M2x2f m2x2f(float m00, float m01, float m10, float m11);
LADEF M2x2f m2x2ff(float s);
LADEF M2x2f m2x2f_identity(void);
LADEF float m2x2f_det(M2x2f m);
LADEF M2x2f m2x2f_inverse(M2x2f m);
LADEF M2x2f m2x2f2x2d(M2x2d a);
LADEF M2x2f m2x2f2x2i(M2x2i a);
LADEF M2x2f m2x2f2x2u(M2x2u a);
LADEF M2x2f m2x2f2x3f(M2x3f a);
LADEF M2x2f m2x2f2x3d(M2x3d a);
LADEF M2x2f m2x2f2x3i(M2x3i a);
LADEF M2x2f m2x2f2x3u(M2x3u a);
LADEF M2x2f m2x2f2x4f(M2x4f a);
LADEF M2x2f m2x2f2x4d(M2x4d a);
LADEF M2x2f m2x2f2x4i(M2x4i a);
LADEF M2x2f m2x2f2x4u(M2x4u a);
LADEF M2x2f m2x2f3x2f(M3x2f a);
LADEF M2x2f m2x2f3x2d(M3x2d a);
LADEF M2x2f m2x2f3x2i(M3x2i a);
LADEF M2x2f m2x2f3x2u(M3x2u a);
LADEF M2x2f m2x2f3x3f(M3x3f a);
LADEF M2x2f m2x2f3x3d(M3x3d a);
LADEF M2x2f m2x2f3x3i(M3x3i a);
LADEF M2x2f m2x2f3x3u(M3x3u a);
LADEF M2x2f m2x2f3x4f(M3x4f a);
LADEF M2x2f m2x2f3x4d(M3x4d a);
LADEF M2x2f m2x2f3x4i(M3x4i a);
LADEF M2x2f m2x2f3x4u(M3x4u a);
LADEF M2x2f m2x2f4x2f(M4x2f a);
LADEF M2x2f m2x2f4x2d(M4x2d a);
LADEF M2x2f m2x2f4x2i(M4x2i a);
LADEF M2x2f m2x2f4x2u(M4x2u a);
LADEF M2x2f m2x2f4x3f(M4x3f a);
LADEF M2x2f m2x2f4x3d(M4x3d a);
LADEF M2x2f m2x2f4x3i(M4x3i a);
LADEF M2x2f m2x2f4x3u(M4x3u a);
LADEF M2x2f m2x2f4x4f(M4x4f a);
LADEF M2x2f m2x2f4x4d(M4x4d a);
LADEF M2x2f m2x2f4x4i(M4x4i a);
LADEF M2x2f m2x2f4x4u(M4x4u a);
LADEF M2x2f m2x2f_sum(M2x2f a, M2x2f b);
LADEF M2x2f m2x2f_sub(M2x2f a, M2x2f b);
LADEF M2x2f m2x2f_mul(M2x2f a, M2x2f b);
LADEF M2x2f m2x2f_div(M2x2f a, M2x2f b);
LADEF M2x2f m2x2f_mod(M2x2f a, M2x2f b);
LADEF M2x2f m2x2f_transpose(M2x2f a);
LADEF M2x2f m2x2f_mmul_m2x2f(M2x2f a, M2x2f b);
LADEF M2x3f m2x2f_mmul_m2x3f(M2x2f a, M2x3f b);
LADEF M2x4f m2x2f_mmul_m2x4f(M2x2f a, M2x4f b);
LADEF V2f m2x2f_mul_v2f(M2x2f m, V2f v);

#define M2x2d_Fmt "m2x2d(%lf, %lf, %lf, %lf)"
#define M2x2d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1]
LADEF M2x2d m2x2d(double m00, double m01, double m10, double m11);
LADEF M2x2d m2x2dd(double s);
LADEF M2x2d m2x2d_identity(void);
LADEF double m2x2d_det(M2x2d m);
LADEF M2x2d m2x2d_inverse(M2x2d m);
LADEF M2x2d m2x2d2x2f(M2x2f a);
LADEF M2x2d m2x2d2x2i(M2x2i a);
LADEF M2x2d m2x2d2x2u(M2x2u a);
LADEF M2x2d m2x2d2x3f(M2x3f a);
LADEF M2x2d m2x2d2x3d(M2x3d a);
LADEF M2x2d m2x2d2x3i(M2x3i a);
LADEF M2x2d m2x2d2x3u(M2x3u a);
LADEF M2x2d m2x2d2x4f(M2x4f a);
LADEF M2x2d m2x2d2x4d(M2x4d a);
LADEF M2x2d m2x2d2x4i(M2x4i a);
LADEF M2x2d m2x2d2x4u(M2x4u a);
LADEF M2x2d m2x2d3x2f(M3x2f a);
LADEF M2x2d m2x2d3x2d(M3x2d a);
LADEF M2x2d m2x2d3x2i(M3x2i a);
LADEF M2x2d m2x2d3x2u(M3x2u a);
LADEF M2x2d m2x2d3x3f(M3x3f a);
LADEF M2x2d m2x2d3x3d(M3x3d a);
LADEF M2x2d m2x2d3x3i(M3x3i a);
LADEF M2x2d m2x2d3x3u(M3x3u a);
LADEF M2x2d m2x2d3x4f(M3x4f a);
LADEF M2x2d m2x2d3x4d(M3x4d a);
LADEF M2x2d m2x2d3x4i(M3x4i a);
LADEF M2x2d m2x2d3x4u(M3x4u a);
LADEF M2x2d m2x2d4x2f(M4x2f a);
LADEF M2x2d m2x2d4x2d(M4x2d a);
LADEF M2x2d m2x2d4x2i(M4x2i a);
LADEF M2x2d m2x2d4x2u(M4x2u a);
LADEF M2x2d m2x2d4x3f(M4x3f a);
LADEF M2x2d m2x2d4x3d(M4x3d a);
LADEF M2x2d m2x2d4x3i(M4x3i a);
LADEF M2x2d m2x2d4x3u(M4x3u a);
LADEF M2x2d m2x2d4x4f(M4x4f a);
LADEF M2x2d m2x2d4x4d(M4x4d a);
LADEF M2x2d m2x2d4x4i(M4x4i a);
LADEF M2x2d m2x2d4x4u(M4x4u a);
LADEF M2x2d m2x2d_sum(M2x2d a, M2x2d b);
LADEF M2x2d m2x2d_sub(M2x2d a, M2x2d b);
LADEF M2x2d m2x2d_mul(M2x2d a, M2x2d b);
LADEF M2x2d m2x2d_div(M2x2d a, M2x2d b);
LADEF M2x2d m2x2d_mod(M2x2d a, M2x2d b);
LADEF M2x2d m2x2d_transpose(M2x2d a);
LADEF M2x2d m2x2d_mmul_m2x2d(M2x2d a, M2x2d b);
LADEF M2x3d m2x2d_mmul_m2x3d(M2x2d a, M2x3d b);
LADEF M2x4d m2x2d_mmul_m2x4d(M2x2d a, M2x4d b);
LADEF V2d m2x2d_mul_v2d(M2x2d m, V2d v);

#define M2x2i_Fmt "m2x2i(%d, %d, %d, %d)"
#define M2x2i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1]
LADEF M2x2i m2x2i(int m00, int m01, int m10, int m11);
LADEF M2x2i m2x2ii(int s);
LADEF M2x2i m2x2i_identity(void);
LADEF M2x2i m2x2i2x2f(M2x2f a);
LADEF M2x2i m2x2i2x2d(M2x2d a);
LADEF M2x2i m2x2i2x2u(M2x2u a);
LADEF M2x2i m2x2i2x3f(M2x3f a);
LADEF M2x2i m2x2i2x3d(M2x3d a);
LADEF M2x2i m2x2i2x3i(M2x3i a);
LADEF M2x2i m2x2i2x3u(M2x3u a);
LADEF M2x2i m2x2i2x4f(M2x4f a);
LADEF M2x2i m2x2i2x4d(M2x4d a);
LADEF M2x2i m2x2i2x4i(M2x4i a);
LADEF M2x2i m2x2i2x4u(M2x4u a);
LADEF M2x2i m2x2i3x2f(M3x2f a);
LADEF M2x2i m2x2i3x2d(M3x2d a);
LADEF M2x2i m2x2i3x2i(M3x2i a);
LADEF M2x2i m2x2i3x2u(M3x2u a);
LADEF M2x2i m2x2i3x3f(M3x3f a);
LADEF M2x2i m2x2i3x3d(M3x3d a);
LADEF M2x2i m2x2i3x3i(M3x3i a);
LADEF M2x2i m2x2i3x3u(M3x3u a);
LADEF M2x2i m2x2i3x4f(M3x4f a);
LADEF M2x2i m2x2i3x4d(M3x4d a);
LADEF M2x2i m2x2i3x4i(M3x4i a);
LADEF M2x2i m2x2i3x4u(M3x4u a);
LADEF M2x2i m2x2i4x2f(M4x2f a);
LADEF M2x2i m2x2i4x2d(M4x2d a);
LADEF M2x2i m2x2i4x2i(M4x2i a);
LADEF M2x2i m2x2i4x2u(M4x2u a);
LADEF M2x2i m2x2i4x3f(M4x3f a);
LADEF M2x2i m2x2i4x3d(M4x3d a);
LADEF M2x2i m2x2i4x3i(M4x3i a);
LADEF M2x2i m2x2i4x3u(M4x3u a);
LADEF M2x2i m2x2i4x4f(M4x4f a);
LADEF M2x2i m2x2i4x4d(M4x4d a);
LADEF M2x2i m2x2i4x4i(M4x4i a);
LADEF M2x2i m2x2i4x4u(M4x4u a);
LADEF M2x2i m2x2i_sum(M2x2i a, M2x2i b);
LADEF M2x2i m2x2i_sub(M2x2i a, M2x2i b);
LADEF M2x2i m2x2i_mul(M2x2i a, M2x2i b);
LADEF M2x2i m2x2i_div(M2x2i a, M2x2i b);
LADEF M2x2i m2x2i_mod(M2x2i a, M2x2i b);
LADEF M2x2i m2x2i_transpose(M2x2i a);
LADEF M2x2i m2x2i_mmul_m2x2i(M2x2i a, M2x2i b);
LADEF M2x3i m2x2i_mmul_m2x3i(M2x2i a, M2x3i b);
LADEF M2x4i m2x2i_mmul_m2x4i(M2x2i a, M2x4i b);
LADEF V2i m2x2i_mul_v2i(M2x2i m, V2i v);

#define M2x2u_Fmt "m2x2u(%u, %u, %u, %u)"
#define M2x2u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1]
LADEF M2x2u m2x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11);
LADEF M2x2u m2x2uu(unsigned int s);
LADEF M2x2u m2x2u_identity(void);
LADEF M2x2u m2x2u2x2f(M2x2f a);
LADEF M2x2u m2x2u2x2d(M2x2d a);
LADEF M2x2u m2x2u2x2i(M2x2i a);
LADEF M2x2u m2x2u2x3f(M2x3f a);
LADEF M2x2u m2x2u2x3d(M2x3d a);
LADEF M2x2u m2x2u2x3i(M2x3i a);
LADEF M2x2u m2x2u2x3u(M2x3u a);
LADEF M2x2u m2x2u2x4f(M2x4f a);
LADEF M2x2u m2x2u2x4d(M2x4d a);
LADEF M2x2u m2x2u2x4i(M2x4i a);
LADEF M2x2u m2x2u2x4u(M2x4u a);
LADEF M2x2u m2x2u3x2f(M3x2f a);
LADEF M2x2u m2x2u3x2d(M3x2d a);
LADEF M2x2u m2x2u3x2i(M3x2i a);
LADEF M2x2u m2x2u3x2u(M3x2u a);
LADEF M2x2u m2x2u3x3f(M3x3f a);
LADEF M2x2u m2x2u3x3d(M3x3d a);
LADEF M2x2u m2x2u3x3i(M3x3i a);
LADEF M2x2u m2x2u3x3u(M3x3u a);
LADEF M2x2u m2x2u3x4f(M3x4f a);
LADEF M2x2u m2x2u3x4d(M3x4d a);
LADEF M2x2u m2x2u3x4i(M3x4i a);
LADEF M2x2u m2x2u3x4u(M3x4u a);
LADEF M2x2u m2x2u4x2f(M4x2f a);
LADEF M2x2u m2x2u4x2d(M4x2d a);
LADEF M2x2u m2x2u4x2i(M4x2i a);
LADEF M2x2u m2x2u4x2u(M4x2u a);
LADEF M2x2u m2x2u4x3f(M4x3f a);
LADEF M2x2u m2x2u4x3d(M4x3d a);
LADEF M2x2u m2x2u4x3i(M4x3i a);
LADEF M2x2u m2x2u4x3u(M4x3u a);
LADEF M2x2u m2x2u4x4f(M4x4f a);
LADEF M2x2u m2x2u4x4d(M4x4d a);
LADEF M2x2u m2x2u4x4i(M4x4i a);
LADEF M2x2u m2x2u4x4u(M4x4u a);
LADEF M2x2u m2x2u_sum(M2x2u a, M2x2u b);
LADEF M2x2u m2x2u_sub(M2x2u a, M2x2u b);
LADEF M2x2u m2x2u_mul(M2x2u a, M2x2u b);
LADEF M2x2u m2x2u_div(M2x2u a, M2x2u b);
LADEF M2x2u m2x2u_mod(M2x2u a, M2x2u b);
LADEF M2x2u m2x2u_transpose(M2x2u a);
LADEF M2x2u m2x2u_mmul_m2x2u(M2x2u a, M2x2u b);
LADEF M2x3u m2x2u_mmul_m2x3u(M2x2u a, M2x3u b);
LADEF M2x4u m2x2u_mmul_m2x4u(M2x2u a, M2x4u b);
LADEF V2u m2x2u_mul_v2u(M2x2u m, V2u v);

#define M2x3f_Fmt "m2x3f(%f, %f, %f, %f, %f, %f)"
#define M2x3f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2]
LADEF M2x3f m2x3f(float m00, float m01, float m02, float m10, float m11, float m12);
LADEF M2x3f m2x3ff(float s);
LADEF M2x3f m2x3f2x2f(M2x2f a);
LADEF M2x3f m2x3f2x2d(M2x2d a);
LADEF M2x3f m2x3f2x2i(M2x2i a);
LADEF M2x3f m2x3f2x2u(M2x2u a);
LADEF M2x3f m2x3f2x3d(M2x3d a);
LADEF M2x3f m2x3f2x3i(M2x3i a);
LADEF M2x3f m2x3f2x3u(M2x3u a);
LADEF M2x3f m2x3f2x4f(M2x4f a);
LADEF M2x3f m2x3f2x4d(M2x4d a);
LADEF M2x3f m2x3f2x4i(M2x4i a);
LADEF M2x3f m2x3f2x4u(M2x4u a);
LADEF M2x3f m2x3f3x2f(M3x2f a);
LADEF M2x3f m2x3f3x2d(M3x2d a);
LADEF M2x3f m2x3f3x2i(M3x2i a);
LADEF M2x3f m2x3f3x2u(M3x2u a);
LADEF M2x3f m2x3f3x3f(M3x3f a);
LADEF M2x3f m2x3f3x3d(M3x3d a);
LADEF M2x3f m2x3f3x3i(M3x3i a);
LADEF M2x3f m2x3f3x3u(M3x3u a);
LADEF M2x3f m2x3f3x4f(M3x4f a);
LADEF M2x3f m2x3f3x4d(M3x4d a);
LADEF M2x3f m2x3f3x4i(M3x4i a);
LADEF M2x3f m2x3f3x4u(M3x4u a);
LADEF M2x3f m2x3f4x2f(M4x2f a);
LADEF M2x3f m2x3f4x2d(M4x2d a);
LADEF M2x3f m2x3f4x2i(M4x2i a);
LADEF M2x3f m2x3f4x2u(M4x2u a);
LADEF M2x3f m2x3f4x3f(M4x3f a);
LADEF M2x3f m2x3f4x3d(M4x3d a);
LADEF M2x3f m2x3f4x3i(M4x3i a);
LADEF M2x3f m2x3f4x3u(M4x3u a);
LADEF M2x3f m2x3f4x4f(M4x4f a);
LADEF M2x3f m2x3f4x4d(M4x4d a);
LADEF M2x3f m2x3f4x4i(M4x4i a);
LADEF M2x3f m2x3f4x4u(M4x4u a);
LADEF M2x3f m2x3f_sum(M2x3f a, M2x3f b);
LADEF M2x3f m2x3f_sub(M2x3f a, M2x3f b);
LADEF M2x3f m2x3f_mul(M2x3f a, M2x3f b);
LADEF M2x3f m2x3f_div(M2x3f a, M2x3f b);
LADEF M2x3f m2x3f_mod(M2x3f a, M2x3f b);
LADEF M3x2f m2x3f_transpose(M2x3f a);
LADEF M2x2f m2x3f_mmul_m3x2f(M2x3f a, M3x2f b);
LADEF M2x3f m2x3f_mmul_m3x3f(M2x3f a, M3x3f b);
LADEF M2x4f m2x3f_mmul_m3x4f(M2x3f a, M3x4f b);
LADEF V2f m2x3f_mul_v3f(M2x3f m, V3f v);

#define M2x3d_Fmt "m2x3d(%lf, %lf, %lf, %lf, %lf, %lf)"
#define M2x3d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2]
LADEF M2x3d m2x3d(double m00, double m01, double m02, double m10, double m11, double m12);
LADEF M2x3d m2x3dd(double s);
LADEF M2x3d m2x3d2x2f(M2x2f a);
LADEF M2x3d m2x3d2x2d(M2x2d a);
LADEF M2x3d m2x3d2x2i(M2x2i a);
LADEF M2x3d m2x3d2x2u(M2x2u a);
LADEF M2x3d m2x3d2x3f(M2x3f a);
LADEF M2x3d m2x3d2x3i(M2x3i a);
LADEF M2x3d m2x3d2x3u(M2x3u a);
LADEF M2x3d m2x3d2x4f(M2x4f a);
LADEF M2x3d m2x3d2x4d(M2x4d a);
LADEF M2x3d m2x3d2x4i(M2x4i a);
LADEF M2x3d m2x3d2x4u(M2x4u a);
LADEF M2x3d m2x3d3x2f(M3x2f a);
LADEF M2x3d m2x3d3x2d(M3x2d a);
LADEF M2x3d m2x3d3x2i(M3x2i a);
LADEF M2x3d m2x3d3x2u(M3x2u a);
LADEF M2x3d m2x3d3x3f(M3x3f a);
LADEF M2x3d m2x3d3x3d(M3x3d a);
LADEF M2x3d m2x3d3x3i(M3x3i a);
LADEF M2x3d m2x3d3x3u(M3x3u a);
LADEF M2x3d m2x3d3x4f(M3x4f a);
LADEF M2x3d m2x3d3x4d(M3x4d a);
LADEF M2x3d m2x3d3x4i(M3x4i a);
LADEF M2x3d m2x3d3x4u(M3x4u a);
LADEF M2x3d m2x3d4x2f(M4x2f a);
LADEF M2x3d m2x3d4x2d(M4x2d a);
LADEF M2x3d m2x3d4x2i(M4x2i a);
LADEF M2x3d m2x3d4x2u(M4x2u a);
LADEF M2x3d m2x3d4x3f(M4x3f a);
LADEF M2x3d m2x3d4x3d(M4x3d a);
LADEF M2x3d m2x3d4x3i(M4x3i a);
LADEF M2x3d m2x3d4x3u(M4x3u a);
LADEF M2x3d m2x3d4x4f(M4x4f a);
LADEF M2x3d m2x3d4x4d(M4x4d a);
LADEF M2x3d m2x3d4x4i(M4x4i a);
LADEF M2x3d m2x3d4x4u(M4x4u a);
LADEF M2x3d m2x3d_sum(M2x3d a, M2x3d b);
LADEF M2x3d m2x3d_sub(M2x3d a, M2x3d b);
LADEF M2x3d m2x3d_mul(M2x3d a, M2x3d b);
LADEF M2x3d m2x3d_div(M2x3d a, M2x3d b);
LADEF M2x3d m2x3d_mod(M2x3d a, M2x3d b);
LADEF M3x2d m2x3d_transpose(M2x3d a);
LADEF M2x2d m2x3d_mmul_m3x2d(M2x3d a, M3x2d b);
LADEF M2x3d m2x3d_mmul_m3x3d(M2x3d a, M3x3d b);
LADEF M2x4d m2x3d_mmul_m3x4d(M2x3d a, M3x4d b);
LADEF V2d m2x3d_mul_v3d(M2x3d m, V3d v);

#define M2x3i_Fmt "m2x3i(%d, %d, %d, %d, %d, %d)"
#define M2x3i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2]
LADEF M2x3i m2x3i(int m00, int m01, int m02, int m10, int m11, int m12);
LADEF M2x3i m2x3ii(int s);
LADEF M2x3i m2x3i2x2f(M2x2f a);
LADEF M2x3i m2x3i2x2d(M2x2d a);
LADEF M2x3i m2x3i2x2i(M2x2i a);
LADEF M2x3i m2x3i2x2u(M2x2u a);
LADEF M2x3i m2x3i2x3f(M2x3f a);
LADEF M2x3i m2x3i2x3d(M2x3d a);
LADEF M2x3i m2x3i2x3u(M2x3u a);
LADEF M2x3i m2x3i2x4f(M2x4f a);
LADEF M2x3i m2x3i2x4d(M2x4d a);
LADEF M2x3i m2x3i2x4i(M2x4i a);
LADEF M2x3i m2x3i2x4u(M2x4u a);
LADEF M2x3i m2x3i3x2f(M3x2f a);
LADEF M2x3i m2x3i3x2d(M3x2d a);
LADEF M2x3i m2x3i3x2i(M3x2i a);
LADEF M2x3i m2x3i3x2u(M3x2u a);
LADEF M2x3i m2x3i3x3f(M3x3f a);
LADEF M2x3i m2x3i3x3d(M3x3d a);
LADEF M2x3i m2x3i3x3i(M3x3i a);
LADEF M2x3i m2x3i3x3u(M3x3u a);
LADEF M2x3i m2x3i3x4f(M3x4f a);
LADEF M2x3i m2x3i3x4d(M3x4d a);
LADEF M2x3i m2x3i3x4i(M3x4i a);
LADEF M2x3i m2x3i3x4u(M3x4u a);
LADEF M2x3i m2x3i4x2f(M4x2f a);
LADEF M2x3i m2x3i4x2d(M4x2d a);
LADEF M2x3i m2x3i4x2i(M4x2i a);
LADEF M2x3i m2x3i4x2u(M4x2u a);
LADEF M2x3i m2x3i4x3f(M4x3f a);
LADEF M2x3i m2x3i4x3d(M4x3d a);
LADEF M2x3i m2x3i4x3i(M4x3i a);
LADEF M2x3i m2x3i4x3u(M4x3u a);
LADEF M2x3i m2x3i4x4f(M4x4f a);
LADEF M2x3i m2x3i4x4d(M4x4d a);
LADEF M2x3i m2x3i4x4i(M4x4i a);
LADEF M2x3i m2x3i4x4u(M4x4u a);
LADEF M2x3i m2x3i_sum(M2x3i a, M2x3i b);
LADEF M2x3i m2x3i_sub(M2x3i a, M2x3i b);
LADEF M2x3i m2x3i_mul(M2x3i a, M2x3i b);
LADEF M2x3i m2x3i_div(M2x3i a, M2x3i b);
LADEF M2x3i m2x3i_mod(M2x3i a, M2x3i b);
LADEF M3x2i m2x3i_transpose(M2x3i a);
LADEF M2x2i m2x3i_mmul_m3x2i(M2x3i a, M3x2i b);
LADEF M2x3i m2x3i_mmul_m3x3i(M2x3i a, M3x3i b);
LADEF M2x4i m2x3i_mmul_m3x4i(M2x3i a, M3x4i b);
LADEF V2i m2x3i_mul_v3i(M2x3i m, V3i v);

#define M2x3u_Fmt "m2x3u(%u, %u, %u, %u, %u, %u)"
#define M2x3u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2]
LADEF M2x3u m2x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12);
LADEF M2x3u m2x3uu(unsigned int s);
LADEF M2x3u m2x3u2x2f(M2x2f a);
LADEF M2x3u m2x3u2x2d(M2x2d a);
LADEF M2x3u m2x3u2x2i(M2x2i a);
LADEF M2x3u m2x3u2x2u(M2x2u a);
LADEF M2x3u m2x3u2x3f(M2x3f a);
LADEF M2x3u m2x3u2x3d(M2x3d a);
LADEF M2x3u m2x3u2x3i(M2x3i a);
LADEF M2x3u m2x3u2x4f(M2x4f a);
LADEF M2x3u m2x3u2x4d(M2x4d a);
LADEF M2x3u m2x3u2x4i(M2x4i a);
LADEF M2x3u m2x3u2x4u(M2x4u a);
LADEF M2x3u m2x3u3x2f(M3x2f a);
LADEF M2x3u m2x3u3x2d(M3x2d a);
LADEF M2x3u m2x3u3x2i(M3x2i a);
LADEF M2x3u m2x3u3x2u(M3x2u a);
LADEF M2x3u m2x3u3x3f(M3x3f a);
LADEF M2x3u m2x3u3x3d(M3x3d a);
LADEF M2x3u m2x3u3x3i(M3x3i a);
LADEF M2x3u m2x3u3x3u(M3x3u a);
LADEF M2x3u m2x3u3x4f(M3x4f a);
LADEF M2x3u m2x3u3x4d(M3x4d a);
LADEF M2x3u m2x3u3x4i(M3x4i a);
LADEF M2x3u m2x3u3x4u(M3x4u a);
LADEF M2x3u m2x3u4x2f(M4x2f a);
LADEF M2x3u m2x3u4x2d(M4x2d a);
LADEF M2x3u m2x3u4x2i(M4x2i a);
LADEF M2x3u m2x3u4x2u(M4x2u a);
LADEF M2x3u m2x3u4x3f(M4x3f a);
LADEF M2x3u m2x3u4x3d(M4x3d a);
LADEF M2x3u m2x3u4x3i(M4x3i a);
LADEF M2x3u m2x3u4x3u(M4x3u a);
LADEF M2x3u m2x3u4x4f(M4x4f a);
LADEF M2x3u m2x3u4x4d(M4x4d a);
LADEF M2x3u m2x3u4x4i(M4x4i a);
LADEF M2x3u m2x3u4x4u(M4x4u a);
LADEF M2x3u m2x3u_sum(M2x3u a, M2x3u b);
LADEF M2x3u m2x3u_sub(M2x3u a, M2x3u b);
LADEF M2x3u m2x3u_mul(M2x3u a, M2x3u b);
LADEF M2x3u m2x3u_div(M2x3u a, M2x3u b);
LADEF M2x3u m2x3u_mod(M2x3u a, M2x3u b);
LADEF M3x2u m2x3u_transpose(M2x3u a);
LADEF M2x2u m2x3u_mmul_m3x2u(M2x3u a, M3x2u b);
LADEF M2x3u m2x3u_mmul_m3x3u(M2x3u a, M3x3u b);
LADEF M2x4u m2x3u_mmul_m3x4u(M2x3u a, M3x4u b);
LADEF V2u m2x3u_mul_v3u(M2x3u m, V3u v);

#define M2x4f_Fmt "m2x4f(%f, %f, %f, %f, %f, %f, %f, %f)"
#define M2x4f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3]
LADEF M2x4f m2x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13);
LADEF M2x4f m2x4ff(float s);
LADEF M2x4f m2x4f2x2f(M2x2f a);
LADEF M2x4f m2x4f2x2d(M2x2d a);
LADEF M2x4f m2x4f2x2i(M2x2i a);
LADEF M2x4f m2x4f2x2u(M2x2u a);
LADEF M2x4f m2x4f2x3f(M2x3f a);
LADEF M2x4f m2x4f2x3d(M2x3d a);
LADEF M2x4f m2x4f2x3i(M2x3i a);
LADEF M2x4f m2x4f2x3u(M2x3u a);
LADEF M2x4f m2x4f2x4d(M2x4d a);
LADEF M2x4f m2x4f2x4i(M2x4i a);
LADEF M2x4f m2x4f2x4u(M2x4u a);
LADEF M2x4f m2x4f3x2f(M3x2f a);
LADEF M2x4f m2x4f3x2d(M3x2d a);
LADEF M2x4f m2x4f3x2i(M3x2i a);
LADEF M2x4f m2x4f3x2u(M3x2u a);
LADEF M2x4f m2x4f3x3f(M3x3f a);
LADEF M2x4f m2x4f3x3d(M3x3d a);
LADEF M2x4f m2x4f3x3i(M3x3i a);
LADEF M2x4f m2x4f3x3u(M3x3u a);
LADEF M2x4f m2x4f3x4f(M3x4f a);
LADEF M2x4f m2x4f3x4d(M3x4d a);
LADEF M2x4f m2x4f3x4i(M3x4i a);
LADEF M2x4f m2x4f3x4u(M3x4u a);
LADEF M2x4f m2x4f4x2f(M4x2f a);
LADEF M2x4f m2x4f4x2d(M4x2d a);
LADEF M2x4f m2x4f4x2i(M4x2i a);
LADEF M2x4f m2x4f4x2u(M4x2u a);
LADEF M2x4f m2x4f4x3f(M4x3f a);
LADEF M2x4f m2x4f4x3d(M4x3d a);
LADEF M2x4f m2x4f4x3i(M4x3i a);
LADEF M2x4f m2x4f4x3u(M4x3u a);
LADEF M2x4f m2x4f4x4f(M4x4f a);
LADEF M2x4f m2x4f4x4d(M4x4d a);
LADEF M2x4f m2x4f4x4i(M4x4i a);
LADEF M2x4f m2x4f4x4u(M4x4u a);
LADEF M2x4f m2x4f_sum(M2x4f a, M2x4f b);
LADEF M2x4f m2x4f_sub(M2x4f a, M2x4f b);
LADEF M2x4f m2x4f_mul(M2x4f a, M2x4f b);
LADEF M2x4f m2x4f_div(M2x4f a, M2x4f b);
LADEF M2x4f m2x4f_mod(M2x4f a, M2x4f b);
LADEF M4x2f m2x4f_transpose(M2x4f a);
LADEF M2x2f m2x4f_mmul_m4x2f(M2x4f a, M4x2f b);
LADEF M2x3f m2x4f_mmul_m4x3f(M2x4f a, M4x3f b);
LADEF M2x4f m2x4f_mmul_m4x4f(M2x4f a, M4x4f b);
LADEF V2f m2x4f_mul_v4f(M2x4f m, V4f v);

#define M2x4d_Fmt "m2x4d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M2x4d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3]
LADEF M2x4d m2x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13);
LADEF M2x4d m2x4dd(double s);
LADEF M2x4d m2x4d2x2f(M2x2f a);
LADEF M2x4d m2x4d2x2d(M2x2d a);
LADEF M2x4d m2x4d2x2i(M2x2i a);
LADEF M2x4d m2x4d2x2u(M2x2u a);
LADEF M2x4d m2x4d2x3f(M2x3f a);
LADEF M2x4d m2x4d2x3d(M2x3d a);
LADEF M2x4d m2x4d2x3i(M2x3i a);
LADEF M2x4d m2x4d2x3u(M2x3u a);
LADEF M2x4d m2x4d2x4f(M2x4f a);
LADEF M2x4d m2x4d2x4i(M2x4i a);
LADEF M2x4d m2x4d2x4u(M2x4u a);
LADEF M2x4d m2x4d3x2f(M3x2f a);
LADEF M2x4d m2x4d3x2d(M3x2d a);
LADEF M2x4d m2x4d3x2i(M3x2i a);
LADEF M2x4d m2x4d3x2u(M3x2u a);
LADEF M2x4d m2x4d3x3f(M3x3f a);
LADEF M2x4d m2x4d3x3d(M3x3d a);
LADEF M2x4d m2x4d3x3i(M3x3i a);
LADEF M2x4d m2x4d3x3u(M3x3u a);
LADEF M2x4d m2x4d3x4f(M3x4f a);
LADEF M2x4d m2x4d3x4d(M3x4d a);
LADEF M2x4d m2x4d3x4i(M3x4i a);
LADEF M2x4d m2x4d3x4u(M3x4u a);
LADEF M2x4d m2x4d4x2f(M4x2f a);
LADEF M2x4d m2x4d4x2d(M4x2d a);
LADEF M2x4d m2x4d4x2i(M4x2i a);
LADEF M2x4d m2x4d4x2u(M4x2u a);
LADEF M2x4d m2x4d4x3f(M4x3f a);
LADEF M2x4d m2x4d4x3d(M4x3d a);
LADEF M2x4d m2x4d4x3i(M4x3i a);
LADEF M2x4d m2x4d4x3u(M4x3u a);
LADEF M2x4d m2x4d4x4f(M4x4f a);
LADEF M2x4d m2x4d4x4d(M4x4d a);
LADEF M2x4d m2x4d4x4i(M4x4i a);
LADEF M2x4d m2x4d4x4u(M4x4u a);
LADEF M2x4d m2x4d_sum(M2x4d a, M2x4d b);
LADEF M2x4d m2x4d_sub(M2x4d a, M2x4d b);
LADEF M2x4d m2x4d_mul(M2x4d a, M2x4d b);
LADEF M2x4d m2x4d_div(M2x4d a, M2x4d b);
LADEF M2x4d m2x4d_mod(M2x4d a, M2x4d b);
LADEF M4x2d m2x4d_transpose(M2x4d a);
LADEF M2x2d m2x4d_mmul_m4x2d(M2x4d a, M4x2d b);
LADEF M2x3d m2x4d_mmul_m4x3d(M2x4d a, M4x3d b);
LADEF M2x4d m2x4d_mmul_m4x4d(M2x4d a, M4x4d b);
LADEF V2d m2x4d_mul_v4d(M2x4d m, V4d v);

#define M2x4i_Fmt "m2x4i(%d, %d, %d, %d, %d, %d, %d, %d)"
#define M2x4i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3]
LADEF M2x4i m2x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13);
LADEF M2x4i m2x4ii(int s);
LADEF M2x4i m2x4i2x2f(M2x2f a);
LADEF M2x4i m2x4i2x2d(M2x2d a);
LADEF M2x4i m2x4i2x2i(M2x2i a);
LADEF M2x4i m2x4i2x2u(M2x2u a);
LADEF M2x4i m2x4i2x3f(M2x3f a);
LADEF M2x4i m2x4i2x3d(M2x3d a);
LADEF M2x4i m2x4i2x3i(M2x3i a);
LADEF M2x4i m2x4i2x3u(M2x3u a);
LADEF M2x4i m2x4i2x4f(M2x4f a);
LADEF M2x4i m2x4i2x4d(M2x4d a);
LADEF M2x4i m2x4i2x4u(M2x4u a);
LADEF M2x4i m2x4i3x2f(M3x2f a);
LADEF M2x4i m2x4i3x2d(M3x2d a);
LADEF M2x4i m2x4i3x2i(M3x2i a);
LADEF M2x4i m2x4i3x2u(M3x2u a);
LADEF M2x4i m2x4i3x3f(M3x3f a);
LADEF M2x4i m2x4i3x3d(M3x3d a);
LADEF M2x4i m2x4i3x3i(M3x3i a);
LADEF M2x4i m2x4i3x3u(M3x3u a);
LADEF M2x4i m2x4i3x4f(M3x4f a);
LADEF M2x4i m2x4i3x4d(M3x4d a);
LADEF M2x4i m2x4i3x4i(M3x4i a);
LADEF M2x4i m2x4i3x4u(M3x4u a);
LADEF M2x4i m2x4i4x2f(M4x2f a);
LADEF M2x4i m2x4i4x2d(M4x2d a);
LADEF M2x4i m2x4i4x2i(M4x2i a);
LADEF M2x4i m2x4i4x2u(M4x2u a);
LADEF M2x4i m2x4i4x3f(M4x3f a);
LADEF M2x4i m2x4i4x3d(M4x3d a);
LADEF M2x4i m2x4i4x3i(M4x3i a);
LADEF M2x4i m2x4i4x3u(M4x3u a);
LADEF M2x4i m2x4i4x4f(M4x4f a);
LADEF M2x4i m2x4i4x4d(M4x4d a);
LADEF M2x4i m2x4i4x4i(M4x4i a);
LADEF M2x4i m2x4i4x4u(M4x4u a);
LADEF M2x4i m2x4i_sum(M2x4i a, M2x4i b);
LADEF M2x4i m2x4i_sub(M2x4i a, M2x4i b);
LADEF M2x4i m2x4i_mul(M2x4i a, M2x4i b);
LADEF M2x4i m2x4i_div(M2x4i a, M2x4i b);
LADEF M2x4i m2x4i_mod(M2x4i a, M2x4i b);
LADEF M4x2i m2x4i_transpose(M2x4i a);
LADEF M2x2i m2x4i_mmul_m4x2i(M2x4i a, M4x2i b);
LADEF M2x3i m2x4i_mmul_m4x3i(M2x4i a, M4x3i b);
LADEF M2x4i m2x4i_mmul_m4x4i(M2x4i a, M4x4i b);
LADEF V2i m2x4i_mul_v4i(M2x4i m, V4i v);

#define M2x4u_Fmt "m2x4u(%u, %u, %u, %u, %u, %u, %u, %u)"
#define M2x4u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3]
LADEF M2x4u m2x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13);
LADEF M2x4u m2x4uu(unsigned int s);
LADEF M2x4u m2x4u2x2f(M2x2f a);
LADEF M2x4u m2x4u2x2d(M2x2d a);
LADEF M2x4u m2x4u2x2i(M2x2i a);
LADEF M2x4u m2x4u2x2u(M2x2u a);
LADEF M2x4u m2x4u2x3f(M2x3f a);
LADEF M2x4u m2x4u2x3d(M2x3d a);
LADEF M2x4u m2x4u2x3i(M2x3i a);
LADEF M2x4u m2x4u2x3u(M2x3u a);
LADEF M2x4u m2x4u2x4f(M2x4f a);
LADEF M2x4u m2x4u2x4d(M2x4d a);
LADEF M2x4u m2x4u2x4i(M2x4i a);
LADEF M2x4u m2x4u3x2f(M3x2f a);
LADEF M2x4u m2x4u3x2d(M3x2d a);
LADEF M2x4u m2x4u3x2i(M3x2i a);
LADEF M2x4u m2x4u3x2u(M3x2u a);
LADEF M2x4u m2x4u3x3f(M3x3f a);
LADEF M2x4u m2x4u3x3d(M3x3d a);
LADEF M2x4u m2x4u3x3i(M3x3i a);
LADEF M2x4u m2x4u3x3u(M3x3u a);
LADEF M2x4u m2x4u3x4f(M3x4f a);
LADEF M2x4u m2x4u3x4d(M3x4d a);
LADEF M2x4u m2x4u3x4i(M3x4i a);
LADEF M2x4u m2x4u3x4u(M3x4u a);
LADEF M2x4u m2x4u4x2f(M4x2f a);
LADEF M2x4u m2x4u4x2d(M4x2d a);
LADEF M2x4u m2x4u4x2i(M4x2i a);
LADEF M2x4u m2x4u4x2u(M4x2u a);
LADEF M2x4u m2x4u4x3f(M4x3f a);
LADEF M2x4u m2x4u4x3d(M4x3d a);
LADEF M2x4u m2x4u4x3i(M4x3i a);
LADEF M2x4u m2x4u4x3u(M4x3u a);
LADEF M2x4u m2x4u4x4f(M4x4f a);
LADEF M2x4u m2x4u4x4d(M4x4d a);
LADEF M2x4u m2x4u4x4i(M4x4i a);
LADEF M2x4u m2x4u4x4u(M4x4u a);
LADEF M2x4u m2x4u_sum(M2x4u a, M2x4u b);
LADEF M2x4u m2x4u_sub(M2x4u a, M2x4u b);
LADEF M2x4u m2x4u_mul(M2x4u a, M2x4u b);
LADEF M2x4u m2x4u_div(M2x4u a, M2x4u b);
LADEF M2x4u m2x4u_mod(M2x4u a, M2x4u b);
LADEF M4x2u m2x4u_transpose(M2x4u a);
LADEF M2x2u m2x4u_mmul_m4x2u(M2x4u a, M4x2u b);
LADEF M2x3u m2x4u_mmul_m4x3u(M2x4u a, M4x3u b);
LADEF M2x4u m2x4u_mmul_m4x4u(M2x4u a, M4x4u b);
LADEF V2u m2x4u_mul_v4u(M2x4u m, V4u v);

#define M3x2f_Fmt "m3x2f(%f, %f, %f, %f, %f, %f)"
#define M3x2f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1]
LADEF M3x2f m3x2f(float m00, float m01, float m10, float m11, float m20, float m21);
LADEF M3x2f m3x2ff(float s);
LADEF M3x2f m3x2f2x2f(M2x2f a);
LADEF M3x2f m3x2f2x2d(M2x2d a);
LADEF M3x2f m3x2f2x2i(M2x2i a);
LADEF M3x2f m3x2f2x2u(M2x2u a);
LADEF M3x2f m3x2f2x3f(M2x3f a);
LADEF M3x2f m3x2f2x3d(M2x3d a);
LADEF M3x2f m3x2f2x3i(M2x3i a);
LADEF M3x2f m3x2f2x3u(M2x3u a);
LADEF M3x2f m3x2f2x4f(M2x4f a);
LADEF M3x2f m3x2f2x4d(M2x4d a);
LADEF M3x2f m3x2f2x4i(M2x4i a);
LADEF M3x2f m3x2f2x4u(M2x4u a);
LADEF M3x2f m3x2f3x2d(M3x2d a);
LADEF M3x2f m3x2f3x2i(M3x2i a);
LADEF M3x2f m3x2f3x2u(M3x2u a);
LADEF M3x2f m3x2f3x3f(M3x3f a);
LADEF M3x2f m3x2f3x3d(M3x3d a);
LADEF M3x2f m3x2f3x3i(M3x3i a);
LADEF M3x2f m3x2f3x3u(M3x3u a);
LADEF M3x2f m3x2f3x4f(M3x4f a);
LADEF M3x2f m3x2f3x4d(M3x4d a);
LADEF M3x2f m3x2f3x4i(M3x4i a);
LADEF M3x2f m3x2f3x4u(M3x4u a);
LADEF M3x2f m3x2f4x2f(M4x2f a);
LADEF M3x2f m3x2f4x2d(M4x2d a);
LADEF M3x2f m3x2f4x2i(M4x2i a);
LADEF M3x2f m3x2f4x2u(M4x2u a);
LADEF M3x2f m3x2f4x3f(M4x3f a);
LADEF M3x2f m3x2f4x3d(M4x3d a);
LADEF M3x2f m3x2f4x3i(M4x3i a);
LADEF M3x2f m3x2f4x3u(M4x3u a);
LADEF M3x2f m3x2f4x4f(M4x4f a);
LADEF M3x2f m3x2f4x4d(M4x4d a);
LADEF M3x2f m3x2f4x4i(M4x4i a);
LADEF M3x2f m3x2f4x4u(M4x4u a);
LADEF M3x2f m3x2f_sum(M3x2f a, M3x2f b);
LADEF M3x2f m3x2f_sub(M3x2f a, M3x2f b);
LADEF M3x2f m3x2f_mul(M3x2f a, M3x2f b);
LADEF M3x2f m3x2f_div(M3x2f a, M3x2f b);
LADEF M3x2f m3x2f_mod(M3x2f a, M3x2f b);
LADEF M2x3f m3x2f_transpose(M3x2f a);
LADEF M3x2f m3x2f_mmul_m2x2f(M3x2f a, M2x2f b);
LADEF M3x3f m3x2f_mmul_m2x3f(M3x2f a, M2x3f b);
LADEF M3x4f m3x2f_mmul_m2x4f(M3x2f a, M2x4f b);
LADEF V3f m3x2f_mul_v2f(M3x2f m, V2f v);

#define M3x2d_Fmt "m3x2d(%lf, %lf, %lf, %lf, %lf, %lf)"
#define M3x2d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1]
LADEF M3x2d m3x2d(double m00, double m01, double m10, double m11, double m20, double m21);
LADEF M3x2d m3x2dd(double s);
LADEF M3x2d m3x2d2x2f(M2x2f a);
LADEF M3x2d m3x2d2x2d(M2x2d a);
LADEF M3x2d m3x2d2x2i(M2x2i a);
LADEF M3x2d m3x2d2x2u(M2x2u a);
LADEF M3x2d m3x2d2x3f(M2x3f a);
LADEF M3x2d m3x2d2x3d(M2x3d a);
LADEF M3x2d m3x2d2x3i(M2x3i a);
LADEF M3x2d m3x2d2x3u(M2x3u a);
LADEF M3x2d m3x2d2x4f(M2x4f a);
LADEF M3x2d m3x2d2x4d(M2x4d a);
LADEF M3x2d m3x2d2x4i(M2x4i a);
LADEF M3x2d m3x2d2x4u(M2x4u a);
LADEF M3x2d m3x2d3x2f(M3x2f a);
LADEF M3x2d m3x2d3x2i(M3x2i a);
LADEF M3x2d m3x2d3x2u(M3x2u a);
LADEF M3x2d m3x2d3x3f(M3x3f a);
LADEF M3x2d m3x2d3x3d(M3x3d a);
LADEF M3x2d m3x2d3x3i(M3x3i a);
LADEF M3x2d m3x2d3x3u(M3x3u a);
LADEF M3x2d m3x2d3x4f(M3x4f a);
LADEF M3x2d m3x2d3x4d(M3x4d a);
LADEF M3x2d m3x2d3x4i(M3x4i a);
LADEF M3x2d m3x2d3x4u(M3x4u a);
LADEF M3x2d m3x2d4x2f(M4x2f a);
LADEF M3x2d m3x2d4x2d(M4x2d a);
LADEF M3x2d m3x2d4x2i(M4x2i a);
LADEF M3x2d m3x2d4x2u(M4x2u a);
LADEF M3x2d m3x2d4x3f(M4x3f a);
LADEF M3x2d m3x2d4x3d(M4x3d a);
LADEF M3x2d m3x2d4x3i(M4x3i a);
LADEF M3x2d m3x2d4x3u(M4x3u a);
LADEF M3x2d m3x2d4x4f(M4x4f a);
LADEF M3x2d m3x2d4x4d(M4x4d a);
LADEF M3x2d m3x2d4x4i(M4x4i a);
LADEF M3x2d m3x2d4x4u(M4x4u a);
LADEF M3x2d m3x2d_sum(M3x2d a, M3x2d b);
LADEF M3x2d m3x2d_sub(M3x2d a, M3x2d b);
LADEF M3x2d m3x2d_mul(M3x2d a, M3x2d b);
LADEF M3x2d m3x2d_div(M3x2d a, M3x2d b);
LADEF M3x2d m3x2d_mod(M3x2d a, M3x2d b);
LADEF M2x3d m3x2d_transpose(M3x2d a);
LADEF M3x2d m3x2d_mmul_m2x2d(M3x2d a, M2x2d b);
LADEF M3x3d m3x2d_mmul_m2x3d(M3x2d a, M2x3d b);
LADEF M3x4d m3x2d_mmul_m2x4d(M3x2d a, M2x4d b);
LADEF V3d m3x2d_mul_v2d(M3x2d m, V2d v);

#define M3x2i_Fmt "m3x2i(%d, %d, %d, %d, %d, %d)"
#define M3x2i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1]
LADEF M3x2i m3x2i(int m00, int m01, int m10, int m11, int m20, int m21);
LADEF M3x2i m3x2ii(int s);
LADEF M3x2i m3x2i2x2f(M2x2f a);
LADEF M3x2i m3x2i2x2d(M2x2d a);
LADEF M3x2i m3x2i2x2i(M2x2i a);
LADEF M3x2i m3x2i2x2u(M2x2u a);
LADEF M3x2i m3x2i2x3f(M2x3f a);
LADEF M3x2i m3x2i2x3d(M2x3d a);
LADEF M3x2i m3x2i2x3i(M2x3i a);
LADEF M3x2i m3x2i2x3u(M2x3u a);
LADEF M3x2i m3x2i2x4f(M2x4f a);
LADEF M3x2i m3x2i2x4d(M2x4d a);
LADEF M3x2i m3x2i2x4i(M2x4i a);
LADEF M3x2i m3x2i2x4u(M2x4u a);
LADEF M3x2i m3x2i3x2f(M3x2f a);
LADEF M3x2i m3x2i3x2d(M3x2d a);
LADEF M3x2i m3x2i3x2u(M3x2u a);
LADEF M3x2i m3x2i3x3f(M3x3f a);
LADEF M3x2i m3x2i3x3d(M3x3d a);
LADEF M3x2i m3x2i3x3i(M3x3i a);
LADEF M3x2i m3x2i3x3u(M3x3u a);
LADEF M3x2i m3x2i3x4f(M3x4f a);
LADEF M3x2i m3x2i3x4d(M3x4d a);
LADEF M3x2i m3x2i3x4i(M3x4i a);
LADEF M3x2i m3x2i3x4u(M3x4u a);
LADEF M3x2i m3x2i4x2f(M4x2f a);
LADEF M3x2i m3x2i4x2d(M4x2d a);
LADEF M3x2i m3x2i4x2i(M4x2i a);
LADEF M3x2i m3x2i4x2u(M4x2u a);
LADEF M3x2i m3x2i4x3f(M4x3f a);
LADEF M3x2i m3x2i4x3d(M4x3d a);
LADEF M3x2i m3x2i4x3i(M4x3i a);
LADEF M3x2i m3x2i4x3u(M4x3u a);
LADEF M3x2i m3x2i4x4f(M4x4f a);
LADEF M3x2i m3x2i4x4d(M4x4d a);
LADEF M3x2i m3x2i4x4i(M4x4i a);
LADEF M3x2i m3x2i4x4u(M4x4u a);
LADEF M3x2i m3x2i_sum(M3x2i a, M3x2i b);
LADEF M3x2i m3x2i_sub(M3x2i a, M3x2i b);
LADEF M3x2i m3x2i_mul(M3x2i a, M3x2i b);
LADEF M3x2i m3x2i_div(M3x2i a, M3x2i b);
LADEF M3x2i m3x2i_mod(M3x2i a, M3x2i b);
LADEF M2x3i m3x2i_transpose(M3x2i a);
LADEF M3x2i m3x2i_mmul_m2x2i(M3x2i a, M2x2i b);
LADEF M3x3i m3x2i_mmul_m2x3i(M3x2i a, M2x3i b);
LADEF M3x4i m3x2i_mmul_m2x4i(M3x2i a, M2x4i b);
LADEF V3i m3x2i_mul_v2i(M3x2i m, V2i v);

#define M3x2u_Fmt "m3x2u(%u, %u, %u, %u, %u, %u)"
#define M3x2u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1]
LADEF M3x2u m3x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11, unsigned int m20, unsigned int m21);
LADEF M3x2u m3x2uu(unsigned int s);
LADEF M3x2u m3x2u2x2f(M2x2f a);
LADEF M3x2u m3x2u2x2d(M2x2d a);
LADEF M3x2u m3x2u2x2i(M2x2i a);
LADEF M3x2u m3x2u2x2u(M2x2u a);
LADEF M3x2u m3x2u2x3f(M2x3f a);
LADEF M3x2u m3x2u2x3d(M2x3d a);
LADEF M3x2u m3x2u2x3i(M2x3i a);
LADEF M3x2u m3x2u2x3u(M2x3u a);
LADEF M3x2u m3x2u2x4f(M2x4f a);
LADEF M3x2u m3x2u2x4d(M2x4d a);
LADEF M3x2u m3x2u2x4i(M2x4i a);
LADEF M3x2u m3x2u2x4u(M2x4u a);
LADEF M3x2u m3x2u3x2f(M3x2f a);
LADEF M3x2u m3x2u3x2d(M3x2d a);
LADEF M3x2u m3x2u3x2i(M3x2i a);
LADEF M3x2u m3x2u3x3f(M3x3f a);
LADEF M3x2u m3x2u3x3d(M3x3d a);
LADEF M3x2u m3x2u3x3i(M3x3i a);
LADEF M3x2u m3x2u3x3u(M3x3u a);
LADEF M3x2u m3x2u3x4f(M3x4f a);
LADEF M3x2u m3x2u3x4d(M3x4d a);
LADEF M3x2u m3x2u3x4i(M3x4i a);
LADEF M3x2u m3x2u3x4u(M3x4u a);
LADEF M3x2u m3x2u4x2f(M4x2f a);
LADEF M3x2u m3x2u4x2d(M4x2d a);
LADEF M3x2u m3x2u4x2i(M4x2i a);
LADEF M3x2u m3x2u4x2u(M4x2u a);
LADEF M3x2u m3x2u4x3f(M4x3f a);
LADEF M3x2u m3x2u4x3d(M4x3d a);
LADEF M3x2u m3x2u4x3i(M4x3i a);
LADEF M3x2u m3x2u4x3u(M4x3u a);
LADEF M3x2u m3x2u4x4f(M4x4f a);
LADEF M3x2u m3x2u4x4d(M4x4d a);
LADEF M3x2u m3x2u4x4i(M4x4i a);
LADEF M3x2u m3x2u4x4u(M4x4u a);
LADEF M3x2u m3x2u_sum(M3x2u a, M3x2u b);
LADEF M3x2u m3x2u_sub(M3x2u a, M3x2u b);
LADEF M3x2u m3x2u_mul(M3x2u a, M3x2u b);
LADEF M3x2u m3x2u_div(M3x2u a, M3x2u b);
LADEF M3x2u m3x2u_mod(M3x2u a, M3x2u b);
LADEF M2x3u m3x2u_transpose(M3x2u a);
LADEF M3x2u m3x2u_mmul_m2x2u(M3x2u a, M2x2u b);
LADEF M3x3u m3x2u_mmul_m2x3u(M3x2u a, M2x3u b);
LADEF M3x4u m3x2u_mmul_m2x4u(M3x2u a, M2x4u b);
LADEF V3u m3x2u_mul_v2u(M3x2u m, V2u v);

#define M3x3f_Fmt "m3x3f(%f, %f, %f, %f, %f, %f, %f, %f, %f)"
#define M3x3f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2]
LADEF M3x3f m3x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
LADEF M3x3f m3x3ff(float s);
LADEF M3x3f m3x3f_identity(void);
LADEF float m3x3f_det(M3x3f m);
LADEF M3x3f m3x3f_inverse(M3x3f m);
LADEF M3x3f m3x3f2x2f(M2x2f a);
LADEF M3x3f m3x3f2x2d(M2x2d a);
LADEF M3x3f m3x3f2x2i(M2x2i a);
LADEF M3x3f m3x3f2x2u(M2x2u a);
LADEF M3x3f m3x3f2x3f(M2x3f a);
LADEF M3x3f m3x3f2x3d(M2x3d a);
LADEF M3x3f m3x3f2x3i(M2x3i a);
LADEF M3x3f m3x3f2x3u(M2x3u a);
LADEF M3x3f m3x3f2x4f(M2x4f a);
LADEF M3x3f m3x3f2x4d(M2x4d a);
LADEF M3x3f m3x3f2x4i(M2x4i a);
LADEF M3x3f m3x3f2x4u(M2x4u a);
LADEF M3x3f m3x3f3x2f(M3x2f a);
LADEF M3x3f m3x3f3x2d(M3x2d a);
LADEF M3x3f m3x3f3x2i(M3x2i a);
LADEF M3x3f m3x3f3x2u(M3x2u a);
LADEF M3x3f m3x3f3x3d(M3x3d a);
LADEF M3x3f m3x3f3x3i(M3x3i a);
LADEF M3x3f m3x3f3x3u(M3x3u a);
LADEF M3x3f m3x3f3x4f(M3x4f a);
LADEF M3x3f m3x3f3x4d(M3x4d a);
LADEF M3x3f m3x3f3x4i(M3x4i a);
LADEF M3x3f m3x3f3x4u(M3x4u a);
LADEF M3x3f m3x3f4x2f(M4x2f a);
LADEF M3x3f m3x3f4x2d(M4x2d a);
LADEF M3x3f m3x3f4x2i(M4x2i a);
LADEF M3x3f m3x3f4x2u(M4x2u a);
LADEF M3x3f m3x3f4x3f(M4x3f a);
LADEF M3x3f m3x3f4x3d(M4x3d a);
LADEF M3x3f m3x3f4x3i(M4x3i a);
LADEF M3x3f m3x3f4x3u(M4x3u a);
LADEF M3x3f m3x3f4x4f(M4x4f a);
LADEF M3x3f m3x3f4x4d(M4x4d a);
LADEF M3x3f m3x3f4x4i(M4x4i a);
LADEF M3x3f m3x3f4x4u(M4x4u a);
LADEF M3x3f m3x3f_sum(M3x3f a, M3x3f b);
LADEF M3x3f m3x3f_sub(M3x3f a, M3x3f b);
LADEF M3x3f m3x3f_mul(M3x3f a, M3x3f b);
LADEF M3x3f m3x3f_div(M3x3f a, M3x3f b);
LADEF M3x3f m3x3f_mod(M3x3f a, M3x3f b);
LADEF M3x3f m3x3f_transpose(M3x3f a);
LADEF M3x2f m3x3f_mmul_m3x2f(M3x3f a, M3x2f b);
LADEF M3x3f m3x3f_mmul_m3x3f(M3x3f a, M3x3f b);
LADEF M3x4f m3x3f_mmul_m3x4f(M3x3f a, M3x4f b);
LADEF V3f m3x3f_mul_v3f(M3x3f m, V3f v);

#define M3x3d_Fmt "m3x3d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M3x3d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2]
LADEF M3x3d m3x3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22);
LADEF M3x3d m3x3dd(double s);
LADEF M3x3d m3x3d_identity(void);
LADEF double m3x3d_det(M3x3d m);
LADEF M3x3d m3x3d_inverse(M3x3d m);
LADEF M3x3d m3x3d2x2f(M2x2f a);
LADEF M3x3d m3x3d2x2d(M2x2d a);
LADEF M3x3d m3x3d2x2i(M2x2i a);
LADEF M3x3d m3x3d2x2u(M2x2u a);
LADEF M3x3d m3x3d2x3f(M2x3f a);
LADEF M3x3d m3x3d2x3d(M2x3d a);
LADEF M3x3d m3x3d2x3i(M2x3i a);
LADEF M3x3d m3x3d2x3u(M2x3u a);
LADEF M3x3d m3x3d2x4f(M2x4f a);
LADEF M3x3d m3x3d2x4d(M2x4d a);
LADEF M3x3d m3x3d2x4i(M2x4i a);
LADEF M3x3d m3x3d2x4u(M2x4u a);
LADEF M3x3d m3x3d3x2f(M3x2f a);
LADEF M3x3d m3x3d3x2d(M3x2d a);
LADEF M3x3d m3x3d3x2i(M3x2i a);
LADEF M3x3d m3x3d3x2u(M3x2u a);
LADEF M3x3d m3x3d3x3f(M3x3f a);
LADEF M3x3d m3x3d3x3i(M3x3i a);
LADEF M3x3d m3x3d3x3u(M3x3u a);
LADEF M3x3d m3x3d3x4f(M3x4f a);
LADEF M3x3d m3x3d3x4d(M3x4d a);
LADEF M3x3d m3x3d3x4i(M3x4i a);
LADEF M3x3d m3x3d3x4u(M3x4u a);
LADEF M3x3d m3x3d4x2f(M4x2f a);
LADEF M3x3d m3x3d4x2d(M4x2d a);
LADEF M3x3d m3x3d4x2i(M4x2i a);
LADEF M3x3d m3x3d4x2u(M4x2u a);
LADEF M3x3d m3x3d4x3f(M4x3f a);
LADEF M3x3d m3x3d4x3d(M4x3d a);
LADEF M3x3d m3x3d4x3i(M4x3i a);
LADEF M3x3d m3x3d4x3u(M4x3u a);
LADEF M3x3d m3x3d4x4f(M4x4f a);
LADEF M3x3d m3x3d4x4d(M4x4d a);
LADEF M3x3d m3x3d4x4i(M4x4i a);
LADEF M3x3d m3x3d4x4u(M4x4u a);
LADEF M3x3d m3x3d_sum(M3x3d a, M3x3d b);
LADEF M3x3d m3x3d_sub(M3x3d a, M3x3d b);
LADEF M3x3d m3x3d_mul(M3x3d a, M3x3d b);
LADEF M3x3d m3x3d_div(M3x3d a, M3x3d b);
LADEF M3x3d m3x3d_mod(M3x3d a, M3x3d b);
LADEF M3x3d m3x3d_transpose(M3x3d a);
LADEF M3x2d m3x3d_mmul_m3x2d(M3x3d a, M3x2d b);
LADEF M3x3d m3x3d_mmul_m3x3d(M3x3d a, M3x3d b);
LADEF M3x4d m3x3d_mmul_m3x4d(M3x3d a, M3x4d b);
LADEF V3d m3x3d_mul_v3d(M3x3d m, V3d v);

#define M3x3i_Fmt "m3x3i(%d, %d, %d, %d, %d, %d, %d, %d, %d)"
#define M3x3i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2]
LADEF M3x3i m3x3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22);
LADEF M3x3i m3x3ii(int s);
LADEF M3x3i m3x3i_identity(void);
LADEF M3x3i m3x3i2x2f(M2x2f a);
LADEF M3x3i m3x3i2x2d(M2x2d a);
LADEF M3x3i m3x3i2x2i(M2x2i a);
LADEF M3x3i m3x3i2x2u(M2x2u a);
LADEF M3x3i m3x3i2x3f(M2x3f a);
LADEF M3x3i m3x3i2x3d(M2x3d a);
LADEF M3x3i m3x3i2x3i(M2x3i a);
LADEF M3x3i m3x3i2x3u(M2x3u a);
LADEF M3x3i m3x3i2x4f(M2x4f a);
LADEF M3x3i m3x3i2x4d(M2x4d a);
LADEF M3x3i m3x3i2x4i(M2x4i a);
LADEF M3x3i m3x3i2x4u(M2x4u a);
LADEF M3x3i m3x3i3x2f(M3x2f a);
LADEF M3x3i m3x3i3x2d(M3x2d a);
LADEF M3x3i m3x3i3x2i(M3x2i a);
LADEF M3x3i m3x3i3x2u(M3x2u a);
LADEF M3x3i m3x3i3x3f(M3x3f a);
LADEF M3x3i m3x3i3x3d(M3x3d a);
LADEF M3x3i m3x3i3x3u(M3x3u a);
LADEF M3x3i m3x3i3x4f(M3x4f a);
LADEF M3x3i m3x3i3x4d(M3x4d a);
LADEF M3x3i m3x3i3x4i(M3x4i a);
LADEF M3x3i m3x3i3x4u(M3x4u a);
LADEF M3x3i m3x3i4x2f(M4x2f a);
LADEF M3x3i m3x3i4x2d(M4x2d a);
LADEF M3x3i m3x3i4x2i(M4x2i a);
LADEF M3x3i m3x3i4x2u(M4x2u a);
LADEF M3x3i m3x3i4x3f(M4x3f a);
LADEF M3x3i m3x3i4x3d(M4x3d a);
LADEF M3x3i m3x3i4x3i(M4x3i a);
LADEF M3x3i m3x3i4x3u(M4x3u a);
LADEF M3x3i m3x3i4x4f(M4x4f a);
LADEF M3x3i m3x3i4x4d(M4x4d a);
LADEF M3x3i m3x3i4x4i(M4x4i a);
LADEF M3x3i m3x3i4x4u(M4x4u a);
LADEF M3x3i m3x3i_sum(M3x3i a, M3x3i b);
LADEF M3x3i m3x3i_sub(M3x3i a, M3x3i b);
LADEF M3x3i m3x3i_mul(M3x3i a, M3x3i b);
LADEF M3x3i m3x3i_div(M3x3i a, M3x3i b);
LADEF M3x3i m3x3i_mod(M3x3i a, M3x3i b);
LADEF M3x3i m3x3i_transpose(M3x3i a);
LADEF M3x2i m3x3i_mmul_m3x2i(M3x3i a, M3x2i b);
LADEF M3x3i m3x3i_mmul_m3x3i(M3x3i a, M3x3i b);
LADEF M3x4i m3x3i_mmul_m3x4i(M3x3i a, M3x4i b);
LADEF V3i m3x3i_mul_v3i(M3x3i m, V3i v);

#define M3x3u_Fmt "m3x3u(%u, %u, %u, %u, %u, %u, %u, %u, %u)"
#define M3x3u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2]
LADEF M3x3u m3x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m20, unsigned int m21, unsigned int m22);
LADEF M3x3u m3x3uu(unsigned int s);
LADEF M3x3u m3x3u_identity(void);
LADEF M3x3u m3x3u2x2f(M2x2f a);
LADEF M3x3u m3x3u2x2d(M2x2d a);
LADEF M3x3u m3x3u2x2i(M2x2i a);
LADEF M3x3u m3x3u2x2u(M2x2u a);
LADEF M3x3u m3x3u2x3f(M2x3f a);
LADEF M3x3u m3x3u2x3d(M2x3d a);
LADEF M3x3u m3x3u2x3i(M2x3i a);
LADEF M3x3u m3x3u2x3u(M2x3u a);
LADEF M3x3u m3x3u2x4f(M2x4f a);
LADEF M3x3u m3x3u2x4d(M2x4d a);
LADEF M3x3u m3x3u2x4i(M2x4i a);
LADEF M3x3u m3x3u2x4u(M2x4u a);
LADEF M3x3u m3x3u3x2f(M3x2f a);
LADEF M3x3u m3x3u3x2d(M3x2d a);
LADEF M3x3u m3x3u3x2i(M3x2i a);
LADEF M3x3u m3x3u3x2u(M3x2u a);
LADEF M3x3u m3x3u3x3f(M3x3f a);
LADEF M3x3u m3x3u3x3d(M3x3d a);
LADEF M3x3u m3x3u3x3i(M3x3i a);
LADEF M3x3u m3x3u3x4f(M3x4f a);
LADEF M3x3u m3x3u3x4d(M3x4d a);
LADEF M3x3u m3x3u3x4i(M3x4i a);
LADEF M3x3u m3x3u3x4u(M3x4u a);
LADEF M3x3u m3x3u4x2f(M4x2f a);
LADEF M3x3u m3x3u4x2d(M4x2d a);
LADEF M3x3u m3x3u4x2i(M4x2i a);
LADEF M3x3u m3x3u4x2u(M4x2u a);
LADEF M3x3u m3x3u4x3f(M4x3f a);
LADEF M3x3u m3x3u4x3d(M4x3d a);
LADEF M3x3u m3x3u4x3i(M4x3i a);
LADEF M3x3u m3x3u4x3u(M4x3u a);
LADEF M3x3u m3x3u4x4f(M4x4f a);
LADEF M3x3u m3x3u4x4d(M4x4d a);
LADEF M3x3u m3x3u4x4i(M4x4i a);
LADEF M3x3u m3x3u4x4u(M4x4u a);
LADEF M3x3u m3x3u_sum(M3x3u a, M3x3u b);
LADEF M3x3u m3x3u_sub(M3x3u a, M3x3u b);
LADEF M3x3u m3x3u_mul(M3x3u a, M3x3u b);
LADEF M3x3u m3x3u_div(M3x3u a, M3x3u b);
LADEF M3x3u m3x3u_mod(M3x3u a, M3x3u b);
LADEF M3x3u m3x3u_transpose(M3x3u a);
LADEF M3x2u m3x3u_mmul_m3x2u(M3x3u a, M3x2u b);
LADEF M3x3u m3x3u_mmul_m3x3u(M3x3u a, M3x3u b);
LADEF M3x4u m3x3u_mmul_m3x4u(M3x3u a, M3x4u b);
LADEF V3u m3x3u_mul_v3u(M3x3u m, V3u v);

#define M3x4f_Fmt "m3x4f(%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f)"
#define M3x4f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3]
LADEF M3x4f m3x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23);
LADEF M3x4f m3x4ff(float s);
LADEF M3x4f m3x4f2x2f(M2x2f a);
LADEF M3x4f m3x4f2x2d(M2x2d a);
LADEF M3x4f m3x4f2x2i(M2x2i a);
LADEF M3x4f m3x4f2x2u(M2x2u a);
LADEF M3x4f m3x4f2x3f(M2x3f a);
LADEF M3x4f m3x4f2x3d(M2x3d a);
LADEF M3x4f m3x4f2x3i(M2x3i a);
LADEF M3x4f m3x4f2x3u(M2x3u a);
LADEF M3x4f m3x4f2x4f(M2x4f a);
LADEF M3x4f m3x4f2x4d(M2x4d a);
LADEF M3x4f m3x4f2x4i(M2x4i a);
LADEF M3x4f m3x4f2x4u(M2x4u a);
LADEF M3x4f m3x4f3x2f(M3x2f a);
LADEF M3x4f m3x4f3x2d(M3x2d a);
LADEF M3x4f m3x4f3x2i(M3x2i a);
LADEF M3x4f m3x4f3x2u(M3x2u a);
LADEF M3x4f m3x4f3x3f(M3x3f a);
LADEF M3x4f m3x4f3x3d(M3x3d a);
LADEF M3x4f m3x4f3x3i(M3x3i a);
LADEF M3x4f m3x4f3x3u(M3x3u a);
LADEF M3x4f m3x4f3x4d(M3x4d a);
LADEF M3x4f m3x4f3x4i(M3x4i a);
LADEF M3x4f m3x4f3x4u(M3x4u a);
LADEF M3x4f m3x4f4x2f(M4x2f a);
LADEF M3x4f m3x4f4x2d(M4x2d a);
LADEF M3x4f m3x4f4x2i(M4x2i a);
LADEF M3x4f m3x4f4x2u(M4x2u a);
LADEF M3x4f m3x4f4x3f(M4x3f a);
LADEF M3x4f m3x4f4x3d(M4x3d a);
LADEF M3x4f m3x4f4x3i(M4x3i a);
LADEF M3x4f m3x4f4x3u(M4x3u a);
LADEF M3x4f m3x4f4x4f(M4x4f a);
LADEF M3x4f m3x4f4x4d(M4x4d a);
LADEF M3x4f m3x4f4x4i(M4x4i a);
LADEF M3x4f m3x4f4x4u(M4x4u a);
LADEF M3x4f m3x4f_sum(M3x4f a, M3x4f b);
LADEF M3x4f m3x4f_sub(M3x4f a, M3x4f b);
LADEF M3x4f m3x4f_mul(M3x4f a, M3x4f b);
LADEF M3x4f m3x4f_div(M3x4f a, M3x4f b);
LADEF M3x4f m3x4f_mod(M3x4f a, M3x4f b);
LADEF M4x3f m3x4f_transpose(M3x4f a);
LADEF M3x2f m3x4f_mmul_m4x2f(M3x4f a, M4x2f b);
LADEF M3x3f m3x4f_mmul_m4x3f(M3x4f a, M4x3f b);
LADEF M3x4f m3x4f_mmul_m4x4f(M3x4f a, M4x4f b);
LADEF V3f m3x4f_mul_v4f(M3x4f m, V4f v);

#define M3x4d_Fmt "m3x4d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M3x4d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3]
LADEF M3x4d m3x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23);
LADEF M3x4d m3x4dd(double s);
LADEF M3x4d m3x4d2x2f(M2x2f a);
LADEF M3x4d m3x4d2x2d(M2x2d a);
LADEF M3x4d m3x4d2x2i(M2x2i a);
LADEF M3x4d m3x4d2x2u(M2x2u a);
LADEF M3x4d m3x4d2x3f(M2x3f a);
LADEF M3x4d m3x4d2x3d(M2x3d a);
LADEF M3x4d m3x4d2x3i(M2x3i a);
LADEF M3x4d m3x4d2x3u(M2x3u a);
LADEF M3x4d m3x4d2x4f(M2x4f a);
LADEF M3x4d m3x4d2x4d(M2x4d a);
LADEF M3x4d m3x4d2x4i(M2x4i a);
LADEF M3x4d m3x4d2x4u(M2x4u a);
LADEF M3x4d m3x4d3x2f(M3x2f a);
LADEF M3x4d m3x4d3x2d(M3x2d a);
LADEF M3x4d m3x4d3x2i(M3x2i a);
LADEF M3x4d m3x4d3x2u(M3x2u a);
LADEF M3x4d m3x4d3x3f(M3x3f a);
LADEF M3x4d m3x4d3x3d(M3x3d a);
LADEF M3x4d m3x4d3x3i(M3x3i a);
LADEF M3x4d m3x4d3x3u(M3x3u a);
LADEF M3x4d m3x4d3x4f(M3x4f a);
LADEF M3x4d m3x4d3x4i(M3x4i a);
LADEF M3x4d m3x4d3x4u(M3x4u a);
LADEF M3x4d m3x4d4x2f(M4x2f a);
LADEF M3x4d m3x4d4x2d(M4x2d a);
LADEF M3x4d m3x4d4x2i(M4x2i a);
LADEF M3x4d m3x4d4x2u(M4x2u a);
LADEF M3x4d m3x4d4x3f(M4x3f a);
LADEF M3x4d m3x4d4x3d(M4x3d a);
LADEF M3x4d m3x4d4x3i(M4x3i a);
LADEF M3x4d m3x4d4x3u(M4x3u a);
LADEF M3x4d m3x4d4x4f(M4x4f a);
LADEF M3x4d m3x4d4x4d(M4x4d a);
LADEF M3x4d m3x4d4x4i(M4x4i a);
LADEF M3x4d m3x4d4x4u(M4x4u a);
LADEF M3x4d m3x4d_sum(M3x4d a, M3x4d b);
LADEF M3x4d m3x4d_sub(M3x4d a, M3x4d b);
LADEF M3x4d m3x4d_mul(M3x4d a, M3x4d b);
LADEF M3x4d m3x4d_div(M3x4d a, M3x4d b);
LADEF M3x4d m3x4d_mod(M3x4d a, M3x4d b);
LADEF M4x3d m3x4d_transpose(M3x4d a);
LADEF M3x2d m3x4d_mmul_m4x2d(M3x4d a, M4x2d b);
LADEF M3x3d m3x4d_mmul_m4x3d(M3x4d a, M4x3d b);
LADEF M3x4d m3x4d_mmul_m4x4d(M3x4d a, M4x4d b);
LADEF V3d m3x4d_mul_v4d(M3x4d m, V4d v);

#define M3x4i_Fmt "m3x4i(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)"
#define M3x4i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3]
LADEF M3x4i m3x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23);
LADEF M3x4i m3x4ii(int s);
LADEF M3x4i m3x4i2x2f(M2x2f a);
LADEF M3x4i m3x4i2x2d(M2x2d a);
LADEF M3x4i m3x4i2x2i(M2x2i a);
LADEF M3x4i m3x4i2x2u(M2x2u a);
LADEF M3x4i m3x4i2x3f(M2x3f a);
LADEF M3x4i m3x4i2x3d(M2x3d a);
LADEF M3x4i m3x4i2x3i(M2x3i a);
LADEF M3x4i m3x4i2x3u(M2x3u a);
LADEF M3x4i m3x4i2x4f(M2x4f a);
LADEF M3x4i m3x4i2x4d(M2x4d a);
LADEF M3x4i m3x4i2x4i(M2x4i a);
LADEF M3x4i m3x4i2x4u(M2x4u a);
LADEF M3x4i m3x4i3x2f(M3x2f a);
LADEF M3x4i m3x4i3x2d(M3x2d a);
LADEF M3x4i m3x4i3x2i(M3x2i a);
LADEF M3x4i m3x4i3x2u(M3x2u a);
LADEF M3x4i m3x4i3x3f(M3x3f a);
LADEF M3x4i m3x4i3x3d(M3x3d a);
LADEF M3x4i m3x4i3x3i(M3x3i a);
LADEF M3x4i m3x4i3x3u(M3x3u a);
LADEF M3x4i m3x4i3x4f(M3x4f a);
LADEF M3x4i m3x4i3x4d(M3x4d a);
LADEF M3x4i m3x4i3x4u(M3x4u a);
LADEF M3x4i m3x4i4x2f(M4x2f a);
LADEF M3x4i m3x4i4x2d(M4x2d a);
LADEF M3x4i m3x4i4x2i(M4x2i a);
LADEF M3x4i m3x4i4x2u(M4x2u a);
LADEF M3x4i m3x4i4x3f(M4x3f a);
LADEF M3x4i m3x4i4x3d(M4x3d a);
LADEF M3x4i m3x4i4x3i(M4x3i a);
LADEF M3x4i m3x4i4x3u(M4x3u a);
LADEF M3x4i m3x4i4x4f(M4x4f a);
LADEF M3x4i m3x4i4x4d(M4x4d a);
LADEF M3x4i m3x4i4x4i(M4x4i a);
LADEF M3x4i m3x4i4x4u(M4x4u a);
LADEF M3x4i m3x4i_sum(M3x4i a, M3x4i b);
LADEF M3x4i m3x4i_sub(M3x4i a, M3x4i b);
LADEF M3x4i m3x4i_mul(M3x4i a, M3x4i b);
LADEF M3x4i m3x4i_div(M3x4i a, M3x4i b);
LADEF M3x4i m3x4i_mod(M3x4i a, M3x4i b);
LADEF M4x3i m3x4i_transpose(M3x4i a);
LADEF M3x2i m3x4i_mmul_m4x2i(M3x4i a, M4x2i b);
LADEF M3x3i m3x4i_mmul_m4x3i(M3x4i a, M4x3i b);
LADEF M3x4i m3x4i_mmul_m4x4i(M3x4i a, M4x4i b);
LADEF V3i m3x4i_mul_v4i(M3x4i m, V4i v);

#define M3x4u_Fmt "m3x4u(%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u)"
#define M3x4u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3]
LADEF M3x4u m3x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m23);
LADEF M3x4u m3x4uu(unsigned int s);
LADEF M3x4u m3x4u2x2f(M2x2f a);
LADEF M3x4u m3x4u2x2d(M2x2d a);
LADEF M3x4u m3x4u2x2i(M2x2i a);
LADEF M3x4u m3x4u2x2u(M2x2u a);
LADEF M3x4u m3x4u2x3f(M2x3f a);
LADEF M3x4u m3x4u2x3d(M2x3d a);
LADEF M3x4u m3x4u2x3i(M2x3i a);
LADEF M3x4u m3x4u2x3u(M2x3u a);
LADEF M3x4u m3x4u2x4f(M2x4f a);
LADEF M3x4u m3x4u2x4d(M2x4d a);
LADEF M3x4u m3x4u2x4i(M2x4i a);
LADEF M3x4u m3x4u2x4u(M2x4u a);
LADEF M3x4u m3x4u3x2f(M3x2f a);
LADEF M3x4u m3x4u3x2d(M3x2d a);
LADEF M3x4u m3x4u3x2i(M3x2i a);
LADEF M3x4u m3x4u3x2u(M3x2u a);
LADEF M3x4u m3x4u3x3f(M3x3f a);
LADEF M3x4u m3x4u3x3d(M3x3d a);
LADEF M3x4u m3x4u3x3i(M3x3i a);
LADEF M3x4u m3x4u3x3u(M3x3u a);
LADEF M3x4u m3x4u3x4f(M3x4f a);
LADEF M3x4u m3x4u3x4d(M3x4d a);
LADEF M3x4u m3x4u3x4i(M3x4i a);
LADEF M3x4u m3x4u4x2f(M4x2f a);
LADEF M3x4u m3x4u4x2d(M4x2d a);
LADEF M3x4u m3x4u4x2i(M4x2i a);
LADEF M3x4u m3x4u4x2u(M4x2u a);
LADEF M3x4u m3x4u4x3f(M4x3f a);
LADEF M3x4u m3x4u4x3d(M4x3d a);
LADEF M3x4u m3x4u4x3i(M4x3i a);
LADEF M3x4u m3x4u4x3u(M4x3u a);
LADEF M3x4u m3x4u4x4f(M4x4f a);
LADEF M3x4u m3x4u4x4d(M4x4d a);
LADEF M3x4u m3x4u4x4i(M4x4i a);
LADEF M3x4u m3x4u4x4u(M4x4u a);
LADEF M3x4u m3x4u_sum(M3x4u a, M3x4u b);
LADEF M3x4u m3x4u_sub(M3x4u a, M3x4u b);
LADEF M3x4u m3x4u_mul(M3x4u a, M3x4u b);
LADEF M3x4u m3x4u_div(M3x4u a, M3x4u b);
LADEF M3x4u m3x4u_mod(M3x4u a, M3x4u b);
LADEF M4x3u m3x4u_transpose(M3x4u a);
LADEF M3x2u m3x4u_mmul_m4x2u(M3x4u a, M4x2u b);
LADEF M3x3u m3x4u_mmul_m4x3u(M3x4u a, M4x3u b);
LADEF M3x4u m3x4u_mmul_m4x4u(M3x4u a, M4x4u b);
LADEF V3u m3x4u_mul_v4u(M3x4u m, V4u v);

#define M4x2f_Fmt "m4x2f(%f, %f, %f, %f, %f, %f, %f, %f)"
#define M4x2f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1], (m).rc[3][0], (m).rc[3][1]
LADEF M4x2f m4x2f(float m00, float m01, float m10, float m11, float m20, float m21, float m30, float m31);
LADEF M4x2f m4x2ff(float s);
LADEF M4x2f m4x2f2x2f(M2x2f a);
LADEF M4x2f m4x2f2x2d(M2x2d a);
LADEF M4x2f m4x2f2x2i(M2x2i a);
LADEF M4x2f m4x2f2x2u(M2x2u a);
LADEF M4x2f m4x2f2x3f(M2x3f a);
LADEF M4x2f m4x2f2x3d(M2x3d a);
LADEF M4x2f m4x2f2x3i(M2x3i a);
LADEF M4x2f m4x2f2x3u(M2x3u a);
LADEF M4x2f m4x2f2x4f(M2x4f a);
LADEF M4x2f m4x2f2x4d(M2x4d a);
LADEF M4x2f m4x2f2x4i(M2x4i a);
LADEF M4x2f m4x2f2x4u(M2x4u a);
LADEF M4x2f m4x2f3x2f(M3x2f a);
LADEF M4x2f m4x2f3x2d(M3x2d a);
LADEF M4x2f m4x2f3x2i(M3x2i a);
LADEF M4x2f m4x2f3x2u(M3x2u a);
LADEF M4x2f m4x2f3x3f(M3x3f a);
LADEF M4x2f m4x2f3x3d(M3x3d a);
LADEF M4x2f m4x2f3x3i(M3x3i a);
LADEF M4x2f m4x2f3x3u(M3x3u a);
LADEF M4x2f m4x2f3x4f(M3x4f a);
LADEF M4x2f m4x2f3x4d(M3x4d a);
LADEF M4x2f m4x2f3x4i(M3x4i a);
LADEF M4x2f m4x2f3x4u(M3x4u a);
LADEF M4x2f m4x2f4x2d(M4x2d a);
LADEF M4x2f m4x2f4x2i(M4x2i a);
LADEF M4x2f m4x2f4x2u(M4x2u a);
LADEF M4x2f m4x2f4x3f(M4x3f a);
LADEF M4x2f m4x2f4x3d(M4x3d a);
LADEF M4x2f m4x2f4x3i(M4x3i a);
LADEF M4x2f m4x2f4x3u(M4x3u a);
LADEF M4x2f m4x2f4x4f(M4x4f a);
LADEF M4x2f m4x2f4x4d(M4x4d a);
LADEF M4x2f m4x2f4x4i(M4x4i a);
LADEF M4x2f m4x2f4x4u(M4x4u a);
LADEF M4x2f m4x2f_sum(M4x2f a, M4x2f b);
LADEF M4x2f m4x2f_sub(M4x2f a, M4x2f b);
LADEF M4x2f m4x2f_mul(M4x2f a, M4x2f b);
LADEF M4x2f m4x2f_div(M4x2f a, M4x2f b);
LADEF M4x2f m4x2f_mod(M4x2f a, M4x2f b);
LADEF M2x4f m4x2f_transpose(M4x2f a);
LADEF M4x2f m4x2f_mmul_m2x2f(M4x2f a, M2x2f b);
LADEF M4x3f m4x2f_mmul_m2x3f(M4x2f a, M2x3f b);
LADEF M4x4f m4x2f_mmul_m2x4f(M4x2f a, M2x4f b);
LADEF V4f m4x2f_mul_v2f(M4x2f m, V2f v);

#define M4x2d_Fmt "m4x2d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M4x2d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1], (m).rc[3][0], (m).rc[3][1]
LADEF M4x2d m4x2d(double m00, double m01, double m10, double m11, double m20, double m21, double m30, double m31);
LADEF M4x2d m4x2dd(double s);
LADEF M4x2d m4x2d2x2f(M2x2f a);
LADEF M4x2d m4x2d2x2d(M2x2d a);
LADEF M4x2d m4x2d2x2i(M2x2i a);
LADEF M4x2d m4x2d2x2u(M2x2u a);
LADEF M4x2d m4x2d2x3f(M2x3f a);
LADEF M4x2d m4x2d2x3d(M2x3d a);
LADEF M4x2d m4x2d2x3i(M2x3i a);
LADEF M4x2d m4x2d2x3u(M2x3u a);
LADEF M4x2d m4x2d2x4f(M2x4f a);
LADEF M4x2d m4x2d2x4d(M2x4d a);
LADEF M4x2d m4x2d2x4i(M2x4i a);
LADEF M4x2d m4x2d2x4u(M2x4u a);
LADEF M4x2d m4x2d3x2f(M3x2f a);
LADEF M4x2d m4x2d3x2d(M3x2d a);
LADEF M4x2d m4x2d3x2i(M3x2i a);
LADEF M4x2d m4x2d3x2u(M3x2u a);
LADEF M4x2d m4x2d3x3f(M3x3f a);
LADEF M4x2d m4x2d3x3d(M3x3d a);
LADEF M4x2d m4x2d3x3i(M3x3i a);
LADEF M4x2d m4x2d3x3u(M3x3u a);
LADEF M4x2d m4x2d3x4f(M3x4f a);
LADEF M4x2d m4x2d3x4d(M3x4d a);
LADEF M4x2d m4x2d3x4i(M3x4i a);
LADEF M4x2d m4x2d3x4u(M3x4u a);
LADEF M4x2d m4x2d4x2f(M4x2f a);
LADEF M4x2d m4x2d4x2i(M4x2i a);
LADEF M4x2d m4x2d4x2u(M4x2u a);
LADEF M4x2d m4x2d4x3f(M4x3f a);
LADEF M4x2d m4x2d4x3d(M4x3d a);
LADEF M4x2d m4x2d4x3i(M4x3i a);
LADEF M4x2d m4x2d4x3u(M4x3u a);
LADEF M4x2d m4x2d4x4f(M4x4f a);
LADEF M4x2d m4x2d4x4d(M4x4d a);
LADEF M4x2d m4x2d4x4i(M4x4i a);
LADEF M4x2d m4x2d4x4u(M4x4u a);
LADEF M4x2d m4x2d_sum(M4x2d a, M4x2d b);
LADEF M4x2d m4x2d_sub(M4x2d a, M4x2d b);
LADEF M4x2d m4x2d_mul(M4x2d a, M4x2d b);
LADEF M4x2d m4x2d_div(M4x2d a, M4x2d b);
LADEF M4x2d m4x2d_mod(M4x2d a, M4x2d b);
LADEF M2x4d m4x2d_transpose(M4x2d a);
LADEF M4x2d m4x2d_mmul_m2x2d(M4x2d a, M2x2d b);
LADEF M4x3d m4x2d_mmul_m2x3d(M4x2d a, M2x3d b);
LADEF M4x4d m4x2d_mmul_m2x4d(M4x2d a, M2x4d b);
LADEF V4d m4x2d_mul_v2d(M4x2d m, V2d v);

#define M4x2i_Fmt "m4x2i(%d, %d, %d, %d, %d, %d, %d, %d)"
#define M4x2i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1], (m).rc[3][0], (m).rc[3][1]
LADEF M4x2i m4x2i(int m00, int m01, int m10, int m11, int m20, int m21, int m30, int m31);
LADEF M4x2i m4x2ii(int s);
LADEF M4x2i m4x2i2x2f(M2x2f a);
LADEF M4x2i m4x2i2x2d(M2x2d a);
LADEF M4x2i m4x2i2x2i(M2x2i a);
LADEF M4x2i m4x2i2x2u(M2x2u a);
LADEF M4x2i m4x2i2x3f(M2x3f a);
LADEF M4x2i m4x2i2x3d(M2x3d a);
LADEF M4x2i m4x2i2x3i(M2x3i a);
LADEF M4x2i m4x2i2x3u(M2x3u a);
LADEF M4x2i m4x2i2x4f(M2x4f a);
LADEF M4x2i m4x2i2x4d(M2x4d a);
LADEF M4x2i m4x2i2x4i(M2x4i a);
LADEF M4x2i m4x2i2x4u(M2x4u a);
LADEF M4x2i m4x2i3x2f(M3x2f a);
LADEF M4x2i m4x2i3x2d(M3x2d a);
LADEF M4x2i m4x2i3x2i(M3x2i a);
LADEF M4x2i m4x2i3x2u(M3x2u a);
LADEF M4x2i m4x2i3x3f(M3x3f a);
LADEF M4x2i m4x2i3x3d(M3x3d a);
LADEF M4x2i m4x2i3x3i(M3x3i a);
LADEF M4x2i m4x2i3x3u(M3x3u a);
LADEF M4x2i m4x2i3x4f(M3x4f a);
LADEF M4x2i m4x2i3x4d(M3x4d a);
LADEF M4x2i m4x2i3x4i(M3x4i a);
LADEF M4x2i m4x2i3x4u(M3x4u a);
LADEF M4x2i m4x2i4x2f(M4x2f a);
LADEF M4x2i m4x2i4x2d(M4x2d a);
LADEF M4x2i m4x2i4x2u(M4x2u a);
LADEF M4x2i m4x2i4x3f(M4x3f a);
LADEF M4x2i m4x2i4x3d(M4x3d a);
LADEF M4x2i m4x2i4x3i(M4x3i a);
LADEF M4x2i m4x2i4x3u(M4x3u a);
LADEF M4x2i m4x2i4x4f(M4x4f a);
LADEF M4x2i m4x2i4x4d(M4x4d a);
LADEF M4x2i m4x2i4x4i(M4x4i a);
LADEF M4x2i m4x2i4x4u(M4x4u a);
LADEF M4x2i m4x2i_sum(M4x2i a, M4x2i b);
LADEF M4x2i m4x2i_sub(M4x2i a, M4x2i b);
LADEF M4x2i m4x2i_mul(M4x2i a, M4x2i b);
LADEF M4x2i m4x2i_div(M4x2i a, M4x2i b);
LADEF M4x2i m4x2i_mod(M4x2i a, M4x2i b);
LADEF M2x4i m4x2i_transpose(M4x2i a);
LADEF M4x2i m4x2i_mmul_m2x2i(M4x2i a, M2x2i b);
LADEF M4x3i m4x2i_mmul_m2x3i(M4x2i a, M2x3i b);
LADEF M4x4i m4x2i_mmul_m2x4i(M4x2i a, M2x4i b);
LADEF V4i m4x2i_mul_v2i(M4x2i m, V2i v);

#define M4x2u_Fmt "m4x2u(%u, %u, %u, %u, %u, %u, %u, %u)"
#define M4x2u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[1][0], (m).rc[1][1], (m).rc[2][0], (m).rc[2][1], (m).rc[3][0], (m).rc[3][1]
LADEF M4x2u m4x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11, unsigned int m20, unsigned int m21, unsigned int m30, unsigned int m31);
LADEF M4x2u m4x2uu(unsigned int s);
LADEF M4x2u m4x2u2x2f(M2x2f a);
LADEF M4x2u m4x2u2x2d(M2x2d a);
LADEF M4x2u m4x2u2x2i(M2x2i a);
LADEF M4x2u m4x2u2x2u(M2x2u a);
LADEF M4x2u m4x2u2x3f(M2x3f a);
LADEF M4x2u m4x2u2x3d(M2x3d a);
LADEF M4x2u m4x2u2x3i(M2x3i a);
LADEF M4x2u m4x2u2x3u(M2x3u a);
LADEF M4x2u m4x2u2x4f(M2x4f a);
LADEF M4x2u m4x2u2x4d(M2x4d a);
LADEF M4x2u m4x2u2x4i(M2x4i a);
LADEF M4x2u m4x2u2x4u(M2x4u a);
LADEF M4x2u m4x2u3x2f(M3x2f a);
LADEF M4x2u m4x2u3x2d(M3x2d a);
LADEF M4x2u m4x2u3x2i(M3x2i a);
LADEF M4x2u m4x2u3x2u(M3x2u a);
LADEF M4x2u m4x2u3x3f(M3x3f a);
LADEF M4x2u m4x2u3x3d(M3x3d a);
LADEF M4x2u m4x2u3x3i(M3x3i a);
LADEF M4x2u m4x2u3x3u(M3x3u a);
LADEF M4x2u m4x2u3x4f(M3x4f a);
LADEF M4x2u m4x2u3x4d(M3x4d a);
LADEF M4x2u m4x2u3x4i(M3x4i a);
LADEF M4x2u m4x2u3x4u(M3x4u a);
LADEF M4x2u m4x2u4x2f(M4x2f a);
LADEF M4x2u m4x2u4x2d(M4x2d a);
LADEF M4x2u m4x2u4x2i(M4x2i a);
LADEF M4x2u m4x2u4x3f(M4x3f a);
LADEF M4x2u m4x2u4x3d(M4x3d a);
LADEF M4x2u m4x2u4x3i(M4x3i a);
LADEF M4x2u m4x2u4x3u(M4x3u a);
LADEF M4x2u m4x2u4x4f(M4x4f a);
LADEF M4x2u m4x2u4x4d(M4x4d a);
LADEF M4x2u m4x2u4x4i(M4x4i a);
LADEF M4x2u m4x2u4x4u(M4x4u a);
LADEF M4x2u m4x2u_sum(M4x2u a, M4x2u b);
LADEF M4x2u m4x2u_sub(M4x2u a, M4x2u b);
LADEF M4x2u m4x2u_mul(M4x2u a, M4x2u b);
LADEF M4x2u m4x2u_div(M4x2u a, M4x2u b);
LADEF M4x2u m4x2u_mod(M4x2u a, M4x2u b);
LADEF M2x4u m4x2u_transpose(M4x2u a);
LADEF M4x2u m4x2u_mmul_m2x2u(M4x2u a, M2x2u b);
LADEF M4x3u m4x2u_mmul_m2x3u(M4x2u a, M2x3u b);
LADEF M4x4u m4x2u_mmul_m2x4u(M4x2u a, M2x4u b);
LADEF V4u m4x2u_mul_v2u(M4x2u m, V2u v);

#define M4x3f_Fmt "m4x3f(%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f)"
#define M4x3f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2]
LADEF M4x3f m4x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, float m30, float m31, float m32);
LADEF M4x3f m4x3ff(float s);
LADEF M4x3f m4x3f2x2f(M2x2f a);
LADEF M4x3f m4x3f2x2d(M2x2d a);
LADEF M4x3f m4x3f2x2i(M2x2i a);
LADEF M4x3f m4x3f2x2u(M2x2u a);
LADEF M4x3f m4x3f2x3f(M2x3f a);
LADEF M4x3f m4x3f2x3d(M2x3d a);
LADEF M4x3f m4x3f2x3i(M2x3i a);
LADEF M4x3f m4x3f2x3u(M2x3u a);
LADEF M4x3f m4x3f2x4f(M2x4f a);
LADEF M4x3f m4x3f2x4d(M2x4d a);
LADEF M4x3f m4x3f2x4i(M2x4i a);
LADEF M4x3f m4x3f2x4u(M2x4u a);
LADEF M4x3f m4x3f3x2f(M3x2f a);
LADEF M4x3f m4x3f3x2d(M3x2d a);
LADEF M4x3f m4x3f3x2i(M3x2i a);
LADEF M4x3f m4x3f3x2u(M3x2u a);
LADEF M4x3f m4x3f3x3f(M3x3f a);
LADEF M4x3f m4x3f3x3d(M3x3d a);
LADEF M4x3f m4x3f3x3i(M3x3i a);
LADEF M4x3f m4x3f3x3u(M3x3u a);
LADEF M4x3f m4x3f3x4f(M3x4f a);
LADEF M4x3f m4x3f3x4d(M3x4d a);
LADEF M4x3f m4x3f3x4i(M3x4i a);
LADEF M4x3f m4x3f3x4u(M3x4u a);
LADEF M4x3f m4x3f4x2f(M4x2f a);
LADEF M4x3f m4x3f4x2d(M4x2d a);
LADEF M4x3f m4x3f4x2i(M4x2i a);
LADEF M4x3f m4x3f4x2u(M4x2u a);
LADEF M4x3f m4x3f4x3d(M4x3d a);
LADEF M4x3f m4x3f4x3i(M4x3i a);
LADEF M4x3f m4x3f4x3u(M4x3u a);
LADEF M4x3f m4x3f4x4f(M4x4f a);
LADEF M4x3f m4x3f4x4d(M4x4d a);
LADEF M4x3f m4x3f4x4i(M4x4i a);
LADEF M4x3f m4x3f4x4u(M4x4u a);
LADEF M4x3f m4x3f_sum(M4x3f a, M4x3f b);
LADEF M4x3f m4x3f_sub(M4x3f a, M4x3f b);
LADEF M4x3f m4x3f_mul(M4x3f a, M4x3f b);
LADEF M4x3f m4x3f_div(M4x3f a, M4x3f b);
LADEF M4x3f m4x3f_mod(M4x3f a, M4x3f b);
LADEF M3x4f m4x3f_transpose(M4x3f a);
LADEF M4x2f m4x3f_mmul_m3x2f(M4x3f a, M3x2f b);
LADEF M4x3f m4x3f_mmul_m3x3f(M4x3f a, M3x3f b);
LADEF M4x4f m4x3f_mmul_m3x4f(M4x3f a, M3x4f b);
LADEF V4f m4x3f_mul_v3f(M4x3f m, V3f v);

#define M4x3d_Fmt "m4x3d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M4x3d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2]
LADEF M4x3d m4x3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22, double m30, double m31, double m32);
LADEF M4x3d m4x3dd(double s);
LADEF M4x3d m4x3d2x2f(M2x2f a);
LADEF M4x3d m4x3d2x2d(M2x2d a);
LADEF M4x3d m4x3d2x2i(M2x2i a);
LADEF M4x3d m4x3d2x2u(M2x2u a);
LADEF M4x3d m4x3d2x3f(M2x3f a);
LADEF M4x3d m4x3d2x3d(M2x3d a);
LADEF M4x3d m4x3d2x3i(M2x3i a);
LADEF M4x3d m4x3d2x3u(M2x3u a);
LADEF M4x3d m4x3d2x4f(M2x4f a);
LADEF M4x3d m4x3d2x4d(M2x4d a);
LADEF M4x3d m4x3d2x4i(M2x4i a);
LADEF M4x3d m4x3d2x4u(M2x4u a);
LADEF M4x3d m4x3d3x2f(M3x2f a);
LADEF M4x3d m4x3d3x2d(M3x2d a);
LADEF M4x3d m4x3d3x2i(M3x2i a);
LADEF M4x3d m4x3d3x2u(M3x2u a);
LADEF M4x3d m4x3d3x3f(M3x3f a);
LADEF M4x3d m4x3d3x3d(M3x3d a);
LADEF M4x3d m4x3d3x3i(M3x3i a);
LADEF M4x3d m4x3d3x3u(M3x3u a);
LADEF M4x3d m4x3d3x4f(M3x4f a);
LADEF M4x3d m4x3d3x4d(M3x4d a);
LADEF M4x3d m4x3d3x4i(M3x4i a);
LADEF M4x3d m4x3d3x4u(M3x4u a);
LADEF M4x3d m4x3d4x2f(M4x2f a);
LADEF M4x3d m4x3d4x2d(M4x2d a);
LADEF M4x3d m4x3d4x2i(M4x2i a);
LADEF M4x3d m4x3d4x2u(M4x2u a);
LADEF M4x3d m4x3d4x3f(M4x3f a);
LADEF M4x3d m4x3d4x3i(M4x3i a);
LADEF M4x3d m4x3d4x3u(M4x3u a);
LADEF M4x3d m4x3d4x4f(M4x4f a);
LADEF M4x3d m4x3d4x4d(M4x4d a);
LADEF M4x3d m4x3d4x4i(M4x4i a);
LADEF M4x3d m4x3d4x4u(M4x4u a);
LADEF M4x3d m4x3d_sum(M4x3d a, M4x3d b);
LADEF M4x3d m4x3d_sub(M4x3d a, M4x3d b);
LADEF M4x3d m4x3d_mul(M4x3d a, M4x3d b);
LADEF M4x3d m4x3d_div(M4x3d a, M4x3d b);
LADEF M4x3d m4x3d_mod(M4x3d a, M4x3d b);
LADEF M3x4d m4x3d_transpose(M4x3d a);
LADEF M4x2d m4x3d_mmul_m3x2d(M4x3d a, M3x2d b);
LADEF M4x3d m4x3d_mmul_m3x3d(M4x3d a, M3x3d b);
LADEF M4x4d m4x3d_mmul_m3x4d(M4x3d a, M3x4d b);
LADEF V4d m4x3d_mul_v3d(M4x3d m, V3d v);

#define M4x3i_Fmt "m4x3i(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)"
#define M4x3i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2]
LADEF M4x3i m4x3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22, int m30, int m31, int m32);
LADEF M4x3i m4x3ii(int s);
LADEF M4x3i m4x3i2x2f(M2x2f a);
LADEF M4x3i m4x3i2x2d(M2x2d a);
LADEF M4x3i m4x3i2x2i(M2x2i a);
LADEF M4x3i m4x3i2x2u(M2x2u a);
LADEF M4x3i m4x3i2x3f(M2x3f a);
LADEF M4x3i m4x3i2x3d(M2x3d a);
LADEF M4x3i m4x3i2x3i(M2x3i a);
LADEF M4x3i m4x3i2x3u(M2x3u a);
LADEF M4x3i m4x3i2x4f(M2x4f a);
LADEF M4x3i m4x3i2x4d(M2x4d a);
LADEF M4x3i m4x3i2x4i(M2x4i a);
LADEF M4x3i m4x3i2x4u(M2x4u a);
LADEF M4x3i m4x3i3x2f(M3x2f a);
LADEF M4x3i m4x3i3x2d(M3x2d a);
LADEF M4x3i m4x3i3x2i(M3x2i a);
LADEF M4x3i m4x3i3x2u(M3x2u a);
LADEF M4x3i m4x3i3x3f(M3x3f a);
LADEF M4x3i m4x3i3x3d(M3x3d a);
LADEF M4x3i m4x3i3x3i(M3x3i a);
LADEF M4x3i m4x3i3x3u(M3x3u a);
LADEF M4x3i m4x3i3x4f(M3x4f a);
LADEF M4x3i m4x3i3x4d(M3x4d a);
LADEF M4x3i m4x3i3x4i(M3x4i a);
LADEF M4x3i m4x3i3x4u(M3x4u a);
LADEF M4x3i m4x3i4x2f(M4x2f a);
LADEF M4x3i m4x3i4x2d(M4x2d a);
LADEF M4x3i m4x3i4x2i(M4x2i a);
LADEF M4x3i m4x3i4x2u(M4x2u a);
LADEF M4x3i m4x3i4x3f(M4x3f a);
LADEF M4x3i m4x3i4x3d(M4x3d a);
LADEF M4x3i m4x3i4x3u(M4x3u a);
LADEF M4x3i m4x3i4x4f(M4x4f a);
LADEF M4x3i m4x3i4x4d(M4x4d a);
LADEF M4x3i m4x3i4x4i(M4x4i a);
LADEF M4x3i m4x3i4x4u(M4x4u a);
LADEF M4x3i m4x3i_sum(M4x3i a, M4x3i b);
LADEF M4x3i m4x3i_sub(M4x3i a, M4x3i b);
LADEF M4x3i m4x3i_mul(M4x3i a, M4x3i b);
LADEF M4x3i m4x3i_div(M4x3i a, M4x3i b);
LADEF M4x3i m4x3i_mod(M4x3i a, M4x3i b);
LADEF M3x4i m4x3i_transpose(M4x3i a);
LADEF M4x2i m4x3i_mmul_m3x2i(M4x3i a, M3x2i b);
LADEF M4x3i m4x3i_mmul_m3x3i(M4x3i a, M3x3i b);
LADEF M4x4i m4x3i_mmul_m3x4i(M4x3i a, M3x4i b);
LADEF V4i m4x3i_mul_v3i(M4x3i m, V3i v);

#define M4x3u_Fmt "m4x3u(%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u)"
#define M4x3u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2]
LADEF M4x3u m4x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m30, unsigned int m31, unsigned int m32);
LADEF M4x3u m4x3uu(unsigned int s);
LADEF M4x3u m4x3u2x2f(M2x2f a);
LADEF M4x3u m4x3u2x2d(M2x2d a);
LADEF M4x3u m4x3u2x2i(M2x2i a);
LADEF M4x3u m4x3u2x2u(M2x2u a);
LADEF M4x3u m4x3u2x3f(M2x3f a);
LADEF M4x3u m4x3u2x3d(M2x3d a);
LADEF M4x3u m4x3u2x3i(M2x3i a);
LADEF M4x3u m4x3u2x3u(M2x3u a);
LADEF M4x3u m4x3u2x4f(M2x4f a);
LADEF M4x3u m4x3u2x4d(M2x4d a);
LADEF M4x3u m4x3u2x4i(M2x4i a);
LADEF M4x3u m4x3u2x4u(M2x4u a);
LADEF M4x3u m4x3u3x2f(M3x2f a);
LADEF M4x3u m4x3u3x2d(M3x2d a);
LADEF M4x3u m4x3u3x2i(M3x2i a);
LADEF M4x3u m4x3u3x2u(M3x2u a);
LADEF M4x3u m4x3u3x3f(M3x3f a);
LADEF M4x3u m4x3u3x3d(M3x3d a);
LADEF M4x3u m4x3u3x3i(M3x3i a);
LADEF M4x3u m4x3u3x3u(M3x3u a);
LADEF M4x3u m4x3u3x4f(M3x4f a);
LADEF M4x3u m4x3u3x4d(M3x4d a);
LADEF M4x3u m4x3u3x4i(M3x4i a);
LADEF M4x3u m4x3u3x4u(M3x4u a);
LADEF M4x3u m4x3u4x2f(M4x2f a);
LADEF M4x3u m4x3u4x2d(M4x2d a);
LADEF M4x3u m4x3u4x2i(M4x2i a);
LADEF M4x3u m4x3u4x2u(M4x2u a);
LADEF M4x3u m4x3u4x3f(M4x3f a);
LADEF M4x3u m4x3u4x3d(M4x3d a);
LADEF M4x3u m4x3u4x3i(M4x3i a);
LADEF M4x3u m4x3u4x4f(M4x4f a);
LADEF M4x3u m4x3u4x4d(M4x4d a);
LADEF M4x3u m4x3u4x4i(M4x4i a);
LADEF M4x3u m4x3u4x4u(M4x4u a);
LADEF M4x3u m4x3u_sum(M4x3u a, M4x3u b);
LADEF M4x3u m4x3u_sub(M4x3u a, M4x3u b);
LADEF M4x3u m4x3u_mul(M4x3u a, M4x3u b);
LADEF M4x3u m4x3u_div(M4x3u a, M4x3u b);
LADEF M4x3u m4x3u_mod(M4x3u a, M4x3u b);
LADEF M3x4u m4x3u_transpose(M4x3u a);
LADEF M4x2u m4x3u_mmul_m3x2u(M4x3u a, M3x2u b);
LADEF M4x3u m4x3u_mmul_m3x3u(M4x3u a, M3x3u b);
LADEF M4x4u m4x3u_mmul_m3x4u(M4x3u a, M3x4u b);
LADEF V4u m4x3u_mul_v3u(M4x3u m, V3u v);

#define M4x4f_Fmt "m4x4f(%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f)"
#define M4x4f_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2], (m).rc[3][3]
LADEF M4x4f m4x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
LADEF M4x4f m4x4ff(float s);
LADEF M4x4f m4x4f_identity(void);
LADEF float m4x4f_det(M4x4f m);
LADEF M4x4f m4x4f_inverse(M4x4f m);
LADEF M4x4f m4x4f2x2f(M2x2f a);
LADEF M4x4f m4x4f2x2d(M2x2d a);
LADEF M4x4f m4x4f2x2i(M2x2i a);
LADEF M4x4f m4x4f2x2u(M2x2u a);
LADEF M4x4f m4x4f2x3f(M2x3f a);
LADEF M4x4f m4x4f2x3d(M2x3d a);
LADEF M4x4f m4x4f2x3i(M2x3i a);
LADEF M4x4f m4x4f2x3u(M2x3u a);
LADEF M4x4f m4x4f2x4f(M2x4f a);
LADEF M4x4f m4x4f2x4d(M2x4d a);
LADEF M4x4f m4x4f2x4i(M2x4i a);
LADEF M4x4f m4x4f2x4u(M2x4u a);
LADEF M4x4f m4x4f3x2f(M3x2f a);
LADEF M4x4f m4x4f3x2d(M3x2d a);
LADEF M4x4f m4x4f3x2i(M3x2i a);
LADEF M4x4f m4x4f3x2u(M3x2u a);
LADEF M4x4f m4x4f3x3f(M3x3f a);
LADEF M4x4f m4x4f3x3d(M3x3d a);
LADEF M4x4f m4x4f3x3i(M3x3i a);
LADEF M4x4f m4x4f3x3u(M3x3u a);
LADEF M4x4f m4x4f3x4f(M3x4f a);
LADEF M4x4f m4x4f3x4d(M3x4d a);
LADEF M4x4f m4x4f3x4i(M3x4i a);
LADEF M4x4f m4x4f3x4u(M3x4u a);
LADEF M4x4f m4x4f4x2f(M4x2f a);
LADEF M4x4f m4x4f4x2d(M4x2d a);
LADEF M4x4f m4x4f4x2i(M4x2i a);
LADEF M4x4f m4x4f4x2u(M4x2u a);
LADEF M4x4f m4x4f4x3f(M4x3f a);
LADEF M4x4f m4x4f4x3d(M4x3d a);
LADEF M4x4f m4x4f4x3i(M4x3i a);
LADEF M4x4f m4x4f4x3u(M4x3u a);
LADEF M4x4f m4x4f4x4d(M4x4d a);
LADEF M4x4f m4x4f4x4i(M4x4i a);
LADEF M4x4f m4x4f4x4u(M4x4u a);
LADEF M4x4f m4x4f_sum(M4x4f a, M4x4f b);
LADEF M4x4f m4x4f_sub(M4x4f a, M4x4f b);
LADEF M4x4f m4x4f_mul(M4x4f a, M4x4f b);
LADEF M4x4f m4x4f_div(M4x4f a, M4x4f b);
LADEF M4x4f m4x4f_mod(M4x4f a, M4x4f b);
LADEF M4x4f m4x4f_transpose(M4x4f a);
LADEF M4x2f m4x4f_mmul_m4x2f(M4x4f a, M4x2f b);
LADEF M4x3f m4x4f_mmul_m4x3f(M4x4f a, M4x3f b);
LADEF M4x4f m4x4f_mmul_m4x4f(M4x4f a, M4x4f b);
LADEF V4f m4x4f_mul_v4f(M4x4f m, V4f v);

#define M4x4d_Fmt "m4x4d(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)"
#define M4x4d_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2], (m).rc[3][3]
LADEF M4x4d m4x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33);
LADEF M4x4d m4x4dd(double s);
LADEF M4x4d m4x4d_identity(void);
LADEF double m4x4d_det(M4x4d m);
LADEF M4x4d m4x4d_inverse(M4x4d m);
LADEF M4x4d m4x4d2x2f(M2x2f a);
LADEF M4x4d m4x4d2x2d(M2x2d a);
LADEF M4x4d m4x4d2x2i(M2x2i a);
LADEF M4x4d m4x4d2x2u(M2x2u a);
LADEF M4x4d m4x4d2x3f(M2x3f a);
LADEF M4x4d m4x4d2x3d(M2x3d a);
LADEF M4x4d m4x4d2x3i(M2x3i a);
LADEF M4x4d m4x4d2x3u(M2x3u a);
LADEF M4x4d m4x4d2x4f(M2x4f a);
LADEF M4x4d m4x4d2x4d(M2x4d a);
LADEF M4x4d m4x4d2x4i(M2x4i a);
LADEF M4x4d m4x4d2x4u(M2x4u a);
LADEF M4x4d m4x4d3x2f(M3x2f a);
LADEF M4x4d m4x4d3x2d(M3x2d a);
LADEF M4x4d m4x4d3x2i(M3x2i a);
LADEF M4x4d m4x4d3x2u(M3x2u a);
LADEF M4x4d m4x4d3x3f(M3x3f a);
LADEF M4x4d m4x4d3x3d(M3x3d a);
LADEF M4x4d m4x4d3x3i(M3x3i a);
LADEF M4x4d m4x4d3x3u(M3x3u a);
LADEF M4x4d m4x4d3x4f(M3x4f a);
LADEF M4x4d m4x4d3x4d(M3x4d a);
LADEF M4x4d m4x4d3x4i(M3x4i a);
LADEF M4x4d m4x4d3x4u(M3x4u a);
LADEF M4x4d m4x4d4x2f(M4x2f a);
LADEF M4x4d m4x4d4x2d(M4x2d a);
LADEF M4x4d m4x4d4x2i(M4x2i a);
LADEF M4x4d m4x4d4x2u(M4x2u a);
LADEF M4x4d m4x4d4x3f(M4x3f a);
LADEF M4x4d m4x4d4x3d(M4x3d a);
LADEF M4x4d m4x4d4x3i(M4x3i a);
LADEF M4x4d m4x4d4x3u(M4x3u a);
LADEF M4x4d m4x4d4x4f(M4x4f a);
LADEF M4x4d m4x4d4x4i(M4x4i a);
LADEF M4x4d m4x4d4x4u(M4x4u a);
LADEF M4x4d m4x4d_sum(M4x4d a, M4x4d b);
LADEF M4x4d m4x4d_sub(M4x4d a, M4x4d b);
LADEF M4x4d m4x4d_mul(M4x4d a, M4x4d b);
LADEF M4x4d m4x4d_div(M4x4d a, M4x4d b);
LADEF M4x4d m4x4d_mod(M4x4d a, M4x4d b);
LADEF M4x4d m4x4d_transpose(M4x4d a);
LADEF M4x2d m4x4d_mmul_m4x2d(M4x4d a, M4x2d b);
LADEF M4x3d m4x4d_mmul_m4x3d(M4x4d a, M4x3d b);
LADEF M4x4d m4x4d_mmul_m4x4d(M4x4d a, M4x4d b);
LADEF V4d m4x4d_mul_v4d(M4x4d m, V4d v);

#define M4x4i_Fmt "m4x4i(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)"
#define M4x4i_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2], (m).rc[3][3]
LADEF M4x4i m4x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23, int m30, int m31, int m32, int m33);
LADEF M4x4i m4x4ii(int s);
LADEF M4x4i m4x4i_identity(void);
LADEF M4x4i m4x4i2x2f(M2x2f a);
LADEF M4x4i m4x4i2x2d(M2x2d a);
LADEF M4x4i m4x4i2x2i(M2x2i a);
LADEF M4x4i m4x4i2x2u(M2x2u a);
LADEF M4x4i m4x4i2x3f(M2x3f a);
LADEF M4x4i m4x4i2x3d(M2x3d a);
LADEF M4x4i m4x4i2x3i(M2x3i a);
LADEF M4x4i m4x4i2x3u(M2x3u a);
LADEF M4x4i m4x4i2x4f(M2x4f a);
LADEF M4x4i m4x4i2x4d(M2x4d a);
LADEF M4x4i m4x4i2x4i(M2x4i a);
LADEF M4x4i m4x4i2x4u(M2x4u a);
LADEF M4x4i m4x4i3x2f(M3x2f a);
LADEF M4x4i m4x4i3x2d(M3x2d a);
LADEF M4x4i m4x4i3x2i(M3x2i a);
LADEF M4x4i m4x4i3x2u(M3x2u a);
LADEF M4x4i m4x4i3x3f(M3x3f a);
LADEF M4x4i m4x4i3x3d(M3x3d a);
LADEF M4x4i m4x4i3x3i(M3x3i a);
LADEF M4x4i m4x4i3x3u(M3x3u a);
LADEF M4x4i m4x4i3x4f(M3x4f a);
LADEF M4x4i m4x4i3x4d(M3x4d a);
LADEF M4x4i m4x4i3x4i(M3x4i a);
LADEF M4x4i m4x4i3x4u(M3x4u a);
LADEF M4x4i m4x4i4x2f(M4x2f a);
LADEF M4x4i m4x4i4x2d(M4x2d a);
LADEF M4x4i m4x4i4x2i(M4x2i a);
LADEF M4x4i m4x4i4x2u(M4x2u a);
LADEF M4x4i m4x4i4x3f(M4x3f a);
LADEF M4x4i m4x4i4x3d(M4x3d a);
LADEF M4x4i m4x4i4x3i(M4x3i a);
LADEF M4x4i m4x4i4x3u(M4x3u a);
LADEF M4x4i m4x4i4x4f(M4x4f a);
LADEF M4x4i m4x4i4x4d(M4x4d a);
LADEF M4x4i m4x4i4x4u(M4x4u a);
LADEF M4x4i m4x4i_sum(M4x4i a, M4x4i b);
LADEF M4x4i m4x4i_sub(M4x4i a, M4x4i b);
LADEF M4x4i m4x4i_mul(M4x4i a, M4x4i b);
LADEF M4x4i m4x4i_div(M4x4i a, M4x4i b);
LADEF M4x4i m4x4i_mod(M4x4i a, M4x4i b);
LADEF M4x4i m4x4i_transpose(M4x4i a);
LADEF M4x2i m4x4i_mmul_m4x2i(M4x4i a, M4x2i b);
LADEF M4x3i m4x4i_mmul_m4x3i(M4x4i a, M4x3i b);
LADEF M4x4i m4x4i_mmul_m4x4i(M4x4i a, M4x4i b);
LADEF V4i m4x4i_mul_v4i(M4x4i m, V4i v);

#define M4x4u_Fmt "m4x4u(%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u)"
#define M4x4u_Arg(m) (m).rc[0][0], (m).rc[0][1], (m).rc[0][2], (m).rc[0][3], (m).rc[1][0], (m).rc[1][1], (m).rc[1][2], (m).rc[1][3], (m).rc[2][0], (m).rc[2][1], (m).rc[2][2], (m).rc[2][3], (m).rc[3][0], (m).rc[3][1], (m).rc[3][2], (m).rc[3][3]
LADEF M4x4u m4x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m23, unsigned int m30, unsigned int m31, unsigned int m32, unsigned int m33);
LADEF M4x4u m4x4uu(unsigned int s);
LADEF M4x4u m4x4u_identity(void);
LADEF M4x4u m4x4u2x2f(M2x2f a);
LADEF M4x4u m4x4u2x2d(M2x2d a);
LADEF M4x4u m4x4u2x2i(M2x2i a);
LADEF M4x4u m4x4u2x2u(M2x2u a);
LADEF M4x4u m4x4u2x3f(M2x3f a);
LADEF M4x4u m4x4u2x3d(M2x3d a);
LADEF M4x4u m4x4u2x3i(M2x3i a);
LADEF M4x4u m4x4u2x3u(M2x3u a);
LADEF M4x4u m4x4u2x4f(M2x4f a);
LADEF M4x4u m4x4u2x4d(M2x4d a);
LADEF M4x4u m4x4u2x4i(M2x4i a);
LADEF M4x4u m4x4u2x4u(M2x4u a);
LADEF M4x4u m4x4u3x2f(M3x2f a);
LADEF M4x4u m4x4u3x2d(M3x2d a);
LADEF M4x4u m4x4u3x2i(M3x2i a);
LADEF M4x4u m4x4u3x2u(M3x2u a);
LADEF M4x4u m4x4u3x3f(M3x3f a);
LADEF M4x4u m4x4u3x3d(M3x3d a);
LADEF M4x4u m4x4u3x3i(M3x3i a);
LADEF M4x4u m4x4u3x3u(M3x3u a);
LADEF M4x4u m4x4u3x4f(M3x4f a);
LADEF M4x4u m4x4u3x4d(M3x4d a);
LADEF M4x4u m4x4u3x4i(M3x4i a);
LADEF M4x4u m4x4u3x4u(M3x4u a);
LADEF M4x4u m4x4u4x2f(M4x2f a);
LADEF M4x4u m4x4u4x2d(M4x2d a);
LADEF M4x4u m4x4u4x2i(M4x2i a);
LADEF M4x4u m4x4u4x2u(M4x2u a);
LADEF M4x4u m4x4u4x3f(M4x3f a);
LADEF M4x4u m4x4u4x3d(M4x3d a);
LADEF M4x4u m4x4u4x3i(M4x3i a);
LADEF M4x4u m4x4u4x3u(M4x3u a);
LADEF M4x4u m4x4u4x4f(M4x4f a);
LADEF M4x4u m4x4u4x4d(M4x4d a);
LADEF M4x4u m4x4u4x4i(M4x4i a);
LADEF M4x4u m4x4u_sum(M4x4u a, M4x4u b);
LADEF M4x4u m4x4u_sub(M4x4u a, M4x4u b);
LADEF M4x4u m4x4u_mul(M4x4u a, M4x4u b);
LADEF M4x4u m4x4u_div(M4x4u a, M4x4u b);
LADEF M4x4u m4x4u_mod(M4x4u a, M4x4u b);
LADEF M4x4u m4x4u_transpose(M4x4u a);
LADEF M4x2u m4x4u_mmul_m4x2u(M4x4u a, M4x2u b);
LADEF M4x3u m4x4u_mmul_m4x3u(M4x4u a, M4x3u b);
LADEF M4x4u m4x4u_mmul_m4x4u(M4x4u a, M4x4u b);
LADEF V4u m4x4u_mul_v4u(M4x4u m, V4u v);

LADEF R2f r2f_identity(void);
LADEF R2f r2f_mul(R2f p, R2f q);
LADEF R2f r2f_reverse(R2f p);
LADEF float r2f_lengthsqr(R2f p);
LADEF float r2f_length(R2f p);
LADEF R2f r2f_normalize(R2f p);
LADEF R2f r2f_normal(R2f p);
LADEF R2f r2f_from_angle(float angle);
LADEF R2f r2f_from_unit_vectors(V2f from, V2f to);
LADEF V2f r2f_rotate_v2f(R2f r, V2f v);
LADEF R2f r2f_rotate_r2f(R2f p, R2f r);
LADEF R3f r3f_identity(void);
LADEF R3f r3f_mul(R3f p, R3f q);
LADEF R3f r3f_reverse(R3f p);
LADEF float r3f_lengthsqr(R3f p);
LADEF float r3f_length(R3f p);
LADEF R3f r3f_normalize(R3f p);
LADEF R3f r3f_normal(R3f p);
LADEF R3f r3f_from_plane_angle(V3f bv_plane, float angle);
LADEF R3f r3f_from_unit_vectors(V3f from, V3f to);
LADEF V3f r3f_rotate_v3f(R3f r, V3f v);
LADEF R3f r3f_rotate_r3f(R3f p, R3f r);
LADEF M3x3f r3f_to_m3x3f(R3f r);

LADEF R2d r2d_identity(void);
LADEF R2d r2d_mul(R2d p, R2d q);
LADEF R2d r2d_reverse(R2d p);
LADEF double r2d_lengthsqr(R2d p);
LADEF double r2d_length(R2d p);
LADEF R2d r2d_normalize(R2d p);
LADEF R2d r2d_normal(R2d p);
LADEF R2d r2d_from_angle(double angle);
LADEF R2d r2d_from_unit_vectors(V2d from, V2d to);
LADEF V2d r2d_rotate_v2d(R2d r, V2d v);
LADEF R2d r2d_rotate_r2d(R2d p, R2d r);
LADEF R3d r3d_identity(void);
LADEF R3d r3d_mul(R3d p, R3d q);
LADEF R3d r3d_reverse(R3d p);
LADEF double r3d_lengthsqr(R3d p);
LADEF double r3d_length(R3d p);
LADEF R3d r3d_normalize(R3d p);
LADEF R3d r3d_normal(R3d p);
LADEF R3d r3d_from_plane_angle(V3d bv_plane, double angle);
LADEF R3d r3d_from_unit_vectors(V3d from, V3d to);
LADEF V3d r3d_rotate_v3d(R3d r, V3d v);
LADEF R3d r3d_rotate_r3d(R3d p, R3d r);
LADEF M3x3d r3d_to_m3x3d(R3d r);

#endif // LA_H_

#ifdef LA_IMPLEMENTATION

LADEF float lerpf(float a, float b, float t)
{
    return a + (b - a) * t;
}

LADEF double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}

LADEF int mini(int a, int b)
{
    return a < b ? a : b;
}

LADEF int maxi(int a, int b)
{
    return a < b ? b : a;
}

LADEF unsigned int minu(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

LADEF unsigned int maxu(unsigned int a, unsigned int b)
{
    return a < b ? b : a;
}

LADEF float clampf(float x, float a, float b)
{
    return fminf(fmaxf(a, x), b);
}

LADEF double clampd(double x, double a, double b)
{
    return fmin(fmax(a, x), b);
}

LADEF int clampi(int x, int a, int b)
{
    return mini(maxi(a, x), b);
}

LADEF unsigned int clampu(unsigned int x, unsigned int a, unsigned int b)
{
    return minu(maxu(a, x), b);
}

LADEF V2f v2f(float x, float y)
{
    V2f v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2f v2ff(float x)
{
    return v2f(x, x);
}

LADEF V2f v2f2d(V2d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f2i(V2i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f2u(V2u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f3f(V3f a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f3d(V3d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f3i(V3i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f3u(V3u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f4f(V4f a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f4d(V4d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f4i(V4i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f4u(V4u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF V2f v2f_sum(V2f a, V2f b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2f v2f_sub(V2f a, V2f b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2f v2f_mul(V2f a, V2f b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2f v2f_div(V2f a, V2f b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2f v2f_mod(V2f a, V2f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    return a;
}

LADEF V2f v2f_sqrt(V2f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return a;
}

LADEF V2f v2f_pow(V2f base, V2f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    return base;
}

LADEF V2f v2f_sin(V2f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    return a;
}

LADEF V2f v2f_cos(V2f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    return a;
}

LADEF V2f v2f_min(V2f a, V2f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    return a;
}

LADEF V2f v2f_max(V2f a, V2f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    return a;
}

LADEF V2f v2f_lerp(V2f a, V2f b, V2f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    return a;
}

LADEF V2f v2f_floor(V2f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return a;
}

LADEF V2f v2f_ceil(V2f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return a;
}

LADEF V2f v2f_clamp(V2f x, V2f a, V2f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    return x;
}

LADEF float v2f_sqrlen(V2f a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF float v2f_len(V2f a)
{
    return sqrtf(v2f_sqrlen(a));
}

LADEF V2f v2f_normalize(V2f a)
{
    V2f r;
    float len = v2f_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    return r;
}

LADEF float v2f_dot(V2f a, V2f b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2d v2d(double x, double y)
{
    V2d v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2d v2dd(double x)
{
    return v2d(x, x);
}

LADEF V2d v2d2f(V2f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d2i(V2i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d2u(V2u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d3f(V3f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d3d(V3d a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d3i(V3i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d3u(V3u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d4f(V4f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d4d(V4d a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d4i(V4i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d4u(V4u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF V2d v2d_sum(V2d a, V2d b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2d v2d_sub(V2d a, V2d b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2d v2d_mul(V2d a, V2d b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2d v2d_div(V2d a, V2d b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2d v2d_mod(V2d a, V2d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    return a;
}

LADEF V2d v2d_sqrt(V2d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    return a;
}

LADEF V2d v2d_pow(V2d base, V2d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    return base;
}

LADEF V2d v2d_sin(V2d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    return a;
}

LADEF V2d v2d_cos(V2d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    return a;
}

LADEF V2d v2d_min(V2d a, V2d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    return a;
}

LADEF V2d v2d_max(V2d a, V2d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    return a;
}

LADEF V2d v2d_lerp(V2d a, V2d b, V2d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    return a;
}

LADEF V2d v2d_floor(V2d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    return a;
}

LADEF V2d v2d_ceil(V2d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    return a;
}

LADEF V2d v2d_clamp(V2d x, V2d a, V2d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    return x;
}

LADEF double v2d_sqrlen(V2d a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF double v2d_len(V2d a)
{
    return sqrt(v2d_sqrlen(a));
}

LADEF V2d v2d_normalize(V2d a)
{
    V2d r;
    double len = v2d_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    return r;
}

LADEF double v2d_dot(V2d a, V2d b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2i v2i(int x, int y)
{
    V2i v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2i v2ii(int x)
{
    return v2i(x, x);
}

LADEF V2i v2i2f(V2f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i2d(V2d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i2u(V2u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i3f(V3f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i3d(V3d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i3i(V3i a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i3u(V3u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i4f(V4f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i4d(V4d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i4i(V4i a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i4u(V4u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF V2i v2i_sum(V2i a, V2i b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2i v2i_sub(V2i a, V2i b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2i v2i_mul(V2i a, V2i b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2i v2i_div(V2i a, V2i b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2i v2i_mod(V2i a, V2i b)
{
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

LADEF V2i v2i_min(V2i a, V2i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    return a;
}

LADEF V2i v2i_max(V2i a, V2i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    return a;
}

LADEF V2i v2i_clamp(V2i x, V2i a, V2i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    return x;
}

LADEF int v2i_sqrlen(V2i a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF int v2i_dot(V2i a, V2i b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2u v2u(unsigned int x, unsigned int y)
{
    V2u v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2u v2uu(unsigned int x)
{
    return v2u(x, x);
}

LADEF V2u v2u2f(V2f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u2d(V2d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u2i(V2i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u3f(V3f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u3d(V3d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u3i(V3i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u3u(V3u a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u4f(V4f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u4d(V4d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u4i(V4i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u4u(V4u a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF V2u v2u_sum(V2u a, V2u b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2u v2u_sub(V2u a, V2u b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2u v2u_mul(V2u a, V2u b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2u v2u_div(V2u a, V2u b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2u v2u_mod(V2u a, V2u b)
{
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

LADEF V2u v2u_min(V2u a, V2u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    return a;
}

LADEF V2u v2u_max(V2u a, V2u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    return a;
}

LADEF V2u v2u_clamp(V2u x, V2u a, V2u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    return x;
}

LADEF unsigned int v2u_sqrlen(V2u a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF unsigned int v2u_dot(V2u a, V2u b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V3f v3f(float x, float y, float z)
{
    V3f v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3f v3ff(float x)
{
    return v3f(x, x, x);
}

LADEF V3f v3f2f(V2f a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF V3f v3f2d(V2d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF V3f v3f2i(V2i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF V3f v3f2u(V2u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF V3f v3f3d(V3d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f3i(V3i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f3u(V3u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f4f(V4f a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f4d(V4d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f4i(V4i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f4u(V4u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF V3f v3f_sum(V3f a, V3f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3f v3f_sub(V3f a, V3f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3f v3f_mul(V3f a, V3f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3f v3f_div(V3f a, V3f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3f v3f_mod(V3f a, V3f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    a.z = fmodf(a.z, b.z);
    return a;
}

LADEF V3f v3f_sqrt(V3f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    return a;
}

LADEF V3f v3f_pow(V3f base, V3f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    return base;
}

LADEF V3f v3f_sin(V3f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    return a;
}

LADEF V3f v3f_cos(V3f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    return a;
}

LADEF V3f v3f_min(V3f a, V3f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    return a;
}

LADEF V3f v3f_max(V3f a, V3f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    return a;
}

LADEF V3f v3f_lerp(V3f a, V3f b, V3f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    return a;
}

LADEF V3f v3f_floor(V3f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    return a;
}

LADEF V3f v3f_ceil(V3f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    return a;
}

LADEF V3f v3f_clamp(V3f x, V3f a, V3f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    x.z = clampf(x.z, a.z, b.z);
    return x;
}

LADEF float v3f_sqrlen(V3f a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF float v3f_len(V3f a)
{
    return sqrtf(v3f_sqrlen(a));
}

LADEF V3f v3f_normalize(V3f a)
{
    V3f r;
    float len = v3f_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    r.z = a.z / len;
    return r;
}

LADEF float v3f_dot(V3f a, V3f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3f v3f_cross(V3f a, V3f b)
{
    V3f r;
    r.x = a.y*b.z - a.z*b.y;
    r.y = a.z*b.x - a.x*b.z;
    r.z = a.x*b.y - a.y*b.x;
    return r;
}

LADEF V3f v3f_normal_from_points(V3f a, V3f b, V3f c)
{
    V3f u = v3f_sub(b, a);
    V3f v = v3f_sub(c, a);
    V3f n = v3f_cross(u, v);
    return v3f_normalize(n);
}

LADEF V3d v3d(double x, double y, double z)
{
    V3d v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3d v3dd(double x)
{
    return v3d(x, x, x);
}

LADEF V3d v3d2f(V2f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF V3d v3d2d(V2d a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF V3d v3d2i(V2i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF V3d v3d2u(V2u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF V3d v3d3f(V3f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d3i(V3i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d3u(V3u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d4f(V4f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d4d(V4d a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d4i(V4i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d4u(V4u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF V3d v3d_sum(V3d a, V3d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3d v3d_sub(V3d a, V3d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3d v3d_mul(V3d a, V3d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3d v3d_div(V3d a, V3d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3d v3d_mod(V3d a, V3d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    a.z = fmod(a.z, b.z);
    return a;
}

LADEF V3d v3d_sqrt(V3d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    return a;
}

LADEF V3d v3d_pow(V3d base, V3d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    return base;
}

LADEF V3d v3d_sin(V3d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    return a;
}

LADEF V3d v3d_cos(V3d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    return a;
}

LADEF V3d v3d_min(V3d a, V3d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    return a;
}

LADEF V3d v3d_max(V3d a, V3d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    return a;
}

LADEF V3d v3d_lerp(V3d a, V3d b, V3d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    return a;
}

LADEF V3d v3d_floor(V3d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    return a;
}

LADEF V3d v3d_ceil(V3d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    return a;
}

LADEF V3d v3d_clamp(V3d x, V3d a, V3d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    x.z = clampd(x.z, a.z, b.z);
    return x;
}

LADEF double v3d_sqrlen(V3d a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF double v3d_len(V3d a)
{
    return sqrt(v3d_sqrlen(a));
}

LADEF V3d v3d_normalize(V3d a)
{
    V3d r;
    double len = v3d_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    r.z = a.z / len;
    return r;
}

LADEF double v3d_dot(V3d a, V3d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3d v3d_cross(V3d a, V3d b)
{
    V3d r;
    r.x = a.y*b.z - a.z*b.y;
    r.y = a.z*b.x - a.x*b.z;
    r.z = a.x*b.y - a.y*b.x;
    return r;
}

LADEF V3d v3d_normal_from_points(V3d a, V3d b, V3d c)
{
    V3d u = v3d_sub(b, a);
    V3d v = v3d_sub(c, a);
    V3d n = v3d_cross(u, v);
    return v3d_normalize(n);
}

LADEF V3i v3i(int x, int y, int z)
{
    V3i v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3i v3ii(int x)
{
    return v3i(x, x, x);
}

LADEF V3i v3i2f(V2f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF V3i v3i2d(V2d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF V3i v3i2i(V2i a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF V3i v3i2u(V2u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF V3i v3i3f(V3f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i3d(V3d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i3u(V3u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i4f(V4f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i4d(V4d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i4i(V4i a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i4u(V4u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF V3i v3i_sum(V3i a, V3i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3i v3i_sub(V3i a, V3i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3i v3i_mul(V3i a, V3i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3i v3i_div(V3i a, V3i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3i v3i_mod(V3i a, V3i b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    return a;
}

LADEF V3i v3i_min(V3i a, V3i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    a.z = mini(a.z, b.z);
    return a;
}

LADEF V3i v3i_max(V3i a, V3i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    a.z = maxi(a.z, b.z);
    return a;
}

LADEF V3i v3i_clamp(V3i x, V3i a, V3i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    x.z = clampi(x.z, a.z, b.z);
    return x;
}

LADEF int v3i_sqrlen(V3i a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF int v3i_dot(V3i a, V3i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3i v3i_cross(V3i a, V3i b)
{
    V3i r;
    r.x = a.y*b.z - a.z*b.y;
    r.y = a.z*b.x - a.x*b.z;
    r.z = a.x*b.y - a.y*b.x;
    return r;
}

LADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z)
{
    V3u v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3u v3uu(unsigned int x)
{
    return v3u(x, x, x);
}

LADEF V3u v3u2f(V2f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF V3u v3u2d(V2d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF V3u v3u2i(V2i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF V3u v3u2u(V2u a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF V3u v3u3f(V3f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u3d(V3d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u3i(V3i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u4f(V4f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u4d(V4d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u4i(V4i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u4u(V4u a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF V3u v3u_sum(V3u a, V3u b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3u v3u_sub(V3u a, V3u b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3u v3u_mul(V3u a, V3u b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3u v3u_div(V3u a, V3u b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3u v3u_mod(V3u a, V3u b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    return a;
}

LADEF V3u v3u_min(V3u a, V3u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    a.z = minu(a.z, b.z);
    return a;
}

LADEF V3u v3u_max(V3u a, V3u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    a.z = maxu(a.z, b.z);
    return a;
}

LADEF V3u v3u_clamp(V3u x, V3u a, V3u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    x.z = clampu(x.z, a.z, b.z);
    return x;
}

LADEF unsigned int v3u_sqrlen(V3u a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF unsigned int v3u_dot(V3u a, V3u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3u v3u_cross(V3u a, V3u b)
{
    V3u r;
    r.x = a.y*b.z - a.z*b.y;
    r.y = a.z*b.x - a.x*b.z;
    r.z = a.x*b.y - a.y*b.x;
    return r;
}

LADEF V4f v4f(float x, float y, float z, float w)
{
    V4f v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4f v4ff(float x)
{
    return v4f(x, x, x, x);
}

LADEF V4f v4f2f(V2f a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f2d(V2d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f2i(V2i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f2u(V2u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f3f(V3f a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f3d(V3d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f3i(V3i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f3u(V3u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF V4f v4f4d(V4d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF V4f v4f4i(V4i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF V4f v4f4u(V4u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF V4f v4f_sum(V4f a, V4f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4f v4f_sub(V4f a, V4f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4f v4f_mul(V4f a, V4f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4f v4f_div(V4f a, V4f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4f v4f_mod(V4f a, V4f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    a.z = fmodf(a.z, b.z);
    a.w = fmodf(a.w, b.w);
    return a;
}

LADEF V4f v4f_sqrt(V4f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    a.w = sqrtf(a.w);
    return a;
}

LADEF V4f v4f_pow(V4f base, V4f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    base.w = powf(base.w, exp.w);
    return base;
}

LADEF V4f v4f_sin(V4f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    a.w = sinf(a.w);
    return a;
}

LADEF V4f v4f_cos(V4f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    a.w = cosf(a.w);
    return a;
}

LADEF V4f v4f_min(V4f a, V4f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    a.w = fminf(a.w, b.w);
    return a;
}

LADEF V4f v4f_max(V4f a, V4f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    a.w = fmaxf(a.w, b.w);
    return a;
}

LADEF V4f v4f_lerp(V4f a, V4f b, V4f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    a.w = lerpf(a.w, b.w, t.w);
    return a;
}

LADEF V4f v4f_floor(V4f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    a.w = floorf(a.w);
    return a;
}

LADEF V4f v4f_ceil(V4f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    a.w = ceilf(a.w);
    return a;
}

LADEF V4f v4f_clamp(V4f x, V4f a, V4f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    x.z = clampf(x.z, a.z, b.z);
    x.w = clampf(x.w, a.w, b.w);
    return x;
}

LADEF float v4f_sqrlen(V4f a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF float v4f_len(V4f a)
{
    return sqrtf(v4f_sqrlen(a));
}

LADEF V4f v4f_normalize(V4f a)
{
    V4f r;
    float len = v4f_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    r.z = a.z / len;
    r.w = a.w / len;
    return r;
}

LADEF float v4f_dot(V4f a, V4f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4d v4d(double x, double y, double z, double w)
{
    V4d v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4d v4dd(double x)
{
    return v4d(x, x, x, x);
}

LADEF V4d v4d2f(V2f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d2d(V2d a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d2i(V2i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d2u(V2u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d3f(V3f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d3d(V3d a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d3i(V3i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d3u(V3u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF V4d v4d4f(V4f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF V4d v4d4i(V4i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF V4d v4d4u(V4u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF V4d v4d_sum(V4d a, V4d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4d v4d_sub(V4d a, V4d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4d v4d_mul(V4d a, V4d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4d v4d_div(V4d a, V4d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4d v4d_mod(V4d a, V4d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    a.z = fmod(a.z, b.z);
    a.w = fmod(a.w, b.w);
    return a;
}

LADEF V4d v4d_sqrt(V4d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    a.w = sqrt(a.w);
    return a;
}

LADEF V4d v4d_pow(V4d base, V4d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    base.w = pow(base.w, exp.w);
    return base;
}

LADEF V4d v4d_sin(V4d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    a.w = sin(a.w);
    return a;
}

LADEF V4d v4d_cos(V4d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    a.w = cos(a.w);
    return a;
}

LADEF V4d v4d_min(V4d a, V4d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    a.w = fmin(a.w, b.w);
    return a;
}

LADEF V4d v4d_max(V4d a, V4d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    a.w = fmax(a.w, b.w);
    return a;
}

LADEF V4d v4d_lerp(V4d a, V4d b, V4d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    a.w = lerp(a.w, b.w, t.w);
    return a;
}

LADEF V4d v4d_floor(V4d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    a.w = floor(a.w);
    return a;
}

LADEF V4d v4d_ceil(V4d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    a.w = ceil(a.w);
    return a;
}

LADEF V4d v4d_clamp(V4d x, V4d a, V4d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    x.z = clampd(x.z, a.z, b.z);
    x.w = clampd(x.w, a.w, b.w);
    return x;
}

LADEF double v4d_sqrlen(V4d a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF double v4d_len(V4d a)
{
    return sqrt(v4d_sqrlen(a));
}

LADEF V4d v4d_normalize(V4d a)
{
    V4d r;
    double len = v4d_len(a);
    r.x = a.x / len;
    r.y = a.y / len;
    r.z = a.z / len;
    r.w = a.w / len;
    return r;
}

LADEF double v4d_dot(V4d a, V4d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4i v4i(int x, int y, int z, int w)
{
    V4i v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4i v4ii(int x)
{
    return v4i(x, x, x, x);
}

LADEF V4i v4i2f(V2f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF V4i v4i2d(V2d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF V4i v4i2i(V2i a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF V4i v4i2u(V2u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF V4i v4i3f(V3f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF V4i v4i3d(V3d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF V4i v4i3i(V3i a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF V4i v4i3u(V3u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF V4i v4i4f(V4f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF V4i v4i4d(V4d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF V4i v4i4u(V4u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF V4i v4i_sum(V4i a, V4i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4i v4i_sub(V4i a, V4i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4i v4i_mul(V4i a, V4i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4i v4i_div(V4i a, V4i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4i v4i_mod(V4i a, V4i b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    a.w %= b.w;
    return a;
}

LADEF V4i v4i_min(V4i a, V4i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    a.z = mini(a.z, b.z);
    a.w = mini(a.w, b.w);
    return a;
}

LADEF V4i v4i_max(V4i a, V4i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    a.z = maxi(a.z, b.z);
    a.w = maxi(a.w, b.w);
    return a;
}

LADEF V4i v4i_clamp(V4i x, V4i a, V4i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    x.z = clampi(x.z, a.z, b.z);
    x.w = clampi(x.w, a.w, b.w);
    return x;
}

LADEF int v4i_sqrlen(V4i a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF int v4i_dot(V4i a, V4i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w)
{
    V4u v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4u v4uu(unsigned int x)
{
    return v4u(x, x, x, x);
}

LADEF V4u v4u2f(V2f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF V4u v4u2d(V2d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF V4u v4u2i(V2i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF V4u v4u2u(V2u a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF V4u v4u3f(V3f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF V4u v4u3d(V3d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF V4u v4u3i(V3i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF V4u v4u3u(V3u a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF V4u v4u4f(V4f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF V4u v4u4d(V4d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF V4u v4u4i(V4i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF V4u v4u_sum(V4u a, V4u b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4u v4u_sub(V4u a, V4u b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4u v4u_mul(V4u a, V4u b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4u v4u_div(V4u a, V4u b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4u v4u_mod(V4u a, V4u b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    a.w %= b.w;
    return a;
}

LADEF V4u v4u_min(V4u a, V4u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    a.z = minu(a.z, b.z);
    a.w = minu(a.w, b.w);
    return a;
}

LADEF V4u v4u_max(V4u a, V4u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    a.z = maxu(a.z, b.z);
    a.w = maxu(a.w, b.w);
    return a;
}

LADEF V4u v4u_clamp(V4u x, V4u a, V4u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    x.z = clampu(x.z, a.z, b.z);
    x.w = clampu(x.w, a.w, b.w);
    return x;
}

LADEF unsigned int v4u_sqrlen(V4u a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF unsigned int v4u_dot(V4u a, V4u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF M2x2f m2x2f(float m00, float m01, float m10, float m11)
{
    M2x2f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    return m;
}

LADEF M2x2f m2x2ff(float s)
{
    M2x2f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    return m;
}

LADEF M2x2f m2x2f_identity(void)
{
    M2x2f m;
    m.rc[0][0] = 0.0f;
    m.rc[0][1] = 0.0f;
    m.rc[1][0] = 0.0f;
    m.rc[1][1] = 0.0f;
    m.rc[0][0] = 1.0f;
    m.rc[1][1] = 1.0f;
    return m;
}

LADEF float m2x2f_det(M2x2f m)
{
    float a[2][2];
    for (size_t i = 0; i < 2; ++i) for (size_t j = 0; j < 2; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    float det = 1.0f;
    for (size_t i = 0; i < 2; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 2; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        if (fabsf(a[pivot][i]) < 1e-6f) return 0.0f;
        if (pivot != i) {
            for (size_t c = 0; c < 2; ++c) { float tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 2; ++r) {
            float f = a[r][i] / a[i][i];
            for (size_t c = i; c < 2; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 2; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M2x2f m2x2f_inverse(M2x2f m)
{
    float a[2][2];
    M2x2f inv;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0f; }
        inv.rc[i][i] = 1.0f;
    }
    for (size_t i = 0; i < 2; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 2; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        float piv = a[pivot][i];
        if (fabsf(piv) < 1e-6f) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 2; ++c) { float ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; float ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        float inv_piv = (float)1 / a[i][i];
        for (size_t c = 0; c < 2; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 2; ++r) if (r != i) { float f = a[r][i]; if (fabsf(f) > 0) { for (size_t c = 0; c < 2; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M2x2f m2x2f2x2d(M2x2d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x2i(M2x2i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x2u(M2x2u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x3f(M2x3f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x3d(M2x3d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x3i(M2x3i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x3u(M2x3u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x4f(M2x4f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x4d(M2x4d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x4i(M2x4i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f2x4u(M2x4u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x2f(M3x2f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x2d(M3x2d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x2i(M3x2i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x2u(M3x2u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x3f(M3x3f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x3d(M3x3d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x3i(M3x3i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x3u(M3x3u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x4f(M3x4f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x4d(M3x4d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x4i(M3x4i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f3x4u(M3x4u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x2f(M4x2f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x2d(M4x2d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x2i(M4x2i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x2u(M4x2u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x3f(M4x3f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x3d(M4x3d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x3i(M4x3i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x3u(M4x3u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x4f(M4x4f a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x4d(M4x4d a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x4i(M4x4i a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f4x4u(M4x4u a)
{
    M2x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    return result;
}

LADEF M2x2f m2x2f_sum(M2x2f a, M2x2f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    return a;
}

LADEF M2x2f m2x2f_sub(M2x2f a, M2x2f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    return a;
}

LADEF M2x2f m2x2f_mul(M2x2f a, M2x2f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    return a;
}

LADEF M2x2f m2x2f_div(M2x2f a, M2x2f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    return a;
}

LADEF M2x2f m2x2f_mod(M2x2f a, M2x2f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    return a;
}

LADEF M2x2f m2x2f_transpose(M2x2f a)
{
    M2x2f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    return r;
}

LADEF M2x2f m2x2f_mmul_m2x2f(M2x2f a, M2x2f b)
{
    M2x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3f m2x2f_mmul_m2x3f(M2x2f a, M2x3f b)
{
    M2x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4f m2x2f_mmul_m2x4f(M2x2f a, M2x4f b)
{
    M2x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2f m2x2f_mul_v2f(M2x2f m, V2f v)
{
    V2f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    return r;
}

LADEF M2x2d m2x2d(double m00, double m01, double m10, double m11)
{
    M2x2d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    return m;
}

LADEF M2x2d m2x2dd(double s)
{
    M2x2d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    return m;
}

LADEF M2x2d m2x2d_identity(void)
{
    M2x2d m;
    m.rc[0][0] = 0.0;
    m.rc[0][1] = 0.0;
    m.rc[1][0] = 0.0;
    m.rc[1][1] = 0.0;
    m.rc[0][0] = 1.0;
    m.rc[1][1] = 1.0;
    return m;
}

LADEF double m2x2d_det(M2x2d m)
{
    double a[2][2];
    for (size_t i = 0; i < 2; ++i) for (size_t j = 0; j < 2; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    double det = 1.0;
    for (size_t i = 0; i < 2; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 2; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        if (fabs(a[pivot][i]) < 1e-12) return 0.0;
        if (pivot != i) {
            for (size_t c = 0; c < 2; ++c) { double tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 2; ++r) {
            double f = a[r][i] / a[i][i];
            for (size_t c = i; c < 2; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 2; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M2x2d m2x2d_inverse(M2x2d m)
{
    double a[2][2];
    M2x2d inv;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0; }
        inv.rc[i][i] = 1.0;
    }
    for (size_t i = 0; i < 2; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 2; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        double piv = a[pivot][i];
        if (fabs(piv) < 1e-12) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 2; ++c) { double ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; double ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        double inv_piv = (double)1 / a[i][i];
        for (size_t c = 0; c < 2; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 2; ++r) if (r != i) { double f = a[r][i]; if (fabs(f) > 0) { for (size_t c = 0; c < 2; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M2x2d m2x2d2x2f(M2x2f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x2i(M2x2i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x2u(M2x2u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x3f(M2x3f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x3d(M2x3d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x3i(M2x3i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x3u(M2x3u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x4f(M2x4f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x4d(M2x4d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x4i(M2x4i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d2x4u(M2x4u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x2f(M3x2f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x2d(M3x2d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x2i(M3x2i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x2u(M3x2u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x3f(M3x3f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x3d(M3x3d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x3i(M3x3i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x3u(M3x3u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x4f(M3x4f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x4d(M3x4d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x4i(M3x4i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d3x4u(M3x4u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x2f(M4x2f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x2d(M4x2d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x2i(M4x2i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x2u(M4x2u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x3f(M4x3f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x3d(M4x3d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x3i(M4x3i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x3u(M4x3u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x4f(M4x4f a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x4d(M4x4d a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x4i(M4x4i a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d4x4u(M4x4u a)
{
    M2x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    return result;
}

LADEF M2x2d m2x2d_sum(M2x2d a, M2x2d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    return a;
}

LADEF M2x2d m2x2d_sub(M2x2d a, M2x2d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    return a;
}

LADEF M2x2d m2x2d_mul(M2x2d a, M2x2d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    return a;
}

LADEF M2x2d m2x2d_div(M2x2d a, M2x2d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    return a;
}

LADEF M2x2d m2x2d_mod(M2x2d a, M2x2d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    return a;
}

LADEF M2x2d m2x2d_transpose(M2x2d a)
{
    M2x2d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    return r;
}

LADEF M2x2d m2x2d_mmul_m2x2d(M2x2d a, M2x2d b)
{
    M2x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3d m2x2d_mmul_m2x3d(M2x2d a, M2x3d b)
{
    M2x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4d m2x2d_mmul_m2x4d(M2x2d a, M2x4d b)
{
    M2x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2d m2x2d_mul_v2d(M2x2d m, V2d v)
{
    V2d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    return r;
}

LADEF M2x2i m2x2i(int m00, int m01, int m10, int m11)
{
    M2x2i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    return m;
}

LADEF M2x2i m2x2ii(int s)
{
    M2x2i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    return m;
}

LADEF M2x2i m2x2i_identity(void)
{
    M2x2i m;
    m.rc[0][0] = 0;
    m.rc[0][1] = 0;
    m.rc[1][0] = 0;
    m.rc[1][1] = 0;
    m.rc[0][0] = 1;
    m.rc[1][1] = 1;
    return m;
}



LADEF M2x2i m2x2i2x2f(M2x2f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x2d(M2x2d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x2u(M2x2u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x3f(M2x3f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x3d(M2x3d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x3i(M2x3i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x3u(M2x3u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x4f(M2x4f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x4d(M2x4d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x4i(M2x4i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i2x4u(M2x4u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x2f(M3x2f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x2d(M3x2d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x2i(M3x2i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x2u(M3x2u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x3f(M3x3f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x3d(M3x3d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x3i(M3x3i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x3u(M3x3u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x4f(M3x4f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x4d(M3x4d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x4i(M3x4i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i3x4u(M3x4u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x2f(M4x2f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x2d(M4x2d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x2i(M4x2i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x2u(M4x2u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x3f(M4x3f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x3d(M4x3d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x3i(M4x3i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x3u(M4x3u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x4f(M4x4f a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x4d(M4x4d a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x4i(M4x4i a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i4x4u(M4x4u a)
{
    M2x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    return result;
}

LADEF M2x2i m2x2i_sum(M2x2i a, M2x2i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    return a;
}

LADEF M2x2i m2x2i_sub(M2x2i a, M2x2i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    return a;
}

LADEF M2x2i m2x2i_mul(M2x2i a, M2x2i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    return a;
}

LADEF M2x2i m2x2i_div(M2x2i a, M2x2i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    return a;
}

LADEF M2x2i m2x2i_mod(M2x2i a, M2x2i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    return a;
}

LADEF M2x2i m2x2i_transpose(M2x2i a)
{
    M2x2i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    return r;
}

LADEF M2x2i m2x2i_mmul_m2x2i(M2x2i a, M2x2i b)
{
    M2x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3i m2x2i_mmul_m2x3i(M2x2i a, M2x3i b)
{
    M2x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4i m2x2i_mmul_m2x4i(M2x2i a, M2x4i b)
{
    M2x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2i m2x2i_mul_v2i(M2x2i m, V2i v)
{
    V2i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    return r;
}

LADEF M2x2u m2x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11)
{
    M2x2u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    return m;
}

LADEF M2x2u m2x2uu(unsigned int s)
{
    M2x2u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    return m;
}

LADEF M2x2u m2x2u_identity(void)
{
    M2x2u m;
    m.rc[0][0] = 0u;
    m.rc[0][1] = 0u;
    m.rc[1][0] = 0u;
    m.rc[1][1] = 0u;
    m.rc[0][0] = 1u;
    m.rc[1][1] = 1u;
    return m;
}



LADEF M2x2u m2x2u2x2f(M2x2f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x2d(M2x2d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x2i(M2x2i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x3f(M2x3f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x3d(M2x3d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x3i(M2x3i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x3u(M2x3u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x4f(M2x4f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x4d(M2x4d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x4i(M2x4i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u2x4u(M2x4u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x2f(M3x2f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x2d(M3x2d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x2i(M3x2i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x2u(M3x2u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x3f(M3x3f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x3d(M3x3d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x3i(M3x3i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x3u(M3x3u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x4f(M3x4f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x4d(M3x4d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x4i(M3x4i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u3x4u(M3x4u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x2f(M4x2f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x2d(M4x2d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x2i(M4x2i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x2u(M4x2u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x3f(M4x3f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x3d(M4x3d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x3i(M4x3i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x3u(M4x3u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x4f(M4x4f a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x4d(M4x4d a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x4i(M4x4i a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u4x4u(M4x4u a)
{
    M2x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    return result;
}

LADEF M2x2u m2x2u_sum(M2x2u a, M2x2u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    return a;
}

LADEF M2x2u m2x2u_sub(M2x2u a, M2x2u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    return a;
}

LADEF M2x2u m2x2u_mul(M2x2u a, M2x2u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    return a;
}

LADEF M2x2u m2x2u_div(M2x2u a, M2x2u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    return a;
}

LADEF M2x2u m2x2u_mod(M2x2u a, M2x2u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    return a;
}

LADEF M2x2u m2x2u_transpose(M2x2u a)
{
    M2x2u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    return r;
}

LADEF M2x2u m2x2u_mmul_m2x2u(M2x2u a, M2x2u b)
{
    M2x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3u m2x2u_mmul_m2x3u(M2x2u a, M2x3u b)
{
    M2x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4u m2x2u_mmul_m2x4u(M2x2u a, M2x4u b)
{
    M2x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2u m2x2u_mul_v2u(M2x2u m, V2u v)
{
    V2u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    return r;
}

LADEF M2x3f m2x3f(float m00, float m01, float m02, float m10, float m11, float m12)
{
    M2x3f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    return m;
}

LADEF M2x3f m2x3ff(float s)
{
    M2x3f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    return m;
}

LADEF M2x3f m2x3f2x2f(M2x2f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f2x2d(M2x2d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f2x2i(M2x2i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f2x2u(M2x2u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f2x3d(M2x3d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x3i(M2x3i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x3u(M2x3u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x4f(M2x4f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x4d(M2x4d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x4i(M2x4i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f2x4u(M2x4u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x2f(M3x2f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f3x2d(M3x2d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f3x2i(M3x2i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f3x2u(M3x2u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f3x3f(M3x3f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x3d(M3x3d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x3i(M3x3i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x3u(M3x3u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x4f(M3x4f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x4d(M3x4d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x4i(M3x4i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f3x4u(M3x4u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x2f(M4x2f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f4x2d(M4x2d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f4x2i(M4x2i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f4x2u(M4x2u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    return result;
}

LADEF M2x3f m2x3f4x3f(M4x3f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x3d(M4x3d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x3i(M4x3i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x3u(M4x3u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x4f(M4x4f a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x4d(M4x4d a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x4i(M4x4i a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f4x4u(M4x4u a)
{
    M2x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    return result;
}

LADEF M2x3f m2x3f_sum(M2x3f a, M2x3f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    return a;
}

LADEF M2x3f m2x3f_sub(M2x3f a, M2x3f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    return a;
}

LADEF M2x3f m2x3f_mul(M2x3f a, M2x3f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    return a;
}

LADEF M2x3f m2x3f_div(M2x3f a, M2x3f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    return a;
}

LADEF M2x3f m2x3f_mod(M2x3f a, M2x3f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    return a;
}

LADEF M3x2f m2x3f_transpose(M2x3f a)
{
    M3x2f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    return r;
}

LADEF M2x2f m2x3f_mmul_m3x2f(M2x3f a, M3x2f b)
{
    M2x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3f m2x3f_mmul_m3x3f(M2x3f a, M3x3f b)
{
    M2x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4f m2x3f_mmul_m3x4f(M2x3f a, M3x4f b)
{
    M2x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2f m2x3f_mul_v3f(M2x3f m, V3f v)
{
    V2f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    return r;
}

LADEF M2x3d m2x3d(double m00, double m01, double m02, double m10, double m11, double m12)
{
    M2x3d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    return m;
}

LADEF M2x3d m2x3dd(double s)
{
    M2x3d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    return m;
}

LADEF M2x3d m2x3d2x2f(M2x2f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d2x2d(M2x2d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d2x2i(M2x2i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d2x2u(M2x2u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d2x3f(M2x3f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x3i(M2x3i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x3u(M2x3u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x4f(M2x4f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x4d(M2x4d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x4i(M2x4i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d2x4u(M2x4u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x2f(M3x2f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d3x2d(M3x2d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d3x2i(M3x2i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d3x2u(M3x2u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d3x3f(M3x3f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x3d(M3x3d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x3i(M3x3i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x3u(M3x3u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x4f(M3x4f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x4d(M3x4d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x4i(M3x4i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d3x4u(M3x4u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x2f(M4x2f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d4x2d(M4x2d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d4x2i(M4x2i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d4x2u(M4x2u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    return result;
}

LADEF M2x3d m2x3d4x3f(M4x3f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x3d(M4x3d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x3i(M4x3i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x3u(M4x3u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x4f(M4x4f a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x4d(M4x4d a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x4i(M4x4i a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d4x4u(M4x4u a)
{
    M2x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    return result;
}

LADEF M2x3d m2x3d_sum(M2x3d a, M2x3d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    return a;
}

LADEF M2x3d m2x3d_sub(M2x3d a, M2x3d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    return a;
}

LADEF M2x3d m2x3d_mul(M2x3d a, M2x3d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    return a;
}

LADEF M2x3d m2x3d_div(M2x3d a, M2x3d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    return a;
}

LADEF M2x3d m2x3d_mod(M2x3d a, M2x3d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    return a;
}

LADEF M3x2d m2x3d_transpose(M2x3d a)
{
    M3x2d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    return r;
}

LADEF M2x2d m2x3d_mmul_m3x2d(M2x3d a, M3x2d b)
{
    M2x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3d m2x3d_mmul_m3x3d(M2x3d a, M3x3d b)
{
    M2x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4d m2x3d_mmul_m3x4d(M2x3d a, M3x4d b)
{
    M2x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2d m2x3d_mul_v3d(M2x3d m, V3d v)
{
    V2d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    return r;
}

LADEF M2x3i m2x3i(int m00, int m01, int m02, int m10, int m11, int m12)
{
    M2x3i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    return m;
}

LADEF M2x3i m2x3ii(int s)
{
    M2x3i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    return m;
}

LADEF M2x3i m2x3i2x2f(M2x2f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i2x2d(M2x2d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i2x2i(M2x2i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i2x2u(M2x2u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i2x3f(M2x3f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x3d(M2x3d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x3u(M2x3u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x4f(M2x4f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x4d(M2x4d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x4i(M2x4i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i2x4u(M2x4u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x2f(M3x2f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i3x2d(M3x2d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i3x2i(M3x2i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i3x2u(M3x2u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i3x3f(M3x3f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x3d(M3x3d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x3i(M3x3i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x3u(M3x3u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x4f(M3x4f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x4d(M3x4d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x4i(M3x4i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i3x4u(M3x4u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x2f(M4x2f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i4x2d(M4x2d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i4x2i(M4x2i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i4x2u(M4x2u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    return result;
}

LADEF M2x3i m2x3i4x3f(M4x3f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x3d(M4x3d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x3i(M4x3i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x3u(M4x3u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x4f(M4x4f a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x4d(M4x4d a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x4i(M4x4i a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i4x4u(M4x4u a)
{
    M2x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    return result;
}

LADEF M2x3i m2x3i_sum(M2x3i a, M2x3i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    return a;
}

LADEF M2x3i m2x3i_sub(M2x3i a, M2x3i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    return a;
}

LADEF M2x3i m2x3i_mul(M2x3i a, M2x3i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    return a;
}

LADEF M2x3i m2x3i_div(M2x3i a, M2x3i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    return a;
}

LADEF M2x3i m2x3i_mod(M2x3i a, M2x3i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    return a;
}

LADEF M3x2i m2x3i_transpose(M2x3i a)
{
    M3x2i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    return r;
}

LADEF M2x2i m2x3i_mmul_m3x2i(M2x3i a, M3x2i b)
{
    M2x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3i m2x3i_mmul_m3x3i(M2x3i a, M3x3i b)
{
    M2x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4i m2x3i_mmul_m3x4i(M2x3i a, M3x4i b)
{
    M2x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2i m2x3i_mul_v3i(M2x3i m, V3i v)
{
    V2i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    return r;
}

LADEF M2x3u m2x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12)
{
    M2x3u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    return m;
}

LADEF M2x3u m2x3uu(unsigned int s)
{
    M2x3u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    return m;
}

LADEF M2x3u m2x3u2x2f(M2x2f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u2x2d(M2x2d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u2x2i(M2x2i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u2x2u(M2x2u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u2x3f(M2x3f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x3d(M2x3d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x3i(M2x3i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x4f(M2x4f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x4d(M2x4d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x4i(M2x4i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u2x4u(M2x4u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x2f(M3x2f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u3x2d(M3x2d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u3x2i(M3x2i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u3x2u(M3x2u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u3x3f(M3x3f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x3d(M3x3d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x3i(M3x3i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x3u(M3x3u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x4f(M3x4f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x4d(M3x4d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x4i(M3x4i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u3x4u(M3x4u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x2f(M4x2f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u4x2d(M4x2d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u4x2i(M4x2i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u4x2u(M4x2u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    return result;
}

LADEF M2x3u m2x3u4x3f(M4x3f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x3d(M4x3d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x3i(M4x3i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x3u(M4x3u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x4f(M4x4f a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x4d(M4x4d a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x4i(M4x4i a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u4x4u(M4x4u a)
{
    M2x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    return result;
}

LADEF M2x3u m2x3u_sum(M2x3u a, M2x3u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    return a;
}

LADEF M2x3u m2x3u_sub(M2x3u a, M2x3u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    return a;
}

LADEF M2x3u m2x3u_mul(M2x3u a, M2x3u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    return a;
}

LADEF M2x3u m2x3u_div(M2x3u a, M2x3u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    return a;
}

LADEF M2x3u m2x3u_mod(M2x3u a, M2x3u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    return a;
}

LADEF M3x2u m2x3u_transpose(M2x3u a)
{
    M3x2u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    return r;
}

LADEF M2x2u m2x3u_mmul_m3x2u(M2x3u a, M3x2u b)
{
    M2x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3u m2x3u_mmul_m3x3u(M2x3u a, M3x3u b)
{
    M2x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4u m2x3u_mmul_m3x4u(M2x3u a, M3x4u b)
{
    M2x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2u m2x3u_mul_v3u(M2x3u m, V3u v)
{
    V2u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    return r;
}

LADEF M2x4f m2x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13)
{
    M2x4f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    return m;
}

LADEF M2x4f m2x4ff(float s)
{
    M2x4f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    return m;
}

LADEF M2x4f m2x4f2x2f(M2x2f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x2d(M2x2d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x2i(M2x2i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x2u(M2x2u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x3f(M2x3f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x3d(M2x3d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x3i(M2x3i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x3u(M2x3u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f2x4d(M2x4d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f2x4i(M2x4i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f2x4u(M2x4u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f3x2f(M3x2f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x2d(M3x2d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x2i(M3x2i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x2u(M3x2u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x3f(M3x3f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x3d(M3x3d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x3i(M3x3i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x3u(M3x3u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f3x4f(M3x4f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f3x4d(M3x4d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f3x4i(M3x4i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f3x4u(M3x4u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f4x2f(M4x2f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x2d(M4x2d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x2i(M4x2i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x2u(M4x2u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x3f(M4x3f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x3d(M4x3d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x3i(M4x3i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x3u(M4x3u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    return result;
}

LADEF M2x4f m2x4f4x4f(M4x4f a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f4x4d(M4x4d a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f4x4i(M4x4i a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f4x4u(M4x4u a)
{
    M2x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    return result;
}

LADEF M2x4f m2x4f_sum(M2x4f a, M2x4f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    return a;
}

LADEF M2x4f m2x4f_sub(M2x4f a, M2x4f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    return a;
}

LADEF M2x4f m2x4f_mul(M2x4f a, M2x4f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    return a;
}

LADEF M2x4f m2x4f_div(M2x4f a, M2x4f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    return a;
}

LADEF M2x4f m2x4f_mod(M2x4f a, M2x4f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmodf(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmodf(a.rc[1][3], b.rc[1][3]);
    return a;
}

LADEF M4x2f m2x4f_transpose(M2x4f a)
{
    M4x2f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    return r;
}

LADEF M2x2f m2x4f_mmul_m4x2f(M2x4f a, M4x2f b)
{
    M2x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3f m2x4f_mmul_m4x3f(M2x4f a, M4x3f b)
{
    M2x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4f m2x4f_mmul_m4x4f(M2x4f a, M4x4f b)
{
    M2x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2f m2x4f_mul_v4f(M2x4f m, V4f v)
{
    V2f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    return r;
}

LADEF M2x4d m2x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13)
{
    M2x4d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    return m;
}

LADEF M2x4d m2x4dd(double s)
{
    M2x4d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    return m;
}

LADEF M2x4d m2x4d2x2f(M2x2f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x2d(M2x2d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x2i(M2x2i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x2u(M2x2u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x3f(M2x3f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x3d(M2x3d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x3i(M2x3i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x3u(M2x3u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d2x4f(M2x4f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d2x4i(M2x4i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d2x4u(M2x4u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d3x2f(M3x2f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x2d(M3x2d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x2i(M3x2i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x2u(M3x2u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x3f(M3x3f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x3d(M3x3d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x3i(M3x3i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x3u(M3x3u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d3x4f(M3x4f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d3x4d(M3x4d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d3x4i(M3x4i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d3x4u(M3x4u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d4x2f(M4x2f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x2d(M4x2d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x2i(M4x2i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x2u(M4x2u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x3f(M4x3f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x3d(M4x3d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x3i(M4x3i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x3u(M4x3u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    return result;
}

LADEF M2x4d m2x4d4x4f(M4x4f a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d4x4d(M4x4d a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d4x4i(M4x4i a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d4x4u(M4x4u a)
{
    M2x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    return result;
}

LADEF M2x4d m2x4d_sum(M2x4d a, M2x4d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    return a;
}

LADEF M2x4d m2x4d_sub(M2x4d a, M2x4d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    return a;
}

LADEF M2x4d m2x4d_mul(M2x4d a, M2x4d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    return a;
}

LADEF M2x4d m2x4d_div(M2x4d a, M2x4d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    return a;
}

LADEF M2x4d m2x4d_mod(M2x4d a, M2x4d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmod(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmod(a.rc[1][3], b.rc[1][3]);
    return a;
}

LADEF M4x2d m2x4d_transpose(M2x4d a)
{
    M4x2d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    return r;
}

LADEF M2x2d m2x4d_mmul_m4x2d(M2x4d a, M4x2d b)
{
    M2x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3d m2x4d_mmul_m4x3d(M2x4d a, M4x3d b)
{
    M2x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4d m2x4d_mmul_m4x4d(M2x4d a, M4x4d b)
{
    M2x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2d m2x4d_mul_v4d(M2x4d m, V4d v)
{
    V2d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    return r;
}

LADEF M2x4i m2x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13)
{
    M2x4i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    return m;
}

LADEF M2x4i m2x4ii(int s)
{
    M2x4i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    return m;
}

LADEF M2x4i m2x4i2x2f(M2x2f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x2d(M2x2d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x2i(M2x2i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x2u(M2x2u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x3f(M2x3f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x3d(M2x3d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x3i(M2x3i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x3u(M2x3u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i2x4f(M2x4f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i2x4d(M2x4d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i2x4u(M2x4u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i3x2f(M3x2f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x2d(M3x2d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x2i(M3x2i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x2u(M3x2u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x3f(M3x3f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x3d(M3x3d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x3i(M3x3i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x3u(M3x3u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i3x4f(M3x4f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i3x4d(M3x4d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i3x4i(M3x4i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i3x4u(M3x4u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i4x2f(M4x2f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x2d(M4x2d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x2i(M4x2i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x2u(M4x2u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x3f(M4x3f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x3d(M4x3d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x3i(M4x3i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x3u(M4x3u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    return result;
}

LADEF M2x4i m2x4i4x4f(M4x4f a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i4x4d(M4x4d a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i4x4i(M4x4i a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i4x4u(M4x4u a)
{
    M2x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    return result;
}

LADEF M2x4i m2x4i_sum(M2x4i a, M2x4i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    return a;
}

LADEF M2x4i m2x4i_sub(M2x4i a, M2x4i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    return a;
}

LADEF M2x4i m2x4i_mul(M2x4i a, M2x4i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    return a;
}

LADEF M2x4i m2x4i_div(M2x4i a, M2x4i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    return a;
}

LADEF M2x4i m2x4i_mod(M2x4i a, M2x4i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    return a;
}

LADEF M4x2i m2x4i_transpose(M2x4i a)
{
    M4x2i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    return r;
}

LADEF M2x2i m2x4i_mmul_m4x2i(M2x4i a, M4x2i b)
{
    M2x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3i m2x4i_mmul_m4x3i(M2x4i a, M4x3i b)
{
    M2x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4i m2x4i_mmul_m4x4i(M2x4i a, M4x4i b)
{
    M2x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2i m2x4i_mul_v4i(M2x4i m, V4i v)
{
    V2i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    return r;
}

LADEF M2x4u m2x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13)
{
    M2x4u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    return m;
}

LADEF M2x4u m2x4uu(unsigned int s)
{
    M2x4u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    return m;
}

LADEF M2x4u m2x4u2x2f(M2x2f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x2d(M2x2d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x2i(M2x2i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x2u(M2x2u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x3f(M2x3f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x3d(M2x3d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x3i(M2x3i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x3u(M2x3u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u2x4f(M2x4f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u2x4d(M2x4d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u2x4i(M2x4i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u3x2f(M3x2f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x2d(M3x2d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x2i(M3x2i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x2u(M3x2u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x3f(M3x3f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x3d(M3x3d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x3i(M3x3i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x3u(M3x3u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u3x4f(M3x4f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u3x4d(M3x4d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u3x4i(M3x4i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u3x4u(M3x4u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u4x2f(M4x2f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x2d(M4x2d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x2i(M4x2i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x2u(M4x2u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x3f(M4x3f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x3d(M4x3d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x3i(M4x3i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x3u(M4x3u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    return result;
}

LADEF M2x4u m2x4u4x4f(M4x4f a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u4x4d(M4x4d a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u4x4i(M4x4i a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u4x4u(M4x4u a)
{
    M2x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    return result;
}

LADEF M2x4u m2x4u_sum(M2x4u a, M2x4u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    return a;
}

LADEF M2x4u m2x4u_sub(M2x4u a, M2x4u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    return a;
}

LADEF M2x4u m2x4u_mul(M2x4u a, M2x4u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    return a;
}

LADEF M2x4u m2x4u_div(M2x4u a, M2x4u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    return a;
}

LADEF M2x4u m2x4u_mod(M2x4u a, M2x4u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    return a;
}

LADEF M4x2u m2x4u_transpose(M2x4u a)
{
    M4x2u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    return r;
}

LADEF M2x2u m2x4u_mmul_m4x2u(M2x4u a, M4x2u b)
{
    M2x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    return r;
}

LADEF M2x3u m2x4u_mmul_m4x3u(M2x4u a, M4x3u b)
{
    M2x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    return r;
}

LADEF M2x4u m2x4u_mmul_m4x4u(M2x4u a, M4x4u b)
{
    M2x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    return r;
}

LADEF V2u m2x4u_mul_v4u(M2x4u m, V4u v)
{
    V2u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    return r;
}

LADEF M3x2f m3x2f(float m00, float m01, float m10, float m11, float m20, float m21)
{
    M3x2f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    return m;
}

LADEF M3x2f m3x2ff(float s)
{
    M3x2f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    return m;
}

LADEF M3x2f m3x2f2x2f(M2x2f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x2d(M2x2d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x2i(M2x2i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x2u(M2x2u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x3f(M2x3f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x3d(M2x3d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x3i(M2x3i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x3u(M2x3u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x4f(M2x4f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x4d(M2x4d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x4i(M2x4i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f2x4u(M2x4u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    return result;
}

LADEF M3x2f m3x2f3x2d(M3x2d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x2i(M3x2i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x2u(M3x2u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x3f(M3x3f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x3d(M3x3d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x3i(M3x3i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x3u(M3x3u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x4f(M3x4f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x4d(M3x4d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x4i(M3x4i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f3x4u(M3x4u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x2f(M4x2f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x2d(M4x2d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x2i(M4x2i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x2u(M4x2u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x3f(M4x3f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x3d(M4x3d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x3i(M4x3i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x3u(M4x3u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x4f(M4x4f a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x4d(M4x4d a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x4i(M4x4i a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f4x4u(M4x4u a)
{
    M3x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    return result;
}

LADEF M3x2f m3x2f_sum(M3x2f a, M3x2f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    return a;
}

LADEF M3x2f m3x2f_sub(M3x2f a, M3x2f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    return a;
}

LADEF M3x2f m3x2f_mul(M3x2f a, M3x2f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    return a;
}

LADEF M3x2f m3x2f_div(M3x2f a, M3x2f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    return a;
}

LADEF M3x2f m3x2f_mod(M3x2f a, M3x2f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    return a;
}

LADEF M2x3f m3x2f_transpose(M3x2f a)
{
    M2x3f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    return r;
}

LADEF M3x2f m3x2f_mmul_m2x2f(M3x2f a, M2x2f b)
{
    M3x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3f m3x2f_mmul_m2x3f(M3x2f a, M2x3f b)
{
    M3x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4f m3x2f_mmul_m2x4f(M3x2f a, M2x4f b)
{
    M3x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3f m3x2f_mul_v2f(M3x2f m, V2f v)
{
    V3f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    return r;
}

LADEF M3x2d m3x2d(double m00, double m01, double m10, double m11, double m20, double m21)
{
    M3x2d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    return m;
}

LADEF M3x2d m3x2dd(double s)
{
    M3x2d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    return m;
}

LADEF M3x2d m3x2d2x2f(M2x2f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x2d(M2x2d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x2i(M2x2i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x2u(M2x2u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x3f(M2x3f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x3d(M2x3d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x3i(M2x3i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x3u(M2x3u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x4f(M2x4f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x4d(M2x4d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x4i(M2x4i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d2x4u(M2x4u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    return result;
}

LADEF M3x2d m3x2d3x2f(M3x2f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x2i(M3x2i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x2u(M3x2u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x3f(M3x3f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x3d(M3x3d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x3i(M3x3i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x3u(M3x3u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x4f(M3x4f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x4d(M3x4d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x4i(M3x4i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d3x4u(M3x4u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x2f(M4x2f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x2d(M4x2d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x2i(M4x2i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x2u(M4x2u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x3f(M4x3f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x3d(M4x3d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x3i(M4x3i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x3u(M4x3u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x4f(M4x4f a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x4d(M4x4d a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x4i(M4x4i a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d4x4u(M4x4u a)
{
    M3x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    return result;
}

LADEF M3x2d m3x2d_sum(M3x2d a, M3x2d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    return a;
}

LADEF M3x2d m3x2d_sub(M3x2d a, M3x2d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    return a;
}

LADEF M3x2d m3x2d_mul(M3x2d a, M3x2d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    return a;
}

LADEF M3x2d m3x2d_div(M3x2d a, M3x2d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    return a;
}

LADEF M3x2d m3x2d_mod(M3x2d a, M3x2d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    return a;
}

LADEF M2x3d m3x2d_transpose(M3x2d a)
{
    M2x3d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    return r;
}

LADEF M3x2d m3x2d_mmul_m2x2d(M3x2d a, M2x2d b)
{
    M3x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3d m3x2d_mmul_m2x3d(M3x2d a, M2x3d b)
{
    M3x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4d m3x2d_mmul_m2x4d(M3x2d a, M2x4d b)
{
    M3x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3d m3x2d_mul_v2d(M3x2d m, V2d v)
{
    V3d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    return r;
}

LADEF M3x2i m3x2i(int m00, int m01, int m10, int m11, int m20, int m21)
{
    M3x2i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    return m;
}

LADEF M3x2i m3x2ii(int s)
{
    M3x2i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    return m;
}

LADEF M3x2i m3x2i2x2f(M2x2f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x2d(M2x2d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x2i(M2x2i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x2u(M2x2u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x3f(M2x3f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x3d(M2x3d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x3i(M2x3i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x3u(M2x3u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x4f(M2x4f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x4d(M2x4d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x4i(M2x4i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i2x4u(M2x4u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    return result;
}

LADEF M3x2i m3x2i3x2f(M3x2f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x2d(M3x2d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x2u(M3x2u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x3f(M3x3f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x3d(M3x3d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x3i(M3x3i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x3u(M3x3u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x4f(M3x4f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x4d(M3x4d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x4i(M3x4i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i3x4u(M3x4u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x2f(M4x2f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x2d(M4x2d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x2i(M4x2i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x2u(M4x2u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x3f(M4x3f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x3d(M4x3d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x3i(M4x3i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x3u(M4x3u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x4f(M4x4f a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x4d(M4x4d a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x4i(M4x4i a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i4x4u(M4x4u a)
{
    M3x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    return result;
}

LADEF M3x2i m3x2i_sum(M3x2i a, M3x2i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    return a;
}

LADEF M3x2i m3x2i_sub(M3x2i a, M3x2i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    return a;
}

LADEF M3x2i m3x2i_mul(M3x2i a, M3x2i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    return a;
}

LADEF M3x2i m3x2i_div(M3x2i a, M3x2i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    return a;
}

LADEF M3x2i m3x2i_mod(M3x2i a, M3x2i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    return a;
}

LADEF M2x3i m3x2i_transpose(M3x2i a)
{
    M2x3i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    return r;
}

LADEF M3x2i m3x2i_mmul_m2x2i(M3x2i a, M2x2i b)
{
    M3x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3i m3x2i_mmul_m2x3i(M3x2i a, M2x3i b)
{
    M3x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4i m3x2i_mmul_m2x4i(M3x2i a, M2x4i b)
{
    M3x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3i m3x2i_mul_v2i(M3x2i m, V2i v)
{
    V3i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    return r;
}

LADEF M3x2u m3x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11, unsigned int m20, unsigned int m21)
{
    M3x2u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    return m;
}

LADEF M3x2u m3x2uu(unsigned int s)
{
    M3x2u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    return m;
}

LADEF M3x2u m3x2u2x2f(M2x2f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x2d(M2x2d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x2i(M2x2i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x2u(M2x2u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x3f(M2x3f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x3d(M2x3d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x3i(M2x3i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x3u(M2x3u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x4f(M2x4f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x4d(M2x4d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x4i(M2x4i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u2x4u(M2x4u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    return result;
}

LADEF M3x2u m3x2u3x2f(M3x2f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x2d(M3x2d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x2i(M3x2i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x3f(M3x3f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x3d(M3x3d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x3i(M3x3i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x3u(M3x3u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x4f(M3x4f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x4d(M3x4d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x4i(M3x4i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u3x4u(M3x4u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x2f(M4x2f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x2d(M4x2d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x2i(M4x2i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x2u(M4x2u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x3f(M4x3f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x3d(M4x3d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x3i(M4x3i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x3u(M4x3u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x4f(M4x4f a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x4d(M4x4d a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x4i(M4x4i a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u4x4u(M4x4u a)
{
    M3x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    return result;
}

LADEF M3x2u m3x2u_sum(M3x2u a, M3x2u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    return a;
}

LADEF M3x2u m3x2u_sub(M3x2u a, M3x2u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    return a;
}

LADEF M3x2u m3x2u_mul(M3x2u a, M3x2u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    return a;
}

LADEF M3x2u m3x2u_div(M3x2u a, M3x2u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    return a;
}

LADEF M3x2u m3x2u_mod(M3x2u a, M3x2u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    return a;
}

LADEF M2x3u m3x2u_transpose(M3x2u a)
{
    M2x3u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    return r;
}

LADEF M3x2u m3x2u_mmul_m2x2u(M3x2u a, M2x2u b)
{
    M3x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3u m3x2u_mmul_m2x3u(M3x2u a, M2x3u b)
{
    M3x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4u m3x2u_mmul_m2x4u(M3x2u a, M2x4u b)
{
    M3x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3u m3x2u_mul_v2u(M3x2u m, V2u v)
{
    V3u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    return r;
}

LADEF M3x3f m3x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
    M3x3f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    return m;
}

LADEF M3x3f m3x3ff(float s)
{
    M3x3f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    return m;
}

LADEF M3x3f m3x3f_identity(void)
{
    M3x3f m;
    m.rc[0][0] = 0.0f;
    m.rc[0][1] = 0.0f;
    m.rc[0][2] = 0.0f;
    m.rc[1][0] = 0.0f;
    m.rc[1][1] = 0.0f;
    m.rc[1][2] = 0.0f;
    m.rc[2][0] = 0.0f;
    m.rc[2][1] = 0.0f;
    m.rc[2][2] = 0.0f;
    m.rc[0][0] = 1.0f;
    m.rc[1][1] = 1.0f;
    m.rc[2][2] = 1.0f;
    return m;
}

LADEF float m3x3f_det(M3x3f m)
{
    float a[3][3];
    for (size_t i = 0; i < 3; ++i) for (size_t j = 0; j < 3; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    float det = 1.0f;
    for (size_t i = 0; i < 3; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 3; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        if (fabsf(a[pivot][i]) < 1e-6f) return 0.0f;
        if (pivot != i) {
            for (size_t c = 0; c < 3; ++c) { float tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 3; ++r) {
            float f = a[r][i] / a[i][i];
            for (size_t c = i; c < 3; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 3; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M3x3f m3x3f_inverse(M3x3f m)
{
    float a[3][3];
    M3x3f inv;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0f; }
        inv.rc[i][i] = 1.0f;
    }
    for (size_t i = 0; i < 3; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 3; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        float piv = a[pivot][i];
        if (fabsf(piv) < 1e-6f) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 3; ++c) { float ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; float ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        float inv_piv = (float)1 / a[i][i];
        for (size_t c = 0; c < 3; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 3; ++r) if (r != i) { float f = a[r][i]; if (fabsf(f) > 0) { for (size_t c = 0; c < 3; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M3x3f m3x3f2x2f(M2x2f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x2d(M2x2d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x2i(M2x2i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x2u(M2x2u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x3f(M2x3f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x3d(M2x3d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x3i(M2x3i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x3u(M2x3u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x4f(M2x4f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x4d(M2x4d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x4i(M2x4i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f2x4u(M2x4u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f3x2f(M3x2f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f3x2d(M3x2d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f3x2i(M3x2i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f3x2u(M3x2u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f3x3d(M3x3d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x3i(M3x3i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x3u(M3x3u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x4f(M3x4f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x4d(M3x4d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x4i(M3x4i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f3x4u(M3x4u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x2f(M4x2f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f4x2d(M4x2d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f4x2i(M4x2i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f4x2u(M4x2u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    return result;
}

LADEF M3x3f m3x3f4x3f(M4x3f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x3d(M4x3d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x3i(M4x3i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x3u(M4x3u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x4f(M4x4f a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x4d(M4x4d a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x4i(M4x4i a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f4x4u(M4x4u a)
{
    M3x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    return result;
}

LADEF M3x3f m3x3f_sum(M3x3f a, M3x3f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    return a;
}

LADEF M3x3f m3x3f_sub(M3x3f a, M3x3f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    return a;
}

LADEF M3x3f m3x3f_mul(M3x3f a, M3x3f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    return a;
}

LADEF M3x3f m3x3f_div(M3x3f a, M3x3f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    return a;
}

LADEF M3x3f m3x3f_mod(M3x3f a, M3x3f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmodf(a.rc[2][2], b.rc[2][2]);
    return a;
}

LADEF M3x3f m3x3f_transpose(M3x3f a)
{
    M3x3f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    return r;
}

LADEF M3x2f m3x3f_mmul_m3x2f(M3x3f a, M3x2f b)
{
    M3x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3f m3x3f_mmul_m3x3f(M3x3f a, M3x3f b)
{
    M3x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4f m3x3f_mmul_m3x4f(M3x3f a, M3x4f b)
{
    M3x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3f m3x3f_mul_v3f(M3x3f m, V3f v)
{
    V3f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    return r;
}

LADEF M3x3d m3x3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22)
{
    M3x3d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    return m;
}

LADEF M3x3d m3x3dd(double s)
{
    M3x3d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    return m;
}

LADEF M3x3d m3x3d_identity(void)
{
    M3x3d m;
    m.rc[0][0] = 0.0;
    m.rc[0][1] = 0.0;
    m.rc[0][2] = 0.0;
    m.rc[1][0] = 0.0;
    m.rc[1][1] = 0.0;
    m.rc[1][2] = 0.0;
    m.rc[2][0] = 0.0;
    m.rc[2][1] = 0.0;
    m.rc[2][2] = 0.0;
    m.rc[0][0] = 1.0;
    m.rc[1][1] = 1.0;
    m.rc[2][2] = 1.0;
    return m;
}

LADEF double m3x3d_det(M3x3d m)
{
    double a[3][3];
    for (size_t i = 0; i < 3; ++i) for (size_t j = 0; j < 3; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    double det = 1.0;
    for (size_t i = 0; i < 3; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 3; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        if (fabs(a[pivot][i]) < 1e-12) return 0.0;
        if (pivot != i) {
            for (size_t c = 0; c < 3; ++c) { double tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 3; ++r) {
            double f = a[r][i] / a[i][i];
            for (size_t c = i; c < 3; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 3; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M3x3d m3x3d_inverse(M3x3d m)
{
    double a[3][3];
    M3x3d inv;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0; }
        inv.rc[i][i] = 1.0;
    }
    for (size_t i = 0; i < 3; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 3; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        double piv = a[pivot][i];
        if (fabs(piv) < 1e-12) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 3; ++c) { double ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; double ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        double inv_piv = (double)1 / a[i][i];
        for (size_t c = 0; c < 3; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 3; ++r) if (r != i) { double f = a[r][i]; if (fabs(f) > 0) { for (size_t c = 0; c < 3; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M3x3d m3x3d2x2f(M2x2f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x2d(M2x2d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x2i(M2x2i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x2u(M2x2u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x3f(M2x3f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x3d(M2x3d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x3i(M2x3i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x3u(M2x3u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x4f(M2x4f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x4d(M2x4d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x4i(M2x4i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d2x4u(M2x4u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d3x2f(M3x2f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d3x2d(M3x2d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d3x2i(M3x2i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d3x2u(M3x2u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d3x3f(M3x3f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x3i(M3x3i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x3u(M3x3u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x4f(M3x4f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x4d(M3x4d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x4i(M3x4i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d3x4u(M3x4u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x2f(M4x2f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d4x2d(M4x2d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d4x2i(M4x2i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d4x2u(M4x2u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    return result;
}

LADEF M3x3d m3x3d4x3f(M4x3f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x3d(M4x3d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x3i(M4x3i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x3u(M4x3u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x4f(M4x4f a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x4d(M4x4d a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x4i(M4x4i a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d4x4u(M4x4u a)
{
    M3x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    return result;
}

LADEF M3x3d m3x3d_sum(M3x3d a, M3x3d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    return a;
}

LADEF M3x3d m3x3d_sub(M3x3d a, M3x3d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    return a;
}

LADEF M3x3d m3x3d_mul(M3x3d a, M3x3d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    return a;
}

LADEF M3x3d m3x3d_div(M3x3d a, M3x3d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    return a;
}

LADEF M3x3d m3x3d_mod(M3x3d a, M3x3d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmod(a.rc[2][2], b.rc[2][2]);
    return a;
}

LADEF M3x3d m3x3d_transpose(M3x3d a)
{
    M3x3d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    return r;
}

LADEF M3x2d m3x3d_mmul_m3x2d(M3x3d a, M3x2d b)
{
    M3x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3d m3x3d_mmul_m3x3d(M3x3d a, M3x3d b)
{
    M3x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4d m3x3d_mmul_m3x4d(M3x3d a, M3x4d b)
{
    M3x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3d m3x3d_mul_v3d(M3x3d m, V3d v)
{
    V3d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    return r;
}

LADEF M3x3i m3x3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22)
{
    M3x3i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    return m;
}

LADEF M3x3i m3x3ii(int s)
{
    M3x3i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    return m;
}

LADEF M3x3i m3x3i_identity(void)
{
    M3x3i m;
    m.rc[0][0] = 0;
    m.rc[0][1] = 0;
    m.rc[0][2] = 0;
    m.rc[1][0] = 0;
    m.rc[1][1] = 0;
    m.rc[1][2] = 0;
    m.rc[2][0] = 0;
    m.rc[2][1] = 0;
    m.rc[2][2] = 0;
    m.rc[0][0] = 1;
    m.rc[1][1] = 1;
    m.rc[2][2] = 1;
    return m;
}



LADEF M3x3i m3x3i2x2f(M2x2f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x2d(M2x2d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x2i(M2x2i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x2u(M2x2u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x3f(M2x3f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x3d(M2x3d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x3i(M2x3i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x3u(M2x3u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x4f(M2x4f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x4d(M2x4d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x4i(M2x4i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i2x4u(M2x4u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i3x2f(M3x2f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i3x2d(M3x2d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i3x2i(M3x2i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i3x2u(M3x2u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i3x3f(M3x3f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x3d(M3x3d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x3u(M3x3u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x4f(M3x4f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x4d(M3x4d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x4i(M3x4i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i3x4u(M3x4u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x2f(M4x2f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i4x2d(M4x2d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i4x2i(M4x2i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i4x2u(M4x2u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    return result;
}

LADEF M3x3i m3x3i4x3f(M4x3f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x3d(M4x3d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x3i(M4x3i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x3u(M4x3u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x4f(M4x4f a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x4d(M4x4d a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x4i(M4x4i a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i4x4u(M4x4u a)
{
    M3x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    return result;
}

LADEF M3x3i m3x3i_sum(M3x3i a, M3x3i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    return a;
}

LADEF M3x3i m3x3i_sub(M3x3i a, M3x3i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    return a;
}

LADEF M3x3i m3x3i_mul(M3x3i a, M3x3i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    return a;
}

LADEF M3x3i m3x3i_div(M3x3i a, M3x3i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    return a;
}

LADEF M3x3i m3x3i_mod(M3x3i a, M3x3i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    return a;
}

LADEF M3x3i m3x3i_transpose(M3x3i a)
{
    M3x3i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    return r;
}

LADEF M3x2i m3x3i_mmul_m3x2i(M3x3i a, M3x2i b)
{
    M3x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3i m3x3i_mmul_m3x3i(M3x3i a, M3x3i b)
{
    M3x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4i m3x3i_mmul_m3x4i(M3x3i a, M3x4i b)
{
    M3x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3i m3x3i_mul_v3i(M3x3i m, V3i v)
{
    V3i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    return r;
}

LADEF M3x3u m3x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m20, unsigned int m21, unsigned int m22)
{
    M3x3u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    return m;
}

LADEF M3x3u m3x3uu(unsigned int s)
{
    M3x3u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    return m;
}

LADEF M3x3u m3x3u_identity(void)
{
    M3x3u m;
    m.rc[0][0] = 0u;
    m.rc[0][1] = 0u;
    m.rc[0][2] = 0u;
    m.rc[1][0] = 0u;
    m.rc[1][1] = 0u;
    m.rc[1][2] = 0u;
    m.rc[2][0] = 0u;
    m.rc[2][1] = 0u;
    m.rc[2][2] = 0u;
    m.rc[0][0] = 1u;
    m.rc[1][1] = 1u;
    m.rc[2][2] = 1u;
    return m;
}



LADEF M3x3u m3x3u2x2f(M2x2f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x2d(M2x2d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x2i(M2x2i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x2u(M2x2u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x3f(M2x3f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x3d(M2x3d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x3i(M2x3i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x3u(M2x3u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x4f(M2x4f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x4d(M2x4d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x4i(M2x4i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u2x4u(M2x4u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u3x2f(M3x2f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u3x2d(M3x2d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u3x2i(M3x2i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u3x2u(M3x2u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u3x3f(M3x3f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x3d(M3x3d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x3i(M3x3i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x4f(M3x4f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x4d(M3x4d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x4i(M3x4i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u3x4u(M3x4u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x2f(M4x2f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u4x2d(M4x2d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u4x2i(M4x2i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u4x2u(M4x2u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    return result;
}

LADEF M3x3u m3x3u4x3f(M4x3f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x3d(M4x3d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x3i(M4x3i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x3u(M4x3u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x4f(M4x4f a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x4d(M4x4d a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x4i(M4x4i a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u4x4u(M4x4u a)
{
    M3x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    return result;
}

LADEF M3x3u m3x3u_sum(M3x3u a, M3x3u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    return a;
}

LADEF M3x3u m3x3u_sub(M3x3u a, M3x3u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    return a;
}

LADEF M3x3u m3x3u_mul(M3x3u a, M3x3u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    return a;
}

LADEF M3x3u m3x3u_div(M3x3u a, M3x3u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    return a;
}

LADEF M3x3u m3x3u_mod(M3x3u a, M3x3u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    return a;
}

LADEF M3x3u m3x3u_transpose(M3x3u a)
{
    M3x3u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    return r;
}

LADEF M3x2u m3x3u_mmul_m3x2u(M3x3u a, M3x2u b)
{
    M3x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3u m3x3u_mmul_m3x3u(M3x3u a, M3x3u b)
{
    M3x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4u m3x3u_mmul_m3x4u(M3x3u a, M3x4u b)
{
    M3x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3u m3x3u_mul_v3u(M3x3u m, V3u v)
{
    V3u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    return r;
}

LADEF M3x4f m3x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23)
{
    M3x4f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    return m;
}

LADEF M3x4f m3x4ff(float s)
{
    M3x4f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    return m;
}

LADEF M3x4f m3x4f2x2f(M2x2f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x2d(M2x2d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x2i(M2x2i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x2u(M2x2u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x3f(M2x3f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x3d(M2x3d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x3i(M2x3i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x3u(M2x3u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x4f(M2x4f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x4d(M2x4d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x4i(M2x4i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f2x4u(M2x4u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x2f(M3x2f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x2d(M3x2d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x2i(M3x2i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x2u(M3x2u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x3f(M3x3f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x3d(M3x3d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x3i(M3x3i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x3u(M3x3u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f3x4d(M3x4d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f3x4i(M3x4i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f3x4u(M3x4u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f4x2f(M4x2f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x2d(M4x2d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x2i(M4x2i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x2u(M4x2u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x3f(M4x3f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x3d(M4x3d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x3i(M4x3i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x3u(M4x3u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    return result;
}

LADEF M3x4f m3x4f4x4f(M4x4f a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f4x4d(M4x4d a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f4x4i(M4x4i a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f4x4u(M4x4u a)
{
    M3x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    return result;
}

LADEF M3x4f m3x4f_sum(M3x4f a, M3x4f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    return a;
}

LADEF M3x4f m3x4f_sub(M3x4f a, M3x4f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    return a;
}

LADEF M3x4f m3x4f_mul(M3x4f a, M3x4f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    return a;
}

LADEF M3x4f m3x4f_div(M3x4f a, M3x4f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    return a;
}

LADEF M3x4f m3x4f_mod(M3x4f a, M3x4f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmodf(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmodf(a.rc[1][3], b.rc[1][3]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmodf(a.rc[2][2], b.rc[2][2]);
    a.rc[2][3] = fmodf(a.rc[2][3], b.rc[2][3]);
    return a;
}

LADEF M4x3f m3x4f_transpose(M3x4f a)
{
    M4x3f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    return r;
}

LADEF M3x2f m3x4f_mmul_m4x2f(M3x4f a, M4x2f b)
{
    M3x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3f m3x4f_mmul_m4x3f(M3x4f a, M4x3f b)
{
    M3x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4f m3x4f_mmul_m4x4f(M3x4f a, M4x4f b)
{
    M3x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3f m3x4f_mul_v4f(M3x4f m, V4f v)
{
    V3f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    return r;
}

LADEF M3x4d m3x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23)
{
    M3x4d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    return m;
}

LADEF M3x4d m3x4dd(double s)
{
    M3x4d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    return m;
}

LADEF M3x4d m3x4d2x2f(M2x2f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x2d(M2x2d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x2i(M2x2i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x2u(M2x2u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x3f(M2x3f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x3d(M2x3d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x3i(M2x3i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x3u(M2x3u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x4f(M2x4f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x4d(M2x4d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x4i(M2x4i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d2x4u(M2x4u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x2f(M3x2f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x2d(M3x2d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x2i(M3x2i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x2u(M3x2u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x3f(M3x3f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x3d(M3x3d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x3i(M3x3i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x3u(M3x3u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d3x4f(M3x4f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d3x4i(M3x4i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d3x4u(M3x4u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d4x2f(M4x2f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x2d(M4x2d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x2i(M4x2i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x2u(M4x2u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x3f(M4x3f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x3d(M4x3d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x3i(M4x3i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x3u(M4x3u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    return result;
}

LADEF M3x4d m3x4d4x4f(M4x4f a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d4x4d(M4x4d a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d4x4i(M4x4i a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d4x4u(M4x4u a)
{
    M3x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    return result;
}

LADEF M3x4d m3x4d_sum(M3x4d a, M3x4d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    return a;
}

LADEF M3x4d m3x4d_sub(M3x4d a, M3x4d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    return a;
}

LADEF M3x4d m3x4d_mul(M3x4d a, M3x4d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    return a;
}

LADEF M3x4d m3x4d_div(M3x4d a, M3x4d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    return a;
}

LADEF M3x4d m3x4d_mod(M3x4d a, M3x4d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmod(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmod(a.rc[1][3], b.rc[1][3]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmod(a.rc[2][2], b.rc[2][2]);
    a.rc[2][3] = fmod(a.rc[2][3], b.rc[2][3]);
    return a;
}

LADEF M4x3d m3x4d_transpose(M3x4d a)
{
    M4x3d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    return r;
}

LADEF M3x2d m3x4d_mmul_m4x2d(M3x4d a, M4x2d b)
{
    M3x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3d m3x4d_mmul_m4x3d(M3x4d a, M4x3d b)
{
    M3x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4d m3x4d_mmul_m4x4d(M3x4d a, M4x4d b)
{
    M3x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3d m3x4d_mul_v4d(M3x4d m, V4d v)
{
    V3d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    return r;
}

LADEF M3x4i m3x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23)
{
    M3x4i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    return m;
}

LADEF M3x4i m3x4ii(int s)
{
    M3x4i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    return m;
}

LADEF M3x4i m3x4i2x2f(M2x2f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x2d(M2x2d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x2i(M2x2i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x2u(M2x2u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x3f(M2x3f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x3d(M2x3d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x3i(M2x3i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x3u(M2x3u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x4f(M2x4f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x4d(M2x4d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x4i(M2x4i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i2x4u(M2x4u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x2f(M3x2f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x2d(M3x2d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x2i(M3x2i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x2u(M3x2u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x3f(M3x3f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x3d(M3x3d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x3i(M3x3i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x3u(M3x3u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i3x4f(M3x4f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i3x4d(M3x4d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i3x4u(M3x4u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i4x2f(M4x2f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x2d(M4x2d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x2i(M4x2i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x2u(M4x2u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x3f(M4x3f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x3d(M4x3d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x3i(M4x3i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x3u(M4x3u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    return result;
}

LADEF M3x4i m3x4i4x4f(M4x4f a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i4x4d(M4x4d a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i4x4i(M4x4i a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i4x4u(M4x4u a)
{
    M3x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    return result;
}

LADEF M3x4i m3x4i_sum(M3x4i a, M3x4i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    return a;
}

LADEF M3x4i m3x4i_sub(M3x4i a, M3x4i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    return a;
}

LADEF M3x4i m3x4i_mul(M3x4i a, M3x4i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    return a;
}

LADEF M3x4i m3x4i_div(M3x4i a, M3x4i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    return a;
}

LADEF M3x4i m3x4i_mod(M3x4i a, M3x4i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[2][3] %= b.rc[2][3];
    return a;
}

LADEF M4x3i m3x4i_transpose(M3x4i a)
{
    M4x3i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    return r;
}

LADEF M3x2i m3x4i_mmul_m4x2i(M3x4i a, M4x2i b)
{
    M3x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3i m3x4i_mmul_m4x3i(M3x4i a, M4x3i b)
{
    M3x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4i m3x4i_mmul_m4x4i(M3x4i a, M4x4i b)
{
    M3x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3i m3x4i_mul_v4i(M3x4i m, V4i v)
{
    V3i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    return r;
}

LADEF M3x4u m3x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m23)
{
    M3x4u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    return m;
}

LADEF M3x4u m3x4uu(unsigned int s)
{
    M3x4u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    return m;
}

LADEF M3x4u m3x4u2x2f(M2x2f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x2d(M2x2d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x2i(M2x2i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x2u(M2x2u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x3f(M2x3f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x3d(M2x3d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x3i(M2x3i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x3u(M2x3u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x4f(M2x4f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x4d(M2x4d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x4i(M2x4i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u2x4u(M2x4u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x2f(M3x2f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x2d(M3x2d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x2i(M3x2i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x2u(M3x2u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x3f(M3x3f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x3d(M3x3d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x3i(M3x3i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x3u(M3x3u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u3x4f(M3x4f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u3x4d(M3x4d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u3x4i(M3x4i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u4x2f(M4x2f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x2d(M4x2d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x2i(M4x2i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x2u(M4x2u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x3f(M4x3f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x3d(M4x3d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x3i(M4x3i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x3u(M4x3u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    return result;
}

LADEF M3x4u m3x4u4x4f(M4x4f a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u4x4d(M4x4d a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u4x4i(M4x4i a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u4x4u(M4x4u a)
{
    M3x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    return result;
}

LADEF M3x4u m3x4u_sum(M3x4u a, M3x4u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    return a;
}

LADEF M3x4u m3x4u_sub(M3x4u a, M3x4u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    return a;
}

LADEF M3x4u m3x4u_mul(M3x4u a, M3x4u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    return a;
}

LADEF M3x4u m3x4u_div(M3x4u a, M3x4u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    return a;
}

LADEF M3x4u m3x4u_mod(M3x4u a, M3x4u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[2][3] %= b.rc[2][3];
    return a;
}

LADEF M4x3u m3x4u_transpose(M3x4u a)
{
    M4x3u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    return r;
}

LADEF M3x2u m3x4u_mmul_m4x2u(M3x4u a, M4x2u b)
{
    M3x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    return r;
}

LADEF M3x3u m3x4u_mmul_m4x3u(M3x4u a, M4x3u b)
{
    M3x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    return r;
}

LADEF M3x4u m3x4u_mmul_m4x4u(M3x4u a, M4x4u b)
{
    M3x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    return r;
}

LADEF V3u m3x4u_mul_v4u(M3x4u m, V4u v)
{
    V3u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    return r;
}

LADEF M4x2f m4x2f(float m00, float m01, float m10, float m11, float m20, float m21, float m30, float m31)
{
    M4x2f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    return m;
}

LADEF M4x2f m4x2ff(float s)
{
    M4x2f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    return m;
}

LADEF M4x2f m4x2f2x2f(M2x2f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x2d(M2x2d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x2i(M2x2i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x2u(M2x2u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x3f(M2x3f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x3d(M2x3d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x3i(M2x3i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x3u(M2x3u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x4f(M2x4f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x4d(M2x4d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x4i(M2x4i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f2x4u(M2x4u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x2f(M3x2f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x2d(M3x2d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x2i(M3x2i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x2u(M3x2u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x3f(M3x3f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x3d(M3x3d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x3i(M3x3i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x3u(M3x3u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x4f(M3x4f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x4d(M3x4d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x4i(M3x4i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f3x4u(M3x4u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    return result;
}

LADEF M4x2f m4x2f4x2d(M4x2d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x2i(M4x2i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x2u(M4x2u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x3f(M4x3f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x3d(M4x3d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x3i(M4x3i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x3u(M4x3u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x4f(M4x4f a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x4d(M4x4d a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x4i(M4x4i a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f4x4u(M4x4u a)
{
    M4x2f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    return result;
}

LADEF M4x2f m4x2f_sum(M4x2f a, M4x2f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    return a;
}

LADEF M4x2f m4x2f_sub(M4x2f a, M4x2f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    return a;
}

LADEF M4x2f m4x2f_mul(M4x2f a, M4x2f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    return a;
}

LADEF M4x2f m4x2f_div(M4x2f a, M4x2f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    return a;
}

LADEF M4x2f m4x2f_mod(M4x2f a, M4x2f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    a.rc[3][0] = fmodf(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmodf(a.rc[3][1], b.rc[3][1]);
    return a;
}

LADEF M2x4f m4x2f_transpose(M4x2f a)
{
    M2x4f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    return r;
}

LADEF M4x2f m4x2f_mmul_m2x2f(M4x2f a, M2x2f b)
{
    M4x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3f m4x2f_mmul_m2x3f(M4x2f a, M2x3f b)
{
    M4x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4f m4x2f_mmul_m2x4f(M4x2f a, M2x4f b)
{
    M4x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0f;
    for (size_t k = 0; k < 2; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4f m4x2f_mul_v2f(M4x2f m, V2f v)
{
    V4f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[3] = 0.0f;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    return r;
}

LADEF M4x2d m4x2d(double m00, double m01, double m10, double m11, double m20, double m21, double m30, double m31)
{
    M4x2d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    return m;
}

LADEF M4x2d m4x2dd(double s)
{
    M4x2d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    return m;
}

LADEF M4x2d m4x2d2x2f(M2x2f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x2d(M2x2d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x2i(M2x2i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x2u(M2x2u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x3f(M2x3f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x3d(M2x3d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x3i(M2x3i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x3u(M2x3u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x4f(M2x4f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x4d(M2x4d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x4i(M2x4i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d2x4u(M2x4u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x2f(M3x2f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x2d(M3x2d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x2i(M3x2i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x2u(M3x2u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x3f(M3x3f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x3d(M3x3d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x3i(M3x3i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x3u(M3x3u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x4f(M3x4f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x4d(M3x4d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x4i(M3x4i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d3x4u(M3x4u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    return result;
}

LADEF M4x2d m4x2d4x2f(M4x2f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x2i(M4x2i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x2u(M4x2u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x3f(M4x3f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x3d(M4x3d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x3i(M4x3i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x3u(M4x3u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x4f(M4x4f a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x4d(M4x4d a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x4i(M4x4i a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d4x4u(M4x4u a)
{
    M4x2d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    return result;
}

LADEF M4x2d m4x2d_sum(M4x2d a, M4x2d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    return a;
}

LADEF M4x2d m4x2d_sub(M4x2d a, M4x2d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    return a;
}

LADEF M4x2d m4x2d_mul(M4x2d a, M4x2d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    return a;
}

LADEF M4x2d m4x2d_div(M4x2d a, M4x2d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    return a;
}

LADEF M4x2d m4x2d_mod(M4x2d a, M4x2d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    a.rc[3][0] = fmod(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmod(a.rc[3][1], b.rc[3][1]);
    return a;
}

LADEF M2x4d m4x2d_transpose(M4x2d a)
{
    M2x4d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    return r;
}

LADEF M4x2d m4x2d_mmul_m2x2d(M4x2d a, M2x2d b)
{
    M4x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3d m4x2d_mmul_m2x3d(M4x2d a, M2x3d b)
{
    M4x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4d m4x2d_mmul_m2x4d(M4x2d a, M2x4d b)
{
    M4x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4d m4x2d_mul_v2d(M4x2d m, V2d v)
{
    V4d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[3] = 0.0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    return r;
}

LADEF M4x2i m4x2i(int m00, int m01, int m10, int m11, int m20, int m21, int m30, int m31)
{
    M4x2i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    return m;
}

LADEF M4x2i m4x2ii(int s)
{
    M4x2i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    return m;
}

LADEF M4x2i m4x2i2x2f(M2x2f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x2d(M2x2d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x2i(M2x2i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x2u(M2x2u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x3f(M2x3f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x3d(M2x3d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x3i(M2x3i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x3u(M2x3u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x4f(M2x4f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x4d(M2x4d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x4i(M2x4i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i2x4u(M2x4u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x2f(M3x2f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x2d(M3x2d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x2i(M3x2i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x2u(M3x2u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x3f(M3x3f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x3d(M3x3d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x3i(M3x3i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x3u(M3x3u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x4f(M3x4f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x4d(M3x4d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x4i(M3x4i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i3x4u(M3x4u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    return result;
}

LADEF M4x2i m4x2i4x2f(M4x2f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x2d(M4x2d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x2u(M4x2u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x3f(M4x3f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x3d(M4x3d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x3i(M4x3i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x3u(M4x3u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x4f(M4x4f a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x4d(M4x4d a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x4i(M4x4i a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i4x4u(M4x4u a)
{
    M4x2i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    return result;
}

LADEF M4x2i m4x2i_sum(M4x2i a, M4x2i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    return a;
}

LADEF M4x2i m4x2i_sub(M4x2i a, M4x2i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    return a;
}

LADEF M4x2i m4x2i_mul(M4x2i a, M4x2i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    return a;
}

LADEF M4x2i m4x2i_div(M4x2i a, M4x2i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    return a;
}

LADEF M4x2i m4x2i_mod(M4x2i a, M4x2i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    return a;
}

LADEF M2x4i m4x2i_transpose(M4x2i a)
{
    M2x4i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    return r;
}

LADEF M4x2i m4x2i_mmul_m2x2i(M4x2i a, M2x2i b)
{
    M4x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3i m4x2i_mmul_m2x3i(M4x2i a, M2x3i b)
{
    M4x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4i m4x2i_mmul_m2x4i(M4x2i a, M2x4i b)
{
    M4x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0;
    for (size_t k = 0; k < 2; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4i m4x2i_mul_v2i(M4x2i m, V2i v)
{
    V4i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[3] = 0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    return r;
}

LADEF M4x2u m4x2u(unsigned int m00, unsigned int m01, unsigned int m10, unsigned int m11, unsigned int m20, unsigned int m21, unsigned int m30, unsigned int m31)
{
    M4x2u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    return m;
}

LADEF M4x2u m4x2uu(unsigned int s)
{
    M4x2u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    return m;
}

LADEF M4x2u m4x2u2x2f(M2x2f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x2d(M2x2d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x2i(M2x2i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x2u(M2x2u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x3f(M2x3f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x3d(M2x3d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x3i(M2x3i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x3u(M2x3u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x4f(M2x4f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x4d(M2x4d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x4i(M2x4i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u2x4u(M2x4u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x2f(M3x2f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x2d(M3x2d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x2i(M3x2i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x2u(M3x2u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x3f(M3x3f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x3d(M3x3d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x3i(M3x3i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x3u(M3x3u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x4f(M3x4f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x4d(M3x4d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x4i(M3x4i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u3x4u(M3x4u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    return result;
}

LADEF M4x2u m4x2u4x2f(M4x2f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x2d(M4x2d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x2i(M4x2i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x3f(M4x3f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x3d(M4x3d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x3i(M4x3i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x3u(M4x3u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x4f(M4x4f a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x4d(M4x4d a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x4i(M4x4i a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u4x4u(M4x4u a)
{
    M4x2u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    return result;
}

LADEF M4x2u m4x2u_sum(M4x2u a, M4x2u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    return a;
}

LADEF M4x2u m4x2u_sub(M4x2u a, M4x2u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    return a;
}

LADEF M4x2u m4x2u_mul(M4x2u a, M4x2u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    return a;
}

LADEF M4x2u m4x2u_div(M4x2u a, M4x2u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    return a;
}

LADEF M4x2u m4x2u_mod(M4x2u a, M4x2u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    return a;
}

LADEF M2x4u m4x2u_transpose(M4x2u a)
{
    M2x4u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    return r;
}

LADEF M4x2u m4x2u_mmul_m2x2u(M4x2u a, M2x2u b)
{
    M4x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3u m4x2u_mmul_m2x3u(M4x2u a, M2x3u b)
{
    M4x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4u m4x2u_mmul_m2x4u(M4x2u a, M2x4u b)
{
    M4x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0u;
    for (size_t k = 0; k < 2; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4u m4x2u_mul_v2u(M4x2u m, V2u v)
{
    V4u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[3] = 0u;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    return r;
}

LADEF M4x3f m4x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, float m30, float m31, float m32)
{
    M4x3f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    return m;
}

LADEF M4x3f m4x3ff(float s)
{
    M4x3f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    return m;
}

LADEF M4x3f m4x3f2x2f(M2x2f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x2d(M2x2d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x2i(M2x2i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x2u(M2x2u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x3f(M2x3f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x3d(M2x3d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x3i(M2x3i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x3u(M2x3u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x4f(M2x4f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x4d(M2x4d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x4i(M2x4i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f2x4u(M2x4u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x2f(M3x2f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x2d(M3x2d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x2i(M3x2i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x2u(M3x2u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x3f(M3x3f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x3d(M3x3d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x3i(M3x3i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x3u(M3x3u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x4f(M3x4f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x4d(M3x4d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x4i(M3x4i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f3x4u(M3x4u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f4x2f(M4x2f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f4x2d(M4x2d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f4x2i(M4x2i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f4x2u(M4x2u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    return result;
}

LADEF M4x3f m4x3f4x3d(M4x3d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x3i(M4x3i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x3u(M4x3u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x4f(M4x4f a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x4d(M4x4d a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x4i(M4x4i a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f4x4u(M4x4u a)
{
    M4x3f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    return result;
}

LADEF M4x3f m4x3f_sum(M4x3f a, M4x3f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    return a;
}

LADEF M4x3f m4x3f_sub(M4x3f a, M4x3f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    return a;
}

LADEF M4x3f m4x3f_mul(M4x3f a, M4x3f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    return a;
}

LADEF M4x3f m4x3f_div(M4x3f a, M4x3f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    return a;
}

LADEF M4x3f m4x3f_mod(M4x3f a, M4x3f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmodf(a.rc[2][2], b.rc[2][2]);
    a.rc[3][0] = fmodf(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmodf(a.rc[3][1], b.rc[3][1]);
    a.rc[3][2] = fmodf(a.rc[3][2], b.rc[3][2]);
    return a;
}

LADEF M3x4f m4x3f_transpose(M4x3f a)
{
    M3x4f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    return r;
}

LADEF M4x2f m4x3f_mmul_m3x2f(M4x3f a, M3x2f b)
{
    M4x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3f m4x3f_mmul_m3x3f(M4x3f a, M3x3f b)
{
    M4x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4f m4x3f_mmul_m3x4f(M4x3f a, M3x4f b)
{
    M4x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0f;
    for (size_t k = 0; k < 3; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4f m4x3f_mul_v3f(M4x3f m, V3f v)
{
    V4f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[3] = 0.0f;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    return r;
}

LADEF M4x3d m4x3d(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22, double m30, double m31, double m32)
{
    M4x3d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    return m;
}

LADEF M4x3d m4x3dd(double s)
{
    M4x3d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    return m;
}

LADEF M4x3d m4x3d2x2f(M2x2f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x2d(M2x2d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x2i(M2x2i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x2u(M2x2u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x3f(M2x3f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x3d(M2x3d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x3i(M2x3i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x3u(M2x3u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x4f(M2x4f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x4d(M2x4d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x4i(M2x4i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d2x4u(M2x4u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x2f(M3x2f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x2d(M3x2d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x2i(M3x2i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x2u(M3x2u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x3f(M3x3f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x3d(M3x3d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x3i(M3x3i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x3u(M3x3u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x4f(M3x4f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x4d(M3x4d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x4i(M3x4i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d3x4u(M3x4u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d4x2f(M4x2f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d4x2d(M4x2d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d4x2i(M4x2i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d4x2u(M4x2u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    return result;
}

LADEF M4x3d m4x3d4x3f(M4x3f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x3i(M4x3i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x3u(M4x3u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x4f(M4x4f a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x4d(M4x4d a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x4i(M4x4i a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d4x4u(M4x4u a)
{
    M4x3d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    return result;
}

LADEF M4x3d m4x3d_sum(M4x3d a, M4x3d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    return a;
}

LADEF M4x3d m4x3d_sub(M4x3d a, M4x3d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    return a;
}

LADEF M4x3d m4x3d_mul(M4x3d a, M4x3d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    return a;
}

LADEF M4x3d m4x3d_div(M4x3d a, M4x3d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    return a;
}

LADEF M4x3d m4x3d_mod(M4x3d a, M4x3d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmod(a.rc[2][2], b.rc[2][2]);
    a.rc[3][0] = fmod(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmod(a.rc[3][1], b.rc[3][1]);
    a.rc[3][2] = fmod(a.rc[3][2], b.rc[3][2]);
    return a;
}

LADEF M3x4d m4x3d_transpose(M4x3d a)
{
    M3x4d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    return r;
}

LADEF M4x2d m4x3d_mmul_m3x2d(M4x3d a, M3x2d b)
{
    M4x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3d m4x3d_mmul_m3x3d(M4x3d a, M3x3d b)
{
    M4x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4d m4x3d_mmul_m3x4d(M4x3d a, M3x4d b)
{
    M4x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4d m4x3d_mul_v3d(M4x3d m, V3d v)
{
    V4d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[3] = 0.0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    return r;
}

LADEF M4x3i m4x3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22, int m30, int m31, int m32)
{
    M4x3i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    return m;
}

LADEF M4x3i m4x3ii(int s)
{
    M4x3i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    return m;
}

LADEF M4x3i m4x3i2x2f(M2x2f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x2d(M2x2d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x2i(M2x2i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x2u(M2x2u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x3f(M2x3f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x3d(M2x3d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x3i(M2x3i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x3u(M2x3u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x4f(M2x4f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x4d(M2x4d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x4i(M2x4i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i2x4u(M2x4u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x2f(M3x2f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x2d(M3x2d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x2i(M3x2i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x2u(M3x2u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x3f(M3x3f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x3d(M3x3d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x3i(M3x3i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x3u(M3x3u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x4f(M3x4f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x4d(M3x4d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x4i(M3x4i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i3x4u(M3x4u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i4x2f(M4x2f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i4x2d(M4x2d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i4x2i(M4x2i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i4x2u(M4x2u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    return result;
}

LADEF M4x3i m4x3i4x3f(M4x3f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x3d(M4x3d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x3u(M4x3u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x4f(M4x4f a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x4d(M4x4d a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x4i(M4x4i a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i4x4u(M4x4u a)
{
    M4x3i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    return result;
}

LADEF M4x3i m4x3i_sum(M4x3i a, M4x3i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    return a;
}

LADEF M4x3i m4x3i_sub(M4x3i a, M4x3i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    return a;
}

LADEF M4x3i m4x3i_mul(M4x3i a, M4x3i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    return a;
}

LADEF M4x3i m4x3i_div(M4x3i a, M4x3i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    return a;
}

LADEF M4x3i m4x3i_mod(M4x3i a, M4x3i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    a.rc[3][2] %= b.rc[3][2];
    return a;
}

LADEF M3x4i m4x3i_transpose(M4x3i a)
{
    M3x4i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    return r;
}

LADEF M4x2i m4x3i_mmul_m3x2i(M4x3i a, M3x2i b)
{
    M4x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3i m4x3i_mmul_m3x3i(M4x3i a, M3x3i b)
{
    M4x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4i m4x3i_mmul_m3x4i(M4x3i a, M3x4i b)
{
    M4x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0;
    for (size_t k = 0; k < 3; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4i m4x3i_mul_v3i(M4x3i m, V3i v)
{
    V4i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[3] = 0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    return r;
}

LADEF M4x3u m4x3u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m30, unsigned int m31, unsigned int m32)
{
    M4x3u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    return m;
}

LADEF M4x3u m4x3uu(unsigned int s)
{
    M4x3u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    return m;
}

LADEF M4x3u m4x3u2x2f(M2x2f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x2d(M2x2d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x2i(M2x2i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x2u(M2x2u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x3f(M2x3f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x3d(M2x3d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x3i(M2x3i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x3u(M2x3u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x4f(M2x4f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x4d(M2x4d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x4i(M2x4i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u2x4u(M2x4u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x2f(M3x2f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x2d(M3x2d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x2i(M3x2i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x2u(M3x2u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x3f(M3x3f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x3d(M3x3d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x3i(M3x3i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x3u(M3x3u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x4f(M3x4f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x4d(M3x4d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x4i(M3x4i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u3x4u(M3x4u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u4x2f(M4x2f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u4x2d(M4x2d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u4x2i(M4x2i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u4x2u(M4x2u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    return result;
}

LADEF M4x3u m4x3u4x3f(M4x3f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x3d(M4x3d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x3i(M4x3i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x4f(M4x4f a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x4d(M4x4d a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x4i(M4x4i a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u4x4u(M4x4u a)
{
    M4x3u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    return result;
}

LADEF M4x3u m4x3u_sum(M4x3u a, M4x3u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    return a;
}

LADEF M4x3u m4x3u_sub(M4x3u a, M4x3u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    return a;
}

LADEF M4x3u m4x3u_mul(M4x3u a, M4x3u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    return a;
}

LADEF M4x3u m4x3u_div(M4x3u a, M4x3u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    return a;
}

LADEF M4x3u m4x3u_mod(M4x3u a, M4x3u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    a.rc[3][2] %= b.rc[3][2];
    return a;
}

LADEF M3x4u m4x3u_transpose(M4x3u a)
{
    M3x4u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    return r;
}

LADEF M4x2u m4x3u_mmul_m3x2u(M4x3u a, M3x2u b)
{
    M4x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3u m4x3u_mmul_m3x3u(M4x3u a, M3x3u b)
{
    M4x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4u m4x3u_mmul_m3x4u(M4x3u a, M3x4u b)
{
    M4x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0u;
    for (size_t k = 0; k < 3; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4u m4x3u_mul_v3u(M4x3u m, V3u v)
{
    V4u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[3] = 0u;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    return r;
}

LADEF M4x4f m4x4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
    M4x4f m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    m.rc[3][3] = m33;
    return m;
}

LADEF M4x4f m4x4ff(float s)
{
    M4x4f m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    m.rc[3][3] = s;
    return m;
}

LADEF M4x4f m4x4f_identity(void)
{
    M4x4f m;
    m.rc[0][0] = 0.0f;
    m.rc[0][1] = 0.0f;
    m.rc[0][2] = 0.0f;
    m.rc[0][3] = 0.0f;
    m.rc[1][0] = 0.0f;
    m.rc[1][1] = 0.0f;
    m.rc[1][2] = 0.0f;
    m.rc[1][3] = 0.0f;
    m.rc[2][0] = 0.0f;
    m.rc[2][1] = 0.0f;
    m.rc[2][2] = 0.0f;
    m.rc[2][3] = 0.0f;
    m.rc[3][0] = 0.0f;
    m.rc[3][1] = 0.0f;
    m.rc[3][2] = 0.0f;
    m.rc[3][3] = 0.0f;
    m.rc[0][0] = 1.0f;
    m.rc[1][1] = 1.0f;
    m.rc[2][2] = 1.0f;
    m.rc[3][3] = 1.0f;
    return m;
}

LADEF float m4x4f_det(M4x4f m)
{
    float a[4][4];
    for (size_t i = 0; i < 4; ++i) for (size_t j = 0; j < 4; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    float det = 1.0f;
    for (size_t i = 0; i < 4; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 4; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        if (fabsf(a[pivot][i]) < 1e-6f) return 0.0f;
        if (pivot != i) {
            for (size_t c = 0; c < 4; ++c) { float tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 4; ++r) {
            float f = a[r][i] / a[i][i];
            for (size_t c = i; c < 4; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 4; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M4x4f m4x4f_inverse(M4x4f m)
{
    float a[4][4];
    M4x4f inv;
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0f; }
        inv.rc[i][i] = 1.0f;
    }
    for (size_t i = 0; i < 4; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 4; ++r) if (fabsf(a[r][i]) > fabsf(a[pivot][i])) pivot = r;
        float piv = a[pivot][i];
        if (fabsf(piv) < 1e-6f) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 4; ++c) { float ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; float ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        float inv_piv = (float)1 / a[i][i];
        for (size_t c = 0; c < 4; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 4; ++r) if (r != i) { float f = a[r][i]; if (fabsf(f) > 0) { for (size_t c = 0; c < 4; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M4x4f m4x4f2x2f(M2x2f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x2d(M2x2d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x2i(M2x2i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x2u(M2x2u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x3f(M2x3f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x3d(M2x3d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x3i(M2x3i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x3u(M2x3u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x4f(M2x4f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x4d(M2x4d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x4i(M2x4i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f2x4u(M2x4u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = 0.0f;
    result.rc[2][1] = 0.0f;
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x2f(M3x2f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x2d(M3x2d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x2i(M3x2i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x2u(M3x2u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x3f(M3x3f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x3d(M3x3d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x3i(M3x3i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x3u(M3x3u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x4f(M3x4f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x4d(M3x4d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x4i(M3x4i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f3x4u(M3x4u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = 0.0f;
    result.rc[3][1] = 0.0f;
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x2f(M4x2f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x2d(M4x2d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x2i(M4x2i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x2u(M4x2u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = 0.0f;
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = 0.0f;
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = 0.0f;
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = 0.0f;
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x3f(M4x3f a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x3d(M4x3d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x3i(M4x3i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x3u(M4x3u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = 0.0f;
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = 0.0f;
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = 0.0f;
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = 0.0f;
    return result;
}

LADEF M4x4f m4x4f4x4d(M4x4d a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = (float) a.rc[3][3];
    return result;
}

LADEF M4x4f m4x4f4x4i(M4x4i a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = (float) a.rc[3][3];
    return result;
}

LADEF M4x4f m4x4f4x4u(M4x4u a)
{
    M4x4f result;
    result.rc[0][0] = (float) a.rc[0][0];
    result.rc[0][1] = (float) a.rc[0][1];
    result.rc[0][2] = (float) a.rc[0][2];
    result.rc[0][3] = (float) a.rc[0][3];
    result.rc[1][0] = (float) a.rc[1][0];
    result.rc[1][1] = (float) a.rc[1][1];
    result.rc[1][2] = (float) a.rc[1][2];
    result.rc[1][3] = (float) a.rc[1][3];
    result.rc[2][0] = (float) a.rc[2][0];
    result.rc[2][1] = (float) a.rc[2][1];
    result.rc[2][2] = (float) a.rc[2][2];
    result.rc[2][3] = (float) a.rc[2][3];
    result.rc[3][0] = (float) a.rc[3][0];
    result.rc[3][1] = (float) a.rc[3][1];
    result.rc[3][2] = (float) a.rc[3][2];
    result.rc[3][3] = (float) a.rc[3][3];
    return result;
}

LADEF M4x4f m4x4f_sum(M4x4f a, M4x4f b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    a.rc[3][3] += b.rc[3][3];
    return a;
}

LADEF M4x4f m4x4f_sub(M4x4f a, M4x4f b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    a.rc[3][3] -= b.rc[3][3];
    return a;
}

LADEF M4x4f m4x4f_mul(M4x4f a, M4x4f b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    a.rc[3][3] *= b.rc[3][3];
    return a;
}

LADEF M4x4f m4x4f_div(M4x4f a, M4x4f b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    a.rc[3][3] /= b.rc[3][3];
    return a;
}

LADEF M4x4f m4x4f_mod(M4x4f a, M4x4f b)
{
    a.rc[0][0] = fmodf(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmodf(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmodf(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmodf(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmodf(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmodf(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmodf(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmodf(a.rc[1][3], b.rc[1][3]);
    a.rc[2][0] = fmodf(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmodf(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmodf(a.rc[2][2], b.rc[2][2]);
    a.rc[2][3] = fmodf(a.rc[2][3], b.rc[2][3]);
    a.rc[3][0] = fmodf(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmodf(a.rc[3][1], b.rc[3][1]);
    a.rc[3][2] = fmodf(a.rc[3][2], b.rc[3][2]);
    a.rc[3][3] = fmodf(a.rc[3][3], b.rc[3][3]);
    return a;
}

LADEF M4x4f m4x4f_transpose(M4x4f a)
{
    M4x4f r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    r.rc[3][3] = a.rc[3][3];
    return r;
}

LADEF M4x2f m4x4f_mmul_m4x2f(M4x4f a, M4x2f b)
{
    M4x2f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3f m4x4f_mmul_m4x3f(M4x4f a, M4x3f b)
{
    M4x3f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4f m4x4f_mmul_m4x4f(M4x4f a, M4x4f b)
{
    M4x4f r;
    r.rc[0][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0f;
    for (size_t k = 0; k < 4; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4f m4x4f_mul_v4f(M4x4f m, V4f v)
{
    V4f r;
    r.c[0] = 0.0f;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0f;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0.0f;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    r.c[3] = 0.0f;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    r.c[3] += m.rc[3][3] * v.c[3];
    return r;
}

LADEF M4x4d m4x4d(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33)
{
    M4x4d m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    m.rc[3][3] = m33;
    return m;
}

LADEF M4x4d m4x4dd(double s)
{
    M4x4d m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    m.rc[3][3] = s;
    return m;
}

LADEF M4x4d m4x4d_identity(void)
{
    M4x4d m;
    m.rc[0][0] = 0.0;
    m.rc[0][1] = 0.0;
    m.rc[0][2] = 0.0;
    m.rc[0][3] = 0.0;
    m.rc[1][0] = 0.0;
    m.rc[1][1] = 0.0;
    m.rc[1][2] = 0.0;
    m.rc[1][3] = 0.0;
    m.rc[2][0] = 0.0;
    m.rc[2][1] = 0.0;
    m.rc[2][2] = 0.0;
    m.rc[2][3] = 0.0;
    m.rc[3][0] = 0.0;
    m.rc[3][1] = 0.0;
    m.rc[3][2] = 0.0;
    m.rc[3][3] = 0.0;
    m.rc[0][0] = 1.0;
    m.rc[1][1] = 1.0;
    m.rc[2][2] = 1.0;
    m.rc[3][3] = 1.0;
    return m;
}

LADEF double m4x4d_det(M4x4d m)
{
    double a[4][4];
    for (size_t i = 0; i < 4; ++i) for (size_t j = 0; j < 4; ++j) a[i][j] = m.rc[i][j];
    int sign = 1;
    double det = 1.0;
    for (size_t i = 0; i < 4; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 4; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        if (fabs(a[pivot][i]) < 1e-12) return 0.0;
        if (pivot != i) {
            for (size_t c = 0; c < 4; ++c) { double tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }
            sign = -sign;
        }
        for (size_t r = i+1; r < 4; ++r) {
            double f = a[r][i] / a[i][i];
            for (size_t c = i; c < 4; ++c) a[r][c] -= f * a[i][c];
        }
    }
    for (size_t i = 0; i < 4; ++i) det *= a[i][i];
    return sign < 0 ? -det : det;
}

LADEF M4x4d m4x4d_inverse(M4x4d m)
{
    double a[4][4];
    M4x4d inv;
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = 0.0; }
        inv.rc[i][i] = 1.0;
    }
    for (size_t i = 0; i < 4; ++i) {
        size_t pivot = i;
        for (size_t r = i+1; r < 4; ++r) if (fabs(a[r][i]) > fabs(a[pivot][i])) pivot = r;
        double piv = a[pivot][i];
        if (fabs(piv) < 1e-12) return inv;
        if (pivot != i) {
            for (size_t c = 0; c < 4; ++c) { double ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; double ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }
        }
        double inv_piv = (double)1 / a[i][i];
        for (size_t c = 0; c < 4; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }
        for (size_t r = 0; r < 4; ++r) if (r != i) { double f = a[r][i]; if (fabs(f) > 0) { for (size_t c = 0; c < 4; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }
    }
    return inv;
}

LADEF M4x4d m4x4d2x2f(M2x2f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x2d(M2x2d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x2i(M2x2i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x2u(M2x2u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x3f(M2x3f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x3d(M2x3d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x3i(M2x3i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x3u(M2x3u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x4f(M2x4f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x4d(M2x4d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x4i(M2x4i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d2x4u(M2x4u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = 0.0;
    result.rc[2][1] = 0.0;
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x2f(M3x2f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x2d(M3x2d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x2i(M3x2i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x2u(M3x2u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x3f(M3x3f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x3d(M3x3d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x3i(M3x3i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x3u(M3x3u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x4f(M3x4f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x4d(M3x4d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x4i(M3x4i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d3x4u(M3x4u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = 0.0;
    result.rc[3][1] = 0.0;
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x2f(M4x2f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x2d(M4x2d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x2i(M4x2i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x2u(M4x2u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = 0.0;
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = 0.0;
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = 0.0;
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = 0.0;
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x3f(M4x3f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x3d(M4x3d a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x3i(M4x3i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x3u(M4x3u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = 0.0;
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = 0.0;
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = 0.0;
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = 0.0;
    return result;
}

LADEF M4x4d m4x4d4x4f(M4x4f a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = (double) a.rc[3][3];
    return result;
}

LADEF M4x4d m4x4d4x4i(M4x4i a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = (double) a.rc[3][3];
    return result;
}

LADEF M4x4d m4x4d4x4u(M4x4u a)
{
    M4x4d result;
    result.rc[0][0] = (double) a.rc[0][0];
    result.rc[0][1] = (double) a.rc[0][1];
    result.rc[0][2] = (double) a.rc[0][2];
    result.rc[0][3] = (double) a.rc[0][3];
    result.rc[1][0] = (double) a.rc[1][0];
    result.rc[1][1] = (double) a.rc[1][1];
    result.rc[1][2] = (double) a.rc[1][2];
    result.rc[1][3] = (double) a.rc[1][3];
    result.rc[2][0] = (double) a.rc[2][0];
    result.rc[2][1] = (double) a.rc[2][1];
    result.rc[2][2] = (double) a.rc[2][2];
    result.rc[2][3] = (double) a.rc[2][3];
    result.rc[3][0] = (double) a.rc[3][0];
    result.rc[3][1] = (double) a.rc[3][1];
    result.rc[3][2] = (double) a.rc[3][2];
    result.rc[3][3] = (double) a.rc[3][3];
    return result;
}

LADEF M4x4d m4x4d_sum(M4x4d a, M4x4d b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    a.rc[3][3] += b.rc[3][3];
    return a;
}

LADEF M4x4d m4x4d_sub(M4x4d a, M4x4d b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    a.rc[3][3] -= b.rc[3][3];
    return a;
}

LADEF M4x4d m4x4d_mul(M4x4d a, M4x4d b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    a.rc[3][3] *= b.rc[3][3];
    return a;
}

LADEF M4x4d m4x4d_div(M4x4d a, M4x4d b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    a.rc[3][3] /= b.rc[3][3];
    return a;
}

LADEF M4x4d m4x4d_mod(M4x4d a, M4x4d b)
{
    a.rc[0][0] = fmod(a.rc[0][0], b.rc[0][0]);
    a.rc[0][1] = fmod(a.rc[0][1], b.rc[0][1]);
    a.rc[0][2] = fmod(a.rc[0][2], b.rc[0][2]);
    a.rc[0][3] = fmod(a.rc[0][3], b.rc[0][3]);
    a.rc[1][0] = fmod(a.rc[1][0], b.rc[1][0]);
    a.rc[1][1] = fmod(a.rc[1][1], b.rc[1][1]);
    a.rc[1][2] = fmod(a.rc[1][2], b.rc[1][2]);
    a.rc[1][3] = fmod(a.rc[1][3], b.rc[1][3]);
    a.rc[2][0] = fmod(a.rc[2][0], b.rc[2][0]);
    a.rc[2][1] = fmod(a.rc[2][1], b.rc[2][1]);
    a.rc[2][2] = fmod(a.rc[2][2], b.rc[2][2]);
    a.rc[2][3] = fmod(a.rc[2][3], b.rc[2][3]);
    a.rc[3][0] = fmod(a.rc[3][0], b.rc[3][0]);
    a.rc[3][1] = fmod(a.rc[3][1], b.rc[3][1]);
    a.rc[3][2] = fmod(a.rc[3][2], b.rc[3][2]);
    a.rc[3][3] = fmod(a.rc[3][3], b.rc[3][3]);
    return a;
}

LADEF M4x4d m4x4d_transpose(M4x4d a)
{
    M4x4d r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    r.rc[3][3] = a.rc[3][3];
    return r;
}

LADEF M4x2d m4x4d_mmul_m4x2d(M4x4d a, M4x2d b)
{
    M4x2d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3d m4x4d_mmul_m4x3d(M4x4d a, M4x3d b)
{
    M4x3d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4d m4x4d_mmul_m4x4d(M4x4d a, M4x4d b)
{
    M4x4d r;
    r.rc[0][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0.0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4d m4x4d_mul_v4d(M4x4d m, V4d v)
{
    V4d r;
    r.c[0] = 0.0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0.0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0.0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    r.c[3] = 0.0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    r.c[3] += m.rc[3][3] * v.c[3];
    return r;
}

LADEF M4x4i m4x4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23, int m30, int m31, int m32, int m33)
{
    M4x4i m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    m.rc[3][3] = m33;
    return m;
}

LADEF M4x4i m4x4ii(int s)
{
    M4x4i m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    m.rc[3][3] = s;
    return m;
}

LADEF M4x4i m4x4i_identity(void)
{
    M4x4i m;
    m.rc[0][0] = 0;
    m.rc[0][1] = 0;
    m.rc[0][2] = 0;
    m.rc[0][3] = 0;
    m.rc[1][0] = 0;
    m.rc[1][1] = 0;
    m.rc[1][2] = 0;
    m.rc[1][3] = 0;
    m.rc[2][0] = 0;
    m.rc[2][1] = 0;
    m.rc[2][2] = 0;
    m.rc[2][3] = 0;
    m.rc[3][0] = 0;
    m.rc[3][1] = 0;
    m.rc[3][2] = 0;
    m.rc[3][3] = 0;
    m.rc[0][0] = 1;
    m.rc[1][1] = 1;
    m.rc[2][2] = 1;
    m.rc[3][3] = 1;
    return m;
}



LADEF M4x4i m4x4i2x2f(M2x2f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x2d(M2x2d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x2i(M2x2i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x2u(M2x2u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x3f(M2x3f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x3d(M2x3d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x3i(M2x3i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x3u(M2x3u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x4f(M2x4f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x4d(M2x4d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x4i(M2x4i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i2x4u(M2x4u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = 0;
    result.rc[2][1] = 0;
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x2f(M3x2f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x2d(M3x2d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x2i(M3x2i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x2u(M3x2u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x3f(M3x3f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x3d(M3x3d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x3i(M3x3i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x3u(M3x3u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x4f(M3x4f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x4d(M3x4d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x4i(M3x4i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i3x4u(M3x4u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = 0;
    result.rc[3][1] = 0;
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x2f(M4x2f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x2d(M4x2d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x2i(M4x2i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x2u(M4x2u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = 0;
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = 0;
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = 0;
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = 0;
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x3f(M4x3f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x3d(M4x3d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x3i(M4x3i a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x3u(M4x3u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = 0;
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = 0;
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = 0;
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = 0;
    return result;
}

LADEF M4x4i m4x4i4x4f(M4x4f a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = (int) a.rc[3][3];
    return result;
}

LADEF M4x4i m4x4i4x4d(M4x4d a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = (int) a.rc[3][3];
    return result;
}

LADEF M4x4i m4x4i4x4u(M4x4u a)
{
    M4x4i result;
    result.rc[0][0] = (int) a.rc[0][0];
    result.rc[0][1] = (int) a.rc[0][1];
    result.rc[0][2] = (int) a.rc[0][2];
    result.rc[0][3] = (int) a.rc[0][3];
    result.rc[1][0] = (int) a.rc[1][0];
    result.rc[1][1] = (int) a.rc[1][1];
    result.rc[1][2] = (int) a.rc[1][2];
    result.rc[1][3] = (int) a.rc[1][3];
    result.rc[2][0] = (int) a.rc[2][0];
    result.rc[2][1] = (int) a.rc[2][1];
    result.rc[2][2] = (int) a.rc[2][2];
    result.rc[2][3] = (int) a.rc[2][3];
    result.rc[3][0] = (int) a.rc[3][0];
    result.rc[3][1] = (int) a.rc[3][1];
    result.rc[3][2] = (int) a.rc[3][2];
    result.rc[3][3] = (int) a.rc[3][3];
    return result;
}

LADEF M4x4i m4x4i_sum(M4x4i a, M4x4i b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    a.rc[3][3] += b.rc[3][3];
    return a;
}

LADEF M4x4i m4x4i_sub(M4x4i a, M4x4i b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    a.rc[3][3] -= b.rc[3][3];
    return a;
}

LADEF M4x4i m4x4i_mul(M4x4i a, M4x4i b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    a.rc[3][3] *= b.rc[3][3];
    return a;
}

LADEF M4x4i m4x4i_div(M4x4i a, M4x4i b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    a.rc[3][3] /= b.rc[3][3];
    return a;
}

LADEF M4x4i m4x4i_mod(M4x4i a, M4x4i b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[2][3] %= b.rc[2][3];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    a.rc[3][2] %= b.rc[3][2];
    a.rc[3][3] %= b.rc[3][3];
    return a;
}

LADEF M4x4i m4x4i_transpose(M4x4i a)
{
    M4x4i r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    r.rc[3][3] = a.rc[3][3];
    return r;
}

LADEF M4x2i m4x4i_mmul_m4x2i(M4x4i a, M4x2i b)
{
    M4x2i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3i m4x4i_mmul_m4x3i(M4x4i a, M4x3i b)
{
    M4x3i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4i m4x4i_mmul_m4x4i(M4x4i a, M4x4i b)
{
    M4x4i r;
    r.rc[0][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0;
    for (size_t k = 0; k < 4; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4i m4x4i_mul_v4i(M4x4i m, V4i v)
{
    V4i r;
    r.c[0] = 0;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    r.c[3] = 0;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    r.c[3] += m.rc[3][3] * v.c[3];
    return r;
}

LADEF M4x4u m4x4u(unsigned int m00, unsigned int m01, unsigned int m02, unsigned int m03, unsigned int m10, unsigned int m11, unsigned int m12, unsigned int m13, unsigned int m20, unsigned int m21, unsigned int m22, unsigned int m23, unsigned int m30, unsigned int m31, unsigned int m32, unsigned int m33)
{
    M4x4u m;
    m.rc[0][0] = m00;
    m.rc[0][1] = m01;
    m.rc[0][2] = m02;
    m.rc[0][3] = m03;
    m.rc[1][0] = m10;
    m.rc[1][1] = m11;
    m.rc[1][2] = m12;
    m.rc[1][3] = m13;
    m.rc[2][0] = m20;
    m.rc[2][1] = m21;
    m.rc[2][2] = m22;
    m.rc[2][3] = m23;
    m.rc[3][0] = m30;
    m.rc[3][1] = m31;
    m.rc[3][2] = m32;
    m.rc[3][3] = m33;
    return m;
}

LADEF M4x4u m4x4uu(unsigned int s)
{
    M4x4u m;
    m.rc[0][0] = s;
    m.rc[0][1] = s;
    m.rc[0][2] = s;
    m.rc[0][3] = s;
    m.rc[1][0] = s;
    m.rc[1][1] = s;
    m.rc[1][2] = s;
    m.rc[1][3] = s;
    m.rc[2][0] = s;
    m.rc[2][1] = s;
    m.rc[2][2] = s;
    m.rc[2][3] = s;
    m.rc[3][0] = s;
    m.rc[3][1] = s;
    m.rc[3][2] = s;
    m.rc[3][3] = s;
    return m;
}

LADEF M4x4u m4x4u_identity(void)
{
    M4x4u m;
    m.rc[0][0] = 0u;
    m.rc[0][1] = 0u;
    m.rc[0][2] = 0u;
    m.rc[0][3] = 0u;
    m.rc[1][0] = 0u;
    m.rc[1][1] = 0u;
    m.rc[1][2] = 0u;
    m.rc[1][3] = 0u;
    m.rc[2][0] = 0u;
    m.rc[2][1] = 0u;
    m.rc[2][2] = 0u;
    m.rc[2][3] = 0u;
    m.rc[3][0] = 0u;
    m.rc[3][1] = 0u;
    m.rc[3][2] = 0u;
    m.rc[3][3] = 0u;
    m.rc[0][0] = 1u;
    m.rc[1][1] = 1u;
    m.rc[2][2] = 1u;
    m.rc[3][3] = 1u;
    return m;
}



LADEF M4x4u m4x4u2x2f(M2x2f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x2d(M2x2d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x2i(M2x2i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x2u(M2x2u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x3f(M2x3f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x3d(M2x3d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x3i(M2x3i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x3u(M2x3u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x4f(M2x4f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x4d(M2x4d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x4i(M2x4i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u2x4u(M2x4u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = 0u;
    result.rc[2][1] = 0u;
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x2f(M3x2f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x2d(M3x2d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x2i(M3x2i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x2u(M3x2u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x3f(M3x3f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x3d(M3x3d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x3i(M3x3i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x3u(M3x3u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x4f(M3x4f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x4d(M3x4d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x4i(M3x4i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u3x4u(M3x4u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = 0u;
    result.rc[3][1] = 0u;
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x2f(M4x2f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x2d(M4x2d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x2i(M4x2i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x2u(M4x2u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = 0u;
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = 0u;
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = 0u;
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = 0u;
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x3f(M4x3f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x3d(M4x3d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x3i(M4x3i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x3u(M4x3u a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = 0u;
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = 0u;
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = 0u;
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = 0u;
    return result;
}

LADEF M4x4u m4x4u4x4f(M4x4f a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = (unsigned int) a.rc[3][3];
    return result;
}

LADEF M4x4u m4x4u4x4d(M4x4d a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = (unsigned int) a.rc[3][3];
    return result;
}

LADEF M4x4u m4x4u4x4i(M4x4i a)
{
    M4x4u result;
    result.rc[0][0] = (unsigned int) a.rc[0][0];
    result.rc[0][1] = (unsigned int) a.rc[0][1];
    result.rc[0][2] = (unsigned int) a.rc[0][2];
    result.rc[0][3] = (unsigned int) a.rc[0][3];
    result.rc[1][0] = (unsigned int) a.rc[1][0];
    result.rc[1][1] = (unsigned int) a.rc[1][1];
    result.rc[1][2] = (unsigned int) a.rc[1][2];
    result.rc[1][3] = (unsigned int) a.rc[1][3];
    result.rc[2][0] = (unsigned int) a.rc[2][0];
    result.rc[2][1] = (unsigned int) a.rc[2][1];
    result.rc[2][2] = (unsigned int) a.rc[2][2];
    result.rc[2][3] = (unsigned int) a.rc[2][3];
    result.rc[3][0] = (unsigned int) a.rc[3][0];
    result.rc[3][1] = (unsigned int) a.rc[3][1];
    result.rc[3][2] = (unsigned int) a.rc[3][2];
    result.rc[3][3] = (unsigned int) a.rc[3][3];
    return result;
}

LADEF M4x4u m4x4u_sum(M4x4u a, M4x4u b)
{
    a.rc[0][0] += b.rc[0][0];
    a.rc[0][1] += b.rc[0][1];
    a.rc[0][2] += b.rc[0][2];
    a.rc[0][3] += b.rc[0][3];
    a.rc[1][0] += b.rc[1][0];
    a.rc[1][1] += b.rc[1][1];
    a.rc[1][2] += b.rc[1][2];
    a.rc[1][3] += b.rc[1][3];
    a.rc[2][0] += b.rc[2][0];
    a.rc[2][1] += b.rc[2][1];
    a.rc[2][2] += b.rc[2][2];
    a.rc[2][3] += b.rc[2][3];
    a.rc[3][0] += b.rc[3][0];
    a.rc[3][1] += b.rc[3][1];
    a.rc[3][2] += b.rc[3][2];
    a.rc[3][3] += b.rc[3][3];
    return a;
}

LADEF M4x4u m4x4u_sub(M4x4u a, M4x4u b)
{
    a.rc[0][0] -= b.rc[0][0];
    a.rc[0][1] -= b.rc[0][1];
    a.rc[0][2] -= b.rc[0][2];
    a.rc[0][3] -= b.rc[0][3];
    a.rc[1][0] -= b.rc[1][0];
    a.rc[1][1] -= b.rc[1][1];
    a.rc[1][2] -= b.rc[1][2];
    a.rc[1][3] -= b.rc[1][3];
    a.rc[2][0] -= b.rc[2][0];
    a.rc[2][1] -= b.rc[2][1];
    a.rc[2][2] -= b.rc[2][2];
    a.rc[2][3] -= b.rc[2][3];
    a.rc[3][0] -= b.rc[3][0];
    a.rc[3][1] -= b.rc[3][1];
    a.rc[3][2] -= b.rc[3][2];
    a.rc[3][3] -= b.rc[3][3];
    return a;
}

LADEF M4x4u m4x4u_mul(M4x4u a, M4x4u b)
{
    a.rc[0][0] *= b.rc[0][0];
    a.rc[0][1] *= b.rc[0][1];
    a.rc[0][2] *= b.rc[0][2];
    a.rc[0][3] *= b.rc[0][3];
    a.rc[1][0] *= b.rc[1][0];
    a.rc[1][1] *= b.rc[1][1];
    a.rc[1][2] *= b.rc[1][2];
    a.rc[1][3] *= b.rc[1][3];
    a.rc[2][0] *= b.rc[2][0];
    a.rc[2][1] *= b.rc[2][1];
    a.rc[2][2] *= b.rc[2][2];
    a.rc[2][3] *= b.rc[2][3];
    a.rc[3][0] *= b.rc[3][0];
    a.rc[3][1] *= b.rc[3][1];
    a.rc[3][2] *= b.rc[3][2];
    a.rc[3][3] *= b.rc[3][3];
    return a;
}

LADEF M4x4u m4x4u_div(M4x4u a, M4x4u b)
{
    a.rc[0][0] /= b.rc[0][0];
    a.rc[0][1] /= b.rc[0][1];
    a.rc[0][2] /= b.rc[0][2];
    a.rc[0][3] /= b.rc[0][3];
    a.rc[1][0] /= b.rc[1][0];
    a.rc[1][1] /= b.rc[1][1];
    a.rc[1][2] /= b.rc[1][2];
    a.rc[1][3] /= b.rc[1][3];
    a.rc[2][0] /= b.rc[2][0];
    a.rc[2][1] /= b.rc[2][1];
    a.rc[2][2] /= b.rc[2][2];
    a.rc[2][3] /= b.rc[2][3];
    a.rc[3][0] /= b.rc[3][0];
    a.rc[3][1] /= b.rc[3][1];
    a.rc[3][2] /= b.rc[3][2];
    a.rc[3][3] /= b.rc[3][3];
    return a;
}

LADEF M4x4u m4x4u_mod(M4x4u a, M4x4u b)
{
    a.rc[0][0] %= b.rc[0][0];
    a.rc[0][1] %= b.rc[0][1];
    a.rc[0][2] %= b.rc[0][2];
    a.rc[0][3] %= b.rc[0][3];
    a.rc[1][0] %= b.rc[1][0];
    a.rc[1][1] %= b.rc[1][1];
    a.rc[1][2] %= b.rc[1][2];
    a.rc[1][3] %= b.rc[1][3];
    a.rc[2][0] %= b.rc[2][0];
    a.rc[2][1] %= b.rc[2][1];
    a.rc[2][2] %= b.rc[2][2];
    a.rc[2][3] %= b.rc[2][3];
    a.rc[3][0] %= b.rc[3][0];
    a.rc[3][1] %= b.rc[3][1];
    a.rc[3][2] %= b.rc[3][2];
    a.rc[3][3] %= b.rc[3][3];
    return a;
}

LADEF M4x4u m4x4u_transpose(M4x4u a)
{
    M4x4u r;
    r.rc[0][0] = a.rc[0][0];
    r.rc[1][0] = a.rc[0][1];
    r.rc[2][0] = a.rc[0][2];
    r.rc[3][0] = a.rc[0][3];
    r.rc[0][1] = a.rc[1][0];
    r.rc[1][1] = a.rc[1][1];
    r.rc[2][1] = a.rc[1][2];
    r.rc[3][1] = a.rc[1][3];
    r.rc[0][2] = a.rc[2][0];
    r.rc[1][2] = a.rc[2][1];
    r.rc[2][2] = a.rc[2][2];
    r.rc[3][2] = a.rc[2][3];
    r.rc[0][3] = a.rc[3][0];
    r.rc[1][3] = a.rc[3][1];
    r.rc[2][3] = a.rc[3][2];
    r.rc[3][3] = a.rc[3][3];
    return r;
}

LADEF M4x2u m4x4u_mmul_m4x2u(M4x4u a, M4x2u b)
{
    M4x2u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    return r;
}

LADEF M4x3u m4x4u_mmul_m4x3u(M4x4u a, M4x3u b)
{
    M4x3u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    return r;
}

LADEF M4x4u m4x4u_mmul_m4x4u(M4x4u a, M4x4u b)
{
    M4x4u r;
    r.rc[0][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][0] += a.rc[0][k] * b.rc[k][0];
    r.rc[0][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][1] += a.rc[0][k] * b.rc[k][1];
    r.rc[0][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][2] += a.rc[0][k] * b.rc[k][2];
    r.rc[0][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[0][3] += a.rc[0][k] * b.rc[k][3];
    r.rc[1][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][0] += a.rc[1][k] * b.rc[k][0];
    r.rc[1][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][1] += a.rc[1][k] * b.rc[k][1];
    r.rc[1][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][2] += a.rc[1][k] * b.rc[k][2];
    r.rc[1][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[1][3] += a.rc[1][k] * b.rc[k][3];
    r.rc[2][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][0] += a.rc[2][k] * b.rc[k][0];
    r.rc[2][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][1] += a.rc[2][k] * b.rc[k][1];
    r.rc[2][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][2] += a.rc[2][k] * b.rc[k][2];
    r.rc[2][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[2][3] += a.rc[2][k] * b.rc[k][3];
    r.rc[3][0] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][0] += a.rc[3][k] * b.rc[k][0];
    r.rc[3][1] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][1] += a.rc[3][k] * b.rc[k][1];
    r.rc[3][2] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][2] += a.rc[3][k] * b.rc[k][2];
    r.rc[3][3] = 0u;
    for (size_t k = 0; k < 4; ++k) r.rc[3][3] += a.rc[3][k] * b.rc[k][3];
    return r;
}

LADEF V4u m4x4u_mul_v4u(M4x4u m, V4u v)
{
    V4u r;
    r.c[0] = 0u;
    r.c[0] += m.rc[0][0] * v.c[0];
    r.c[0] += m.rc[0][1] * v.c[1];
    r.c[0] += m.rc[0][2] * v.c[2];
    r.c[0] += m.rc[0][3] * v.c[3];
    r.c[1] = 0u;
    r.c[1] += m.rc[1][0] * v.c[0];
    r.c[1] += m.rc[1][1] * v.c[1];
    r.c[1] += m.rc[1][2] * v.c[2];
    r.c[1] += m.rc[1][3] * v.c[3];
    r.c[2] = 0u;
    r.c[2] += m.rc[2][0] * v.c[0];
    r.c[2] += m.rc[2][1] * v.c[1];
    r.c[2] += m.rc[2][2] * v.c[2];
    r.c[2] += m.rc[2][3] * v.c[3];
    r.c[3] = 0u;
    r.c[3] += m.rc[3][0] * v.c[0];
    r.c[3] += m.rc[3][1] * v.c[1];
    r.c[3] += m.rc[3][2] * v.c[2];
    r.c[3] += m.rc[3][3] * v.c[3];
    return r;
}

LADEF R2f r2f_identity(void)
{
    R2f r;
    r.a = 1.0f; r.b01 = 0.0f;
    return r;
}
LADEF R2f r2f_mul(R2f p, R2f q)
{
    R2f r;
    r.a   = p.a*q.a - p.b01*q.b01;
    r.b01 = p.b01*q.a + p.a*q.b01;
    return r;
}
LADEF R2f r2f_reverse(R2f p)
{
    R2f r;
    r.a = p.a; r.b01 = -p.b01;
    return r;
}
LADEF float r2f_lengthsqr(R2f p)
{
    return p.a*p.a + p.b01*p.b01;
}
LADEF float r2f_length(R2f p)
{
    return sqrtf(r2f_lengthsqr(p));
}
LADEF R2f r2f_normalize(R2f p)
{
    float l = sqrtf(r2f_lengthsqr(p));
    R2f r;
    r.a = p.a / l; r.b01 = p.b01 / l;
    return r;
}
LADEF R2f r2f_normal(R2f p)
{
    return r2f_normalize(p);
}
LADEF R2f r2f_from_angle(float angle)
{
    R2f r;
    float half = angle / (float)2;
    float sa = sinf(half);
    float ca = cosf(half);
    r.a = ca; r.b01 = -sa;
    return r;
}
LADEF R2f r2f_from_unit_vectors(V2f from, V2f to)
{
    R2f r;
    r.a = (float)1 + v2f_dot(to, from);
    r.b01 = to.x*from.y - to.y*from.x;
    return r2f_normalize(r);
}
LADEF V2f r2f_rotate_v2f(R2f p, V2f x)
{
    float aa = p.a*p.a;
    float bb = p.b01*p.b01;
    float twoab = (float)2 * p.a * p.b01;
    V2f r;
    r.x = (aa - bb) * x.x + twoab * x.y;
    r.y = (aa - bb) * x.y - twoab * x.x;
    return r;
}
LADEF R2f r2f_rotate_r2f(R2f p, R2f r)
{
    return r2f_mul(r2f_mul(p, r), r2f_reverse(p));
}

LADEF R3f r3f_identity(void)
{
    R3f r;
    r.a = 1.0f; r.b01 = 0.0f;
    r.b02 = 0.0f; r.b12 = 0.0f;
    return r;
}
LADEF R3f r3f_mul(R3f p, R3f q)
{
    R3f r;
    r.a   = p.a*q.a - p.b01*q.b01 - p.b02*q.b02 - p.b12*q.b12;
    r.b01 = p.b01*q.a + p.a*q.b01 + p.b12*q.b02 - p.b02*q.b12;
    r.b02 = p.b02*q.a + p.a*q.b02 - p.b12*q.b01 + p.b01*q.b12;
    r.b12 = p.b12*q.a + p.a*q.b12 + p.b02*q.b01 - p.b01*q.b02;
    return r;
}
LADEF R3f r3f_reverse(R3f p)
{
    R3f r;
    r.a = p.a; r.b01 = -p.b01;
    r.b02 = -p.b02; r.b12 = -p.b12;
    return r;
}
LADEF float r3f_lengthsqr(R3f p)
{
    return p.a*p.a + p.b01*p.b01 + p.b02*p.b02 + p.b12*p.b12;
}
LADEF float r3f_length(R3f p)
{
    return sqrtf(r3f_lengthsqr(p));
}
LADEF R3f r3f_normalize(R3f p)
{
    float l = sqrtf(r3f_lengthsqr(p));
    R3f r;
    r.a = p.a / l; r.b01 = p.b01 / l;
    r.b02 = p.b02 / l; r.b12 = p.b12 / l;
    return r;
}
LADEF R3f r3f_normal(R3f p)
{
    return r3f_normalize(p);
}
LADEF R3f r3f_from_plane_angle(V3f bv_plane, float angle)
{
    R3f r;
    float half = angle / (float)2;
    float sa = sinf(half);
    float ca = cosf(half);
    r.a = ca;
    r.b01 = -sa * bv_plane.x;
    r.b02 = -sa * bv_plane.y;
    r.b12 = -sa * bv_plane.z;
    return r;
}
LADEF R3f r3f_from_unit_vectors(V3f from, V3f to)
{
    R3f r;
    r.a = (float)1 + v3f_dot(to, from);
    r.b01 = to.x*from.y - to.y*from.x;
    r.b02 = to.x*from.z - to.z*from.x;
    r.b12 = to.y*from.z - to.z*from.y;
    return r3f_normalize(r);
}
LADEF V3f r3f_rotate_v3f(R3f p, V3f x)
{
    float q0 = p.a*x.x + x.y*p.b01 + x.z*p.b02;
    float q1 = p.a*x.y - x.x*p.b01 + x.z*p.b12;
    float q2 = p.a*x.z - x.x*p.b02 - x.y*p.b12;
    float q012 = x.x*p.b12 - x.y*p.b02 + x.z*p.b01;
    V3f r;
    r.x = p.a*q0 + q1*p.b01 + q2*p.b02 + q012*p.b12;
    r.y = p.a*q1 - q0*p.b01 - q012*p.b02 + q2*p.b12;
    r.z = p.a*q2 + q012*p.b01 - q0*p.b02 - q1*p.b12;
    return r;
}
LADEF R3f r3f_rotate_r3f(R3f p, R3f r)
{
    return r3f_mul(r3f_mul(p, r), r3f_reverse(p));
}
LADEF M3x3f r3f_to_m3x3f(R3f p)
{
    V3f e0 = v3f((float)1, (float)0, (float)0);
    V3f e1 = v3f((float)0, (float)1, (float)0);
    V3f e2 = v3f((float)0, (float)0, (float)1);
    V3f c0 = r3f_rotate_v3f(p, e0);
    V3f c1 = r3f_rotate_v3f(p, e1);
    V3f c2 = r3f_rotate_v3f(p, e2);
    M3x3f m;
    m.rc[0][0] = c0.x; m.rc[1][0] = c0.y; m.rc[2][0] = c0.z;
    m.rc[0][1] = c1.x; m.rc[1][1] = c1.y; m.rc[2][1] = c1.z;
    m.rc[0][2] = c2.x; m.rc[1][2] = c2.y; m.rc[2][2] = c2.z;
    return m;
}

LADEF R2d r2d_identity(void)
{
    R2d r;
    r.a = 1.0; r.b01 = 0.0;
    return r;
}
LADEF R2d r2d_mul(R2d p, R2d q)
{
    R2d r;
    r.a   = p.a*q.a - p.b01*q.b01;
    r.b01 = p.b01*q.a + p.a*q.b01;
    return r;
}
LADEF R2d r2d_reverse(R2d p)
{
    R2d r;
    r.a = p.a; r.b01 = -p.b01;
    return r;
}
LADEF double r2d_lengthsqr(R2d p)
{
    return p.a*p.a + p.b01*p.b01;
}
LADEF double r2d_length(R2d p)
{
    return sqrt(r2d_lengthsqr(p));
}
LADEF R2d r2d_normalize(R2d p)
{
    double l = sqrt(r2d_lengthsqr(p));
    R2d r;
    r.a = p.a / l; r.b01 = p.b01 / l;
    return r;
}
LADEF R2d r2d_normal(R2d p)
{
    return r2d_normalize(p);
}
LADEF R2d r2d_from_angle(double angle)
{
    R2d r;
    double half = angle / (double)2;
    double sa = sin(half);
    double ca = cos(half);
    r.a = ca; r.b01 = -sa;
    return r;
}
LADEF R2d r2d_from_unit_vectors(V2d from, V2d to)
{
    R2d r;
    r.a = (double)1 + v2d_dot(to, from);
    r.b01 = to.x*from.y - to.y*from.x;
    return r2d_normalize(r);
}
LADEF V2d r2d_rotate_v2d(R2d p, V2d x)
{
    double aa = p.a*p.a;
    double bb = p.b01*p.b01;
    double twoab = (double)2 * p.a * p.b01;
    V2d r;
    r.x = (aa - bb) * x.x + twoab * x.y;
    r.y = (aa - bb) * x.y - twoab * x.x;
    return r;
}
LADEF R2d r2d_rotate_r2d(R2d p, R2d r)
{
    return r2d_mul(r2d_mul(p, r), r2d_reverse(p));
}

LADEF R3d r3d_identity(void)
{
    R3d r;
    r.a = 1.0; r.b01 = 0.0;
    r.b02 = 0.0; r.b12 = 0.0;
    return r;
}
LADEF R3d r3d_mul(R3d p, R3d q)
{
    R3d r;
    r.a   = p.a*q.a - p.b01*q.b01 - p.b02*q.b02 - p.b12*q.b12;
    r.b01 = p.b01*q.a + p.a*q.b01 + p.b12*q.b02 - p.b02*q.b12;
    r.b02 = p.b02*q.a + p.a*q.b02 - p.b12*q.b01 + p.b01*q.b12;
    r.b12 = p.b12*q.a + p.a*q.b12 + p.b02*q.b01 - p.b01*q.b02;
    return r;
}
LADEF R3d r3d_reverse(R3d p)
{
    R3d r;
    r.a = p.a; r.b01 = -p.b01;
    r.b02 = -p.b02; r.b12 = -p.b12;
    return r;
}
LADEF double r3d_lengthsqr(R3d p)
{
    return p.a*p.a + p.b01*p.b01 + p.b02*p.b02 + p.b12*p.b12;
}
LADEF double r3d_length(R3d p)
{
    return sqrt(r3d_lengthsqr(p));
}
LADEF R3d r3d_normalize(R3d p)
{
    double l = sqrt(r3d_lengthsqr(p));
    R3d r;
    r.a = p.a / l; r.b01 = p.b01 / l;
    r.b02 = p.b02 / l; r.b12 = p.b12 / l;
    return r;
}
LADEF R3d r3d_normal(R3d p)
{
    return r3d_normalize(p);
}
LADEF R3d r3d_from_plane_angle(V3d bv_plane, double angle)
{
    R3d r;
    double half = angle / (double)2;
    double sa = sin(half);
    double ca = cos(half);
    r.a = ca;
    r.b01 = -sa * bv_plane.x;
    r.b02 = -sa * bv_plane.y;
    r.b12 = -sa * bv_plane.z;
    return r;
}
LADEF R3d r3d_from_unit_vectors(V3d from, V3d to)
{
    R3d r;
    r.a = (double)1 + v3d_dot(to, from);
    r.b01 = to.x*from.y - to.y*from.x;
    r.b02 = to.x*from.z - to.z*from.x;
    r.b12 = to.y*from.z - to.z*from.y;
    return r3d_normalize(r);
}
LADEF V3d r3d_rotate_v3d(R3d p, V3d x)
{
    double q0 = p.a*x.x + x.y*p.b01 + x.z*p.b02;
    double q1 = p.a*x.y - x.x*p.b01 + x.z*p.b12;
    double q2 = p.a*x.z - x.x*p.b02 - x.y*p.b12;
    double q012 = x.x*p.b12 - x.y*p.b02 + x.z*p.b01;
    V3d r;
    r.x = p.a*q0 + q1*p.b01 + q2*p.b02 + q012*p.b12;
    r.y = p.a*q1 - q0*p.b01 - q012*p.b02 + q2*p.b12;
    r.z = p.a*q2 + q012*p.b01 - q0*p.b02 - q1*p.b12;
    return r;
}
LADEF R3d r3d_rotate_r3d(R3d p, R3d r)
{
    return r3d_mul(r3d_mul(p, r), r3d_reverse(p));
}
LADEF M3x3d r3d_to_m3x3d(R3d p)
{
    V3d e0 = v3d((double)1, (double)0, (double)0);
    V3d e1 = v3d((double)0, (double)1, (double)0);
    V3d e2 = v3d((double)0, (double)0, (double)1);
    V3d c0 = r3d_rotate_v3d(p, e0);
    V3d c1 = r3d_rotate_v3d(p, e1);
    V3d c2 = r3d_rotate_v3d(p, e2);
    M3x3d m;
    m.rc[0][0] = c0.x; m.rc[1][0] = c0.y; m.rc[2][0] = c0.z;
    m.rc[0][1] = c1.x; m.rc[1][1] = c1.y; m.rc[2][1] = c1.z;
    m.rc[0][2] = c2.x; m.rc[1][2] = c2.y; m.rc[2][2] = c2.z;
    return m;
}

#endif // LA_IMPLEMENTATION
