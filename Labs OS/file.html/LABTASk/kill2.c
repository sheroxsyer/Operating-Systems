#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h> // Include the wait library

int main() {
    int i, pid;
    pid = fork();
    
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent
        // Wait for the child to finish
        wait(NULL);
        printf("Parent process exiting\n");
        exit(0);
    } else if (pid == 0) { // Child
        for (i = 0; i < 5; i++) {
            printf("My parent is %d\n", getppid());
            sleep(1);
        }
        printf("Child process exiting\n");
    }

    return 0;
}

