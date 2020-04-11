#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>


void (*hello)(const char *);

bool init_library(){
    void *hdl = dlopen("./libhello.so", RTLD_LAZY);
    if (hdl == NULL)
        return false;
    hello = (void (*)(const char *))dlsym(hdl, "hello");
    if (hello == NULL)
        return false;
    return true;
}

int main(){
    if (init_library())
        hello("Ariel");
    else
        printf("Library was not loaded \n");
    return 0;
}