#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>







/* Write a C program where the parent process creates a pipe and two child processes.
One child writes a message to the pipe, and the other child reads the message and converts it
to uppercase before displaying it. Ensure that both children and the parent process properly
close file descriptors to avoid resource leaks */

char *to_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}



int main(int argc, char const *argv[])
{
    pid_t pid1, pid2;
    int file_pipes[2];
    char buffer[BUFSIZ + 1];
    const char data[] = "This is my message.";
    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0)
    {
        pid1 = fork();
        if (pid1 == -1)
        {
            perror("fork failed");
            exit(1);
        }
        if (pid1 == 0)
        {
            close(file_pipes[0]);
            write(file_pipes[1], data, strlen(data));
            printf("Sent string: %s\n", data);
            close(file_pipes[1]);
            exit(0);
        }
        else
        {
            pid2 = fork();
            if (pid2 == -1)
            {
                perror("fork failed");
                exit(1);
            }
            if (pid2 == 0)
            {
                close(file_pipes[1]);
                read(file_pipes[0], buffer, BUFSIZ);
                printf("Received string: %s\n", to_upper(buffer));
                close(file_pipes[0]);
                exit(0);
            }
        }
    }
    else
    {
        perror("pipe failed");
        exit(1);
    }
    
}