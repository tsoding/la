#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define VECTOR_MIN_SIZE 2
#define VECTOR_MAX_SIZE 4
static_assert(VECTOR_MIN_SIZE <= VECTOR_MAX_SIZE, "Max vector size may not be less than the min vector size, c'mon");

typedef enum {
    STMT_DECL,
    STMT_IMPL,
} Stmt;

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
} Type_Def;

static_assert(COUNT_TYPES == 4, "The amount of type definitions have changed. Please update the array bellow accordingly");
static Type_Def type_defs[COUNT_TYPES] = {
    [TYPE_FLOAT]        = {.name = "float", .suffix = "f", .fmt = "f", .zero_lit = "0.0f"},
    [TYPE_DOUBLE]       = {.name = "double", .suffix = "d", .fmt = "lf", .zero_lit = "0.0"},
    [TYPE_INT]          = {.name = "int", .suffix = "i", .fmt = "d", .zero_lit = "0"},
    [TYPE_UNSIGNED_INT] = {.name = "unsigned int", .suffix = "u", .fmt = "u", .zero_lit = "0u"},
};

typedef enum {
    OP_SUM = 0,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    COUNT_OPS,
} Op_Type;

typedef struct {
    const char *suffix;
    const char *op;
} Op_Def;

static_assert(COUNT_OPS == 4, "The amount of operator definitions have changed. Please update the array below accordingly");
static Op_Def op_defs[COUNT_OPS] = {
    [OP_SUM] = {.suffix = "sum", .op = "+="},
    [OP_SUB] = {.suffix = "sub", .op = "-="},
    [OP_MUL] = {.suffix = "mul", .op = "*="},
    [OP_DIV] = {.suffix = "div", .op = "/="},
};

char *op_arg_names[] = {"a", "b"};
#define OP_ARITY (sizeof(op_arg_names) / sizeof(op_arg_names[0]))


typedef struct {
    char cstr[128];
} Short_String;

#if defined(__GNUC__) || defined(__clang__)
#define CHECK_PRINTF_FMT(a, b) __attribute__ ((format (printf, a, b)))
#else
#define CHECK_PRINTF_FMT(...)
#endif

CHECK_PRINTF_FMT(1, 2) Short_String shortf(const char *fmt, ...)
{
    Short_String result = {0};

    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(result.cstr, sizeof(result.cstr), fmt, args);
    assert(n >= 0);
    assert((size_t) n + 1 <= sizeof(result.cstr));
    va_end(args);

    return result;
}

Short_String make_vector_type(size_t n, Type_Def type_def)
{
    return shortf("V%zu%s", n, type_def.suffix);
}

Short_String make_vector_prefix(size_t n, Type_Def type_def)
{
    return shortf("v%zu%s", n, type_def.suffix);
}

static_assert(VECTOR_MAX_SIZE == 4, "We defined only 4 vector component names. Please update this list accordingly");
static char *vector_comps[VECTOR_MAX_SIZE] = {"x", "y", "z", "w"};

void gen_vector_def(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    fprintf(stream, "typedef struct { %s ", type_def.name);
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s", vector_comps[i]);
    }
    fprintf(stream, "; } %s;\n", vector_type.cstr);
}

// Generates function signatures of the following form:
// ret_type name(arg_type arg_names[0], arg_type arg_names[1], ..., arg_type arg_names[arity - 1])
// All arguments have the same type.
void gen_func_sig(FILE *stream, const char *ret_type, const char *name, const char *arg_type, char **arg_names, size_t arity)
{
    fprintf(stream, "LADEF %s %s(", ret_type, name);
    if (arity > 0) fprintf(stream, "%s %s", arg_type, arg_names[0]);
    for (size_t arg_index = 1; arg_index < arity; ++arg_index) {
        fprintf(stream, ", ");
        fprintf(stream, "%s %s", arg_type, arg_names[arg_index]);
    }
    fprintf(stream, ")");
}

