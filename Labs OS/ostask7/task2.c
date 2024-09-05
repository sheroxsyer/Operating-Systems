#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    // Step 1
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Step 2
        char outputPath[100];
        snprintf(outputPath, sizeof(outputPath), "/home/ubuntu/output7/%s-cat-output.txt", filename);

        
        char command[150];
        snprintf(command, sizeof(command), "cat %s >> %s", filename, outputPath);
        system(command);

        
        exit(EXIT_SUCCESS);
    } else {
        // Step 3
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            // Step 4
            execlp("more", "more", filename, NULL);

            
            perror("exec");
            exit(EXIT_FAILURE);
        } else {
            fprintf(stderr, "Child process failed to run 'cat' successfully.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Step 5
    exit(EXIT_SUCCESS);
}

