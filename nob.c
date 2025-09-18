#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "thirdparty/nob.h"

#define BUILD_FOLDER      "build/"
#define SRC_FOLDER        "src/"
#define EXAMPLES_FOLDER   "examples/"
#define THIRDPARTY_FOLDER "thirdparty/"

static Cmd cmd = {0};
static Procs procs = {0};

static void compile(void)
{
    cmd_append(&cmd, "cc");
    cmd_append(&cmd, "-O3");
    cmd_append(&cmd, "-march=native");
    cmd_append(&cmd, "-ffast-math");
    cmd_append(&cmd, "-ffp-contract=fast");
    cmd_append(&cmd, "-fno-math-errno");
    cmd_append(&cmd, "-Wall");
    cmd_append(&cmd, "-Wextra");
    cmd_append(&cmd, "-Wswitch-enum");
    cmd_append(&cmd, "-I.");
    cmd_append(&cmd, "-I"THIRDPARTY_FOLDER);
}

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!mkdir_if_not_exists(BUILD_FOLDER)) return 1;

    compile();
    cmd_append(&cmd, "-ggdb");
    cmd_append(&cmd, "-o", BUILD_FOLDER"lag");
    cmd_append(&cmd, SRC_FOLDER"lag.c");
    if (!cmd_run(&cmd)) return 1;

    cmd_append(&cmd, BUILD_FOLDER"lag");
    if (!cmd_run(&cmd, .stdout_path = "./la.h")) return 1;

    {
        compile();
        cmd_append(&cmd, "-pedantic");
        cmd_append(&cmd, "-std=c11");
        cmd_append(&cmd, "-ggdb");
        cmd_append(&cmd, "-o", BUILD_FOLDER"raytrace");
        cmd_append(&cmd, EXAMPLES_FOLDER"raytrace.c");
        cmd_append(&cmd, "-lm");
        if (!cmd_run(&cmd, .async = &procs)) return 1;

        compile();
        cmd_append(&cmd, "-pedantic");
        cmd_append(&cmd, "-std=c11");
        cmd_append(&cmd, "-ggdb");
        cmd_append(&cmd, "-o", BUILD_FOLDER"rigidbox");
        cmd_append(&cmd, EXAMPLES_FOLDER"rigidbox.c");
        cmd_append(&cmd, "-lm");
        if (!cmd_run(&cmd, .async = &procs)) return 1;

        compile();
        cmd_append(&cmd, "-pedantic");
        cmd_append(&cmd, "-std=c11");
        cmd_append(&cmd, "-ggdb");
        cmd_append(&cmd, "-o", BUILD_FOLDER"ball");
        cmd_append(&cmd, EXAMPLES_FOLDER"ball.c");
        cmd_append(&cmd, "-lm");
        if (!cmd_run(&cmd, .async = &procs)) return 1;

        compile();
        cmd_append(&cmd, "-DLA_IMPLEMENTATION");
        cmd_append(&cmd, "-x", "c++");
        cmd_append(&cmd, "-o", BUILD_FOLDER"la.cxx.o");
        cmd_append(&cmd, "-c");
        cmd_append(&cmd, "la.h");
        if (!cmd_run(&cmd, .async = &procs)) return 1;

        compile();
        cmd_append(&cmd, "-pedantic");
        cmd_append(&cmd, "-std=c11");
        cmd_append(&cmd, "-DLA_IMPLEMENTATION");
        cmd_append(&cmd, "-x", "c");
        cmd_append(&cmd, "-o", BUILD_FOLDER"la.c.o");
        cmd_append(&cmd, "-c");
        cmd_append(&cmd, "la.h");
        if (!cmd_run(&cmd, .async = &procs)) return 1;

        if (!procs_flush(&procs)) return 1;
    }

    return 0;
}
