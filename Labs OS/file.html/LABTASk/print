#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // This code runs in the child process
        printf("Hello from child process!\n");
    } else {
        // This code runs in the parent process
        printf("Hello from parent process!\n");
    }

    return 0;
}

