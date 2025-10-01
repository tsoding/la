// This file contains new mechanisms and conventions for generating functions.
// Everything in lag.c is considered old. Over time we should be slowly moving
// code from lag.c to new.c as we migrate it. Then when it's done, we should
// just rename new.c to lag.c.

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

#define VECTOR_MIN_SIZE 2
#define VECTOR_MAX_SIZE 4
static_assert(VECTOR_MIN_SIZE <= VECTOR_MAX_SIZE, "Max vector size may not be less than the min vector size, c'mon");

static_assert(VECTOR_MAX_SIZE == 4, "We defined only 4 vector component names. Please update this list accordingly");
static char *vec_comps[VECTOR_MAX_SIZE] = {"x", "y", "z", "w"};

const char *vec_type(size_t n, Type type)
{
    return temp_sprintf("V%zu%s", n, type_defs[type].suffix);
}

const char *vec_ctor(size_t n, Type type)
{
    return temp_sprintf("v%zu%s", n, type_defs[type].suffix);
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
#define fgen_line_break(out) fprintf((out), " // %s:%d\n", __FILE__, __LINE__)
#else
#define fgen_line_break(out) fprintf((out), "\n")
#endif

#define fgenf(out, ...) \
    do { \
        fprintf((out), __VA_ARGS__); \
        fgen_line_break(out); \
    } while(0)

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
        UNREACHABLE("gen_vec_norm: type");
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

void gen_vec_len(FILE *stream, size_t n, Type type, bool impl)
{
    // We are excluding integers because we don't have sqrt defined for them.
    if (type_defs[type].is_integer) return;

    gen_sig_begin(stream, type_defs[type].name, vec_func(n, type, "len")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    static_assert(COUNT_TYPES == 4, "Amount of types has changed");
    if (type == TYPE_FLOAT) {
        fgenf(stream, "    return sqrtf(%s(a));", vec_func(n, type, "sqrlen"));
    } else if (type == TYPE_DOUBLE) {
        fgenf(stream, "    return sqrt(%s(a));", vec_func(n, type, "sqrlen"));
    } else {
        UNREACHABLE("gen_vec_len: type");
    }
    fgenf(stream, "}");
}

void gen_vec_dot(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, type_defs[type].name, vec_func(n, type, "dot")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
        gen_sig_arg(stream, vec_type(n, type), "b");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fprintf(stream, "{\n");
    fprintf(stream, "    return ");
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, " + ");
        fprintf(stream, "a.%s*b.%s", vec_comps[i], vec_comps[i]);
    }
    fprintf(stream, ";\n");
    fprintf(stream, "}\n");
}

void gen_vec_eq(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, "bool", vec_func(n, type, "eq")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
        gen_sig_arg(stream, vec_type(n, type), "b");
        if (!type_defs[type].is_integer) {
            gen_sig_arg(stream, type_defs[type].name, "eps");
        }
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    for (size_t i = 0; i < n; ++i) {
        if (type_defs[type].is_integer) {
            fgenf(stream, "    if (a.%s != b.%s) return false;", vec_comps[i], vec_comps[i]);
        } else if (type == TYPE_FLOAT) {
            fgenf(stream, "    if (fabsf(b.%s - a.%s) <= eps) return false;", vec_comps[i], vec_comps[i]);
        } else if (type == TYPE_DOUBLE) {
            fgenf(stream, "    if (fabs(b.%s - a.%s) <= eps) return false;", vec_comps[i], vec_comps[i]);
        } else {
            UNREACHABLE("gen_vector_eq: type");
        }
    }
    fgenf(stream, "    return true;");
    fgenf(stream, "}");
}

void gen_vec_sqrlen(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, type_defs[type].name, vec_func(n, type, "sqrlen")); {
        gen_sig_arg(stream, vec_type(n, type), "a");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    return %s(a, a);", vec_func(n, type, "dot"));
    fgenf(stream, "}");
}

const char *vec_convert(size_t dst_n, Type dst_type, size_t src_n, Type src_type)
{
    return temp_sprintf("v%zu%s%zu%s", dst_n, type_defs[dst_type].suffix, src_n, type_defs[src_type].suffix);
}

void gen_vec_convert(FILE *stream, size_t dst_n, Type dst_type, size_t src_n, Type src_type, bool impl)
{
    // Converting to itself is pointless
    if (dst_n == src_n && dst_type == src_type) return;

    gen_sig_begin(stream, vec_type(dst_n, dst_type), vec_convert(dst_n, dst_type, src_n, src_type)); {
        gen_sig_arg(stream, vec_type(src_n, src_type), "a");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    %s result;", vec_type(dst_n, dst_type));
    for (size_t i = 0; i < dst_n; ++i) {
        if (i < src_n) {
            fgenf(stream, "    result.%s = (%s) a.%s;", vec_comps[i], type_defs[dst_type].name, vec_comps[i]);
        } else {
            fgenf(stream, "    result.%s = %s;", vec_comps[i], type_defs[dst_type].zero_lit);
        }
    }
    fgenf(stream, "    return result;");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

void gen_vec_printf_macros(FILE *stream, size_t n, Type type)
{
    fprintf(stream, "#define %s_Fmt \"%s(", vec_type(n, type), vec_ctor(n, type));
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%%%s", type_defs[type].fmt);
    }
    fgenf(stream, ")\"");

    fprintf(stream, "#define %s_Arg(v) ", vec_type(n, type));
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "(v).%s", vec_comps[i]);
    }
    fgen_line_break(stream);
}

// https://registry.khronos.org/OpenGL-Refpages/gl4/html/reflect.xhtml
// I - 2.0 * dot(N, I) * N.
void gen_vec_reflect(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, vec_type(n, type), vec_func(n, type, "reflect")); {
        gen_sig_arg(stream, vec_type(n, type), "i");
        gen_sig_arg(stream, vec_type(n, type), "n");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    %s r = n;", vec_type(n, type));
    fgenf(stream, "    r = %s(r, %s(%s(n, i)));", vec_func(n, type, "mul"), scalar_ctor(n, type), vec_func(n, type, "dot"));
    fgenf(stream, "    r = %s(r, %s(2));",        vec_func(n, type, "mul"), scalar_ctor(n, type));
    fgenf(stream, "    r = %s(i, r);",            vec_func(n, type, "sub"));
    fgenf(stream, "    return r;");
    fgenf(stream, "}");
}

void gen_vec_ctor(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, vec_type(n, type), vec_ctor(n, type)); {
        for (size_t i = 0; i < n; ++i) {
            gen_sig_arg(stream, type_defs[type].name, vec_comps[i]);
        }
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    %s v;", vec_type(n, type));
    for (size_t i = 0; i < n; ++i) {
        fgenf(stream, "    v.%s = %s;", vec_comps[i], vec_comps[i]);
    }
    fgenf(stream, "    return v;");
    fgenf(stream, "}");
}
