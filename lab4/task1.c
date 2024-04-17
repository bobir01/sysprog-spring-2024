#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("bobx.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file"); // for printing the error to stderr
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully!\n");
    close(fd);
    return 0;
}
