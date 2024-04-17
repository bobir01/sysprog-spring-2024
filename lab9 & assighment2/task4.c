#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/* A process creates it’s child through the fork() system call. 
The child created by fork() creates another process through execl system call. 
Prove that the Process ID of process created by fork() and through execl is same. */



void call_exec()
{
    char *args[] = {"/home/bobdev/Desktop/sys_prog/lab9 & assighment2/tmp", NULL}; // this is my custom compiles c file
    execl(args[0], args[0],  NULL);
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
        exit(0);
    default:
        wait(NULL);
        printf("Parent is running\n");
        printf("Parent PID: %d\n", getpid());
        // exit(0);
        break;
    }



    return 0;
}
