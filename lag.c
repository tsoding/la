#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    const char *name;
    const char *suffix;
} Type_Def;

typedef enum {
    TYPE_DEF_FLOAT = 0,
    TYPE_DEF_DOUBLE,
    TYPE_DEF_INT,
    COUNT_TYPE_DEFS,
} Type_Def_Type;

static_assert(COUNT_TYPE_DEFS == 3, "The amount of type definitions have changed. Please update the array bellow accordingly");
static Type_Def type_defs[COUNT_TYPE_DEFS] = {
    [TYPE_DEF_FLOAT]        = {.name = "float", .suffix = "f"},
    [TYPE_DEF_DOUBLE]       = {.name = "double", .suffix = "d"},
    [TYPE_DEF_INT]          = {.name = "int", .suffix = "i"},
};

typedef enum {
    OP_DEF_SUM = 0,
    OP_DEF_SUB,
    OP_DEF_MUL,
    OP_DEF_DIV,
    COUNT_OP_DEFS,
} Op_Def_Type;

typedef struct {
    const char *suffix;
    const char *op;
} Op_Def;

static_assert(COUNT_OP_DEFS == 4, "The amount of operator definitions have changed. Please update the array below accordingly");
static Op_Def op_defs[COUNT_OP_DEFS] = {
    [OP_DEF_SUM] = {.suffix = "sum", .op = "+="},
    [OP_DEF_SUB] = {.suffix = "sub", .op = "-="},
    [OP_DEF_MUL] = {.suffix = "mul", .op = "*="},
    [OP_DEF_DIV] = {.suffix = "div", .op = "/="},
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

Short_String vector_type(size_t n, Type_Def type_def)
{
    return shortf("V%zu%s", n, type_def.suffix);
}

Short_String vector_prefix(size_t n, Type_Def type_def)
{
    return shortf("v%zu%s", n, type_def.suffix);
}

void gen_vector_def(FILE *stream, size_t n, Type_Def type_def)
{
    fprintf(stream, "typedef struct { %s c[%zu]; } V%zu%s;\n",
            type_def.name, n, n, type_def.suffix);
}

Short_String vector_op_sig(size_t n, Type_Def type_def, Op_Def op_def)
{
    Short_String type = vector_type(n, type_def);
    Short_String prefix = vector_prefix(n, type_def);

    return shortf("%s %s_%s(%s a, %s b)",
                  type.data,
                  prefix.data, op_def.suffix,
                  type.data, type.data);
}

void gen_vector_ctor_sig(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String type = vector_type(n, type_def);
    Short_String prefix = vector_prefix(n, type_def);

    fprintf(stream, "%s %s(", type.data, prefix.data);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s x%zu", type_def.name, i);
    }
    fprintf(stream, ")");
}

void gen_vector_ctor_decl(FILE *stream, size_t n, Type_Def type_def)
{
    gen_vector_ctor_sig(stream, n, type_def);
    fprintf(stream, ";\n");
}

void gen_vector_ctor_impl(FILE *stream, size_t n, Type_Def type_def)
{
    Short_String type = vector_type(n, type_def);

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
    fprintf(stream, "%s;\n", vector_op_sig(n, type_def, op_def).data);
}

void gen_vector_op_impl(FILE *stream, size_t n, Type_Def type_def, Op_Def op_def)
{
    fprintf(stream, "%s\n", vector_op_sig(n, type_def, op_def).data);
    fprintf(stream, "{\n");
    fprintf(stream, "    for (int i = 0; i < %zu; ++i) a.c[i] %s b.c[i];\n", n, op_def.op);
    fprintf(stream, "    return a;\n");
    fprintf(stream, "}\n");
}

// TODO: scalar constructor for vectors v<n><t>s(t a)
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
    // Header Part
    {
        fprintf(stdout, "#ifndef LA_H_\n");
        fprintf(stdout, "#define LA_H_\n");
        fprintf(stdout, "\n");

        for (size_t n = 2; n <= 4; ++n) {
            for (Type_Def_Type i = 0; i < COUNT_TYPE_DEFS; ++i) {
                gen_vector_def(stdout, n, type_defs[i]);
            }
            fprintf(stdout, "\n");
        }

        for (size_t n = 2; n <= 4; ++n) {
            for (Type_Def_Type type = 0; type < COUNT_TYPE_DEFS; ++type) {
                for (Op_Def_Type op = 0; op < COUNT_OP_DEFS; ++op) {
                    gen_vector_op_decl(stdout, n, type_defs[type], op_defs[op]);
                }
                fprintf(stdout, "\n");
            }
        }

        for (size_t n = 2; n <= 4; ++n) {
            for (Type_Def_Type type = 0; type < COUNT_TYPE_DEFS; ++type) {
                gen_vector_ctor_decl(stdout, n, type_defs[type]);
            }
            fprintf(stdout, "\n");
        }

        fprintf(stdout, "#endif // LA_H_\n");
        fprintf(stdout, "\n");
    }

    // C part
    {
        fprintf(stdout, "#ifdef LA_IMPLEMENTATION\n");
        fprintf(stdout, "\n");
        for (size_t n = 2; n <= 4; ++n) {
            for (Type_Def_Type type = 0; type < COUNT_TYPE_DEFS; ++type) {
                for (Op_Def_Type op = 0; op < COUNT_OP_DEFS; ++op) {
                    gen_vector_op_impl(stdout, n, type_defs[type], op_defs[op]);
                    fprintf(stdout, "\n");
                }
            }
        }

        for (size_t n = 2; n <= 4; ++n) {
            for (Type_Def_Type type = 0; type < COUNT_TYPE_DEFS; ++type) {
                gen_vector_ctor_impl(stdout, n, type_defs[type]);
                fprintf(stdout, "\n");
            }
        }

        fprintf(stdout, "#endif // LA_IMPLEMENTATION\n");
    }

    return 0;
}
