/*Write a C program that takes two command-line arguments: -n followed by an integer N, and
-m followed by an integer M. use getopt() to iterate through the command-line options The
program should print the sum and product of N and M. For this use fork() to create to child
processes and call a function of addition in one child process and product function in another
child process. You need to save results to the file using the write system call. For instance:
Adjust the values of -n, -m, and -f as needed. If you run the program without providing all
required options, it will display a usage message.
./program -n 5 -m 4 -f example.txt
Brief description about creating child processes.
pid_t variable = fork();
variable of pid_t type = -1 represents error
variable of pid_t type = 0 represents normal state*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void add(int n, int m, int fd) {
    char buffer[50];
    int sum = n + m;
    sprintf(buffer, "Sum: %d\n", sum);
    write(fd, buffer, strlen(buffer));
}

void multiply(int n, int m, int fd) {
    char buffer[50];
    int product = n * m;
    sprintf(buffer, "Product: %d\n", product);
    write(fd, buffer, strlen(buffer));
}

int main(int argc, char *argv[]) {
    int n = 0, m = 0;
    char *filename = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "n:m:f:")) != -1) {
        switch (opt) {
            case 'n':
                n = atoi(optarg);
                break;
            case 'm':
                m = atoi(optarg);
                break;
            case 'f':
                filename = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s -n <number> -m <number> -f <filename>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!n || !m || !filename) {
        fprintf(stderr, "All options -n, -m, and -f are required\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process for addition
        add(n, m, fd);
        // close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // Wait for the first child to finish
        wait(NULL);
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process for multiplication
            multiply(n, m, fd);
            close(fd);
            exit(EXIT_SUCCESS);
        }
    }
    // Wait for the second child to finish
    wait(NULL);
    close(fd);
    return EXIT_SUCCESS;
}
