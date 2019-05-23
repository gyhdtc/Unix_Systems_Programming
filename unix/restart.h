#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

pid_t r_wait(int *stat_loc) {
    int retval;
    while (((retval = wait(stat_loc)) == -1) && (errno == EINTR));
    return retval;
}

int r_close(int r_fildes)
{
    int error;
    while ((error = close(r_fildes) == -1) && (errno == EINTR));
    return error;   
}