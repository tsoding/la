// This file contains new mechanisms of generating functions. Everything
// in lag.c is considered old. Over time we should be slowly moving code
// from lag.c to new.c as we migrate it.

typedef enum {
    TYPE_FLOAT = 0,
    TYPE_DOUBLE,
    TYPE_INT,
    TYPE_UNSIGNED_INT,
    COUNT_TYPES,
} Type;

typedef struct {
    const char *name;
    const char *suffix;
    const char *fmt;
    const char *zero_lit;
    bool is_integer;
} Type_Def;

static_assert(COUNT_TYPES == 4, "The amount of type definitions have changed.");
static Type_Def type_defs[COUNT_TYPES] = {
    [TYPE_FLOAT]        = { .name = "float",        .suffix = "f", .fmt = "f",  .zero_lit = "0.0f", .is_integer = false },
    [TYPE_DOUBLE]       = { .name = "double",       .suffix = "d", .fmt = "lf", .zero_lit = "0.0",  .is_integer = false },
    [TYPE_INT]          = { .name = "int",          .suffix = "i", .fmt = "d",  .zero_lit = "0",    .is_integer = true  },
    [TYPE_UNSIGNED_INT] = { .name = "unsigned int", .suffix = "u", .fmt = "u",  .zero_lit = "0u",   .is_integer = true  },
};

const char *vec_type(size_t n, Type type)
{
    return temp_sprintf("V%zu%s", n, type_defs[type].suffix);
}

const char *vec_func(size_t n, Type type, const char *name)
{
    return temp_sprintf("v%zu%s_%s", n, type_defs[type].suffix, name);
}

const char *scalar_ctor(size_t n, Type type)
{
    return temp_sprintf("v%zu%s%s", n, type_defs[type].suffix, type_defs[type].suffix);
}

// #define GEN_TRACE
#if defined(GEN_TRACE)
#define fgenf(out, ...) \
    do { \
        fprintf((out), __VA_ARGS__); \
        fprintf((out), " // %s:%d\n", __FILE__, __LINE__); \
    } while(0)
#else
#define fgenf(out, ...) \
    do { \
        fprintf((out), __VA_ARGS__); \
        fprintf((out), "\n"); \
    } while(0)
#endif

static size_t sig_arg_count = 0;

void gen_sig_begin(FILE *stream, const char *ret_type, const char *name)
{
    fprintf(stream, "LADEF %s %s(", ret_type, name);
    sig_arg_count = 0;
}

void gen_sig_arg(FILE *stream, const char *arg_type, const char *arg_name)
{
    if (sig_arg_count > 0) fprintf(stream, ", ");
    fprintf(stream, "%s %s", arg_type, arg_name);
    sig_arg_count += 1;
}

void gen_sig_end(FILE *stream, bool impl)
{
    if (impl) {
        fgenf(stream, ")");
    } else {
        fgenf(stream, ");");
    }
}

void gen_vec_norm(FILE *stream, size_t n, Type type, bool impl)
{
    if (!(2 <= n && n <= 4)) return;
    // We are excluding integers because we don't have a vec_len defined for them.
    if (type_defs[type].is_integer) return;

    gen_sig_begin(stream, vec_type(n, type), vec_func(n, type, "norm")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
        gen_sig_arg(stream, type_defs[type].name, "eps");
        gen_sig_arg(stream, vec_type(n, type), "fallback");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    %s l = %s(a);", type_defs[type].name, vec_func(n, type, "len"));
    static_assert(COUNT_TYPES == 4, "Amount of types has changed");
    if (type == TYPE_FLOAT) {
        fgenf(stream, "    if (fabsf(l) <= eps) return fallback;");
    } else if (type == TYPE_DOUBLE) {
        fgenf(stream, "    if (fabs(l) <= eps) return fallback;");
    } else {
        UNREACHABLE("vec_norm: type");
    }
    fgenf(stream, "    return %s(a, %s(l));", vec_func(n, type, "div"), scalar_ctor(n, type));
    fgenf(stream, "}");
}

void gen_vec_cross(FILE *stream, size_t n, Type type, bool impl)
{
    if (n != 3) return; // TODO: does the cross product even make sense for other sizes?

    gen_sig_begin(stream, vec_type(n, type), vec_func(n, type, "cross")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
        gen_sig_arg(stream, vec_type(n, type), "b");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    %s n;", vec_type(n, type));
    fgenf(stream, "    n.x = a.y * b.z - a.z * b.y;");
    fgenf(stream, "    n.y = a.z * b.x - a.x * b.z;");
    fgenf(stream, "    n.z = a.x * b.y - a.y * b.x;");
    fgenf(stream, "    return n;");
    fgenf(stream, "}");
}
