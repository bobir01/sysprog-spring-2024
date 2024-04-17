#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

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

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("%s PLEASE follow usage:/ %s PID SIGNAL C|Z %s\n", red, argv[0], reset);
        exit(1);
    }

    int pid = atoi(argv[1]);
    printf("got pid=%d\n", pid);
    if (strcmp(argv[2], "C") == 0)
    {
        kill(pid, SIGINT);
    }
    else if (
        strcmp(argv[2], "Z") == 0)
    {
        kill(pid, SIGTSTP);
        
    }
    else
    {
        printf("%sThe unknown Signal: %s %s\nSo killing it", red, argv[2], reset);
        kill(pid, SIGKILL);
        kill(getpid(), SIGKILL);
    }

    return 0;
}
