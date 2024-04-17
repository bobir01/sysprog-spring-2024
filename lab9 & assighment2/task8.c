#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>




/* Write two programs P1.c and P2.c. When the program P1 executes it prints 
its process ID on screen, makes handlers for signals SIGINT (Crtl+C) 
and SIGTSTP (Ctrrl+Z), the signal handlers on receiving the signals 
print “SIGINT Received” or “SIGTSTP Received” based on signal type,
 P1 then goes to the infinite loop.
When the process P2 executes, it takes the process ID of P1 from user.
 After that If the user inputs C, P2 sends signal SIGINT to the process P1.
If the user inputs Z, P2 sends signal SIGTSTP to the process P1.
If the user inputs K, P2 first sends signal SIGKILL to the process P1 
and then sends the same signal to it self
Also write down the sample output to show how you will 
interact with both the programs.
 */


// it is p1



    const char *red = "\033[0;31m";
    const char *green = "\033[0;32m";
    // reset color
    const char *reset = "\033[0m";

void signal_clb(int sig)
{

    if (sig ==2){
        printf("Ooops I got Signal %sSIGINT%s", red, reset);

    }else{
        printf("Ooops I got Signal %sSIGSTP%s", green, reset);
    }
    printf("\n");
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
