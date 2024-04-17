#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

/* 
Write down a program for Stop Watch using signals.
 In this program the child process takes the time interval (in seconds) 
 from user, Now the child process counts down, after the time is finished 
 the child process sends SIGALARM to the parent process. 
 On receiving SIGALARM the parent calls the function Times_Up() for Finish Time.
Note: if the user decides to stop the Stop Watch. 
He presses Ctrl+Z, the count down timer stops. Here is the sample output.

 */



void signal_clb(int sig)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("\a");
    }
    
    
    printf("Time is up finish, it is from ALARM!\n");
    (void)signal(SIGALRM, SIG_DFL);
}


void timer(int secs){
    while (secs)
    {
        sleep(1);
        secs--;
        printf("time is: %d\n", secs);
    }
    
}



int main(int argc, char const *argv[])
{
        pid_t pid;

    signal(SIGALRM, signal_clb);

    int timer_secs = 10;


    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        exit(1);

    case 0:
        sleep(3);
        printf("This child started\n");
        timer(timer_secs);

        kill(getppid(), SIGALRM);
        break;
    default:
        wait(NULL);
        printf("Parent is running\n");


        break;
    }
    
    return 0;
}
