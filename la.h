#ifndef LA_H_
#define LA_H_

typedef struct { float c[2]; } V2f;
V2f v2f_sum(V2f a, V2f b);
V2f v2f_sub(V2f a, V2f b);
V2f v2f_mul(V2f a, V2f b);
V2f v2f_div(V2f a, V2f b);
V2f v2f(float x0, float x1);
V2f v2fs(float x);

typedef struct { double c[2]; } V2d;
V2d v2d_sum(V2d a, V2d b);
V2d v2d_sub(V2d a, V2d b);
V2d v2d_mul(V2d a, V2d b);
V2d v2d_div(V2d a, V2d b);
V2d v2d(double x0, double x1);
V2d v2ds(double x);

typedef struct { int c[2]; } V2i;
V2i v2i_sum(V2i a, V2i b);
V2i v2i_sub(V2i a, V2i b);
V2i v2i_mul(V2i a, V2i b);
V2i v2i_div(V2i a, V2i b);
V2i v2i(int x0, int x1);
V2i v2is(int x);

typedef struct { float c[3]; } V3f;
V3f v3f_sum(V3f a, V3f b);
V3f v3f_sub(V3f a, V3f b);
V3f v3f_mul(V3f a, V3f b);
V3f v3f_div(V3f a, V3f b);
V3f v3f(float x0, float x1, float x2);
V3f v3fs(float x);

typedef struct { double c[3]; } V3d;
V3d v3d_sum(V3d a, V3d b);
V3d v3d_sub(V3d a, V3d b);
V3d v3d_mul(V3d a, V3d b);
V3d v3d_div(V3d a, V3d b);
V3d v3d(double x0, double x1, double x2);
V3d v3ds(double x);

typedef struct { int c[3]; } V3i;
V3i v3i_sum(V3i a, V3i b);
V3i v3i_sub(V3i a, V3i b);
V3i v3i_mul(V3i a, V3i b);
V3i v3i_div(V3i a, V3i b);
V3i v3i(int x0, int x1, int x2);
V3i v3is(int x);

typedef struct { float c[4]; } V4f;
V4f v4f_sum(V4f a, V4f b);
V4f v4f_sub(V4f a, V4f b);
V4f v4f_mul(V4f a, V4f b);
V4f v4f_div(V4f a, V4f b);
V4f v4f(float x0, float x1, float x2, float x3);
V4f v4fs(float x);

typedef struct { double c[4]; } V4d;
V4d v4d_sum(V4d a, V4d b);
V4d v4d_sub(V4d a, V4d b);
V4d v4d_mul(V4d a, V4d b);
V4d v4d_div(V4d a, V4d b);
V4d v4d(double x0, double x1, double x2, double x3);
V4d v4ds(double x);

typedef struct { int c[4]; } V4i;
V4i v4i_sum(V4i a, V4i b);
V4i v4i_sub(V4i a, V4i b);
V4i v4i_mul(V4i a, V4i b);
V4i v4i_div(V4i a, V4i b);
V4i v4i(int x0, int x1, int x2, int x3);
V4i v4is(int x);

#endif // LA_H_

#ifdef LA_IMPLEMENTATION

V2f v2f_sum(V2f a, V2f b)
{
    for (int i = 0; i < 2; ++i) a.c[i] += b.c[i];
    return a;
}
V2f v2f_sub(V2f a, V2f b)
{
    for (int i = 0; i < 2; ++i) a.c[i] -= b.c[i];
    return a;
}
V2f v2f_mul(V2f a, V2f b)
{
    for (int i = 0; i < 2; ++i) a.c[i] *= b.c[i];
    return a;
}
V2f v2f_div(V2f a, V2f b)
{
    for (int i = 0; i < 2; ++i) a.c[i] /= b.c[i];
    return a;
}

V2f v2f(float x0, float x1)
{
    V2f result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}

V2f v2fs(float x)
{
    return v2f(x, x);
}

V2d v2d_sum(V2d a, V2d b)
{
    for (int i = 0; i < 2; ++i) a.c[i] += b.c[i];
    return a;
}
V2d v2d_sub(V2d a, V2d b)
{
    for (int i = 0; i < 2; ++i) a.c[i] -= b.c[i];
    return a;
}
V2d v2d_mul(V2d a, V2d b)
{
    for (int i = 0; i < 2; ++i) a.c[i] *= b.c[i];
    return a;
}
V2d v2d_div(V2d a, V2d b)
{
    for (int i = 0; i < 2; ++i) a.c[i] /= b.c[i];
    return a;
}

V2d v2d(double x0, double x1)
{
    V2d result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}

V2d v2ds(double x)
{
    return v2d(x, x);
}

V2i v2i_sum(V2i a, V2i b)
{
    for (int i = 0; i < 2; ++i) a.c[i] += b.c[i];
    return a;
}
V2i v2i_sub(V2i a, V2i b)
{
    for (int i = 0; i < 2; ++i) a.c[i] -= b.c[i];
    return a;
}
V2i v2i_mul(V2i a, V2i b)
{
    for (int i = 0; i < 2; ++i) a.c[i] *= b.c[i];
    return a;
}
V2i v2i_div(V2i a, V2i b)
{
    for (int i = 0; i < 2; ++i) a.c[i] /= b.c[i];
    return a;
}

