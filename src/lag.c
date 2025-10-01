#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#include "new.c"

typedef enum {
    STMT_DECL,
    STMT_IMPL,
} Stmt;

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

char *op_arg_names[] = {"a", "b"};
#define OP_ARITY (sizeof(op_arg_names) / sizeof(op_arg_names[0]))

const char *make_vector_type(size_t n, Type_Def type_def)
{
    return temp_sprintf("V%zu%s", n, type_def.suffix);
}

const char *make_vector_prefix(size_t n, Type_Def type_def)
{
    return temp_sprintf("v%zu%s", n, type_def.suffix);
}

void gen_vector_def(FILE *stream, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    fprintf(stream, "typedef union {\n");

    fprintf(stream, "    struct { %s ", type_def.name);
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s", vec_comps[i]);
    }
    fprintf(stream, "; };\n");

    if (n == 4) {
        const char *half_vector_type = make_vector_type(n/2, type_def);
        fprintf(stream, "    struct { %s %s%s; %s %s%s; };\n",
                half_vector_type, vec_comps[0], vec_comps[1],
                half_vector_type, vec_comps[2], vec_comps[3]);
    }

    fprintf(stream, "    %s c[%zu];\n", type_def.name, n);

    fprintf(stream, "} %s;\n", vector_type);
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

