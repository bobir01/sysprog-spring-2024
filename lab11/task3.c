#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Write a C program that implements a simple producer-consumer scenario using pipes
for interprocess communication. The producer process generates random numbers and sends
them through a pipe to the consumer process. The consumer process calculates the sum of
received numbers. Use loop to write 5 random numbers using pipe in producer program and
read it using while pipe is not empty in consumer program. */


int main(int argc, char const *argv[])
{
    pid_t pid1, pid2;
    int file_pipes[2];
    int buffer[BUFSIZ + 1];
    int sum = 0;
    memset(buffer, '\0', sizeof(buffer));

    if (pipe(file_pipes) == 0)
    {
        pid1 = fork();
        if (pid1 == -1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (pid1 == 0)
        {
            close(file_pipes[0]);
            for (int i = 0; i < 5; i++)
            {
                buffer[i] = rand() % 100;
                write(file_pipes[1], &buffer[i], sizeof(buffer[i]));
                printf("Sent number: %d\n", buffer[i]);
            }
            close(file_pipes[1]);
            exit(0);
        }
        else
        {
            pid2 = fork();
            if (pid2 == -1)
            {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }
            if (pid2 == 0)
            {
                close(file_pipes[1]);
                while (read(file_pipes[0], buffer, BUFSIZ) > 0)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        sum += buffer[i];
                    }
                }
                printf("Sum of numbers: %d\n", sum);
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
    return 0;
}
