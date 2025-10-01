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

const char *make_vector_type(size_t n, Type_Def type_def)
{
    return temp_sprintf("V%zu%s", n, type_def.suffix);
}

const char *make_vector_prefix(size_t n, Type_Def type_def)
{
    return temp_sprintf("v%zu%s", n, type_def.suffix);
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
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_lerp(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_min(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_max(stream, type, false);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_clamp(stream, type, false);
        fprintf(stream, "\n");
        for (size_t n = VECTOR_MIN_SIZE; n <= VECTOR_MAX_SIZE; ++n) {
            for (Type type = 0; type < COUNT_TYPES; ++type) {
                gen_vec_def(stream, n, type);
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

                gen_vec_ops(stream, n, type, false);

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

        for (Type type = 0; type < COUNT_TYPES; ++type) gen_lerp(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_min(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_max(stream, type, true);
        for (Type type = 0; type < COUNT_TYPES; ++type) gen_clamp(stream, type, true);
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

                gen_vec_ops(stream, n, type, true);

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
