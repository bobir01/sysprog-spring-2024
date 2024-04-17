#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE

// extern char **environ;


int main(int argc, char const *argv[]){
	if (argc =! 2)
	{
		perror("provide all the needed argumenst");
	}
	char *var, *value;

	var = argv[1];
	value = getenv("");
	if(value)
		printf("Variable %s has value %s \n", var, value);

	

	

	exit(0);
 }