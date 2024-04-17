#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// Q2. Using execv system call list all the files of bin, and home directory

void print_bin(){
    char *args[] = {"/bin/ls", "/bin", "/home", NULL};
    execv(args[0], args);
}


int main(int argc, char const *argv[])
{

    print_bin();

    return 0;
}
