#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid, parent_pid;
    fprintf(stdout, "Parent %i\n", parent_pid = (int)getpid());
    child_pid = fork();

    if (child_pid != 0)
        fprintf(stdout, "Child %i\n", child_pid);
    else
        fprintf(stdout, "Child NONE\n");

    if (child_pid != 0) {
        kill(child_pid, SIGKILL);
    }

    fprintf(stdout, "Hello i am %i\n", (int)getpid());

    return 0;
}
