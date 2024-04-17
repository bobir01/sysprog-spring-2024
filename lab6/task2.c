#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



/*Write a C program that takes two command-line arguments: -n followed by an integer N, and
-m followed by an integer M take advantage of the getopt(). The program should print the sum
of the first N natural numbers (1 + 2 + 3 + ... + N), and the product of the first M natural
numbers (1 * 2 * 3 * ... * M). If -n or -m flags are not provided, the program should print a
usage message.*/



long long sum_natural_numbers(int N) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    return sum;
}

long long product_natural_numbers(int M) {
    long long product = 1;
    for (int i = 1; i <= M; i++) {
        product *= i;
    }
    return product;
}












int main(int argc, char *argv[]){
int arg;
int option;
int N, M;
while ((option = getopt(argc, argv, "n:m:")) != -1) {
        switch (option) {
            case 'n':
                N = atoi(optarg);
                printf("%s", optarg);
                break;
            case 'm':
                M = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -n N -m M\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }


     if (N == -1 || M == -1) {
        fprintf(stderr, "Both -n and -m options are required.\nUsage: %s -n N -m M\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    
    printf("Sum of the first %d natural numbers: %lld\n", N, sum_natural_numbers(N));
    printf("Product of the first %d natural numbers: %lld\n", M, product_natural_numbers(M));

    return 0;

exit(0);
}
