#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

/* Write a C- program in which child created by fork()
system call kills its parent, and verify that parent has been killed.
 */

void signal_clb(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    (void)signal(SIGINT, SIG_DFL);
}

int main(int argc, char const *argv[])
{
    pid_t pid;

    signal(SIGINT, signal_clb);

    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);

    case 0:
        sleep(3);
        printf("This child started\n");
        printf("Child PID: %d\n", getpid());
        kill(getppid(), 2);
        break;
    default:
        // wait(NULL);
        printf("Parent is running\n");
        printf("Parent PID: %d\n", getpid());

        sleep(5);

        break;
    }

    return 0;
}
