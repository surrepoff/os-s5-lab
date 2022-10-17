#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t start_pid, child_pid;
    fprintf(stdout,
            "START I am %i | My parent is %i | Group is %i | Session id is %i\n",
            start_pid = getpid(),
            (int)getppid(),
            (int)getpgid(start_pid),
            (int)getsid(start_pid));

    child_pid = fork();

    if (child_pid != 0) {
        wait(0);
        if (execvp("./cos", argv) == -1)
            perror("execvp cos call : ");
    } else {
        if (execvp("./sin", argv) == -1)
            perror("execvp sin call : ");
    }

    fprintf(stdout, "Everything is ignored!\n");

    return 0;
}
