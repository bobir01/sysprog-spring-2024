#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// Write a Program to prove 
//that Process ID of parent and it’s child 
//created through exec system calls is same.

void call_exec()
{
    // call exec system call
    //  /home/bobdev/Desktop/sys_prog/lab9/
    char *args[] = {"/home/bobdev/Desktop/sys_prog/lab9/tmp", NULL};
    execv(args[0], args);
}

int main(int argc, char const *argv[])
{
    pid_t pid;


    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        printf("This child started\n");
        printf("Child PID: %d\n", getpid());
        call_exec();
        break;
    default:
        wait(NULL);
        printf("Parent is running\n");
        printf("Parent PID: %d\n", getpid());
        break;
    }
    
    
    return 0;
}
