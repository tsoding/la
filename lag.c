#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    TYPE_FLOAT = 0,
    TYPE_DOUBLE,
    TYPE_INT,
    COUNT_TYPES,
} Type;

typedef struct {
    const char *name;
    const char *suffix;
} Type_Def;

static_assert(COUNT_TYPES == 3, "The amount of type definitions have changed. Please update the array bellow accordingly");
static Type_Def type_defs[COUNT_TYPES] = {
    [TYPE_FLOAT]        = {.name = "float", .suffix = "f"},
    [TYPE_DOUBLE]       = {.name = "double", .suffix = "d"},
    [TYPE_INT]          = {.name = "int", .suffix = "i"},
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

typedef struct {
    char data[128];
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
    int n = vsnprintf(result.data, sizeof(result.data), fmt, args);
    assert(n >= 0);
    assert((size_t) n + 1 <= sizeof(result.data));
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
    fprintf(stream, "typedef struct { %s c[%zu]; } V%zu%s;\n",
            type_def.name, n, n, type_def.suffix);
}

void gen_vector_op_sig(FILE *stream, size_t n, Type_Def type_def, Op_Def op_def)
{
    Short_String type = make_vector_type(n, type_def);
    Short_String prefix = make_vector_prefix(n, type_def);

    fprintf(stream, "%s %s_%s(%s a, %s b)",
            type.data,
            prefix.data, op_def.suffix,
            type.data, type.data);
}

void gen_vector_ctor_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String type = make_vector_type(n, type_def);
    Short_String prefix = make_vector_prefix(n, type_def);

    fprintf(stream, "%s %s(", type.data, prefix.data);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s x%zu", type_def.name, i);
    }
    fprintf(stream, ")");
}

void gen_vector_scalar_ctor_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String type = make_vector_type(n, type_def);
    Short_String prefix = make_vector_prefix(n, type_def);

    fprintf(stream, "%s %ss(%s x)", type.data, prefix.data, type_def.name);
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
    fprintf(stream, "    return %s(", make_vector_prefix(n, type_def).data);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "x");
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
    fprintf(stream, "    %s result;\n", type.data);
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
    fprintf(stream, "    for (int i = 0; i < %zu; ++i) a.c[i] %s b.c[i];\n", n, op_def.op);
    fprintf(stream, "    return a;\n");
    fprintf(stream, "}\n");
}

typedef enum {
    FUN_SQRT = 0,
    FUN_POW,
    COUNT_FUNS,
} Fun_Type;

typedef struct {
    const char *suffix;
    // NOTE: NULL means the function is not supported for this type
    const char *name_for_type[COUNT_TYPES];
    size_t arity;
} Fun_Def;

static_assert(COUNT_FUNS == 2, "The amount of functions have changed. Please update the array below accordingly");
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
    }
};

void gen_vector_fun_decl(FILE *stream, size_t n, Type type, Fun_Type fun)
{
    Type_Def type_def = type_defs[type];
    Fun_Def fun_def = fun_defs[fun];

    if (fun_def.name_for_type[type]) {
        Short_String vector_type = make_vector_type(n, type_def);
        Short_String vector_prefix = make_vector_prefix(n, type_def);
        fprintf(stream, "%s %s_%s(", vector_type.data, vector_prefix.data, fun_def.suffix);
        for (size_t arg = 0; arg < fun_def.arity; ++arg) {
            if (arg > 0) fprintf(stream, ", ");
            fprintf(stream, "%s v%zu", vector_type.data, arg);
        }
        fprintf(stream, ");\n");
    }
}

// TODO: sqrt operation for vectors
// TODO: pow operation for vectors
// TODO: lerp operation for vectors
// TODO: len operation for vectors
// TODO: sqrlen operation for vectors
// TODO: min operation for vectors
// TODO: max operation for vectors
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

        for (size_t n = 2; n <= 4; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vector_def(stream, n, type_defs[type]);
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op_decl(stream, n, type_defs[type], op_defs[op]);
                }
                gen_vector_ctor_decl(stream, n, type_defs[type]);
                gen_vector_scalar_ctor_decl(stream, n, type_defs[type]);
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    gen_vector_fun_decl(stream, n, type, fun);
                }
                printf("\n");
            }
        }

        fprintf(stream, "#endif // LA_H_\n");
        fprintf(stream, "\n");
    }

    // C part
    {
        fprintf(stream, "#ifdef LA_IMPLEMENTATION\n");
        fprintf(stream, "\n");

        for (size_t n = 2; n <= 4; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op_impl(stream, n, type_defs[type], op_defs[op]);
                }
                fprintf(stream, "\n");
                gen_vector_ctor_impl(stream, n, type_defs[type]);
                fprintf(stream, "\n");
                gen_vector_scalar_ctor_impl(stream, n, type_defs[type]);
                fprintf(stream, "\n");
            }
        }

        fprintf(stream, "#endif // LA_IMPLEMENTATION\n");
    }

    return 0;
}
