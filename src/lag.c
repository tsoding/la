#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#define VECTOR_MIN_SIZE 2
#define VECTOR_MAX_SIZE 4
static_assert(VECTOR_MIN_SIZE <= VECTOR_MAX_SIZE, "Max vector size may not be less than the min vector size, c'mon");

#define MATRIX_MIN_DIM 2
#define MATRIX_MAX_DIM 4
static_assert(MATRIX_MIN_DIM <= MATRIX_MAX_DIM, "Max matrix dim may not be less than the min matrix dim");

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
    [TYPE_FLOAT]        = { .name = "float",        .suffix = "f", .fmt = "f",  .zero_lit = "0.0f" },
    [TYPE_DOUBLE]       = { .name = "double",       .suffix = "d", .fmt = "lf", .zero_lit = "0.0"  },
    [TYPE_INT]          = { .name = "int",          .suffix = "i", .fmt = "d",  .zero_lit = "0"    },
    [TYPE_UNSIGNED_INT] = { .name = "unsigned int", .suffix = "u", .fmt = "u",  .zero_lit = "0u"   },
};

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

const char *make_matrix_type(size_t rows, size_t cols, Type_Def type_def)
{
    return temp_sprintf("M%zux%zu%s", rows, cols, type_def.suffix);
}

const char *make_matrix_prefix(size_t rows, size_t cols, Type_Def type_def)
{
    return temp_sprintf("m%zux%zu%s", rows, cols, type_def.suffix);
}

static const char *make_rotor_type(size_t n, Type_Def type_def)
{
    assert(n == 2 || n == 3);
    return temp_sprintf("R%zu%s", n, type_def.suffix);
}

static const char *make_rotor_prefix(size_t n, Type_Def type_def)
{
    assert(n == 2 || n == 3);
    return temp_sprintf("r%zu%s", n, type_def.suffix);
}

static_assert(VECTOR_MAX_SIZE == 4, "We defined only 4 vector component names. Please update this list accordingly");
static char *vector_comps[VECTOR_MAX_SIZE] = {"x", "y", "z", "w"};

void gen_vector_def(FILE *stream, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    fprintf(stream, "typedef union {\n");

    fprintf(stream, "    struct { %s ", type_def.name);
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%s", vector_comps[i]);
    }
    fprintf(stream, "; };\n");

    fprintf(stream, "    %s c[%zu];\n", type_def.name, n);

    fprintf(stream, "} %s;\n", vector_type);
}

void gen_matrix_def(FILE *stream, size_t rows, size_t cols, Type_Def type_def)
{
    const char *matrix_type = make_matrix_type(rows, cols, type_def);
    fprintf(stream, "typedef union {\n");
    fprintf(stream, "    %s rc[%zu][%zu];\n", type_def.name, rows, cols);
    fprintf(stream, "    %s c[%zu];\n", type_def.name, rows*cols);
    fprintf(stream, "} %s;\n", matrix_type);
}

