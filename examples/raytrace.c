// Simple raytrace which writes a ppm to stdout
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define LA_IMPLEMENTATION
#include "../la.h"

typedef V3f Color;
typedef V3f Point3;

static inline V3f v3f_smul(V3f v, float s) { return v3f_mul(v, v3ff(s)); }
static inline V3f v3f_sdiv(V3f v, float s) { return v3f_div(v, v3ff(s)); }

static const float PI_F = 3.14159265358979323846f;

static inline float degrees_to_radians(float degrees)
{
    return degrees * (PI_F / 180.0f);
}

static inline float random_float01(void)
{
    return (float)rand() / ((float)RAND_MAX + 1.0f);
}

static inline float random_float(float min_v, float max_v)
{
    return min_v + (max_v - min_v) * random_float01();
}

static V3f random_in_unit_disk(void)
{
    for (;;) {
        V3f p = v3f(random_float(-1.0f, 1.0f), random_float(-1.0f, 1.0f), 0.0f);
        if (v3f_dot(p, p) < 1.0f) return p;
    }
}

static V3f random_unit_vector(void)
{
    for (;;) {
        V3f p = v3f(random_float(-1.0f, 1.0f), random_float(-1.0f, 1.0f), random_float(-1.0f, 1.0f));
        float lensq = v3f_dot(p, p);
        if (1e-16f < lensq && lensq <= 1.0f) return v3f_sdiv(p, sqrtf(lensq));
    }
}

static inline V3f reflect_vec(V3f v, V3f n)
{
    return v3f_sub(v, v3f_smul(n, 2.0f * v3f_dot(v, n)));
}

static inline V3f refract_vec(V3f uv, V3f n, float etai_over_etat)
{
    float cos_theta = fminf(v3f_dot(v3f_smul(uv, -1.0f), n), 1.0f);
    V3f r_out_perp = v3f_smul(v3f_sum(uv, v3f_smul(n, cos_theta)), etai_over_etat);
    V3f r_out_parallel = v3f_smul(n, -sqrtf(fabsf(1.0f - v3f_dot(r_out_perp, r_out_perp))));
    return v3f_sum(r_out_perp, r_out_parallel);
}

typedef struct {
    Point3 origin;
    V3f direction;
} Ray;

static inline Point3 ray_at(Ray r, float t)
{
    return v3f_sum(r.origin, v3f_smul(r.direction, t));
}

typedef enum {
    MAT_LAMBERTIAN,
    MAT_METAL,
    MAT_DIELECTRIC,
} MaterialKind;

typedef struct {
    MaterialKind kind;
    Color albedo;   // used by lambertian and metal
    float fuzz;     // used by metal
    float ir;       // index of refraction for dielectric
} Material;

typedef struct {
    Point3 center;
    float radius;
    Material mat;
} Sphere;

typedef struct {
    Point3 p;
    V3f normal;
    float t;
    int front_face;
    Material mat;
} HitRecord;

static inline int v3f_near_zero(V3f v)
{
    const float s = 1e-8f;
    return fabsf(v.x) < s && fabsf(v.y) < s && fabsf(v.z) < s;
}

static inline void set_face_normal(HitRecord *rec, Ray r, V3f outward_normal)
{
    rec->front_face = v3f_dot(r.direction, outward_normal) < 0.0f;
    rec->normal = rec->front_face ? outward_normal : v3f_smul(outward_normal, -1.0f);
}

static int sphere_hit(const Sphere *s, const Ray *r, float tmin, float tmax, HitRecord *rec)
{
    V3f oc = v3f_sub(s->center, r->origin);
    float a = v3f_dot(r->direction, r->direction);
    float h = v3f_dot(r->direction, oc);
    float c = v3f_dot(oc, oc) - s->radius * s->radius;

    float discriminant = h*h - a*c;
    if (discriminant < 0.0f) return 0;
    float sqrtd = sqrtf(discriminant);

    float root = (h - sqrtd) / a;
    if (root <= tmin || tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= tmin || tmax <= root) return 0;
    }

    rec->t = root;
    rec->p = ray_at(*r, rec->t);
    V3f outward = v3f_sdiv(v3f_sub(rec->p, s->center), s->radius);
    set_face_normal(rec, *r, outward);
    rec->mat = s->mat;
    return 1;
}

