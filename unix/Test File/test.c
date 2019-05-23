#include <stdio.h>
int makeargv(const char *s,  const char *delimiters, char ***argvp);
int main(int argc, char *argv[]) {
    int a;
    a = argc;
    char **myshit;
    a = makeargv(argv, " ", &myshit);
    printf("gyh=%d\n", a);
    return 0;
}