//#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

void fn1() { 
    printf("\nclone process 1: %d \n",  getpid());
}

void fn2() {
   printf("\nclone process 2: %d \n",  getpid());
}

int main(int argc, char *argv[]) {
    printf("main app: %d \n",  getpid());

    void *p1child_stack = malloc(1024 * 1024);
    void *p2child_stack = malloc(1024 * 1024);

    if(p1child_stack == NULL || p2child_stack == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    int pid1 = clone(fn1, p1child_stack + (1024 * 1024), SIGCHLD, 0);
    if(pid1 < 0) {
        printf("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
    }
    if(pid1 > 0) { //this is the parent process (app)
        int pid2 = clone(fn2, p2child_stack + (1024 * 1024), SIGCHLD, 0);
        if (pid2 < 0) {
            printf("ERROR: Unable to create the child process.\n");
            exit(EXIT_FAILURE);
        }
    }
    free(p1child_stack);
    free(p2child_stack);
    //sleep(5);

    return 0;
}