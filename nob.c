#define NOBUILD_IMPLEMENTATION
#include "./nob.h"

#define CFLAGS "-Wall", "-Wextra", "-pedantic", "-std=c11"
#define LIBS "-lraylib", "-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lX11"
#define TARGET "build/snake"

void build_src(const char *src)
{
    Cstr src_path = PATH("src", src);
    CMD("cc", CFLAGS, "-o", TARGET, src_path, LIBS);
}

int main(int argc, char **argv)
{
    GO_REBUILD_URSELF(argc, argv);

    build_src("main.c");

    return 0;
}