#define NOBUILD_IMPLEMENTATION
#include "./nob.h"

#define CFLAGS "-Wall", "-Wextra", "-pedantic", "-std=c11"
#ifdef __WIN32
    #define LIBS "-lraylib", "-lopengl32", "-lgdi32", "-lwinmm"
    #define BUILD "build"
#else
    #define LIBS "-lraylib", "-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lX11"
    #define BUILD "build", 0755
#endif // _WIN32
#define TARGET "build/snake"

void build_src(const char *src)
{
    Cstr src_path = PATH("src", src);
    if (!path_exists("build")) {
        mkdir(BUILD);
    }
    CMD("cc", CFLAGS, "-o", TARGET, src_path, LIBS);
}

int main(int argc, char **argv)
{
    GO_REBUILD_URSELF(argc, argv);

    build_src("main.c");

    return 0;
}