void gen_vector_op(FILE *stream, Stmt stmt, size_t n, Type type, Op_Type op_type)
{
    Type_Def type_def = type_defs[type];
    Op_Def op_def     = op_defs[op_type];
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s_%s", vector_prefix, op_def.suffix);
    gen_func_sig(stream, vector_type, name, vector_type, op_arg_names, OP_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        assert(n <= VECTOR_MAX_SIZE);
        static_assert(OP_ARITY >= 2, "This code assumes that operation's arity is at least 2");
        for (size_t i = 0; i < n; ++i) {
            // TODO: fmod/fmodf should be probably a Fun_Type
            static_assert(COUNT_OPS == 5, "Amount of ops has changed");
            static_assert(COUNT_TYPES == 4, "Amount of types has changed");
            if (op_type == OP_MOD && type == TYPE_FLOAT) {
                fprintf(stream, "    %s.%s = fmodf(%s.%s, %s.%s);\n",
                        op_arg_names[0], vec_comps[i],
                        op_arg_names[0], vec_comps[i],
                        op_arg_names[1], vec_comps[i]);
            } else if (op_type == OP_MOD && type == TYPE_DOUBLE) {
                fprintf(stream, "    %s.%s = fmod(%s.%s, %s.%s);\n",
                        op_arg_names[0], vec_comps[i],
                        op_arg_names[0], vec_comps[i],
                        op_arg_names[1], vec_comps[i]);
            } else {
                fprintf(stream, "    %s.%s %s %s.%s;\n",
                        op_arg_names[0],
                        vec_comps[i],
                        op_def.op,
                        op_arg_names[1],
                        vec_comps[i]);
            }
        }
        fprintf(stream, "    return %s;\n", op_arg_names[0]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
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

void gen_vector_fun(FILE *stream, Stmt stmt, size_t n, Type type, Fun_Type fun)
{
    Fun_Def fun_def = fun_defs[fun];
    Type_Def type_def = type_defs[type];
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s_%s", vector_prefix, fun_def.suffix);
    gen_func_sig(stream, vector_type, name, vector_type, fun_def.args, fun_def.arity);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");

        Fun_Def fun_def = fun_defs[fun];
        assert(fun_def.name_for_type[type]);
        assert(fun_def.arity >= 1);
        assert(n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    %s.%s = %s(", fun_def.args[0], vec_comps[i], fun_def.name_for_type[type]);
            for (size_t arg_num = 0; arg_num < fun_def.arity; ++arg_num) {
                if (arg_num > 0) fprintf(stream, ", ");
                fprintf(stream, "%s.%s", fun_def.args[arg_num], vec_comps[i]);
            }
            fprintf(stream, ");\n");
        }
        fprintf(stream, "    return %s;\n", fun_def.args[0]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

#define LERP_ARITY 3
static char *lerp_args[LERP_ARITY] = {"a", "b", "t"};

void gen_lerp(FILE *stream, Stmt stmt, const char *name, const char *type)
{
    gen_func_sig(stream, type, name, type, lerp_args, LERP_ARITY);
    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        char *a = lerp_args[0];
        char *b = lerp_args[1];
        char *t = lerp_args[2];
        fprintf(stream, "    return %s + (%s - %s) * %s;\n", a, b, a, t);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

char *minmax_args[] = {"a", "b"};
#define MINMAX_ARITY (sizeof(minmax_args) / sizeof(minmax_args[0]))

void gen_min(FILE *stream, Stmt stmt, Type_Def type_def)
{
    const char *name = temp_sprintf("min%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name, type_def.name, minmax_args, MINMAX_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        static_assert(MINMAX_ARITY == 2, "Unexpected arity of min/max functions");
        fprintf(stream, "    return %s < %s ? %s : %s;\n",
                minmax_args[0], minmax_args[1], minmax_args[0], minmax_args[1]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_max(FILE *stream, Stmt stmt, Type_Def type_def)
{
    const char *name = temp_sprintf("max%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name, type_def.name, minmax_args, MINMAX_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        static_assert(MINMAX_ARITY == 2, "Unexpected arity of min/max functions");
        fprintf(stream, "    return %s < %s ? %s : %s;\n",
                minmax_args[0], minmax_args[1], minmax_args[1], minmax_args[0]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

// TODO: matrices
// TODO: documentation
// TODO: I'm not sure if different size conversions of the vectors are that useful
// Maybe only the same size casting?
// TODO: Would be interesting to introduce some sort of swizzling, like: V4f v2f_xxyy(V2f v)
// TODO: name prefix system similar to the one from nob.h
// TODO: ilerp

int main()
{
    FILE *stream = stdout;

    // Header Part
    {
        fprintf(stream, "#ifndef LA_H_\n");
        fprintf(stream, "#define LA_H_\n");
        fprintf(stream, "\n");
        fprintf(stream, "#include <math.h>\n");
        fprintf(stream, "#include <stdbool.h>\n");
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
            gen_clamp(stream, type, false);
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
                gen_vec_printf_macros(stream, n, type);
                gen_vec_ctor(stream, n, type, false);
                gen_scalar_ctor(stream, n, type, false);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        gen_vec_convert(stream, n, type, src_n, src_type, false);
                    }
                }
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op(stream, STMT_DECL, n, type, op);
                }

                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    if (fun_defs[fun].name_for_type[type]) {
                        gen_vector_fun(stream, STMT_DECL, n, type, fun);
                    }
                }
                gen_vec_sqrlen(stream, n, type, false);
                gen_vec_len(stream, n, type, false);
                gen_vec_dot(stream, n, type, false);
                gen_vec_norm(stream, n, type, false);
                gen_vec_cross(stream, n, type, false);
                gen_vec_eq(stream, n, type, false);
                gen_vec_reflect(stream, n, type, false);
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
            gen_clamp(stream, type, true);
            fputc('\n', stream);
        }
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vec_ctor(stream, n, type, true);
                fputc('\n', stream);
                gen_scalar_ctor(stream, n, type, true);
                fputc('\n', stream);
                for (size_t src_n = VECTOR_MIN_SIZE; src_n <= VECTOR_MAX_SIZE; ++src_n) {
                    for (Type src_type = 0; src_type < COUNT_TYPES; ++src_type) {
                        gen_vec_convert(stream, n, type, src_n, src_type, true);
                    }
                }
                for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                    gen_vector_op(stream, STMT_IMPL, n, type, op);
                    fputc('\n', stream);
                }

                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    if (fun_defs[fun].name_for_type[type]) {
                        gen_vector_fun(stream, STMT_IMPL, n, type, fun);
                        fputc('\n', stream);
                    }
                }
                gen_vec_sqrlen(stream, n, type, true);
                gen_vec_len(stream, n, type, true);
                gen_vec_dot(stream, n, type, true);
                gen_vec_norm(stream, n, type, true);
                gen_vec_cross(stream, n, type, true);
                gen_vec_eq(stream, n, type, true);
                gen_vec_reflect(stream, n, type, true);
                fputc('\n', stream);
            }
        }
        fprintf(stream, "#endif // LA_IMPLEMENTATION\n");
    }

    // TODO: print stats on how many things were generated
    // TODO: v2*_add alias to v2*_sum
    // 'Cause I keep confusing them

    return 0;
}
