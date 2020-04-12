#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 30
char child_stack[STACK_SIZE+1]; 


int app1(){
    char * args[2] = {"./app1",NULL};
    execvp(args[0], args);
    return 0;
}

int app2(){
    char * args[2] = {"./app2",NULL};
    execvp(args[0], args);
    return 0;
}

int app3(){
    char * args[2] = {"./app3",NULL};
    execvp(args[0], args);
    return 0;
}


int main() {
    int clone1 = clone(app1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int clone2 = clone(app2, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int clone3 = clone(app3, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    
    printf("clone id = %d\n", clone1);
    printf("clone id = %d\n", clone2);
    printf("clone id = %d\n", clone3);
    printf("parent id %d\n", getpid());
    sleep(10);
    return 0;
}