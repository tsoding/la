#ifndef LA_H_
#define LA_H_

#include <math.h>
#include <stdbool.h>

#ifndef LADEF
#define LADEF static inline
#endif // LADEF

LADEF float lerpf(float a, float b, float t);
LADEF double lerp(double a, double b, double t);
LADEF int mini(int a, int b);
LADEF unsigned int minu(unsigned int a, unsigned int b);
LADEF int maxi(int a, int b);
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
    struct {
        float _11, _12;
        float _21, _22;
    };
    V2f v[2];
    float m[2][2];
    float c[4];
} M2f;

typedef union {
    struct { double x, y; };
    double c[2];
} V2d;

typedef union {
    struct {
        double _11, _12;
        double _21, _22;
    };
    V2d v[2];
    double m[2][2];
    double c[4];
} M2d;

typedef union {
    struct { int x, y; };
    int c[2];
} V2i;

typedef union {
    struct {
        int _11, _12;
        int _21, _22;
    };
    V2i v[2];
    int m[2][2];
    int c[4];
} M2i;

typedef union {
    struct { unsigned int x, y; };
    unsigned int c[2];
} V2u;

typedef union {
    struct {
        unsigned int _11, _12;
        unsigned int _21, _22;
    };
    V2u v[2];
    unsigned int m[2][2];
    unsigned int c[4];
} M2u;

typedef union {
    struct { float x, y, z; };
    float c[3];
} V3f;

typedef union {
    struct {
        float _11, _12, _13;
        float _21, _22, _23;
        float _31, _32, _33;
    };
    V3f v[3];
    float m[3][3];
    float c[9];
} M3f;

typedef union {
    struct { double x, y, z; };
    double c[3];
} V3d;

typedef union {
    struct {
        double _11, _12, _13;
        double _21, _22, _23;
        double _31, _32, _33;
    };
    V3d v[3];
    double m[3][3];
    double c[9];
} M3d;

typedef union {
    struct { int x, y, z; };
    int c[3];
} V3i;

typedef union {
    struct {
        int _11, _12, _13;
        int _21, _22, _23;
        int _31, _32, _33;
    };
    V3i v[3];
    int m[3][3];
    int c[9];
} M3i;

typedef union {
    struct { unsigned int x, y, z; };
    unsigned int c[3];
} V3u;

typedef union {
    struct {
        unsigned int _11, _12, _13;
        unsigned int _21, _22, _23;
        unsigned int _31, _32, _33;
    };
    V3u v[3];
    unsigned int m[3][3];
    unsigned int c[9];
} M3u;

typedef union {
    struct { float x, y, z, w; };
    struct { V2f xy; V2f zw; };
    float c[4];
} V4f;

typedef union {
    struct {
        float _11, _12, _13, _14;
        float _21, _22, _23, _24;
        float _31, _32, _33, _34;
        float _41, _42, _43, _44;
    };
    V4f v[4];
    float m[4][4];
    float c[16];
} M4f;

typedef union {
    struct { double x, y, z, w; };
    struct { V2d xy; V2d zw; };
    double c[4];
} V4d;

typedef union {
    struct {
        double _11, _12, _13, _14;
        double _21, _22, _23, _24;
        double _31, _32, _33, _34;
        double _41, _42, _43, _44;
    };
    V4d v[4];
    double m[4][4];
    double c[16];
} M4d;

typedef union {
    struct { int x, y, z, w; };
    struct { V2i xy; V2i zw; };
    int c[4];
} V4i;

typedef union {
    struct {
        int _11, _12, _13, _14;
        int _21, _22, _23, _24;
        int _31, _32, _33, _34;
        int _41, _42, _43, _44;
    };
    V4i v[4];
    int m[4][4];
    int c[16];
} M4i;

typedef union {
    struct { unsigned int x, y, z, w; };
    struct { V2u xy; V2u zw; };
    unsigned int c[4];
} V4u;

