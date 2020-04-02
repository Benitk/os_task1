#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t app = getpid();
    int n = fork();

    if(n < 0) //fork failed
        exit(EXIT_FAILURE);

    if(n == 0) { //his is the child process
        pid_t process1 = getpid();
        int m = fork();

        if(m < 0) //fork failed
            exit(EXIT_FAILURE);

        if(m == 0) {
            pid_t process2 = getpid();
            printf("Process 2 %d --> ", process2);
        }
        else   
            printf("Process 1 %d --> ", process1);
    }
    else
        printf("App %d --> ", app);

    //sleep(5); 
    return 0;
}