typedef struct {
    Sphere *data;
    size_t count;
    size_t cap;
} World;

static void world_init(World *w)
{
    w->data = NULL;
    w->count = 0;
    w->cap = 0;
}

static void world_add(World *w, Sphere s)
{
    if (w->count == w->cap) {
        size_t new_cap = w->cap ? w->cap * 2 : 64;
        Sphere *new_data = (Sphere *)realloc(w->data, new_cap * sizeof(*new_data));
        if (!new_data) {
            fprintf(stderr, "Out of memory adding sphere\n");
            exit(1);
        }
        w->data = new_data;
        w->cap = new_cap;
    }
    w->data[w->count++] = s;
}

static int world_hit(const World *w, const Ray *r, float tmin, float tmax, HitRecord *out_rec)
{
    HitRecord temp;
    int hit_anything = 0;
    float closest = tmax;

    for (size_t i = 0; i < w->count; ++i) {
        if (sphere_hit(&w->data[i], r, tmin, closest, &temp)) {
            hit_anything = 1;
            closest = temp.t;
            *out_rec = temp;
        }
    }
    return hit_anything;
}

static float schlick_reflectance(float cosine, float refraction_index)
{
    float r0 = (1.0f - refraction_index) / (1.0f + refraction_index);
    r0 = r0 * r0;
    return r0 + (1.0f - r0) * powf(1.0f - cosine, 5.0f);
}

static int material_scatter(const Material *m, Ray r_in, const HitRecord *rec, Color *attenuation, Ray *scattered)
{
    switch (m->kind) {
        case MAT_LAMBERTIAN: {
            V3f scatter_direction = v3f_sum(rec->normal, random_unit_vector());
            if (v3f_near_zero(scatter_direction)) scatter_direction = rec->normal;
            *scattered = (Ray){ rec->p, scatter_direction };
            *attenuation = m->albedo;
            return 1;
        }
        case MAT_METAL: {
            V3f reflected = v3f_normalize(reflect_vec(r_in.direction, rec->normal));
            V3f fuzz_vec = v3f_smul(random_unit_vector(), (m->fuzz < 1.0f) ? m->fuzz : 1.0f);
            *scattered = (Ray){ rec->p, v3f_sum(reflected, fuzz_vec) };
            *attenuation = m->albedo;
            return v3f_dot(scattered->direction, rec->normal) > 0.0f;
        }
        case MAT_DIELECTRIC: {
            *attenuation = v3ff(1.0f);
            float ri = rec->front_face ? (1.0f / m->ir) : m->ir;
            V3f unit_direction = v3f_normalize(r_in.direction);
            float cos_theta = fminf(v3f_dot(v3f_smul(unit_direction, -1.0f), rec->normal), 1.0f);
            float sin_theta = sqrtf(fmaxf(0.0f, 1.0f - cos_theta * cos_theta));
            int cannot_refract = ri * sin_theta > 1.0f;
            V3f direction;
            if (cannot_refract || schlick_reflectance(cos_theta, ri) > random_float01()) {
                direction = reflect_vec(unit_direction, rec->normal);
            } else {
                direction = refract_vec(unit_direction, rec->normal, ri);
            }
            *scattered = (Ray){ rec->p, direction };
            return 1;
        }
    }
    return 0;
}

typedef struct {
    float aspect_ratio;      // width / height
    int image_width;
    int samples_per_pixel;
    int max_depth;
    float vfov;              // vertical field-of-view in degrees
    Point3 lookfrom;
    Point3 lookat;
    V3f vup;
    float defocus_angle;     // aperture angle in degrees
    float focus_dist;        // distance to focus plane

    // Derived
    int image_height;
    float pixel_samples_scale;
    Point3 center;
    Point3 pixel00_loc;
    V3f pixel_delta_u;
    V3f pixel_delta_v;
    V3f u, v, w;
    V3f defocus_disk_u;
    V3f defocus_disk_v;
} Camera;

