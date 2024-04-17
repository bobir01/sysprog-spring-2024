#include <time.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[])
{
	time_t timeval;
	(void)time(&timeval);

	printf("%s\n", ctime(&timeval));

    char *my_local_dt = "hi.txt";
    
    // struct *timeptr, timeval;


	// size_t strftime(my_local_dt, time_t, "%x", struct tm *timeptr);
	
    char buffer[L_tmpnam];
   	char *ptr;

	printf("%s\n", tmpnam(buffer));
}