#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    char name[100];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    printf("Listing files in the current directory:\n");
    system("ls");

    // Creating a directory named 'test'
    system("mkdir test");
    printf("\nContents of the 'test' directory:\n");
    system("ls test");

    // Removing the 'test' directory
    system("rmdir test");

    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    int p;
    printf("Original Process, PID = %d\n", getpid());
    p = fork();

    if (p == -1) {
        perror("Fork failed");
        return 1;
    }

    if (p == 0) {
        // This code runs in the child process.
        printf("Child PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        // This code runs in the parent process.
        printf("Parent PID = %d, Child PID = %d\n", getpid(), p);
    }

    return 0;
}

