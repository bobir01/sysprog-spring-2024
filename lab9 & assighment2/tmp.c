#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>




int main(int argc, char const *argv[])
{

    const char *red = "\033[0;31m";
    const char *green = "\033[0;32m";
    // reset color
    const char *reset = "\033[0m";

    
    printf("%sChild id from exec: %d%s\n", red, getpid(), reset);
    //  get ppid
    printf("%sParent id from exec: %d\n%s", green,getppid(), reset);
    return 0;
}
