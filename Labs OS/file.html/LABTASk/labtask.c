#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/types.h>

int main() {
    char name[100];
	 printf("Please enter your name: ");
	 scanf("%s", name);
	 printf("Hello, %s!\n", name);
	printf("Listing files in the current directory:\n");
    system("ls");
	system("mkdir test");
	printf("\nContents of the 'test' directory:\n");
    system("ls test");
	 system("rmdir test");
	 printf("process id %d /n",getpid());
	 printf("parent process id %d/n",getppid());

    return 0;
}
