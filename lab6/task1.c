#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Write a C program to check if the number of arguments passed is exactly 11 (including the
program name). If not, it prints out a usage message. Otherwise, it processes each argument. If
an argument starts with a hyphen ('-'), it’s printed as option: xyz, it's then considered an option
and processed accordingly by the process_option function. Otherwise, it's considered a regular
argument and printed out. The process_option function handles specific options such as "help",
"version", and "info". For each process_option take the appropriate actions.*/







void process_option(char* option){

	if (strcmp(option, "-help") == 0) {
        printf("Help option selected. Usage: [options] [arguments]\n");
    } else if (strcmp(option, "-version") == 0) {
        printf("Version 1.0\n");
    } else if (strcmp(option, "-info") == 0) {
        printf("This program processes arguments and options.\n");
    } else {
        printf("Unknown option: %s\n", option);
    }

}

int main(int argc, char *argv[]){
int arg;
// if (argc != 11){
// 	printf("%s takes exactly 11 arguments, passed %d\n", argv[0], argc-1);
// 	exit(1);
// }

int opt;
while((opt = getopt(argc, argv, ":if:help:info:version")) != -1) {
	switch(opt) {
		case 'i':
			process_option("-info");
			break;
		case 'h':
			process_option("-help");
			break;
		case 'v':
			process_option("-version");
		break;
	default: printf("-%d option\n", opt);

	}
}

exit(0);
}
