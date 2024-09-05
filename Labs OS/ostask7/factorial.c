#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


unsigned long long calculateFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calculateFactorial(n - 1);
    }
}

int main() {
    int n;

    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    
    unsigned long long finalResult = 1;

    // Create child processes
    for (int i = 1; i <= n; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            unsigned long long result = calculateFactorial(i);
            printf("Child %d: Factorial of %d = %llu\n", i, i, result);

            // Use path and filename provided
            char filePath[100];
            snprintf(filePath, sizeof(filePath), "/home/ubuntu/output7/output%d.txt", i);

            
            FILE *file = fopen(filePath, "w");
            fprintf(file, "%llu", result);
            fclose(file);

            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    for (int i = 1; i <= n; ++i) {
        wait(NULL);

        
        char filePath[100];
        snprintf(filePath, sizeof(filePath), "/home/ubuntu/output7/output%d.txt", i);

        FILE *file = fopen(filePath, "r");
        unsigned long long childResult;
        fscanf(file, "%llu", &childResult);
        fclose(file);

        
        finalResult *= childResult;
    }

    
    printf("Parent: Final Result = %llu\n", finalResult);

    return 0;
}

