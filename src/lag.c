#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

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

void gen_vec_def(FILE *stream, size_t n, Type type)
{
    fgenf(stream, "typedef union {");

    fprintf(stream, "    struct { %s ", type_defs[type].name);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s", vec_comps[i]);
    }
    fgenf(stream, "; };");

    if (n == 4) {
        // TODO: add more different group components like this
        fgenf(stream, "    struct { %s %s%s; %s %s%s; };",
              vec_type(n/2, type), vec_comps[0], vec_comps[1],
              vec_type(n/2, type), vec_comps[2], vec_comps[3]);
    }

    fgenf(stream, "    %s c[%zu];", type_defs[type].name, n);

    fgenf(stream, "} %s;", vec_type(n, type));
}

typedef enum {
    OP_SUM = 0,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    COUNT_OPS,
} Op_Type;

typedef struct {
    const char *suffix;
    const char *op;
} Op_Def;

static_assert(COUNT_OPS == 5, "The amount of operator definitions have changed. Please update the array below accordingly");
static Op_Def op_defs[COUNT_OPS] = {
    [OP_SUM] = {.suffix = "sum", .op = "+="},
    [OP_SUB] = {.suffix = "sub", .op = "-="},
    [OP_MUL] = {.suffix = "mul", .op = "*="},
    [OP_DIV] = {.suffix = "div", .op = "/="},
    [OP_MOD] = {.suffix = "mod", .op = "%="},
};

void gen_vec_ops(FILE *stream, size_t n, Type type, bool impl)
{
    for (Op_Type op = 0; op < COUNT_OPS; ++op) {
        gen_sig_begin(stream, vec_type(n, type), vec_func(n, type, op_defs[op].suffix));
        gen_sig_arg(stream, vec_type(n, type), "a");
        gen_sig_arg(stream, vec_type(n, type), "b");
        gen_sig_end(stream, impl);

        if (!impl) continue;

        fgenf(stream, "{");
        for (size_t i = 0; i < n; ++i) {
            if (op == OP_MOD && type == TYPE_FLOAT) {
                fgenf(stream, "    a.%s = fmodf(a.%s, b.%s);", vec_comps[i], vec_comps[i], vec_comps[i]);
            } else if (op == OP_MOD && type == TYPE_DOUBLE) {
                fgenf(stream, "    a.%s = fmod(a.%s, b.%s);", vec_comps[i], vec_comps[i], vec_comps[i]);
            } else {
                fgenf(stream, "    a.%s %s b.%s;", vec_comps[i], op_defs[op].op, vec_comps[i]);
            }
        }
        fgenf(stream, "    return a;");
        fgenf(stream, "}");
        fgen_line_break(stream);
    }
}

// This is enumeration for scalar functions that we "map" over components of the vectors
typedef enum {
    FUN_SQRT = 0,
    FUN_POW,
    FUN_SIN,
    FUN_COS,
    FUN_MIN,
    FUN_MAX,
    FUN_LERP,
    FUN_FLOOR,
    FUN_CEIL,
    FUN_CLAMP,
    COUNT_FUNS,
} Fun_Type;

#define FUN_DEF_MAX_ARITY 5

typedef struct {
    const char *suffix;
    // NOTE: NULL means the function is not supported for this type
    const char *name_for_type[COUNT_TYPES];
    size_t arity;
    char *args[FUN_DEF_MAX_ARITY];
} Fun_Def;