void gen_rotor_def(FILE *stream, size_t n, Type_Def type_def)
{
    const char *rotor_type = make_rotor_type(n, type_def);
    fprintf(stream, "typedef struct {\n");
    fprintf(stream, "    %s a;\n", type_def.name);
    fprintf(stream, "    %s b01;\n", type_def.name);
    if (n == 3) {
        fprintf(stream, "    %s b02;\n", type_def.name);
        fprintf(stream, "    %s b12;\n", type_def.name);
    }
    fprintf(stream, "} %s;\n", rotor_type);
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
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    assert(n <= VECTOR_MAX_SIZE);
    gen_func_sig(stream, vector_type, vector_prefix, type_def.name, vector_comps, n);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s v;\n", vector_type);
        assert(n <= VECTOR_MAX_SIZE);
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    v.%s = %s;\n", vector_comps[i], vector_comps[i]);
        }
        fprintf(stream, "    return v;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_vector_scalar_ctor(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s%s", vector_prefix, type_def.suffix);
    static_assert(VECTOR_MAX_SIZE >= 1, "The vector size is too short for this code");
    gen_func_sig(stream, vector_type, name, type_def.name, vector_comps, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return %s(", make_vector_prefix(n, type_def));
        for (size_t i = 0; i < n; ++i) {
            if (i > 0) fprintf(stream, ", ");
            static_assert(VECTOR_MAX_SIZE >= 1, "The vector size is too short for this code");
            fprintf(stream, "%s", vector_comps[0]);
        }
        fprintf(stream, ");\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_ctor(FILE *stream, Stmt stmt, size_t rows, size_t cols, Type_Def type_def)
{
    const char *matrix_type = make_matrix_type(rows, cols, type_def);
    const char *matrix_prefix = make_matrix_prefix(rows, cols, type_def);
    size_t arity = rows * cols;
    char *arg_names[16];
    size_t k = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            arg_names[k++] = temp_sprintf("m%zu%zu", i, j);
        }
    }
    gen_func_sig(stream, matrix_type, matrix_prefix, type_def.name, arg_names, arity);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s m;\n", matrix_type);
        size_t t = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                fprintf(stream, "    m.rc[%zu][%zu] = %s;\n", i, j, arg_names[t++]);
            }
        }
        fprintf(stream, "    return m;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_scalar_ctor(FILE *stream, Stmt stmt, size_t rows, size_t cols, Type_Def type_def)
{
    const char *matrix_type = make_matrix_type(rows, cols, type_def);
    const char *matrix_prefix = make_matrix_prefix(rows, cols, type_def);
    const char *name = temp_sprintf("%s%s", matrix_prefix, type_def.suffix);
    static char *arg_name = "s";
    gen_func_sig(stream, matrix_type, name, type_def.name, &arg_name, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s m;\n", matrix_type);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                fprintf(stream, "    m.rc[%zu][%zu] = %s;\n", i, j, arg_name);
            }
        }
        fprintf(stream, "    return m;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
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
                        op_arg_names[0], vector_comps[i],
                        op_arg_names[0], vector_comps[i],
                        op_arg_names[1], vector_comps[i]);
            } else if (op_type == OP_MOD && type == TYPE_DOUBLE) {
                fprintf(stream, "    %s.%s = fmod(%s.%s, %s.%s);\n",
                        op_arg_names[0], vector_comps[i],
                        op_arg_names[0], vector_comps[i],
                        op_arg_names[1], vector_comps[i]);
            } else {
                fprintf(stream, "    %s.%s %s %s.%s;\n",
                        op_arg_names[0],
                        vector_comps[i],
                        op_def.op,
                        op_arg_names[1],
                        vector_comps[i]);
            }
        }
        fprintf(stream, "    return %s;\n", op_arg_names[0]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_op(FILE *stream, Stmt stmt, size_t rows, size_t cols, Type type, Op_Type op_type)
{
    Type_Def type_def = type_defs[type];
    Op_Def op_def     = op_defs[op_type];
    const char *matrix_type = make_matrix_type(rows, cols, type_def);
    const char *matrix_prefix = make_matrix_prefix(rows, cols, type_def);
    const char *name = temp_sprintf("%s_%s", matrix_prefix, op_def.suffix);
    gen_func_sig(stream, matrix_type, name, matrix_type, op_arg_names, OP_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        static_assert(OP_ARITY >= 2, "This code assumes that operation's arity is at least 2");
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                static_assert(COUNT_OPS == 5, "Amount of ops has changed");
                static_assert(COUNT_TYPES == 4, "Amount of types has changed");
                if (op_type == OP_MOD && type == TYPE_FLOAT) {
                    fprintf(stream, "    %s.rc[%zu][%zu] = fmodf(%s.rc[%zu][%zu], %s.rc[%zu][%zu]);\n",
                            op_arg_names[0], i, j,
                            op_arg_names[0], i, j,
                            op_arg_names[1], i, j);
                } else if (op_type == OP_MOD && type == TYPE_DOUBLE) {
                    fprintf(stream, "    %s.rc[%zu][%zu] = fmod(%s.rc[%zu][%zu], %s.rc[%zu][%zu]);\n",
                            op_arg_names[0], i, j,
                            op_arg_names[0], i, j,
                            op_arg_names[1], i, j);
                } else {
                    fprintf(stream, "    %s.rc[%zu][%zu] %s %s.rc[%zu][%zu];\n",
                            op_arg_names[0], i, j,
                            op_def.op,
                            op_arg_names[1], i, j);
                }
            }
        }
        fprintf(stream, "    return %s;\n", op_arg_names[0]);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
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
            fprintf(stream, "    %s.%s = %s(", fun_def.args[0], vector_comps[i], fun_def.name_for_type[type]);
            for (size_t arg_num = 0; arg_num < fun_def.arity; ++arg_num) {
                if (arg_num > 0) fprintf(stream, ", ");
                fprintf(stream, "%s.%s", fun_def.args[arg_num], vector_comps[i]);
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

char *clamp_args[] = {"x", "a", "b"};
#define CLAMP_ARITY (sizeof(clamp_args) / sizeof(clamp_args[0]))

void gen_clamp(FILE *stream, Stmt stmt, Type type, Fun_Def min_def, Fun_Def max_def)
{
    Type_Def type_def = type_defs[type];
    const char *name = temp_sprintf("clamp%s", type_def.suffix);
    gen_func_sig(stream, type_def.name, name, type_def.name, clamp_args, CLAMP_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
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
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

static char *sqrlen_arg_name = "a";

void gen_vector_sqrlen(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s_sqrlen", vector_prefix);
    gen_func_sig(stream, type_def.name, name, vector_type, &sqrlen_arg_name, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
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
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_vector_printf_macros(FILE *stream, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);

    fprintf(stream, "#define %s_Fmt \"%s(", vector_type, vector_prefix);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "%%%s", type_def.fmt);
    }
    fprintf(stream, ")\"\n");

    fprintf(stream, "#define %s_Arg(v) ", vector_type);
    assert(n <= VECTOR_MAX_SIZE);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) fprintf(stream, ", ");
        fprintf(stream, "(v).%s", vector_comps[i]);
    }
    fprintf(stream, "\n");
}

void gen_matrix_printf_macros(FILE *stream, size_t rows, size_t cols, Type_Def type_def)
{
    const char *matrix_type = make_matrix_type(rows, cols, type_def);
    const char *matrix_prefix = make_matrix_prefix(rows, cols, type_def);

    fprintf(stream, "#define %s_Fmt \"%s(", matrix_type, matrix_prefix);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i > 0 || j > 0) fprintf(stream, ", ");
            fprintf(stream, "%%%s", type_def.fmt);
        }
    }
    fprintf(stream, ")\"\n");

    fprintf(stream, "#define %s_Arg(m) ", matrix_type);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i > 0 || j > 0) fprintf(stream, ", ");
            fprintf(stream, "(m).rc[%zu][%zu]", i, j);
        }
    }
    fprintf(stream, "\n");
}

static_assert(COUNT_TYPES == 4, "Amount of types have changed");
const char *funcs_sqrt_defined_for[COUNT_TYPES] = {
    [TYPE_FLOAT] = "sqrtf",
    [TYPE_DOUBLE] = "sqrt",
};

static_assert(COUNT_TYPES == 4, "Amount of types have changed");
const char *funcs_fabs_defined_for[COUNT_TYPES] = {
    [TYPE_FLOAT] = "fabsf",
    [TYPE_DOUBLE] = "fabs",
};

static const char *type_epsilon_lit(Type type)
{
    switch (type) {
    case TYPE_FLOAT: return "1e-6f";
    case TYPE_DOUBLE: return "1e-12";

    case TYPE_INT:;
    case TYPE_UNSIGNED_INT:;
    case COUNT_TYPES:;
    // fallthrough
    default: return NULL;
    }
}