typedef union {
    struct {
        unsigned int _11, _12, _13, _14;
        unsigned int _21, _22, _23, _24;
        unsigned int _31, _32, _33, _34;
        unsigned int _41, _42, _43, _44;
    };
    V4u v[4];
    unsigned int m[4][4];
    unsigned int c[16];
} M4u;

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
LADEF V2f v2f_add(V2f a, V2f b);
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
LADEF float v2f_dot(V2f a, V2f b);
LADEF V2f v2f_norm(V2f a, float eps, V2f fallback);
LADEF bool v2f_eq(V2f a, V2f b, float eps);
LADEF V2f v2f_reflect(V2f i, V2f n);
LADEF M2f m2f_id(void);
LADEF M2f m2f_zero(void);
LADEF M2f m2f_mul(M2f a, M2f b);
LADEF V2f m2f_mul_vec(M2f m, V2f v);
LADEF M2f m2f_rot(float angle);

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
LADEF V2d v2d_add(V2d a, V2d b);
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
LADEF double v2d_dot(V2d a, V2d b);
LADEF V2d v2d_norm(V2d a, double eps, V2d fallback);
LADEF bool v2d_eq(V2d a, V2d b, double eps);
LADEF V2d v2d_reflect(V2d i, V2d n);
LADEF M2d m2d_id(void);
LADEF M2d m2d_zero(void);
LADEF M2d m2d_mul(M2d a, M2d b);
LADEF V2d m2d_mul_vec(M2d m, V2d v);
LADEF M2d m2d_rot(double angle);

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
LADEF V2i v2i_add(V2i a, V2i b);
LADEF V2i v2i_sub(V2i a, V2i b);
LADEF V2i v2i_mul(V2i a, V2i b);
LADEF V2i v2i_div(V2i a, V2i b);
LADEF V2i v2i_mod(V2i a, V2i b);
LADEF V2i v2i_min(V2i a, V2i b);
LADEF V2i v2i_max(V2i a, V2i b);
LADEF V2i v2i_clamp(V2i x, V2i a, V2i b);
LADEF int v2i_sqrlen(V2i a);
LADEF int v2i_dot(V2i a, V2i b);
LADEF bool v2i_eq(V2i a, V2i b);
LADEF V2i v2i_reflect(V2i i, V2i n);
LADEF M2i m2i_id(void);
LADEF M2i m2i_zero(void);
LADEF M2i m2i_mul(M2i a, M2i b);
LADEF V2i m2i_mul_vec(M2i m, V2i v);

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
LADEF V2u v2u_add(V2u a, V2u b);
LADEF V2u v2u_sub(V2u a, V2u b);
LADEF V2u v2u_mul(V2u a, V2u b);
LADEF V2u v2u_div(V2u a, V2u b);
LADEF V2u v2u_mod(V2u a, V2u b);
LADEF V2u v2u_min(V2u a, V2u b);
LADEF V2u v2u_max(V2u a, V2u b);
LADEF V2u v2u_clamp(V2u x, V2u a, V2u b);
LADEF unsigned int v2u_sqrlen(V2u a);
LADEF unsigned int v2u_dot(V2u a, V2u b);
LADEF bool v2u_eq(V2u a, V2u b);
LADEF V2u v2u_reflect(V2u i, V2u n);
LADEF M2u m2u_id(void);
LADEF M2u m2u_zero(void);
LADEF M2u m2u_mul(M2u a, M2u b);
LADEF V2u m2u_mul_vec(M2u m, V2u v);

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
LADEF V3f v3f_add(V3f a, V3f b);
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
LADEF float v3f_dot(V3f a, V3f b);
LADEF V3f v3f_norm(V3f a, float eps, V3f fallback);
LADEF V3f v3f_cross(V3f a, V3f b);
LADEF bool v3f_eq(V3f a, V3f b, float eps);
LADEF V3f v3f_reflect(V3f i, V3f n);
LADEF M3f m3f_id(void);
LADEF M3f m3f_zero(void);
LADEF M3f m3f_mul(M3f a, M3f b);
LADEF V3f m3f_mul_vec(M3f m, V3f v);
LADEF M3f m3f_rot_x(float angle);
LADEF M3f m3f_rot_y(float angle);
LADEF M3f m3f_rot_z(float angle);

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
LADEF V3d v3d_add(V3d a, V3d b);
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
LADEF double v3d_dot(V3d a, V3d b);
LADEF V3d v3d_norm(V3d a, double eps, V3d fallback);
LADEF V3d v3d_cross(V3d a, V3d b);
LADEF bool v3d_eq(V3d a, V3d b, double eps);
LADEF V3d v3d_reflect(V3d i, V3d n);
LADEF M3d m3d_id(void);
LADEF M3d m3d_zero(void);
LADEF M3d m3d_mul(M3d a, M3d b);
LADEF V3d m3d_mul_vec(M3d m, V3d v);
LADEF M3d m3d_rot_x(double angle);
LADEF M3d m3d_rot_y(double angle);
LADEF M3d m3d_rot_z(double angle);

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
LADEF V3i v3i_add(V3i a, V3i b);
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
LADEF bool v3i_eq(V3i a, V3i b);
LADEF V3i v3i_reflect(V3i i, V3i n);
LADEF M3i m3i_id(void);
LADEF M3i m3i_zero(void);
LADEF M3i m3i_mul(M3i a, M3i b);
LADEF V3i m3i_mul_vec(M3i m, V3i v);

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
LADEF V3u v3u_add(V3u a, V3u b);
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
LADEF bool v3u_eq(V3u a, V3u b);
LADEF V3u v3u_reflect(V3u i, V3u n);
LADEF M3u m3u_id(void);
LADEF M3u m3u_zero(void);
LADEF M3u m3u_mul(M3u a, M3u b);
LADEF V3u m3u_mul_vec(M3u m, V3u v);

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
LADEF V4f v4f_add(V4f a, V4f b);
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
LADEF float v4f_dot(V4f a, V4f b);
LADEF V4f v4f_norm(V4f a, float eps, V4f fallback);
LADEF bool v4f_eq(V4f a, V4f b, float eps);
LADEF V4f v4f_reflect(V4f i, V4f n);
LADEF M4f m4f_id(void);
LADEF M4f m4f_zero(void);
LADEF M4f m4f_mul(M4f a, M4f b);
LADEF V4f m4f_mul_vec(M4f m, V4f v);
LADEF M4f m4f_rot_x(float angle);
LADEF M4f m4f_rot_y(float angle);
LADEF M4f m4f_rot_z(float angle);

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
LADEF V4d v4d_add(V4d a, V4d b);
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
LADEF double v4d_dot(V4d a, V4d b);
LADEF V4d v4d_norm(V4d a, double eps, V4d fallback);
LADEF bool v4d_eq(V4d a, V4d b, double eps);
LADEF V4d v4d_reflect(V4d i, V4d n);
LADEF M4d m4d_id(void);
LADEF M4d m4d_zero(void);
LADEF M4d m4d_mul(M4d a, M4d b);
LADEF V4d m4d_mul_vec(M4d m, V4d v);
LADEF M4d m4d_rot_x(double angle);
LADEF M4d m4d_rot_y(double angle);
LADEF M4d m4d_rot_z(double angle);

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
LADEF V4i v4i_add(V4i a, V4i b);
LADEF V4i v4i_sub(V4i a, V4i b);
LADEF V4i v4i_mul(V4i a, V4i b);
LADEF V4i v4i_div(V4i a, V4i b);
LADEF V4i v4i_mod(V4i a, V4i b);
LADEF V4i v4i_min(V4i a, V4i b);
LADEF V4i v4i_max(V4i a, V4i b);
LADEF V4i v4i_clamp(V4i x, V4i a, V4i b);
LADEF int v4i_sqrlen(V4i a);
LADEF int v4i_dot(V4i a, V4i b);
LADEF bool v4i_eq(V4i a, V4i b);
LADEF V4i v4i_reflect(V4i i, V4i n);
LADEF M4i m4i_id(void);
LADEF M4i m4i_zero(void);
LADEF M4i m4i_mul(M4i a, M4i b);
LADEF V4i m4i_mul_vec(M4i m, V4i v);

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
LADEF V4u v4u_add(V4u a, V4u b);
LADEF V4u v4u_sub(V4u a, V4u b);
LADEF V4u v4u_mul(V4u a, V4u b);
LADEF V4u v4u_div(V4u a, V4u b);
LADEF V4u v4u_mod(V4u a, V4u b);
LADEF V4u v4u_min(V4u a, V4u b);
LADEF V4u v4u_max(V4u a, V4u b);
LADEF V4u v4u_clamp(V4u x, V4u a, V4u b);
LADEF unsigned int v4u_sqrlen(V4u a);
LADEF unsigned int v4u_dot(V4u a, V4u b);
LADEF bool v4u_eq(V4u a, V4u b);
LADEF V4u v4u_reflect(V4u i, V4u n);
LADEF M4u m4u_id(void);
LADEF M4u m4u_zero(void);
LADEF M4u m4u_mul(M4u a, M4u b);
LADEF V4u m4u_mul_vec(M4u m, V4u v);

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

