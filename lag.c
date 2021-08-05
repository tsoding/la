#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define VECTOR_MIN_SIZE 2
#define VECTOR_MAX_SIZE 4
static_assert(VECTOR_MIN_SIZE <= VECTOR_MAX_SIZE, "Max vector size may not be less than the min vector size, c'mon");

typedef enum {
    TYPE_FLOAT = 0,
    TYPE_DOUBLE,
    TYPE_INT,
    COUNT_TYPES,
} Type;

typedef struct {
    const char *name;
    const char *suffix;
    const char *fmt;
} Type_Def;

static_assert(COUNT_TYPES == 3, "The amount of type definitions have changed. Please update the array bellow accordingly");
static Type_Def type_defs[COUNT_TYPES] = {
    [TYPE_FLOAT]        = {.name = "float", .suffix = "f", .fmt = "f"},
    [TYPE_DOUBLE]       = {.name = "double", .suffix = "d", .fmt = "lf"},
    [TYPE_INT]          = {.name = "int", .suffix = "i", .fmt = "d"},
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

#define OP_ARITY 2
char *op_arg_names[OP_ARITY] = {"a", "b"};

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

void gen_vector_def(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    fprintf(stream, "typedef struct { %s c[%zu]; } %s;\n",
            type_def.name, n, vector_type.cstr);
}

// Generates function signatures of the following form:
// ret_type name(arg_type arg_prefix0, arg_type arg_prefix1, ...)
// All arguments have the same type. The amount of arguments is defined by the arity
void gen_func_sig(FILE *stream, const char *ret_type, const char *name, const char *arg_type, const char *arg_prefix, size_t arity)
{
    fprintf(stream, "%s %s(", ret_type, name);
    if (arity > 0) fprintf(stream, "%s %s0", arg_type, arg_prefix);
    for (size_t arg_index = 1; arg_index < arity; ++arg_index) {
        fprintf(stream, ", ");
        fprintf(stream, "%s %s%zu", arg_type, arg_prefix, arg_index);
    }
    fprintf(stream, ")");
}

// Generates function signatures of the following form:
// ret_type name(arg_type arg_names[0], arg_type arg_names[1], ..., arg_type arg_names[arity - 1])
// All arguments have the same type.
// TODO: human readable arguments with gen_func_sig_with_names() everywhere completely superseding gen_func_wig()
void gen_func_sig_with_names(FILE *stream, const char *ret_type, const char *name, const char *arg_type, char **arg_names, size_t arity)
{
    fprintf(stream, "%s %s(", ret_type, name);
    if (arity > 0) fprintf(stream, "%s %s", arg_type, arg_names[0]);
    for (size_t arg_index = 1; arg_index < arity; ++arg_index) {
        fprintf(stream, ", ");
        fprintf(stream, "%s %s", arg_type, arg_names[arg_index]);
    }
    fprintf(stream, ")");
}

void gen_vector_op_sig(FILE *stream, size_t n, Type_Def type_def, Op_Def op_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s_%s", vector_prefix.cstr, op_def.suffix);
    
    gen_func_sig_with_names(stream, vector_type.cstr, name.cstr, vector_type.cstr, op_arg_names, OP_ARITY);
}

void gen_vector_ctor_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    gen_func_sig(stream, vector_type.cstr, vector_prefix.cstr, type_def.name, "x", n);
}

void gen_vector_scalar_ctor_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%ss", vector_prefix.cstr);
    gen_func_sig(stream, vector_type.cstr, name.cstr, type_def.name, "x", 1);
}

void gen_vector_scalar_ctor_decl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_scalar_ctor_sig(stream, n, type_def);
    fprintf(stream, ";\n");
}

void gen_vector_scalar_ctor_impl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_scalar_ctor_sig(stream, n, type_def);
    fprintf(stream, "\n");
    fprintf(stream, "{\n");
    fprintf(stream, "    return %s(", make_vector_prefix(n, type_def).cstr);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "x0");
    }
    fprintf(stream, ");\n");
    fprintf(stream, "}\n");
}

void gen_vector_ctor_decl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_ctor_sig(stream, n, type_def);
    fprintf(stream, ";\n");
}