void gen_vector_len(FILE *stream, Stmt stmt, size_t n, Type_Def type_def, const char *sqrt_name)
{
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *func_name = temp_sprintf("%s_len", vector_prefix);

    gen_func_sig(stream, type_def.name, func_name, vector_type, &sqrlen_arg_name, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        const char *sqrlen_name = temp_sprintf("%s_sqrlen", vector_prefix);
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return %s(%s(%s));\n", sqrt_name, sqrlen_name, sqrlen_arg_name);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

static char *dot_args[] = {"a", "b"};
#define DOT_ARITY (sizeof(dot_args) / sizeof(dot_args[0]))

void gen_vector_dot(FILE *stream, Stmt stmt, size_t n, Type_Def type_def)
{
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s_dot", vector_prefix);
    gen_func_sig(stream, type_def.name, name, vector_type, dot_args, DOT_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    return ");
        for (size_t i = 0; i < n; ++i) {
            if (i > 0) fprintf(stream, " + ");
            fprintf(stream, "%s.%s*%s.%s", dot_args[0], vector_comps[i], dot_args[1], vector_comps[i]);
        }
        fprintf(stream, ";\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_vector_normalize(FILE *stream, Stmt stmt, size_t n, Type type, const char *sqrt_name)
{
    // name unused for now
    (void)sqrt_name;
    Type_Def type_def = type_defs[type];
    const char *vector_type = make_vector_type(n, type_def);
    const char *vector_prefix = make_vector_prefix(n, type_def);
    const char *name = temp_sprintf("%s_normalize", vector_prefix);
    static char *arg = "a";
    gen_func_sig(stream, vector_type, name, vector_type, &arg, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        const char *len_func = temp_sprintf("%s_len", vector_prefix);
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s r;\n", vector_type);
        fprintf(stream, "    %s len = %s(%s);\n", type_def.name, len_func, arg);
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    r.%s = %s.%s / len;\n", vector_comps[i], arg, vector_comps[i]);
        }
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_vector_cross(FILE *stream, Stmt stmt, Type_Def type_def)
{
    const char *vector_type = make_vector_type(3, type_def);
    const char *vector_prefix = make_vector_prefix(3, type_def);
    const char *name = temp_sprintf("%s_cross", vector_prefix);
    gen_func_sig(stream, vector_type, name, vector_type, dot_args, DOT_ARITY);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s r;\n", vector_type);
        fprintf(stream, "    r.x = a.y*b.z - a.z*b.y;\n");
        fprintf(stream, "    r.y = a.z*b.x - a.x*b.z;\n");
        fprintf(stream, "    r.z = a.x*b.y - a.y*b.x;\n");
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_triangle_normal(FILE *stream, Stmt stmt, Type type)
{
    Type_Def type_def = type_defs[type];
    const char *vector_type = make_vector_type(3, type_def);
    const char *vector_prefix = make_vector_prefix(3, type_def);
    static char *args[3] = {"a", "b", "c"};
    const char *name = temp_sprintf("%s_normal_from_points", vector_prefix);
    gen_func_sig(stream, vector_type, name, vector_type, args, 3);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        const char *sub_name = temp_sprintf("%s_sub", vector_prefix);
        const char *cross_name = temp_sprintf("%s_cross", vector_prefix);
        const char *norm_name = temp_sprintf("%s_normalize", vector_prefix);
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s u = %s(b, a);\n", vector_type, sub_name);
        fprintf(stream, "    %s v = %s(c, a);\n", vector_type, sub_name);
        fprintf(stream, "    %s n = %s(u, v);\n", vector_type, cross_name);
        fprintf(stream, "    return %s(n);\n", norm_name);
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

char *vector_convert_arg = "a";

void gen_vector_convert(FILE *stream, Stmt stmt,
                        size_t dst_n, Type_Def dst_type_def,
                        size_t src_n, Type_Def src_type_def)
{
    const char *dst_type = make_vector_type(dst_n, dst_type_def);
    const char *src_type = make_vector_type(src_n, src_type_def);
    const char *name = temp_sprintf("v%zu%s%zu%s", dst_n, dst_type_def.suffix, src_n, src_type_def.suffix);
    gen_func_sig(stream, dst_type, name, src_type, &vector_convert_arg, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s result;\n", dst_type);
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
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_convert(FILE *stream, Stmt stmt,
                        size_t dst_rows, size_t dst_cols, Type_Def dst_type_def,
                        size_t src_rows, size_t src_cols, Type_Def src_type_def)
{
    const char *dst_type = make_matrix_type(dst_rows, dst_cols, dst_type_def);
    const char *src_type = make_matrix_type(src_rows, src_cols, src_type_def);
    const char *name = temp_sprintf("m%zux%zu%s%zux%zu%s", dst_rows, dst_cols, dst_type_def.suffix, src_rows, src_cols, src_type_def.suffix);

    fprintf(stream, "LADEF %s %s(%s a)", dst_type, name, src_type);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s result;\n", dst_type);
        for (size_t i = 0; i < dst_rows; ++i) {
            for (size_t j = 0; j < dst_cols; ++j) {
                if (i < src_rows && j < src_cols) {
                    fprintf(stream, "    result.rc[%zu][%zu] = (%s) a.rc[%zu][%zu];\n", i, j, dst_type_def.name, i, j);
                } else {
                    fprintf(stream, "    result.rc[%zu][%zu] = %s;\n", i, j, dst_type_def.zero_lit);
                }
            }
        }
        fprintf(stream, "    return result;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

static const char *type_one_lit(Type type)
{
    static_assert(COUNT_TYPES == 4, "Amount of types have changed");
    switch (type) {
    case TYPE_FLOAT: return "1.0f";
    case TYPE_DOUBLE: return "1.0";
    case TYPE_INT: return "1";
    case TYPE_UNSIGNED_INT: return "1u";
    case COUNT_TYPES:; // fallthrough
    default: UNREACHABLE("invalid type for one literal");
    }
}

void gen_matrix_identity(FILE *stream, Stmt stmt, size_t n, Type type)
{
    Type_Def type_def = type_defs[type];
    const char *matrix_type = make_matrix_type(n, n, type_def);
    const char *matrix_prefix = make_matrix_prefix(n, n, type_def);
    const char *name = temp_sprintf("%s_identity", matrix_prefix);
    fprintf(stream, "LADEF %s %s(void)", matrix_type, name);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s m;\n", matrix_type);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                fprintf(stream, "    m.rc[%zu][%zu] = %s;\n", i, j, type_defs[type].zero_lit);
            }
        }
        for (size_t i = 0; i < n; ++i) {
            fprintf(stream, "    m.rc[%zu][%zu] = %s;\n", i, i, type_one_lit(type));
        }
        fprintf(stream, "    return m;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_transpose(FILE *stream, Stmt stmt, size_t rows, size_t cols, Type_Def type_def)
{
    const char *src_type = make_matrix_type(rows, cols, type_def);
    const char *dst_type = make_matrix_type(cols, rows, type_def);
    const char *src_prefix = make_matrix_prefix(rows, cols, type_def);
    const char *name = temp_sprintf("%s_transpose", src_prefix);
    static char *arg = "a";

    gen_func_sig(stream, dst_type, name, src_type, &arg, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s r;\n", dst_type);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                fprintf(stream, "    r.rc[%zu][%zu] = %s.rc[%zu][%zu];\n", j, i, arg, i, j);
            }
        }
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_mul(FILE *stream, Stmt stmt,
                    size_t a_rows, size_t a_cols,
                    size_t b_rows, size_t b_cols,
                    Type_Def type_def)
{
    assert(a_cols == b_rows);
    const char *a_type = make_matrix_type(a_rows, a_cols, type_def);
    const char *b_type = make_matrix_type(b_rows, b_cols, type_def);
    const char *r_type = make_matrix_type(a_rows, b_cols, type_def);
    const char *name = temp_sprintf("%s_mmul_%s", make_matrix_prefix(a_rows, a_cols, type_def), make_matrix_prefix(b_rows, b_cols, type_def));

    fprintf(stream, "LADEF %s %s(%s a, %s b)", r_type, name, a_type, b_type);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s r;\n", r_type);
        for (size_t i = 0; i < a_rows; ++i) {
            for (size_t j = 0; j < b_cols; ++j) {
                fprintf(stream, "    r.rc[%zu][%zu] = %s;\n", i, j, type_def.zero_lit);
                fprintf(stream, "    for (size_t k = 0; k < %zu; ++k) r.rc[%zu][%zu] += a.rc[%zu][k] * b.rc[k][%zu];\n", a_cols, i, j, i, j);
            }
        }
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_mat_vec_mul(FILE *stream, Stmt stmt,
                     size_t rows, size_t cols,
                     Type_Def type_def)
{
    // Column-vector convention: M(rows x cols) * V(cols) -> V(rows)
    const char *m_type = make_matrix_type(rows, cols, type_def);
    const char *v_in_type = make_vector_type(cols, type_def);
    const char *v_out_type = make_vector_type(rows, type_def);
    const char *name = temp_sprintf("%s_mul_%s", make_matrix_prefix(rows, cols, type_def), make_vector_prefix(cols, type_def));
    fprintf(stream, "LADEF %s %s(%s m, %s v)", v_out_type, name, m_type, v_in_type);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s r;\n", v_out_type);
        for (size_t i = 0; i < rows; ++i) {
            fprintf(stream, "    r.c[%zu] = %s;\n", i, type_def.zero_lit);
            for (size_t k = 0; k < cols; ++k) {
                fprintf(stream, "    r.c[%zu] += m.rc[%zu][%zu] * v.c[%zu];\n", i, i, k, k);
            }
        }
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_det(FILE *stream, Stmt stmt, size_t n, Type type)
{
    Type_Def type_def = type_defs[type];
    const char *matrix_type = make_matrix_type(n, n, type_def);
    const char *matrix_prefix = make_matrix_prefix(n, n, type_def);
    const char *name = temp_sprintf("%s_det", matrix_prefix);
    static char *arg = "m";
    const char *fabs_name = funcs_fabs_defined_for[type];
    const char *eps = type_epsilon_lit(type);
    if (!fabs_name || !eps) return; // not supported for this type

    gen_func_sig(stream, type_def.name, name, matrix_type, &arg, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s a[%zu][%zu];\n", type_def.name, n, n);
        fprintf(stream, "    for (size_t i = 0; i < %zu; ++i) for (size_t j = 0; j < %zu; ++j) a[i][j] = m.rc[i][j];\n", n, n);
        fprintf(stream, "    int sign = 1;\n");
        fprintf(stream, "    %s det = %s;\n", type_def.name, type_one_lit(type));
        fprintf(stream, "    for (size_t i = 0; i < %zu; ++i) {\n", n);
        fprintf(stream, "        size_t pivot = i;\n");
        fprintf(stream, "        for (size_t r = i+1; r < %zu; ++r) if (%s(a[r][i]) > %s(a[pivot][i])) pivot = r;\n", n, fabs_name, fabs_name);
        fprintf(stream, "        if (%s(a[pivot][i]) < %s) return %s;\n", fabs_name, eps, type_defs[type].zero_lit);
        fprintf(stream, "        if (pivot != i) {\n");
        fprintf(stream, "            for (size_t c = 0; c < %zu; ++c) { %s tmp = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = tmp; }\n", n, type_def.name);
        fprintf(stream, "            sign = -sign;\n");
        fprintf(stream, "        }\n");
        fprintf(stream, "        for (size_t r = i+1; r < %zu; ++r) {\n", n);
        fprintf(stream, "            %s f = a[r][i] / a[i][i];\n", type_def.name);
        fprintf(stream, "            for (size_t c = i; c < %zu; ++c) a[r][c] -= f * a[i][c];\n", n);
        fprintf(stream, "        }\n");
        fprintf(stream, "    }\n");
        fprintf(stream, "    for (size_t i = 0; i < %zu; ++i) det *= a[i][i];\n", n);
        fprintf(stream, "    return sign < 0 ? -det : det;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_matrix_inverse(FILE *stream, Stmt stmt, size_t n, Type type)
{
    Type_Def type_def = type_defs[type];
    const char *matrix_type = make_matrix_type(n, n, type_def);
    const char *matrix_prefix = make_matrix_prefix(n, n, type_def);
    const char *name = temp_sprintf("%s_inverse", matrix_prefix);
    static char *arg = "m";
    const char *fabs_name = funcs_fabs_defined_for[type];
    const char *eps = type_epsilon_lit(type);
    if (!fabs_name || !eps) return; // not supported for this type

    gen_func_sig(stream, matrix_type, name, matrix_type, &arg, 1);

    switch (stmt) {
    case STMT_DECL: {
        fprintf(stream, ";\n");
    } break;
    case STMT_IMPL: {
        fprintf(stream, "\n");
        fprintf(stream, "{\n");
        fprintf(stream, "    %s a[%zu][%zu];\n", type_def.name, n, n);
        fprintf(stream, "    %s inv;\n", matrix_type);
        fprintf(stream, "    for (size_t i = 0; i < %zu; ++i) {\n", n);
        fprintf(stream, "        for (size_t j = 0; j < %zu; ++j) { a[i][j] = m.rc[i][j]; inv.rc[i][j] = %s; }\n", n, type_defs[type].zero_lit);
        fprintf(stream, "        inv.rc[i][i] = %s;\n", type_one_lit(type));
        fprintf(stream, "    }\n");
        fprintf(stream, "    for (size_t i = 0; i < %zu; ++i) {\n", n);
        fprintf(stream, "        size_t pivot = i;\n");
        fprintf(stream, "        for (size_t r = i+1; r < %zu; ++r) if (%s(a[r][i]) > %s(a[pivot][i])) pivot = r;\n", n, fabs_name, fabs_name);
        fprintf(stream, "        %s piv = a[pivot][i];\n", type_def.name);
        fprintf(stream, "        if (%s(piv) < %s) return inv;\n", fabs_name, eps);
        fprintf(stream, "        if (pivot != i) {\n");
        fprintf(stream, "            for (size_t c = 0; c < %zu; ++c) { %s ta = a[i][c]; a[i][c] = a[pivot][c]; a[pivot][c] = ta; %s ti = inv.rc[i][c]; inv.rc[i][c] = inv.rc[pivot][c]; inv.rc[pivot][c] = ti; }\n", n, type_def.name, type_def.name);
        fprintf(stream, "        }\n");
        fprintf(stream, "        %s inv_piv = (%s)1 / a[i][i];\n", type_def.name, type_def.name);
        fprintf(stream, "        for (size_t c = 0; c < %zu; ++c) { a[i][c] *= inv_piv; inv.rc[i][c] *= inv_piv; }\n", n);
        fprintf(stream, "        for (size_t r = 0; r < %zu; ++r) if (r != i) { %s f = a[r][i]; if (%s(f) > 0) { for (size_t c = 0; c < %zu; ++c) { a[r][c] -= f * a[i][c]; inv.rc[r][c] -= f * inv.rc[i][c]; } } }\n", n, type_def.name, fabs_name, n);
        fprintf(stream, "    }\n");
        fprintf(stream, "    return inv;\n");
        fprintf(stream, "}\n");
    } break;
    default: UNREACHABLE(temp_sprintf("invalid stmt: %d", stmt));
    }
}

void gen_rotor_funcs(FILE *stream, Stmt stmt, size_t n, Type type)
{
    assert(n == 2 || n == 3);
    Type_Def type_def = type_defs[type];
    // Only support float/double
    if (!(type == TYPE_FLOAT || type == TYPE_DOUBLE)) return;

    const char *rotor_type   = make_rotor_type(n, type_def);
    const char *rotor_prefix = make_rotor_prefix(n, type_def);
    const char *vec_type     = make_vector_type(n, type_def);
    const char *vec_prefix   = make_vector_prefix(n, type_def);

    const char *sqrt_name = funcs_sqrt_defined_for[type];
    const char *sin_name  = fun_defs[FUN_SIN].name_for_type[type];
    const char *cos_name  = fun_defs[FUN_COS].name_for_type[type];
    assert(sqrt_name && sin_name && cos_name);

    // Helpers for names
    const char *identity_name      = temp_sprintf("%s_identity", rotor_prefix);
    const char *mul_name           = temp_sprintf("%s_mul", rotor_prefix);
    const char *reverse_name       = temp_sprintf("%s_reverse", rotor_prefix);
    const char *lengthsqrd_name    = temp_sprintf("%s_lengthsqr", rotor_prefix);
    const char *length_name        = temp_sprintf("%s_length", rotor_prefix);
    const char *normalize_name     = temp_sprintf("%s_normalize", rotor_prefix);
    const char *normal_name        = temp_sprintf("%s_normal", rotor_prefix);
    const char *from_to_name       = temp_sprintf("%s_from_unit_vectors", rotor_prefix);
    const char *rotate_vec_name    = temp_sprintf("%s_rotate_%s", rotor_prefix, vec_prefix);
    const char *rotate_rotor_name  = temp_sprintf("%s_rotate_%s", rotor_prefix, rotor_prefix);

    const char *dot_name = temp_sprintf("%s_dot", vec_prefix);

    const char *from_angle_name = NULL;
    const char *plane_angle_name = NULL;
    const char *m3_type = NULL;
    const char *to_m3_name = NULL;
    if (n == 2) {
        from_angle_name = temp_sprintf("%s_from_angle", rotor_prefix);
    } else { // n == 3
        plane_angle_name = temp_sprintf("%s_from_plane_angle", rotor_prefix);
        m3_type = make_matrix_type(3, 3, type_def);
        to_m3_name = temp_sprintf("%s_to_%s", rotor_prefix, make_matrix_prefix(3,3,type_def));
    }

    // Declarations
    if (stmt == STMT_DECL) {
        fprintf(stream, "LADEF %s %s(void);\n", rotor_type, identity_name);
        fprintf(stream, "LADEF %s %s(%s p, %s q);\n", rotor_type, mul_name, rotor_type, rotor_type);
        fprintf(stream, "LADEF %s %s(%s p);\n", rotor_type, reverse_name, rotor_type);
        fprintf(stream, "LADEF %s %s(%s p);\n", type_def.name, lengthsqrd_name, rotor_type);
        fprintf(stream, "LADEF %s %s(%s p);\n", type_def.name, length_name, rotor_type);
        fprintf(stream, "LADEF %s %s(%s p);\n", rotor_type, normalize_name, rotor_type);
        fprintf(stream, "LADEF %s %s(%s p);\n", rotor_type, normal_name, rotor_type);
        if (n == 2) {
            fprintf(stream, "LADEF %s %s(%s angle);\n", rotor_type, from_angle_name, type_def.name);
        } else {
            fprintf(stream, "LADEF %s %s(%s bv_plane, %s angle);\n", rotor_type, plane_angle_name, make_vector_type(3, type_def), type_def.name);
        }
        fprintf(stream, "LADEF %s %s(%s from, %s to);\n", rotor_type, from_to_name, vec_type, vec_type);
        fprintf(stream, "LADEF %s %s(%s r, %s v);\n", vec_type, rotate_vec_name, rotor_type, vec_type);
        fprintf(stream, "LADEF %s %s(%s p, %s r);\n", rotor_type, rotate_rotor_name, rotor_type, rotor_type);
        if (n == 3) {
            fprintf(stream, "LADEF %s %s(%s r);\n", m3_type, to_m3_name, rotor_type);
        }
        return;
    }

    // identity
    fprintf(stream, "LADEF %s %s(void)\n{\n", rotor_type, identity_name);
    fprintf(stream, "    %s r;\n", rotor_type);
    fprintf(stream, "    r.a = %s; r.b01 = %s;\n", type_one_lit(type), type_def.zero_lit);
    if (n == 3) {
        fprintf(stream, "    r.b02 = %s; r.b12 = %s;\n", type_def.zero_lit, type_def.zero_lit);
    }
    fprintf(stream, "    return r;\n");
    fprintf(stream, "}\n");

    // mul
    fprintf(stream, "LADEF %s %s(%s p, %s q)\n{\n", rotor_type, mul_name, rotor_type, rotor_type);
    fprintf(stream, "    %s r;\n", rotor_type);
    if (n == 2) {
        fprintf(stream, "    r.a   = p.a*q.a - p.b01*q.b01;\n");
        fprintf(stream, "    r.b01 = p.b01*q.a + p.a*q.b01;\n");
    } else {
        fprintf(stream, "    r.a   = p.a*q.a - p.b01*q.b01 - p.b02*q.b02 - p.b12*q.b12;\n");
        fprintf(stream, "    r.b01 = p.b01*q.a + p.a*q.b01 + p.b12*q.b02 - p.b02*q.b12;\n");
        fprintf(stream, "    r.b02 = p.b02*q.a + p.a*q.b02 - p.b12*q.b01 + p.b01*q.b12;\n");
        fprintf(stream, "    r.b12 = p.b12*q.a + p.a*q.b12 + p.b02*q.b01 - p.b01*q.b02;\n");
    }
    fprintf(stream, "    return r;\n");
    fprintf(stream, "}\n");

    // reverse
    fprintf(stream, "LADEF %s %s(%s p)\n{\n", rotor_type, reverse_name, rotor_type);
    fprintf(stream, "    %s r;\n", rotor_type);
    fprintf(stream, "    r.a = p.a; r.b01 = -p.b01;\n");
    if (n == 3) {
        fprintf(stream, "    r.b02 = -p.b02; r.b12 = -p.b12;\n");
    }
    fprintf(stream, "    return r;\n");
    fprintf(stream, "}\n");

    // lengthsqrd
    fprintf(stream, "LADEF %s %s(%s p)\n{\n", type_def.name, lengthsqrd_name, rotor_type);
    fprintf(stream, "    return p.a*p.a + p.b01*p.b01");
    if (n == 3) fprintf(stream, " + p.b02*p.b02 + p.b12*p.b12");
    fprintf(stream, ";\n}\n");

    // length
    fprintf(stream, "LADEF %s %s(%s p)\n{\n", type_def.name, length_name, rotor_type);
    fprintf(stream, "    return %s(%s(p));\n", sqrt_name, lengthsqrd_name);
    fprintf(stream, "}\n");

    // normalize
    fprintf(stream, "LADEF %s %s(%s p)\n{\n", rotor_type, normalize_name, rotor_type);
    fprintf(stream, "    %s l = %s(%s(p));\n", type_def.name, sqrt_name, lengthsqrd_name);
    fprintf(stream, "    %s r;\n", rotor_type);
    fprintf(stream, "    r.a = p.a / l; r.b01 = p.b01 / l;\n");
    if (n == 3) {
        fprintf(stream, "    r.b02 = p.b02 / l; r.b12 = p.b12 / l;\n");
    }
    fprintf(stream, "    return r;\n");
    fprintf(stream, "}\n");

    // normal
    fprintf(stream, "LADEF %s %s(%s p)\n{\n", rotor_type, normal_name, rotor_type);
    fprintf(stream, "    return %s(p);\n", normalize_name);
    fprintf(stream, "}\n");

    // from angle (2D)
    if (n == 2) {
        fprintf(stream, "LADEF %s %s(%s angle)\n{\n", rotor_type, from_angle_name, type_def.name);
        fprintf(stream, "    %s r;\n", rotor_type);
        fprintf(stream, "    %s half = angle / (%s)2;\n", type_def.name, type_def.name);
        fprintf(stream, "    %s sa = %s(half);\n", type_def.name, sin_name);
        fprintf(stream, "    %s ca = %s(half);\n", type_def.name, cos_name);
        fprintf(stream, "    r.a = ca; r.b01 = -sa;\n");
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    } else {
        // from plane + angle (3D)
        fprintf(stream, "LADEF %s %s(%s bv_plane, %s angle)\n{\n", rotor_type, plane_angle_name, make_vector_type(3, type_def), type_def.name);
        fprintf(stream, "    %s r;\n", rotor_type);
        fprintf(stream, "    %s half = angle / (%s)2;\n", type_def.name, type_def.name);
        fprintf(stream, "    %s sa = %s(half);\n", type_def.name, sin_name);
        fprintf(stream, "    %s ca = %s(half);\n", type_def.name, cos_name);
        fprintf(stream, "    r.a = ca;\n");
        fprintf(stream, "    r.b01 = -sa * bv_plane.x;\n");
        fprintf(stream, "    r.b02 = -sa * bv_plane.y;\n");
        fprintf(stream, "    r.b12 = -sa * bv_plane.z;\n");
        fprintf(stream, "    return r;\n");
        fprintf(stream, "}\n");
    }

    // from unit vectors
    fprintf(stream, "LADEF %s %s(%s from, %s to)\n{\n", rotor_type, from_to_name, vec_type, vec_type);
    fprintf(stream, "    %s r;\n", rotor_type);
    fprintf(stream, "    r.a = (%s)1 + %s(to, from);\n", type_def.name, dot_name);
    if (n == 2) {
        fprintf(stream, "    r.b01 = to.x*from.y - to.y*from.x;\n");
    } else {
        fprintf(stream, "    r.b01 = to.x*from.y - to.y*from.x;\n");
        fprintf(stream, "    r.b02 = to.x*from.z - to.z*from.x;\n");
        fprintf(stream, "    r.b12 = to.y*from.z - to.z*from.y;\n");
    }
    fprintf(stream, "    return %s(r);\n", normalize_name);
    fprintf(stream, "}\n");

    // rotate vector
    fprintf(stream, "LADEF %s %s(%s p, %s x)\n{\n", vec_type, rotate_vec_name, rotor_type, vec_type);
    if (n == 2) {
        fprintf(stream, "    %s aa = p.a*p.a;\n", type_def.name);
        fprintf(stream, "    %s bb = p.b01*p.b01;\n", type_def.name);
        fprintf(stream, "    %s twoab = (%s)2 * p.a * p.b01;\n", type_def.name, type_def.name);
        fprintf(stream, "    %s r;\n", vec_type);
        fprintf(stream, "    r.x = (aa - bb) * x.x + twoab * x.y;\n");
        fprintf(stream, "    r.y = (aa - bb) * x.y - twoab * x.x;\n");
        fprintf(stream, "    return r;\n");
    } else {
        fprintf(stream, "    %s q0 = p.a*x.x + x.y*p.b01 + x.z*p.b02;\n", type_def.name);
        fprintf(stream, "    %s q1 = p.a*x.y - x.x*p.b01 + x.z*p.b12;\n", type_def.name);
        fprintf(stream, "    %s q2 = p.a*x.z - x.x*p.b02 - x.y*p.b12;\n", type_def.name);
        fprintf(stream, "    %s q012 = x.x*p.b12 - x.y*p.b02 + x.z*p.b01;\n", type_def.name);
        fprintf(stream, "    %s r;\n", vec_type);
        fprintf(stream, "    r.x = p.a*q0 + q1*p.b01 + q2*p.b02 + q012*p.b12;\n");
        fprintf(stream, "    r.y = p.a*q1 - q0*p.b01 - q012*p.b02 + q2*p.b12;\n");
        fprintf(stream, "    r.z = p.a*q2 + q012*p.b01 - q0*p.b02 - q1*p.b12;\n");
        fprintf(stream, "    return r;\n");
    }
    fprintf(stream, "}\n");

    // rotate rotor: p * r * p^*
    fprintf(stream, "LADEF %s %s(%s p, %s r)\n{\n", rotor_type, rotate_rotor_name, rotor_type, rotor_type);
    fprintf(stream, "    return %s(%s(p, r), %s(p));\n", mul_name, mul_name, reverse_name);
    fprintf(stream, "}\n");

    // to 3x3 matrix (columns are rotated basis vectors)
    if (n == 3) {
        fprintf(stream, "LADEF %s %s(%s p)\n{\n", m3_type, to_m3_name, rotor_type);
        fprintf(stream, "    %s e0 = %s((%s)1, (%s)0, (%s)0);\n", make_vector_type(3, type_def), make_vector_prefix(3, type_def), type_def.name, type_def.name, type_def.name);
        fprintf(stream, "    %s e1 = %s((%s)0, (%s)1, (%s)0);\n", make_vector_type(3, type_def), make_vector_prefix(3, type_def), type_def.name, type_def.name, type_def.name);
        fprintf(stream, "    %s e2 = %s((%s)0, (%s)0, (%s)1);\n", make_vector_type(3, type_def), make_vector_prefix(3, type_def), type_def.name, type_def.name, type_def.name);
        fprintf(stream, "    %s c0 = %s(p, e0);\n", make_vector_type(3, type_def), rotate_vec_name);
        fprintf(stream, "    %s c1 = %s(p, e1);\n", make_vector_type(3, type_def), rotate_vec_name);
        fprintf(stream, "    %s c2 = %s(p, e2);\n", make_vector_type(3, type_def), rotate_vec_name);
        fprintf(stream, "    %s m;\n", m3_type);
        fprintf(stream, "    m.rc[0][0] = c0.x; m.rc[1][0] = c0.y; m.rc[2][0] = c0.z;\n");
        fprintf(stream, "    m.rc[0][1] = c1.x; m.rc[1][1] = c1.y; m.rc[2][1] = c1.z;\n");
        fprintf(stream, "    m.rc[0][2] = c2.x; m.rc[1][2] = c2.y; m.rc[2][2] = c2.z;\n");
        fprintf(stream, "    return m;\n");
        fprintf(stream, "}\n");
    }
}

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
        fprintf(stream, "#include <stddef.h>\n");
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
        for (size_t rows = MATRIX_MIN_DIM; rows <= MATRIX_MAX_DIM; ++rows) {
            for (size_t cols = MATRIX_MIN_DIM; cols <= MATRIX_MAX_DIM; ++cols) {
                for (Type type = 0; type < COUNT_TYPES; ++type) {
                    gen_matrix_def(stream, rows, cols, type_defs[type]);
                }
            }
        }
        fprintf(stream, "\n");
        for (Type t = 0; t < COUNT_TYPES; ++t) {
            if (t == TYPE_FLOAT || t == TYPE_DOUBLE) {
                gen_rotor_def(stream, 2, type_defs[t]);
                gen_rotor_def(stream, 3, type_defs[t]);
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
                    gen_vector_op(stream, STMT_DECL, n, type, op);
                }
                for (Fun_Type fun = 0; fun < COUNT_FUNS; ++fun) {
                    if (fun_defs[fun].name_for_type[type]) {
                        gen_vector_fun(stream, STMT_DECL, n, type, fun);
                    }
                }
                gen_vector_sqrlen(stream, STMT_DECL, n, type_defs[type]);
                if (funcs_sqrt_defined_for[type]) {
                    gen_vector_len(stream, STMT_DECL, n, type_defs[type], funcs_sqrt_defined_for[type]);
                    gen_vector_normalize(stream, STMT_DECL, n, type, funcs_sqrt_defined_for[type]);
                }
                gen_vector_dot(stream, STMT_DECL, n, type_defs[type]);
                if (n == 3) {
                    gen_vector_cross(stream, STMT_DECL, type_defs[type]);
                    if (funcs_sqrt_defined_for[type]) {
                        gen_triangle_normal(stream, STMT_DECL, type);
                    }
                }
                fprintf(stream, "\n");
            }
        }

        for (size_t rows = MATRIX_MIN_DIM; rows <= MATRIX_MAX_DIM; ++rows) {
            for (size_t cols = MATRIX_MIN_DIM; cols <= MATRIX_MAX_DIM; ++cols) {
                for (Type type = 0; type < COUNT_TYPES; ++type) {
                    gen_matrix_printf_macros(stream, rows, cols, type_defs[type]);
                    gen_matrix_ctor(stream, STMT_DECL, rows, cols, type_defs[type]);
                    gen_matrix_scalar_ctor(stream, STMT_DECL, rows, cols, type_defs[type]);
                    if (rows == cols) {
                        gen_matrix_identity(stream, STMT_DECL, rows, type);
                        gen_matrix_det(stream, STMT_DECL, rows, type);
                        gen_matrix_inverse(stream, STMT_DECL, rows, type);
                    }
                    for (size_t srows = MATRIX_MIN_DIM; srows <= MATRIX_MAX_DIM; ++srows) {
                        for (size_t scols = MATRIX_MIN_DIM; scols <= MATRIX_MAX_DIM; ++scols) {
                            for (Type stype = 0; stype < COUNT_TYPES; ++stype) {
                                if (srows != rows || scols != cols || stype != type) {
                                    gen_matrix_convert(stream, STMT_DECL, rows, cols, type_defs[type], srows, scols, type_defs[stype]);
                                }
                            }
                        }
                    }
                    for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                        gen_matrix_op(stream, STMT_DECL, rows, cols, type, op);
                    }
                    gen_matrix_transpose(stream, STMT_DECL, rows, cols, type_defs[type]);
                    for (size_t bc = MATRIX_MIN_DIM; bc <= MATRIX_MAX_DIM; ++bc) {
                        // a(rows x cols) * b(cols x bc) -> r(rows x bc)
                        gen_matrix_mul(stream, STMT_DECL, rows, cols, cols, bc, type_defs[type]);
                    }
                    gen_mat_vec_mul(stream, STMT_DECL, rows, cols, type_defs[type]);
                    fprintf(stream, "\n");
                }
            }
        }

        for (Type t = 0; t < COUNT_TYPES; ++t) {
            if (t == TYPE_FLOAT || t == TYPE_DOUBLE) {
                gen_rotor_funcs(stream, STMT_DECL, 2, t);
                gen_rotor_funcs(stream, STMT_DECL, 3, t);
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
                    gen_vector_op(stream, STMT_IMPL, n, type, op);
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
                    gen_vector_normalize(stream, STMT_IMPL, n, type, funcs_sqrt_defined_for[type]);
                    fputc('\n', stream);
                }
                gen_vector_dot(stream, STMT_IMPL, n, type_defs[type]);
                fputc('\n', stream);
                if (n == 3) {
                    gen_vector_cross(stream, STMT_IMPL, type_defs[type]);
                    fputc('\n', stream);
                    if (funcs_sqrt_defined_for[type]) {
                        gen_triangle_normal(stream, STMT_IMPL, type);
                        fputc('\n', stream);
                    }
                }
            }
        }
        for (size_t rows = MATRIX_MIN_DIM; rows <= MATRIX_MAX_DIM; ++rows) {
            for (size_t cols = MATRIX_MIN_DIM; cols <= MATRIX_MAX_DIM; ++cols) {
                for (Type type = 0; type < COUNT_TYPES; ++type) {
                    gen_matrix_ctor(stream, STMT_IMPL, rows, cols, type_defs[type]);
                    fputc('\n', stream);
                    gen_matrix_scalar_ctor(stream, STMT_IMPL, rows, cols, type_defs[type]);
                    fputc('\n', stream);
                    if (rows == cols) {
                        gen_matrix_identity(stream, STMT_IMPL, rows, type);
                        fputc('\n', stream);
                        gen_matrix_det(stream, STMT_IMPL, rows, type);
                        fputc('\n', stream);
                        gen_matrix_inverse(stream, STMT_IMPL, rows, type);
                        fputc('\n', stream);
                    }
                    for (size_t srows = MATRIX_MIN_DIM; srows <= MATRIX_MAX_DIM; ++srows) {
                        for (size_t scols = MATRIX_MIN_DIM; scols <= MATRIX_MAX_DIM; ++scols) {
                            for (Type stype = 0; stype < COUNT_TYPES; ++stype) {
                                if (srows != rows || scols != cols || stype != type) {
                                    gen_matrix_convert(stream, STMT_IMPL, rows, cols, type_defs[type], srows, scols, type_defs[stype]);
                                    fputc('\n', stream);
                                }
                            }
                        }
                    }
                    for (Op_Type op = 0; op < COUNT_OPS; ++op) {
                        gen_matrix_op(stream, STMT_IMPL, rows, cols, type, op);
                        fputc('\n', stream);
                    }
                    gen_matrix_transpose(stream, STMT_IMPL, rows, cols, type_defs[type]);
                    fputc('\n', stream);
                    for (size_t bc = MATRIX_MIN_DIM; bc <= MATRIX_MAX_DIM; ++bc) {
                        gen_matrix_mul(stream, STMT_IMPL, rows, cols, cols, bc, type_defs[type]);
                        fputc('\n', stream);
                    }
                    gen_mat_vec_mul(stream, STMT_IMPL, rows, cols, type_defs[type]);
                    fputc('\n', stream);
                }
            }
        }

        for (Type t = 0; t < COUNT_TYPES; ++t) {
            if (t == TYPE_FLOAT || t == TYPE_DOUBLE) {
                gen_rotor_funcs(stream, STMT_IMPL, 2, t);
                fputc('\n', stream);
                gen_rotor_funcs(stream, STMT_IMPL, 3, t);
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