V2i v2i(int x0, int x1)
{
    V2i result;
    result.c[0] = x0;
    result.c[1] = x1;
    return result;
}

V2i v2is(int x)
{
    return v2i(x, x);
}

V3f v3f_sum(V3f a, V3f b)
{
    for (int i = 0; i < 3; ++i) a.c[i] += b.c[i];
    return a;
}
V3f v3f_sub(V3f a, V3f b)
{
    for (int i = 0; i < 3; ++i) a.c[i] -= b.c[i];
    return a;
}
V3f v3f_mul(V3f a, V3f b)
{
    for (int i = 0; i < 3; ++i) a.c[i] *= b.c[i];
    return a;
}
V3f v3f_div(V3f a, V3f b)
{
    for (int i = 0; i < 3; ++i) a.c[i] /= b.c[i];
    return a;
}

V3f v3f(float x0, float x1, float x2)
{
    V3f result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}

V3f v3fs(float x)
{
    return v3f(x, x, x);
}

V3d v3d_sum(V3d a, V3d b)
{
    for (int i = 0; i < 3; ++i) a.c[i] += b.c[i];
    return a;
}
V3d v3d_sub(V3d a, V3d b)
{
    for (int i = 0; i < 3; ++i) a.c[i] -= b.c[i];
    return a;
}
V3d v3d_mul(V3d a, V3d b)
{
    for (int i = 0; i < 3; ++i) a.c[i] *= b.c[i];
    return a;
}
V3d v3d_div(V3d a, V3d b)
{
    for (int i = 0; i < 3; ++i) a.c[i] /= b.c[i];
    return a;
}

V3d v3d(double x0, double x1, double x2)
{
    V3d result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}

V3d v3ds(double x)
{
    return v3d(x, x, x);
}

V3i v3i_sum(V3i a, V3i b)
{
    for (int i = 0; i < 3; ++i) a.c[i] += b.c[i];
    return a;
}
V3i v3i_sub(V3i a, V3i b)
{
    for (int i = 0; i < 3; ++i) a.c[i] -= b.c[i];
    return a;
}
V3i v3i_mul(V3i a, V3i b)
{
    for (int i = 0; i < 3; ++i) a.c[i] *= b.c[i];
    return a;
}
V3i v3i_div(V3i a, V3i b)
{
    for (int i = 0; i < 3; ++i) a.c[i] /= b.c[i];
    return a;
}

V3i v3i(int x0, int x1, int x2)
{
    V3i result;
    result.c[0] = x0;
    result.c[1] = x1;
    result.c[2] = x2;
    return result;
}

V3i v3is(int x)
{
    return v3i(x, x, x);
}

V4f v4f_sum(V4f a, V4f b)
{
    for (int i = 0; i < 4; ++i) a.c[i] += b.c[i];
    return a;
}
V4f v4f_sub(V4f a, V4f b)
{
    for (int i = 0; i < 4; ++i) a.c[i] -= b.c[i];
    return a;
}
V4f v4f_mul(V4f a, V4f b)
{
    for (int i = 0; i < 4; ++i) a.c[i] *= b.c[i];
    return a;
}
V4f v4f_div(V4f a, V4f b)
{
    for (int i = 0; i < 4; ++i) a.c[i] /= b.c[i];
    return a;
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

V4f v4fs(float x)
{
    return v4f(x, x, x, x);
}

V4d v4d_sum(V4d a, V4d b)
{
    for (int i = 0; i < 4; ++i) a.c[i] += b.c[i];
    return a;
}
V4d v4d_sub(V4d a, V4d b)
{
    for (int i = 0; i < 4; ++i) a.c[i] -= b.c[i];
    return a;
}
V4d v4d_mul(V4d a, V4d b)
{
    for (int i = 0; i < 4; ++i) a.c[i] *= b.c[i];
    return a;
}
V4d v4d_div(V4d a, V4d b)
{
    for (int i = 0; i < 4; ++i) a.c[i] /= b.c[i];
    return a;
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

V4d v4ds(double x)
{
    return v4d(x, x, x, x);
}

V4i v4i_sum(V4i a, V4i b)
{
    for (int i = 0; i < 4; ++i) a.c[i] += b.c[i];
    return a;
}
V4i v4i_sub(V4i a, V4i b)
{
    for (int i = 0; i < 4; ++i) a.c[i] -= b.c[i];
    return a;
}
V4i v4i_mul(V4i a, V4i b)
{
    for (int i = 0; i < 4; ++i) a.c[i] *= b.c[i];
    return a;
}
V4i v4i_div(V4i a, V4i b)
{
    for (int i = 0; i < 4; ++i) a.c[i] /= b.c[i];
    return a;
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

V4i v4is(int x)
{
    return v4i(x, x, x, x);
}

#endif // LA_IMPLEMENTATION
