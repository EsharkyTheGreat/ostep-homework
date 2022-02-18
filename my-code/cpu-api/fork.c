#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    int wstatus = 0;
    if (pid == 0)
    {
        printf("[child] About to call wait\n");
        pid_t res = wait(&wstatus);
        printf("[child] Resulting PID we got is %d\n", res);
        printf("[child] The status we got is %d\n", wstatus);
    }
    else
    {
        printf("[parent] Printing message in parent\n");
    }
}