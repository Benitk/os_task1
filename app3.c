#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t app = getpid();
    int n = fork();

    if(n < 0) //fork failed
        exit(EXIT_FAILURE);

    if(n == 0) { //it's the child process
        
        pid_t child = getpid();
        umask(0);
        pid_t sid = setsid();
    
        /* Change the current working directory */
        if((chdir("/")) < 0) 
                exit(EXIT_FAILURE);
        
        /* Close it's input-output channels */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
    }
    //sleep(5);
    return 0;
}