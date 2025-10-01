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
                gen_vec_funs(stream, n, type, false);
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
                gen_vec_funs(stream, n, type, true);
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
