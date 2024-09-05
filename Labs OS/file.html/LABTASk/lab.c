#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];
printf("Please enter your name: ");
scanf("%s", name);
printf("Hello, %s!\n", name);
printf("Listing files in the current directory:\n");
    system("ls");
// Use the system() function to create a directory named 'test'
    system("mkdir test");

    // Use the system() function to display the contents of the 'test' directory
    printf("\nContents of the 'test' directory:\n");
    system("ls test");

    // Use the system() function to remove the 'test' directory
    system("rmdir test");

    return 0;
}