void gen_vector_ctor(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    assert(n <= VECTOR_MAX_SIZE);
    gen_func_sig(stream, vector_type.cstr, vector_prefix.cstr, type_def.name, vector_comps, n);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s v;\n", vector_type.cstr);
        assert(n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    v.%s = %s;\n", vector_comps[i], vector_comps[i]);
        }
        fprintf(stream, "    return v;\n");
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

void gen_vector_scalar_ctor(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s%s", vector_prefix.cstr, type_def.suffix);
    static_assert(VECTOR_MAX_SIZE >= 1, "The vector size is too short for this code");
    gen_func_sig(stream, vector_type.cstr, name.cstr, type_def.name, vector_comps, 1);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return %s(", make_vector_prefix(n, type_def).cstr);
        for (size_t i = 0; i < n; ++i) {
            if (i > 0) fprintf(stream, ", ");
            static_assert(VECTOR_MAX_SIZE >= 1, "The vector size is too short for this code");
            fprintf(stream, "%s", vector_comps[0]);
        }
        fprintf(stream, ");\n");
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

void gen_vector_op(FILE *stream, Stmt stmt, size_t n, Type_Def type_def, Op_Def op_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s_%s", vector_prefix.cstr, op_def.suffix);
    gen_func_sig(stream, vector_type.cstr, name.cstr, vector_type.cstr, op_arg_names, OP_ARITY);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        assert(n <= VECTOR_MAX_SIZE);
        static_assert(OP_ARITY >= 2, "This code assumes that operation's arity is at least 2");
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    %s.%s %s %s.%s;\n", 
                    op_arg_names[0], 
                    vector_comps[i],
                    op_def.op, 
                    op_arg_names[1],
                    vector_comps[i]);
        }
        fprintf(stream, "    return %s;\n", op_arg_names[0]);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

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

void gen_vector_fun(FILE *stream, Stmt stmt, size_t n, Type type, Fun_Type fun)
{
    Fun_Def fun_def = fun_defs[fun];
    Type_Def type_def = type_defs[type];
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s_%s", vector_prefix.cstr, fun_def.suffix);
    gen_func_sig(stream, vector_type.cstr, name.cstr, vector_type.cstr, fun_def.args, fun_def.arity);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");

        Fun_Def fun_def = fun_defs[fun];
        assert(fun_def.name_for_type[type]);
        assert(fun_def.arity >= 1);
        assert(n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    %s.%s = %s(", fun_def.args[0], vector_comps[i], fun_def.name_for_type[type]);
            for (size_t arg_num = 0; arg_num < fun_def.arity; ++arg_num) {
                if (arg_num > 0) fprintf(stream, ", ");
                fprintf(stream, "%s.%s", fun_def.args[arg_num], vector_comps[i]);
            }
            fprintf(stream, ");\n");
        }
        fprintf(stream, "    return %s;\n", fun_def.args[0]);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

#define LERP_ARITY 3
static char *lerp_args[LERP_ARITY] = {"a", "b", "t"};

void gen_lerp(FILE *stream, Stmt stmt, const char *name, const char *type)
{
    gen_func_sig(stream, type, name, type, lerp_args, LERP_ARITY);
    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        char *a = lerp_args[0];
        char *b = lerp_args[1];
        char *t = lerp_args[2];
        fprintf(stream, "    return %s + (%s - %s) * %s;\n", a, b, a, t);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

char *minmax_args[] = {"a", "b"};
#define MINMAX_ARITY (sizeof(minmax_args) / sizeof(minmax_args[0]))

void gen_min(FILE *stream, Stmt stmt, Type_Def type_def)
{
    Short_String name = shortf("min%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name.cstr, type_def.name, minmax_args, MINMAX_ARITY);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        static_assert(MINMAX_ARITY == 2, "Unexpected arity of min/max functions");
        fprintf(stream, "    return %s < %s ? %s : %s;\n", 
                minmax_args[0], minmax_args[1], minmax_args[0], minmax_args[1]);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

void gen_max(FILE *stream, Stmt stmt, Type_Def type_def)
{
    Short_String name = shortf("max%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name.cstr, type_def.name, minmax_args, MINMAX_ARITY);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        static_assert(MINMAX_ARITY == 2, "Unexpected arity of min/max functions");
        fprintf(stream, "    return %s < %s ? %s : %s;\n", 
                minmax_args[0], minmax_args[1], minmax_args[1], minmax_args[0]);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

char *clamp_args[] = {"x", "a", "b"};
#define CLAMP_ARITY (sizeof(clamp_args) / sizeof(clamp_args[0]))

void gen_clamp(FILE *stream, Stmt stmt, Type type, Fun_Def min_def, Fun_Def max_def)
{
    Type_Def type_def = type_defs[type];
    Short_String name = shortf("clamp%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name.cstr, type_def.name, clamp_args, CLAMP_ARITY);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");

        static_assert(CLAMP_ARITY == 3, "Unexpected clamp arity");
        const char *min_name = min_def.name_for_type[type];
        assert(min_name != NULL);
        const char *max_name = max_def.name_for_type[type];
        assert(max_name != NULL);
        fprintf(stream, "    return %s(%s(%s, %s), %s);\n", 
                min_name, max_name, clamp_args[1], clamp_args[0], clamp_args[2]);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

static char *sqrlen_arg_name = "a";

void gen_vector_sqrlen(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s_sqrlen", vector_prefix.cstr);
    gen_func_sig(stream, type_def.name, name.cstr, vector_type.cstr, &sqrlen_arg_name, 1);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return ");
        assert(n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < n; ++i) {
            if (i > 0) fprintf(stream, " + ");
            fprintf(stream, "%s.%s*%s.%s", sqrlen_arg_name, vector_comps[i], sqrlen_arg_name, vector_comps[i]);
        }
        fprintf(stream, ";\n");
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

void gen_vector_printf_macros(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);

    fprintf(stream, "#define %s_Fmt \"%s(", vector_type.cstr, vector_prefix.cstr);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%%%s", type_def.fmt);
    }
    fprintf(stream, ")\"\n");

    fprintf(stream, "#define %s_Arg(v) ", vector_type.cstr);
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "(v).%s", vector_comps[i]);
    }
    fprintf(stream, "\n");
}

static_assert(COUNT_TYPES == 4, "Amount of types have changed");
const char *funcs_sqrt_defined_for[COUNT_TYPES] = {
    [TYPE_FLOAT] = "sqrtf",
    [TYPE_DOUBLE] = "sqrt",
};

void gen_vector_len(FILE *stream, Stmt stmt, size_t n, Type_Def type_def, const char *sqrt_name)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String func_name = shortf("%s_len", vector_prefix.cstr);

    gen_func_sig(stream, type_def.name, func_name.cstr, vector_type.cstr, &sqrlen_arg_name, 1);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        Short_String sqrlen_name = shortf("%s_sqrlen", vector_prefix.cstr);
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return %s(%s(%s));\n", sqrt_name, sqrlen_name.cstr, sqrlen_arg_name);
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

char *vector_convert_arg = "a";

void gen_vector_convert(FILE *stream, Stmt stmt,
                        size_t dst_n, Type_Def dst_type_def,
                        size_t src_n, Type_Def src_type_def)
{
    Short_String dst_type = make_vector_type(dst_n, dst_type_def);
    Short_String src_type = make_vector_type(src_n, src_type_def);
    Short_String name = shortf("v%zu%s%zu%s", dst_n, dst_type_def.suffix, src_n, src_type_def.suffix);
    gen_func_sig(stream, dst_type.cstr, name.cstr, src_type.cstr, &vector_convert_arg, 1);

    if (stmt == STMT_DECL) {
        fprintf(stream, ";\n");
    } else if (stmt == STMT_IMPL) {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s result;\n", dst_type.cstr);
        assert(dst_n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < dst_n; ++i) {
            if (i < src_n) {
                fprintf(stream, "    result.%s = (%s) %s.%s;\n", vector_comps[i], dst_type_def.name, vector_convert_arg, vector_comps[i]);
            } else {
                fprintf(stream, "    result.%s = %s;\n", vector_comps[i], dst_type_def.zero_lit);
            }
        }
        fprintf(stream, "    return result;\n");
        fprintf(stream, "}\n");
    } else {
        assert(0 && "unreachable");
        exit(69);
    }
}

// TODO: matrices
// TODO: documentation
// TODO: I'm not sure if different size conversions of the vectors are that useful
// Maybe only the same size casting?
// TODO: Would be interesting to introduce some sort of swizzling, like: V4f v2f_xxyy(V2f v)

int main()
{
    FILE *stream = stdout;

    // Header Part
    {
        fprintf(stream, "#ifndef LA_H_\n");
        fprintf(stream, "#define LA_H_\n");
        fprintf(stream, "\n");
        fprintf(stream, "#include <math.h>\n");
        fprintf(stream, "\n");
        fprintf(stream, "#ifndef LADEF\n");
        fprintf(stream, "#define LADEF static inline\n");
        fprintf(stream, "#endif // LADEF\n");
        fprintf(stream, "\n");
        gen_lerp(stream, STMT_DECL, "lerpf", "float");
        gen_lerp(stream, STMT_DECL, "lerp", "double");
        // TODO: more robust generation of min/max functions
        // kinda similar to how we do that for sqrt ones
        gen_min(stream, STMT_DECL, type_defs[TYPE_INT]);
        gen_max(stream, STMT_DECL, type_defs[TYPE_INT]);
        gen_min(stream, STMT_DECL, type_defs[TYPE_UNSIGNED_INT]);
        gen_max(stream, STMT_DECL, type_defs[TYPE_UNSIGNED_INT]);
        for (Type type = 0; type < COUNT_TYPES; ++type) {
            gen_clamp(stream, STMT_DECL, type, fun_defs[FUN_MIN], fun_defs[FUN_MAX]);
        }
        fprintf(stream, "\n");
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_def(stream, n, type_defs[type]);
            }
        }
        fprintf(stream, "\n");
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_printf_macros(stream, n, type_defs[type]);
                gen_vector_ctor(stream, STMT_DECL, n, type_defs[type]);
                gen_vector_scalar_ctor(stream, STMT_DECL, n, type_defs[type]);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        if (src_n != n || src_type != type) {
                            gen_vector_convert(stream, STMT_DECL, n, type_defs[type], src_n, type_defs[src_type]);
                        }
                    }
                }
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op(stream, STMT_DECL, n, type_defs[type], op_defs[op]);
                }
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    if (fun_defs[fun].name_for_type[type]) {
                        gen_vector_fun(stream, STMT_DECL, n, type, fun);
                    }
                }
                gen_vector_sqrlen(stream, STMT_DECL, n, type_defs[type]);
                if (funcs_sqrt_defined_for[type]) {
                    gen_vector_len(stream, STMT_DECL, n, type_defs[type], funcs_sqrt_defined_for[type]);
                }
                fprintf(stream, "\n");
            }
        }

        fprintf(stream, "#endif // LA_H_\n");
        fprintf(stream, "\n");
    }

    // C part
    {
        fprintf(stream, "#ifdef LA_IMPLEMENTATION\n");
        fprintf(stream, "\n");

        gen_lerp(stream, STMT_IMPL, "lerpf", "float");
        fputc('\n', stream);
        gen_lerp(stream, STMT_IMPL, "lerp", "double");
        fputc('\n', stream);
        gen_min(stream, STMT_IMPL, type_defs[TYPE_INT]);
        fputc('\n', stream);
        gen_max(stream, STMT_IMPL, type_defs[TYPE_INT]);
        fputc('\n', stream);
        gen_min(stream, STMT_IMPL, type_defs[TYPE_UNSIGNED_INT]);
        fputc('\n', stream);
        gen_max(stream, STMT_IMPL, type_defs[TYPE_UNSIGNED_INT]);
        fputc('\n', stream);
        for (Type type = 0; type < COUNT_TYPES; ++type) {
            gen_clamp(stream, STMT_IMPL, type, fun_defs[FUN_MIN], fun_defs[FUN_MAX]);
            fputc('\n', stream);
        }
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_ctor(stream, STMT_IMPL, n, type_defs[type]);
                fputc('\n', stream);
                gen_vector_scalar_ctor(stream, STMT_IMPL, n, type_defs[type]);
                fputc('\n', stream);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        if (src_n != n || src_type != type) {
                            gen_vector_convert(stream, STMT_IMPL, n, type_defs[type], src_n, type_defs[src_type]);
                            fputc('\n', stream);
                        }
                    }
                }
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op(stream, STMT_IMPL, n, type_defs[type], op_defs[op]);
                    fputc('\n', stream);
                }
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    if (fun_defs[fun].name_for_type[type]) {
                        gen_vector_fun(stream, STMT_IMPL, n, type, fun);
                        fputc('\n', stream);
                    }
                }
                gen_vector_sqrlen(stream, STMT_IMPL, n, type_defs[type]);
                fputc('\n', stream);
                if (funcs_sqrt_defined_for[type]) {
                    gen_vector_len(stream, STMT_IMPL, n, type_defs[type], funcs_sqrt_defined_for[type]);
                    fputc('\n', stream);
                }
            }
        }
        fprintf(stream, "#endif // LA_IMPLEMENTATION\n");
    }

    // TODO: print stats on how many things were generated
    // TODO: v2*_add alias to v2*_sum
    // 'Cause I keep confusing them

    return 0;
}
