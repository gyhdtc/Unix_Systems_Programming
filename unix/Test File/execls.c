#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "restart.h"

int main(int argc, int *argv[]){
    pid_t childpid;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command arg1 arg2...\n", argv[0]);
        return 1;
    }
    childpid = fork();
    if (childpid == -1) {
        perror("Failed to fork");
        return 1;
    }
    if (childpid == 0) {
        execvp(argv[1], &argv[1]);
        perror("Child failed to execvp the command");
        return 1;
    }
    if (childpid != r_wait(NULL)) {
        perror("Parent failed to wait duo to signal or error");
        return 1;
    }
    return 0;
}