void gen_vector_ctor_impl(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String type = make_vector_type(n, type_def);

    gen_vector_ctor_sig(stream, n, type_def);
    fprintf(stream, "\n");
    fprintf(stream, "{\n");
    fprintf(stream, "    %s result;\n", type.cstr);
    for (size_t i = 0; i < n; ++i) {
        fprintf(stream, "    result.c[%zu] = x%zu;\n", i, i);
    }
    fprintf(stream, "    return result;\n");
    fprintf(stream, "}\n");
}

void gen_vector_op_decl(FILE *stream, size_t n, Type_Def type_def, Op_Def op_def)
{
    gen_vector_op_sig(stream, n, type_def, op_def);
    fprintf(stream, ";\n");
}

void gen_vector_op_impl(FILE *stream, size_t n, Type_Def type_def, Op_Def op_def)
{
    gen_vector_op_sig(stream, n, type_def, op_def);
    fprintf(stream, "\n");
    fprintf(stream, "{\n");
    fprintf(stream, "    for (int i = 0; i < %zu; ++i) %s.c[i] %s %s.c[i];\n", n, op_arg_names[0], op_def.op, op_arg_names[1]);
    fprintf(stream, "    return %s;\n", op_arg_names[0]);
    fprintf(stream, "}\n");
}

typedef enum {
    FUN_SQRT = 0,
    FUN_POW,
    FUN_SIN,
    FUN_COS,
    FUN_MIN,
    FUN_MAX,
    FUN_LERP,
    COUNT_FUNS,
} Fun_Type;

typedef struct {
    const char *suffix;
    // NOTE: NULL means the function is not supported for this type
    const char *name_for_type[COUNT_TYPES];
    size_t arity;
} Fun_Def;

static_assert(COUNT_FUNS == 7, "The amount of functions have changed. Please update the array below accordingly");
static_assert(COUNT_TYPES == 3, "The amount of type definitions have changed. Please update the array bellow accordingly");
Fun_Def fun_defs[COUNT_FUNS] = {
    [FUN_SQRT] = {
        .suffix = "sqrt",
        .name_for_type = {
            [TYPE_FLOAT] = "sqrtf",
            [TYPE_DOUBLE] = "sqrt",
        },
        .arity = 1,
    },
    [FUN_POW] = {
        .suffix = "pow",
        .name_for_type = {
            [TYPE_FLOAT] = "powf",
            [TYPE_DOUBLE] = "pow",
        },
        .arity = 2,
    },
    [FUN_SIN] = {
        .suffix = "sin",
        .name_for_type = {
            [TYPE_FLOAT] = "sinf",
            [TYPE_DOUBLE] = "sin",
        },
        .arity = 1,
    },
    [FUN_COS] = {
        .suffix = "cos",
        .name_for_type = {
            [TYPE_FLOAT] = "cosf",
            [TYPE_DOUBLE] = "cos",
        },
        .arity = 1,
    },
    [FUN_MIN] = {
        .suffix = "min",
        .name_for_type = {
            [TYPE_FLOAT] = "fminf",
            [TYPE_DOUBLE] = "fmin",
        },
        .arity = 2,
    },
    [FUN_MAX] = {
        .suffix = "max",
        .name_for_type = {
            [TYPE_FLOAT] = "fmaxf",
            [TYPE_DOUBLE] = "fmax",
        },
        .arity = 2,
    },
    [FUN_LERP] = {
        .suffix = "lerp",
        .name_for_type = {
            [TYPE_FLOAT] = "lerpf",
            [TYPE_DOUBLE] = "lerp",
        },
        .arity = 3,
    }
};

void gen_vector_fun_decl(FILE *stream, size_t n, Type type, Fun_Type fun)
{
    Fun_Def fun_def = fun_defs[fun];

    if (fun_def.name_for_type[type]) {
        Type_Def type_def = type_defs[type];
        Short_String vector_type = make_vector_type(n, type_def);
        Short_String vector_prefix = make_vector_prefix(n, type_def);
        Short_String name = shortf("%s_%s", vector_prefix.cstr, fun_def.suffix);
        gen_func_sig(stream, vector_type.cstr, name.cstr, vector_type.cstr, "v", fun_def.arity);
        fprintf(stream, ";\n");
    }
}