LADEF unsigned int minu(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

LADEF int maxi(int a, int b)
{
    return a > b ? a : b;
}

LADEF unsigned int maxu(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

LADEF float clampf(float x, float a, float b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF double clampd(double x, double a, double b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF int clampi(int x, int a, int b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF unsigned int clampu(unsigned int x, unsigned int a, unsigned int b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
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

LADEF V2f v2f_add(V2f a, V2f b)
{
    return v2f_sum(a, b);
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
    return v2f_dot(a, a);
}

LADEF float v2f_len(V2f a)
{
    return sqrtf(v2f_sqrlen(a));
}

LADEF float v2f_dot(V2f a, V2f b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2f v2f_norm(V2f a, float eps, V2f fallback)
{
    float l = v2f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v2f_div(a, v2ff(l));
}

LADEF bool v2f_eq(V2f a, V2f b, float eps)
{
    if (fabsf(b.x - a.x) <= eps) return false;
    if (fabsf(b.y - a.y) <= eps) return false;
    return true;
}

LADEF V2f v2f_reflect(V2f i, V2f n)
{
    V2f r = n;
    r = v2f_mul(r, v2ff(v2f_dot(n, i)));
    r = v2f_mul(r, v2ff(2));
    r = v2f_sub(i, r);
    return r;
}

LADEF M2f m2f_id(void)
{
    M2f m = m2f_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2f m2f_zero(void)
{
    M2f m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2f m2f_mul(M2f a, M2f b)
{
    M2f m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2f m2f_mul_vec(M2f m, V2f v)
{
    V2f r;
    r.x = v2f_dot(m.v[0], v);
    r.y = v2f_dot(m.v[1], v);
    return r;
}

LADEF M2f m2f_rot(float angle)
{
    M2f m;
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
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

LADEF V2d v2d_add(V2d a, V2d b)
{
    return v2d_sum(a, b);
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
    return v2d_dot(a, a);
}

LADEF double v2d_len(V2d a)
{
    return sqrt(v2d_sqrlen(a));
}

LADEF double v2d_dot(V2d a, V2d b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2d v2d_norm(V2d a, double eps, V2d fallback)
{
    double l = v2d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v2d_div(a, v2dd(l));
}

LADEF bool v2d_eq(V2d a, V2d b, double eps)
{
    if (fabs(b.x - a.x) <= eps) return false;
    if (fabs(b.y - a.y) <= eps) return false;
    return true;
}

LADEF V2d v2d_reflect(V2d i, V2d n)
{
    V2d r = n;
    r = v2d_mul(r, v2dd(v2d_dot(n, i)));
    r = v2d_mul(r, v2dd(2));
    r = v2d_sub(i, r);
    return r;
}

LADEF M2d m2d_id(void)
{
    M2d m = m2d_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2d m2d_zero(void)
{
    M2d m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2d m2d_mul(M2d a, M2d b)
{
    M2d m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2d m2d_mul_vec(M2d m, V2d v)
{
    V2d r;
    r.x = v2d_dot(m.v[0], v);
    r.y = v2d_dot(m.v[1], v);
    return r;
}

LADEF M2d m2d_rot(double angle)
{
    M2d m;
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
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

LADEF V2i v2i_add(V2i a, V2i b)
{
    return v2i_sum(a, b);
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
    return v2i_dot(a, a);
}

LADEF int v2i_dot(V2i a, V2i b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF bool v2i_eq(V2i a, V2i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    return true;
}

LADEF V2i v2i_reflect(V2i i, V2i n)
{
    V2i r = n;
    r = v2i_mul(r, v2ii(v2i_dot(n, i)));
    r = v2i_mul(r, v2ii(2));
    r = v2i_sub(i, r);
    return r;
}

LADEF M2i m2i_id(void)
{
    M2i m = m2i_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2i m2i_zero(void)
{
    M2i m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2i m2i_mul(M2i a, M2i b)
{
    M2i m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2i m2i_mul_vec(M2i m, V2i v)
{
    V2i r;
    r.x = v2i_dot(m.v[0], v);
    r.y = v2i_dot(m.v[1], v);
    return r;
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

LADEF V2u v2u_add(V2u a, V2u b)
{
    return v2u_sum(a, b);
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
    return v2u_dot(a, a);
}

LADEF unsigned int v2u_dot(V2u a, V2u b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF bool v2u_eq(V2u a, V2u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    return true;
}

LADEF V2u v2u_reflect(V2u i, V2u n)
{
    V2u r = n;
    r = v2u_mul(r, v2uu(v2u_dot(n, i)));
    r = v2u_mul(r, v2uu(2));
    r = v2u_sub(i, r);
    return r;
}

LADEF M2u m2u_id(void)
{
    M2u m = m2u_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2u m2u_zero(void)
{
    M2u m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2u m2u_mul(M2u a, M2u b)
{
    M2u m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2u m2u_mul_vec(M2u m, V2u v)
{
    V2u r;
    r.x = v2u_dot(m.v[0], v);
    r.y = v2u_dot(m.v[1], v);
    return r;
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

LADEF V3f v3f_add(V3f a, V3f b)
{
    return v3f_sum(a, b);
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
    return v3f_dot(a, a);
}

LADEF float v3f_len(V3f a)
{
    return sqrtf(v3f_sqrlen(a));
}

LADEF float v3f_dot(V3f a, V3f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3f v3f_norm(V3f a, float eps, V3f fallback)
{
    float l = v3f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v3f_div(a, v3ff(l));
}

LADEF V3f v3f_cross(V3f a, V3f b)
{
    V3f n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3f_eq(V3f a, V3f b, float eps)
{
    if (fabsf(b.x - a.x) <= eps) return false;
    if (fabsf(b.y - a.y) <= eps) return false;
    if (fabsf(b.z - a.z) <= eps) return false;
    return true;
}

LADEF V3f v3f_reflect(V3f i, V3f n)
{
    V3f r = n;
    r = v3f_mul(r, v3ff(v3f_dot(n, i)));
    r = v3f_mul(r, v3ff(2));
    r = v3f_sub(i, r);
    return r;
}

LADEF M3f m3f_id(void)
{
    M3f m = m3f_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3f m3f_zero(void)
{
    M3f m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3f m3f_mul(M3f a, M3f b)
{
    M3f m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3f m3f_mul_vec(M3f m, V3f v)
{
    V3f r;
    r.x = v3f_dot(m.v[0], v);
    r.y = v3f_dot(m.v[1], v);
    r.z = v3f_dot(m.v[2], v);
    return r;
}

LADEF M3f m3f_rot_x(float angle)
{
    M3f m = m3f_id();
    m._22 = cosf(angle);
    m._23 = -sinf(angle);
    m._32 = sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M3f m3f_rot_y(float angle)
{
    M3f m = m3f_id();
    m._11 = cosf(angle);
    m._13 = sinf(angle);
    m._31 = -sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M3f m3f_rot_z(float angle)
{
    M3f m = m3f_id();
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
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

LADEF V3d v3d_add(V3d a, V3d b)
{
    return v3d_sum(a, b);
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
    return v3d_dot(a, a);
}

LADEF double v3d_len(V3d a)
{
    return sqrt(v3d_sqrlen(a));
}

LADEF double v3d_dot(V3d a, V3d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3d v3d_norm(V3d a, double eps, V3d fallback)
{
    double l = v3d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v3d_div(a, v3dd(l));
}

LADEF V3d v3d_cross(V3d a, V3d b)
{
    V3d n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3d_eq(V3d a, V3d b, double eps)
{
    if (fabs(b.x - a.x) <= eps) return false;
    if (fabs(b.y - a.y) <= eps) return false;
    if (fabs(b.z - a.z) <= eps) return false;
    return true;
}

LADEF V3d v3d_reflect(V3d i, V3d n)
{
    V3d r = n;
    r = v3d_mul(r, v3dd(v3d_dot(n, i)));
    r = v3d_mul(r, v3dd(2));
    r = v3d_sub(i, r);
    return r;
}

LADEF M3d m3d_id(void)
{
    M3d m = m3d_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3d m3d_zero(void)
{
    M3d m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3d m3d_mul(M3d a, M3d b)
{
    M3d m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3d m3d_mul_vec(M3d m, V3d v)
{
    V3d r;
    r.x = v3d_dot(m.v[0], v);
    r.y = v3d_dot(m.v[1], v);
    r.z = v3d_dot(m.v[2], v);
    return r;
}

LADEF M3d m3d_rot_x(double angle)
{
    M3d m = m3d_id();
    m._22 = cos(angle);
    m._23 = -sin(angle);
    m._32 = sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M3d m3d_rot_y(double angle)
{
    M3d m = m3d_id();
    m._11 = cos(angle);
    m._13 = sin(angle);
    m._31 = -sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M3d m3d_rot_z(double angle)
{
    M3d m = m3d_id();
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
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

LADEF V3i v3i_add(V3i a, V3i b)
{
    return v3i_sum(a, b);
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
    return v3i_dot(a, a);
}

LADEF int v3i_dot(V3i a, V3i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3i v3i_cross(V3i a, V3i b)
{
    V3i n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3i_eq(V3i a, V3i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    return true;
}

LADEF V3i v3i_reflect(V3i i, V3i n)
{
    V3i r = n;
    r = v3i_mul(r, v3ii(v3i_dot(n, i)));
    r = v3i_mul(r, v3ii(2));
    r = v3i_sub(i, r);
    return r;
}

LADEF M3i m3i_id(void)
{
    M3i m = m3i_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3i m3i_zero(void)
{
    M3i m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3i m3i_mul(M3i a, M3i b)
{
    M3i m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3i m3i_mul_vec(M3i m, V3i v)
{
    V3i r;
    r.x = v3i_dot(m.v[0], v);
    r.y = v3i_dot(m.v[1], v);
    r.z = v3i_dot(m.v[2], v);
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

LADEF V3u v3u_add(V3u a, V3u b)
{
    return v3u_sum(a, b);
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
    return v3u_dot(a, a);
}

LADEF unsigned int v3u_dot(V3u a, V3u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3u v3u_cross(V3u a, V3u b)
{
    V3u n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3u_eq(V3u a, V3u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    return true;
}

LADEF V3u v3u_reflect(V3u i, V3u n)
{
    V3u r = n;
    r = v3u_mul(r, v3uu(v3u_dot(n, i)));
    r = v3u_mul(r, v3uu(2));
    r = v3u_sub(i, r);
    return r;
}

LADEF M3u m3u_id(void)
{
    M3u m = m3u_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3u m3u_zero(void)
{
    M3u m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3u m3u_mul(M3u a, M3u b)
{
    M3u m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3u m3u_mul_vec(M3u m, V3u v)
{
    V3u r;
    r.x = v3u_dot(m.v[0], v);
    r.y = v3u_dot(m.v[1], v);
    r.z = v3u_dot(m.v[2], v);
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

LADEF V4f v4f_add(V4f a, V4f b)
{
    return v4f_sum(a, b);
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
    return v4f_dot(a, a);
}

LADEF float v4f_len(V4f a)
{
    return sqrtf(v4f_sqrlen(a));
}

LADEF float v4f_dot(V4f a, V4f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4f v4f_norm(V4f a, float eps, V4f fallback)
{
    float l = v4f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v4f_div(a, v4ff(l));
}

LADEF bool v4f_eq(V4f a, V4f b, float eps)
{
    if (fabsf(b.x - a.x) <= eps) return false;
    if (fabsf(b.y - a.y) <= eps) return false;
    if (fabsf(b.z - a.z) <= eps) return false;
    if (fabsf(b.w - a.w) <= eps) return false;
    return true;
}

LADEF V4f v4f_reflect(V4f i, V4f n)
{
    V4f r = n;
    r = v4f_mul(r, v4ff(v4f_dot(n, i)));
    r = v4f_mul(r, v4ff(2));
    r = v4f_sub(i, r);
    return r;
}

LADEF M4f m4f_id(void)
{
    M4f m = m4f_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4f m4f_zero(void)
{
    M4f m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4f m4f_mul(M4f a, M4f b)
{
    M4f m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4f m4f_mul_vec(M4f m, V4f v)
{
    V4f r;
    r.x = v4f_dot(m.v[0], v);
    r.y = v4f_dot(m.v[1], v);
    r.z = v4f_dot(m.v[2], v);
    r.w = v4f_dot(m.v[3], v);
    return r;
}

LADEF M4f m4f_rot_x(float angle)
{
    M4f m = m4f_id();
    m._22 = cosf(angle);
    m._23 = -sinf(angle);
    m._32 = sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M4f m4f_rot_y(float angle)
{
    M4f m = m4f_id();
    m._11 = cosf(angle);
    m._13 = sinf(angle);
    m._31 = -sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M4f m4f_rot_z(float angle)
{
    M4f m = m4f_id();
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
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

LADEF V4d v4d_add(V4d a, V4d b)
{
    return v4d_sum(a, b);
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
    return v4d_dot(a, a);
}

LADEF double v4d_len(V4d a)
{
    return sqrt(v4d_sqrlen(a));
}

LADEF double v4d_dot(V4d a, V4d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4d v4d_norm(V4d a, double eps, V4d fallback)
{
    double l = v4d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v4d_div(a, v4dd(l));
}

LADEF bool v4d_eq(V4d a, V4d b, double eps)
{
    if (fabs(b.x - a.x) <= eps) return false;
    if (fabs(b.y - a.y) <= eps) return false;
    if (fabs(b.z - a.z) <= eps) return false;
    if (fabs(b.w - a.w) <= eps) return false;
    return true;
}

LADEF V4d v4d_reflect(V4d i, V4d n)
{
    V4d r = n;
    r = v4d_mul(r, v4dd(v4d_dot(n, i)));
    r = v4d_mul(r, v4dd(2));
    r = v4d_sub(i, r);
    return r;
}

LADEF M4d m4d_id(void)
{
    M4d m = m4d_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4d m4d_zero(void)
{
    M4d m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4d m4d_mul(M4d a, M4d b)
{
    M4d m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4d m4d_mul_vec(M4d m, V4d v)
{
    V4d r;
    r.x = v4d_dot(m.v[0], v);
    r.y = v4d_dot(m.v[1], v);
    r.z = v4d_dot(m.v[2], v);
    r.w = v4d_dot(m.v[3], v);
    return r;
}

LADEF M4d m4d_rot_x(double angle)
{
    M4d m = m4d_id();
    m._22 = cos(angle);
    m._23 = -sin(angle);
    m._32 = sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M4d m4d_rot_y(double angle)
{
    M4d m = m4d_id();
    m._11 = cos(angle);
    m._13 = sin(angle);
    m._31 = -sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M4d m4d_rot_z(double angle)
{
    M4d m = m4d_id();
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
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

LADEF V4i v4i_add(V4i a, V4i b)
{
    return v4i_sum(a, b);
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
    return v4i_dot(a, a);
}

LADEF int v4i_dot(V4i a, V4i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF bool v4i_eq(V4i a, V4i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    if (a.w != b.w) return false;
    return true;
}

LADEF V4i v4i_reflect(V4i i, V4i n)
{
    V4i r = n;
    r = v4i_mul(r, v4ii(v4i_dot(n, i)));
    r = v4i_mul(r, v4ii(2));
    r = v4i_sub(i, r);
    return r;
}

LADEF M4i m4i_id(void)
{
    M4i m = m4i_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4i m4i_zero(void)
{
    M4i m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4i m4i_mul(M4i a, M4i b)
{
    M4i m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4i m4i_mul_vec(M4i m, V4i v)
{
    V4i r;
    r.x = v4i_dot(m.v[0], v);
    r.y = v4i_dot(m.v[1], v);
    r.z = v4i_dot(m.v[2], v);
    r.w = v4i_dot(m.v[3], v);
    return r;
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

LADEF V4u v4u_add(V4u a, V4u b)
{
    return v4u_sum(a, b);
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
    return v4u_dot(a, a);
}

LADEF unsigned int v4u_dot(V4u a, V4u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF bool v4u_eq(V4u a, V4u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    if (a.w != b.w) return false;
    return true;
}

LADEF V4u v4u_reflect(V4u i, V4u n)
{
    V4u r = n;
    r = v4u_mul(r, v4uu(v4u_dot(n, i)));
    r = v4u_mul(r, v4uu(2));
    r = v4u_sub(i, r);
    return r;
}

LADEF M4u m4u_id(void)
{
    M4u m = m4u_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4u m4u_zero(void)
{
    M4u m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4u m4u_mul(M4u a, M4u b)
{
    M4u m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4u m4u_mul_vec(M4u m, V4u v)
{
    V4u r;
    r.x = v4u_dot(m.v[0], v);
    r.y = v4u_dot(m.v[1], v);
    r.z = v4u_dot(m.v[2], v);
    r.w = v4u_dot(m.v[3], v);
    return r;
}

#endif // LA_IMPLEMENTATION
