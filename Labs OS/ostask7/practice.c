#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num, num_children, i, status;
    pid_t child_pid;

    // Get input for the number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Determine the number of child processes
    if (num <= 3) {
        num_children = num;
    } else {
        num_children = 3;
    }

    // Create child processes
    for (i = 0; i < num_children; i++) {
        child_pid = fork();

        if (child_pid == 0) {
            // Child process
            int start = (i * num) / num_children + 1;
            int end = ((i + 1) * num) / num_children;

            int partial_factorial = 1;
            for (int j = start; j <= end; j++) {
                partial_factorial *= j;
            }

            // Write partial factorial to a file
            FILE *fp = fopen("partial_factorial.txt", "a");
            fprintf(fp, "%d\n", partial_factorial);
            fclose(fp);

            exit(0);
        }
    }

    // Parent process
    for (i = 0; i < num_children; i++) {
        wait(&status);

        // Read partial factorial from file
        FILE *fp = fopen("partial_factorial.txt", "r");
        int partial_factorial;
        fscanf(fp, "%d", &partial_factorial);
        fclose(fp);

        // Remove the line from the file
        FILE *fp_new = fopen("partial_factorial.tmp", "w");
        char line[100];
        while (fgets(line, sizeof(line), fp)) {
            if (atoi(line) != partial_factorial) {
                fprintf(fp_new, "%s", line);
            }
        }
        fclose(fp);
        fclose(fp_new);
        remove("partial_factorial.txt");
        rename("partial_factorial.tmp", "partial_factorial.txt");

        // Update the final factorial
        printf("Child %d: %d\n", i + 1, partial_factorial);
    }

    // Calculate the final factorial
    int final_factorial = 1;
    for (i = 0; i < num_children; i++) {
        FILE *fp = fopen("partial_factorial.txt", "r");
        int partial_factorial;
        fscanf(fp, "%d", &partial_factorial);
        fclose(fp);

        final_factorial *= partial_factorial;
    }

    printf("Final factorial: %d\n", final_factorial);

    return 0;
}

