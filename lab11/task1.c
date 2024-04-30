#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* : Write a C program for inter-process communication using pipe; create a parent process
that generates two child processes. One child sends a message to the other child using a pipe.
The receiving child should display the message received. Ensure proper error handling. */
int main()
{
    pid_t pid1, pid2;
    int file_pipes[2];
    char buffer[BUFSIZ + 1];
    const char data[] = "Hello, World!";
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
                printf("Received string: %s\n", buffer);
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