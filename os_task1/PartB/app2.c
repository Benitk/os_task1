#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 30
char child_stack[STACK_SIZE+1]; 

void print(const char *text){
    int i;
    for(i=0;i<CYCLES;i++){
        usleep(300000);
    }
}

int child1(){
    print("thread");
    return 0;
}


int main() {
    int clone1 = clone(child1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int clone2 = clone(child1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    printf("clone id = %d\n", clone1);
    printf("clone id = %d\n", clone2);
    child1();
    printf("parent id %d\n", getpid());
    return 0;
}