#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

/* Wright a C program which could handle both Ctrl+z,
and Ctrl+c signals, and
prints the caught signal number. */

static int signal_cnt = 0;

void signal_clb(int sig)
{
    printf("OUCH! - I got signal %d If you want to terminate press CTL+C one more time\n", sig);

    if(signal_cnt > 1){
        printf("existing with SIGINT\n");
        signal(SIGINT, SIG_DFL);
    }
    signal_cnt++;
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, signal_clb);
    signal(SIGTSTP, signal_clb);

    while (1)
    {
        sleep(1);
    }
    
    

    return 0;
}