static_assert(COUNT_FUNS == 10, "The amount of functions have changed. Please update the array below accordingly");
static_assert(COUNT_TYPES == 4, "The amount of type definitions have changed. Please update the array bellow accordingly");
Fun_Def fun_defs[COUNT_FUNS] = {
    [FUN_SQRT] = {
        .suffix = "sqrt",
        .name_for_type = {
            [TYPE_FLOAT] = "sqrtf",
            [TYPE_DOUBLE] = "sqrt",
        },
        .arity = 1,
        .args = {"a"}
    },
    [FUN_POW] = {
        .suffix = "pow",
        .name_for_type = {
            [TYPE_FLOAT] = "powf",
            [TYPE_DOUBLE] = "pow",
        },
        .arity = 2,
        .args = {"base", "exp"},
    },
    [FUN_SIN] = {
        .suffix = "sin",
        .name_for_type = {
            [TYPE_FLOAT] = "sinf",
            [TYPE_DOUBLE] = "sin",
        },
        .arity = 1,
        .args = {"a"},
    },
    [FUN_COS] = {
        .suffix = "cos",
        .name_for_type = {
            [TYPE_FLOAT] = "cosf",
            [TYPE_DOUBLE] = "cos",
        },
        .arity = 1,
        .args = {"a"},
    },
    [FUN_MIN] = {
        .suffix = "min",
        .name_for_type = {
            [TYPE_FLOAT] = "fminf",
            [TYPE_DOUBLE] = "fmin",
            [TYPE_INT] = "mini",
            [TYPE_UNSIGNED_INT] = "minu",
        },
        .arity = 2,
        .args = {"a", "b"},
    },
    [FUN_MAX] = {
        .suffix = "max",
        .name_for_type = {
            [TYPE_FLOAT] = "fmaxf",
            [TYPE_DOUBLE] = "fmax",
            [TYPE_INT] = "maxi",
            [TYPE_UNSIGNED_INT] = "maxu",
        },
        .arity = 2,
        .args = {"a", "b"},
    },
    [FUN_LERP] = {
        .suffix = "lerp",
        .name_for_type = {
            [TYPE_FLOAT] = "lerpf",
            [TYPE_DOUBLE] = "lerp",
        },
        .arity = 3,
        .args = {"a", "b", "t"},
    },
    [FUN_FLOOR] = {
        .suffix = "floor",
        .name_for_type = {
            [TYPE_FLOAT] = "floorf",
            [TYPE_DOUBLE] = "floor",
        },
        .arity = 1,
        .args = {"a"},
    },
    [FUN_CEIL] = {
        .suffix = "ceil",
        .name_for_type = {
            [TYPE_FLOAT] = "ceilf",
            [TYPE_DOUBLE] = "ceil",
        },
        .arity = 1,
        .args = {"a"},
    },
    [FUN_CLAMP] = {
        .suffix = "clamp",
        .name_for_type = {
            [TYPE_FLOAT] = "clampf",
            [TYPE_DOUBLE] = "clampd",
            [TYPE_INT] = "clampi",
            [TYPE_UNSIGNED_INT] = "clampu",
        },
        .arity = 3,
        .args = {"x", "a", "b"}
    }
};

void gen_vec_funs(FILE *stream, size_t n, Type type, bool impl)
{
    for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
        // Function is not defined for the type
        if (fun_defs[fun].name_for_type[type] == NULL) continue;

        gen_sig_begin(stream, vec_type(n, type), vec_func(n, type, fun_defs[fun].suffix));
        for (size_t arg_num = 0; arg_num < fun_defs[fun].arity; ++arg_num) {
            gen_sig_arg(stream, vec_type(n, type), fun_defs[fun].args[arg_num]);
        }
        gen_sig_end(stream, impl);

        if (!impl) continue;

        assert(fun_defs[fun].arity > 0);

        fgenf(stream, "{");
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    %s.%s = %s(", fun_defs[fun].args[0], vec_comps[i], fun_defs[fun].name_for_type[type]);
            for (size_t arg_num = 0; arg_num < fun_defs[fun].arity; ++arg_num) {
                if (arg_num > 0) fprintf(stream, ", ");
                fprintf(stream, "%s.%s", fun_defs[fun].args[arg_num], vec_comps[i]);
            }
            fgenf(stream, ");");
        }
        fgenf(stream, "    return %s;", fun_defs[fun].args[0]);
        fgenf(stream, "}");
        fgen_line_break(stream);
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
    fgen_line_break(stream);
}

void gen_scalar_ctor(FILE *stream, size_t n, Type type, bool impl)
{
    gen_sig_begin(stream, vec_type(n, type), scalar_ctor(n, type)); {
        gen_sig_arg(stream, type_defs[type].name, "x");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fprintf(stream, "    return %s(", vec_ctor(n, type));
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "x");
    }
    fgenf(stream, ");");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

