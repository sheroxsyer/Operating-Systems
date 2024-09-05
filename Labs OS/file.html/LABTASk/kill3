#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int i, pid;
pid = fork();
if (pid > 0) // Parent
{
sleep(120);
}
else if (pid == 0) // Child
{
exit(0);
}
}
