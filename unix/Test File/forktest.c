#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int mypid;
    int childpid;
    // mypid = getpid();
    childpid = fork();
    if (childpid == 0) {
        // some trouble is in here.
        mypid = (int)getpid();
        printf("I am c %d and mypid is %d and childpid %d\n", (int)getgid(), mypid, childpid);
    }
    else {
        mypid = (int)getpid();
        printf("I am p %d and mypid is %d and childpid %d\n", (int)getpid(), mypid, childpid);
    }
    return 0;
}