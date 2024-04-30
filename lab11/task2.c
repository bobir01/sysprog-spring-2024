#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/* Write a C program that utilizes popen, fread, and fwrite functions to perform the
following tasks: (1)Use popen with the find command to find all files in the current directory
ending with the .txt extension and (2) next time change the string to find lines and character in
any .txt file.
First time use:
(1)char command[] = "find . -type f -name \"*.txt\""; // Command to find .txt files
Second time use:
(2)char command[] ="cat abc.txt | wc -l && cat abc.txt | wc -c"; //command to count lines
in txt and characters
Finally Store the output of find command in a buffer. Use popen with the od -c command to
display the output stored in the buffer in octal form. */



int main(int argc, char const *argv[])
{
    FILE *file;
    char buffer[BUFSIZ + 1];
    const char command[] = "find . -type f -name \"*.c\"";
    memset(buffer, '\0', sizeof(buffer));
    file = popen(command, "r");
    if (file != NULL)
    {
        fread(buffer, sizeof(char), BUFSIZ, file);
        printf("Output of find command: %s\n", buffer);
        pclose(file);
    }
    else
    {
        perror("popen failed");
        exit(1);
    }


    return 0;
}
