#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
void print_a_z()
{
    char c;
    for (c = 'a'; c <= 'z'; c++)
    {
        printf("Child is runnig: %c\n", c);
        sleep(1);
    }
}

void print_0_9()
{
    int c = 0;
    for (; c <= 9; c++)
    {
        printf("Parent is running: %d\n", c);
        sleep(1);
    }
}

int main()
{
    pid_t pid;
    char *message;
    int n;
    printf("fork program starting\n");
    pid = fork();

    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        printf("This child started\n");
        print_a_z();
        break;
    default:
        wait(NULL);
        message = "This is the parent";
        print_0_9();
        break;
    }

    exit(0);
}
