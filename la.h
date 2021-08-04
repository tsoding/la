#ifndef LA_H_
#define LA_H_

typedef struct { float c[2]; } V2f;
typedef struct { double c[2]; } V2d;
typedef struct { int c[2]; } V2i;
typedef struct { unsigned int c[2]; } V2u;

typedef struct { float c[3]; } V3f;
typedef struct { double c[3]; } V3d;
typedef struct { int c[3]; } V3i;
typedef struct { unsigned int c[3]; } V3u;

typedef struct { float c[4]; } V4f;
typedef struct { double c[4]; } V4d;
typedef struct { int c[4]; } V4i;
typedef struct { unsigned int c[4]; } V4u;

V2f v2f_sum(V2f a, V2f b);
V2f v2f_sub(V2f a, V2f b);
V2f v2f_mul(V2f a, V2f b);
V2f v2f_div(V2f a, V2f b);

V2d v2d_sum(V2d a, V2d b);
V2d v2d_sub(V2d a, V2d b);
V2d v2d_mul(V2d a, V2d b);
V2d v2d_div(V2d a, V2d b);

V2i v2i_sum(V2i a, V2i b);
V2i v2i_sub(V2i a, V2i b);
V2i v2i_mul(V2i a, V2i b);
V2i v2i_div(V2i a, V2i b);

V2u v2u_sum(V2u a, V2u b);
V2u v2u_sub(V2u a, V2u b);
V2u v2u_mul(V2u a, V2u b);
V2u v2u_div(V2u a, V2u b);

V3f v3f_sum(V3f a, V3f b);
V3f v3f_sub(V3f a, V3f b);
V3f v3f_mul(V3f a, V3f b);
V3f v3f_div(V3f a, V3f b);

V3d v3d_sum(V3d a, V3d b);
V3d v3d_sub(V3d a, V3d b);
V3d v3d_mul(V3d a, V3d b);
V3d v3d_div(V3d a, V3d b);

V3i v3i_sum(V3i a, V3i b);
V3i v3i_sub(V3i a, V3i b);
V3i v3i_mul(V3i a, V3i b);
V3i v3i_div(V3i a, V3i b);

V3u v3u_sum(V3u a, V3u b);
V3u v3u_sub(V3u a, V3u b);
V3u v3u_mul(V3u a, V3u b);
V3u v3u_div(V3u a, V3u b);

V4f v4f_sum(V4f a, V4f b);
V4f v4f_sub(V4f a, V4f b);
V4f v4f_mul(V4f a, V4f b);
V4f v4f_div(V4f a, V4f b);

V4d v4d_sum(V4d a, V4d b);
V4d v4d_sub(V4d a, V4d b);
V4d v4d_mul(V4d a, V4d b);
V4d v4d_div(V4d a, V4d b);

V4i v4i_sum(V4i a, V4i b);
V4i v4i_sub(V4i a, V4i b);
V4i v4i_mul(V4i a, V4i b);
V4i v4i_div(V4i a, V4i b);

V4u v4u_sum(V4u a, V4u b);
V4u v4u_sub(V4u a, V4u b);
V4u v4u_mul(V4u a, V4u b);
V4u v4u_div(V4u a, V4u b);

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

V2u v2u_sum(V2u a, V2u b)
{
    for (int i = 0; i < 2; ++i) a.c[i] += b.c[i];
    return a;
}

V2u v2u_sub(V2u a, V2u b)
{
    for (int i = 0; i < 2; ++i) a.c[i] -= b.c[i];
    return a;
}

V2u v2u_mul(V2u a, V2u b)
{
    for (int i = 0; i < 2; ++i) a.c[i] *= b.c[i];
    return a;
}

V2u v2u_div(V2u a, V2u b)
{
    for (int i = 0; i < 2; ++i) a.c[i] /= b.c[i];
    return a;
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

V3u v3u_sum(V3u a, V3u b)
{
    for (int i = 0; i < 3; ++i) a.c[i] += b.c[i];
    return a;
}

V3u v3u_sub(V3u a, V3u b)
{
    for (int i = 0; i < 3; ++i) a.c[i] -= b.c[i];
    return a;
}

V3u v3u_mul(V3u a, V3u b)
{
    for (int i = 0; i < 3; ++i) a.c[i] *= b.c[i];
    return a;
}

V3u v3u_div(V3u a, V3u b)
{
    for (int i = 0; i < 3; ++i) a.c[i] /= b.c[i];
    return a;
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

V4u v4u_sum(V4u a, V4u b)
{
    for (int i = 0; i < 4; ++i) a.c[i] += b.c[i];
    return a;
}

V4u v4u_sub(V4u a, V4u b)
{
    for (int i = 0; i < 4; ++i) a.c[i] -= b.c[i];
    return a;
}

V4u v4u_mul(V4u a, V4u b)
{
    for (int i = 0; i < 4; ++i) a.c[i] *= b.c[i];
    return a;
}

V4u v4u_div(V4u a, V4u b)
{
    for (int i = 0; i < 4; ++i) a.c[i] /= b.c[i];
    return a;
}

#endif // LA_IMPLEMENTATION