void gen_vector_fun_impl(FILE *stream, size_t n, Type type, Fun_Type fun)
{
    Type_Def type_def = type_defs[type];
    Fun_Def fun_def = fun_defs[fun];

    const char *arg_prefix = "v";

    if (fun_def.name_for_type[type]) {
        Short_String vector_type = make_vector_type(n, type_def);
        Short_String vector_prefix = make_vector_prefix(n, type_def);
        Short_String name = shortf("%s_%s", vector_prefix.cstr, fun_def.suffix);

        gen_func_sig(stream, vector_type.cstr, name.cstr, vector_type.cstr, "v", fun_def.arity);
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        assert(fun_def.arity >= 1);
        fprintf(stream, "    for (int i = 0; i < %zu; ++i) %s0.c[i] = %s(",
                n, arg_prefix, fun_def.name_for_type[type]);
        for (size_t arg_num = 0; arg_num < fun_def.arity; ++arg_num) {
            if (arg_num > 0) fprintf(stream, ", ");
            fprintf(stream, "%s%zu.c[i]", arg_prefix, arg_num);
        }
        fprintf(stream, ");\n");
        fprintf(stream, "    return %s0;\n", arg_prefix);
        fprintf(stream, "}\n");
    }
}

void gen_lerp_sig(FILE *stream, const char *name, const char *type)
{
    gen_func_sig(stream, type, name, type, "x", 3);
}

void gen_lerp_decl(FILE *stream, const char *name, const char *type)
{
    gen_lerp_sig(stream, name, type);
    fprintf(stream, ";\n");
}

void gen_lerp_impl(FILE *stream, const char *name, const char *type)
{
    gen_lerp_sig(stream, name, type);
    fprintf(stream, "\n");
    fprintf(stream, "{\n");
    fprintf(stream, "    return x0 + (x1 - x0) * x2;\n");
    fprintf(stream, "}\n");
}

void gen_vector_sqrlen_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String vector_type = make_vector_type(n, type_def);
    Short_String vector_prefix = make_vector_prefix(n, type_def);
    Short_String name = shortf("%s_sqrlen", vector_prefix.cstr);
    gen_func_sig(stream, type_def.name, name.cstr, vector_type.cstr, "v", 1);
}

void gen_vector_sqrlen_decl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_sqrlen_sig(stream, n, type_def);
    fprintf(stream, ";\n");
}

void gen_vector_sqrlen_impl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_sqrlen_sig(stream, n, type_def);
    fprintf(stream, "\n");
    fprintf(stream, "{\n");
    fprintf(stream, "    return ");
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, " + ");
        fprintf(stream, "v0.c[%zu]*v0.c[%zu]", i, i);
    }
    fprintf(stream, ";\n");
    fprintf(stream, "}\n");
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
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "v.c[%zu]", i);
    }
    fprintf(stream, "\n");
}

// TODO: len operation for vectors (basically wrappers around sqrlen)
// TODO: matrices
// TODO: macro blocks to disable certain sizes, types, etc

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

        gen_lerp_decl(stream, "lerpf", "float");
        gen_lerp_decl(stream, "lerp", "double");
        fprintf(stream, "\n");
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_def(stream, n, type_defs[type]);
                gen_vector_printf_macros(stream, n, type_defs[type]);
                gen_vector_ctor_decl(stream, n, type_defs[type]);
                gen_vector_scalar_ctor_decl(stream, n, type_defs[type]);
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op_decl(stream, n, type_defs[type], op_defs[op]);
                }
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    gen_vector_fun_decl(stream, n, type, fun);
                }
                gen_vector_sqrlen_decl(stream, n, type_defs[type]);
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

        gen_lerp_impl(stream, "lerpf", "float");
        gen_lerp_impl(stream, "lerp", "double");
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_ctor_impl(stream, n, type_defs[type]);
                gen_vector_scalar_ctor_impl(stream, n, type_defs[type]);
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op_impl(stream, n, type_defs[type], op_defs[op]);
                }
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    gen_vector_fun_impl(stream, n, type, fun);
                }
                gen_vector_sqrlen_impl(stream, n, type_defs[type]);
            }
        }

        fprintf(stream, "\n");
        fprintf(stream, "#endif // LA_IMPLEMENTATION\n");
    }

    return 0;
}
