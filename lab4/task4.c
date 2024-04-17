#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: ./file_copy <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    const char *i_file = argv[1];
    const char *o_file = argv[2];

    int input_fd = open(i_file, O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        exit(1);
    }

    int output_fd = open(o_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (output_fd == -1) {
        perror("Error opening output file");
        close(input_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to output file");
            close(input_fd);
            close(output_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading input file");
        close(input_fd);
        close(output_fd);
        exit(EXIT_FAILURE);
    }

    close(input_fd);
    close(output_fd);
    printf("File copied successfully!\n");
    return EXIT_SUCCESS;
}
