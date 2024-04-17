#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *message = "Hello, this is a test message.";
    const char *filename = "bobx.txt";

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_written = write(fd, message, strlen(message));
    if (bytes_written == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    printf("Message successfully written to %s\n", filename);

    close(fd);
    return 0;
}