void gen_clamp(FILE *stream, Type type, bool impl)
{
    gen_sig_begin(stream, type_defs[type].name, temp_sprintf("clamp%s", type_defs[type].suffix)); {
        gen_sig_arg(stream, type_defs[type].name, "x");
        gen_sig_arg(stream, type_defs[type].name, "a");
        gen_sig_arg(stream, type_defs[type].name, "b");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    if (x < a) x = a;");
    fgenf(stream, "    if (x > b) x = b;");
    fgenf(stream, "    return x;");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

void gen_min(FILE *stream, Type type, bool impl)
{
    // Ignoring floats 'cause they have fminf, fmaxf, etc.
    if (!type_defs[type].is_integer) return;

    gen_sig_begin(stream, type_defs[type].name, temp_sprintf("min%s", type_defs[type].suffix)); {
        gen_sig_arg(stream, type_defs[type].name, "a");
        gen_sig_arg(stream, type_defs[type].name, "b");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    return a < b ? a : b;");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

void gen_max(FILE *stream, Type type, bool impl)
{
    // Ignoring floats 'cause they have fminf, fmaxf, etc.
    if (!type_defs[type].is_integer) return;

    gen_sig_begin(stream, type_defs[type].name, temp_sprintf("max%s", type_defs[type].suffix)); {
        gen_sig_arg(stream, type_defs[type].name, "a");
        gen_sig_arg(stream, type_defs[type].name, "b");
    } gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    return a > b ? a : b;");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

void gen_lerp(FILE *stream, Type type, bool impl)
{
    // Ignoring integers 'cause lerp doesn't make much sense for them
    if (type_defs[type].is_integer) return;

    if (type == TYPE_DOUBLE) {
        gen_sig_begin(stream, type_defs[type].name, "lerp");
    } else if (type == TYPE_FLOAT) {
        gen_sig_begin(stream, type_defs[type].name, "lerpf");
    } else {
        UNREACHABLE("gen_lerp: type");
    }
    gen_sig_arg(stream, type_defs[type].name, "a");
    gen_sig_arg(stream, type_defs[type].name, "b");
    gen_sig_arg(stream, type_defs[type].name, "t");
    gen_sig_end(stream, impl);

    if (!impl) return;

    fgenf(stream, "{");
    fgenf(stream, "    return a + (b - a) * t;");
    fgenf(stream, "}");
    fgen_line_break(stream);
}

int main()
{
    FILE *stream = stdout;

    // Header Part
    {
        fgenf(stream, "#ifndef LA_H_");
        fgenf(stream, "#define LA_H_");
        fgen_line_break(stream);
        fgenf(stream, "#include <math.h>");
        fgenf(stream, "#include <stdbool.h>");
        fgen_line_break(stream);
        fgenf(stream, "#ifndef LADEF");
        fgenf(stream, "#define LADEF static inline");
        fgenf(stream, "#endif // LADEF");
        fgen_line_break(stream);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_lerp(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_min(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_max(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_clamp(stream, type, false);
        fgen_line_break(stream);
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vec_def(stream, n, type);
            }
        }
        fgen_line_break(stream);
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vec_printf_macros(stream, n, type);
                gen_vec_ctor(stream, n, type, false);
                gen_scalar_ctor(stream, n, type, false);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        gen_vec_convert(stream, n, type, src_n, src_type, false);
                    }
                }

                gen_vec_ops(stream, n, type, false);
                gen_vec_funs(stream, n, type, false);
                gen_vec_sqrlen(stream, n, type, false);
                gen_vec_len(stream, n, type, false);
                gen_vec_dot(stream, n, type, false);
                gen_vec_norm(stream, n, type, false);
                gen_vec_cross(stream, n, type, false);
                gen_vec_eq(stream, n, type, false);
                gen_vec_reflect(stream, n, type, false);
                fgen_line_break(stream);
            }
        }

        fgenf(stream, "#endif // LA_H_");
        fgen_line_break(stream);
    }

    // C part
    {
        fgenf(stream, "#ifdef LA_IMPLEMENTATION");
        fgen_line_break(stream);

        for (Type type = 0; type < COUNT_TYPES; ++type) gen_lerp(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_min(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_max(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_clamp(stream, type, true);
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vec_ctor(stream, n, type, true);
                gen_scalar_ctor(stream, n, type, true);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        gen_vec_convert(stream, n, type, src_n, src_type, true);
                    }
                }

                gen_vec_ops(stream, n, type, true);
                gen_vec_funs(stream, n, type, true);
                gen_vec_sqrlen(stream, n, type, true);
                gen_vec_len(stream, n, type, true);
                gen_vec_dot(stream, n, type, true);
                gen_vec_norm(stream, n, type, true);
                gen_vec_cross(stream, n, type, true);
                gen_vec_eq(stream, n, type, true);
                gen_vec_reflect(stream, n, type, true);
                fgen_line_break(stream);
            }
        }
        fgenf(stream, "#endif // LA_IMPLEMENTATION");
    }

    return 0;
}

// TODO: print stats on how many things were generated
// TODO: v2*_add alias to v2*_sum
// 'Cause I keep confusing them
// TODO: matrices
// TODO: documentation
// TODO: I'm not sure if different size conversions of the vectors are that useful
// Maybe only the same size casting?
// TODO: Would be interesting to introduce some sort of swizzling, like: V4f v2f_xxyy(V2f v)
// TODO: name prefix system similar to the one from nob.h
// TODO: ilerp