static void camera_initialize(Camera *cam)
{
    cam->image_height = (int)((float)cam->image_width / cam->aspect_ratio);
    if (cam->image_height < 1) cam->image_height = 1;
    cam->pixel_samples_scale = 1.0f / (float)cam->samples_per_pixel;
    cam->center = cam->lookfrom;

    float theta = degrees_to_radians(cam->vfov);
    float h = tanf(theta * 0.5f);
    float viewport_height = 2.0f * h * cam->focus_dist;
    float viewport_width = viewport_height * ((float)cam->image_width / (float)cam->image_height);

    cam->w = v3f_normalize(v3f_sub(cam->lookfrom, cam->lookat));
    cam->u = v3f_normalize(v3f_cross(cam->vup, cam->w));
    cam->v = v3f_cross(cam->w, cam->u);

    V3f viewport_u = v3f_smul(cam->u, viewport_width);
    V3f viewport_v = v3f_smul(cam->v, -viewport_height);

    cam->pixel_delta_u = v3f_sdiv(viewport_u, (float)cam->image_width);
    cam->pixel_delta_v = v3f_sdiv(viewport_v, (float)cam->image_height);

    Point3 viewport_upper_left = v3f_sub(v3f_sub(v3f_sub(cam->center, v3f_smul(cam->w, cam->focus_dist)), v3f_smul(viewport_u, 0.5f)), v3f_smul(viewport_v, 0.5f));
    cam->pixel00_loc = v3f_sum(viewport_upper_left, v3f_smul(v3f_sum(cam->pixel_delta_u, cam->pixel_delta_v), 0.5f));

    float defocus_radius = cam->focus_dist * tanf(degrees_to_radians(cam->defocus_angle * 0.5f));
    cam->defocus_disk_u = v3f_smul(cam->u, defocus_radius);
    cam->defocus_disk_v = v3f_smul(cam->v, defocus_radius);
}

static inline V3f sample_square(void)
{
    return v3f(random_float01() - 0.5f, random_float01() - 0.5f, 0.0f);
}

static inline Point3 defocus_disk_sample(const Camera *cam)
{
    V3f p = random_in_unit_disk();
    return v3f_sum(cam->center, v3f_sum(v3f_smul(cam->defocus_disk_u, p.x), v3f_smul(cam->defocus_disk_v, p.y)));
}

static Ray camera_get_ray(const Camera *cam, int i, int j)
{
    V3f offset = sample_square();
    Point3 pixel_sample = v3f_sum(cam->pixel00_loc,
        v3f_sum(v3f_smul(cam->pixel_delta_u, (float)i + offset.x),
                v3f_smul(cam->pixel_delta_v, (float)j + offset.y)));

    Point3 ray_origin = (cam->defocus_angle <= 0.0f) ? cam->center : defocus_disk_sample(cam);
    V3f ray_direction = v3f_sub(pixel_sample, ray_origin);
    return (Ray){ ray_origin, ray_direction };
}

static Color ray_color(Ray r, int depth, const World *world)
{
    if (depth <= 0) return v3ff(0.0f);

    HitRecord rec;
    if (world_hit(world, &r, 0.001f, INFINITY, &rec)) {
        Ray scattered;
        Color attenuation;
        if (material_scatter(&rec.mat, r, &rec, &attenuation, &scattered)) {
            Color bounced = ray_color(scattered, depth - 1, world);
            return v3f_mul(attenuation, bounced);
        }
        return v3ff(0.0f);
    }

    V3f unit_direction = v3f_normalize(r.direction);
    float a = 0.5f * (unit_direction.y + 1.0f);
    return v3f_sum(v3f_smul(v3ff(1.0f), (1.0f - a)), v3f_smul(v3f(0.5f, 0.7f, 1.0f), a));
}

static inline float linear_to_gamma(float x)
{
    return x > 0.0f ? sqrtf(x) : 0.0f;
}

static void write_color(FILE *out, Color pixel_color, float pixel_samples_scale)
{
    float r = pixel_color.x * pixel_samples_scale;
    float g = pixel_color.y * pixel_samples_scale;
    float b = pixel_color.z * pixel_samples_scale;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    int rbyte = (int)(256.0f * clampf(r, 0.000f, 0.999f));
    int gbyte = (int)(256.0f * clampf(g, 0.000f, 0.999f));
    int bbyte = (int)(256.0f * clampf(b, 0.000f, 0.999f));

    fprintf(out, "%d %d %d\n", rbyte, gbyte, bbyte);
}

