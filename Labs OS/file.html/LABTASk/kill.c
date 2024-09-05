#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Hello\n"); // Add a newline character
    kill(getpid(), SIGTERM); // Send a termination signal (SIGTERM)
    printf("Goodbye\n"); // This might not get printed due to the termination signal
    return 0;
}