int main(void)
{
    srand((unsigned)time(NULL));

    World world; world_init(&world);

    Material ground_mat = { .kind = MAT_LAMBERTIAN, .albedo = v3f(0.5f, 0.5f, 0.5f) };
    world_add(&world, (Sphere){ v3f(0.0f, -1000.0f, 0.0f), 1000.0f, ground_mat });

    for (int a = -11; a < 11; ++a) {
        for (int b = -11; b < 11; ++b) {
            float choose_mat = random_float01();
            Point3 center = v3f((float)a + 0.9f * random_float01(), 0.2f, (float)b + 0.9f * random_float01());
            V3f diff = v3f_sub(center, v3f(4.0f, 0.2f, 0.0f));
            if (v3f_len(diff) > 0.9f) {
                if (choose_mat < 0.8f) {
                    // diffuse
                    Color albedo = v3f_mul(v3f(random_float01(), random_float01(), random_float01()),
                                            v3f(random_float01(), random_float01(), random_float01()));
                    Material mat = { .kind = MAT_LAMBERTIAN, .albedo = albedo };
                    world_add(&world, (Sphere){ center, 0.2f, mat });
                } else if (choose_mat < 0.95f) {
                    // metal
                    Color albedo = v3f(random_float(0.5f, 1.0f), random_float(0.5f, 1.0f), random_float(0.5f, 1.0f));
                    float fuzz = random_float(0.0f, 0.5f);
                    Material mat = { .kind = MAT_METAL, .albedo = albedo, .fuzz = fuzz };
                    world_add(&world, (Sphere){ center, 0.2f, mat });
                } else {
                    // glass
                    Material mat = { .kind = MAT_DIELECTRIC, .ir = 1.5f };
                    world_add(&world, (Sphere){ center, 0.2f, mat });
                }
            }
        }
    }

    Material material1 = { .kind = MAT_DIELECTRIC, .ir = 1.5f };
    world_add(&world, (Sphere){ v3f(0.0f, 1.0f, 0.0f), 1.0f, material1 });

    Material material2 = { .kind = MAT_LAMBERTIAN, .albedo = v3f(0.4f, 0.2f, 0.1f) };
    world_add(&world, (Sphere){ v3f(-4.0f, 1.0f, 0.0f), 1.0f, material2 });

    Material material3 = { .kind = MAT_METAL, .albedo = v3f(0.7f, 0.6f, 0.5f), .fuzz = 0.0f };
    world_add(&world, (Sphere){ v3f(4.0f, 1.0f, 0.0f), 1.0f, material3 });

    Camera cam = {0};
    cam.aspect_ratio = 16.0f / 9.0f;
    cam.image_width = 1200;
    cam.samples_per_pixel = 10;
    cam.max_depth = 20;
    cam.vfov = 20.0f;
    cam.lookfrom = v3f(13.0f, 2.0f, 3.0f);
    cam.lookat   = v3f(0.0f, 0.0f, 0.0f);
    cam.vup      = v3f(0.0f, 1.0f, 0.0f);
    cam.defocus_angle = 0.6f;
    cam.focus_dist    = 10.0f;

    camera_initialize(&cam);

    // PPM header
    fprintf(stdout, "P3\n%d %d\n255\n", cam.image_width, cam.image_height);

    for (int j = 0; j < cam.image_height; ++j) {
        fprintf(stderr, "\rScanlines remaining: %d ", cam.image_height - j);
        fflush(stderr);
        for (int i = 0; i < cam.image_width; ++i) {
            Color pixel = v3ff(0.0f);
            for (int s = 0; s < cam.samples_per_pixel; ++s) {
                Ray r = camera_get_ray(&cam, i, j);
                pixel = v3f_sum(pixel, ray_color(r, cam.max_depth, &world));
            }
            write_color(stdout, pixel, cam.pixel_samples_scale);
        }
    }
    fprintf(stderr, "\rDone.                \n");

    free(world.data);
    return 0;
}
