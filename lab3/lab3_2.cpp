#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fprintf(stdout,
            "START I am %i | My parent is %i\n",
            (int)getpid(),
            (int)getppid());

    int i = 0;

    while (i++ < 3) {
        fork();
        fprintf(stdout,
                "i = %d I am %i | My parent is %i\n",
                i,
                (int)getpid(),
                (int)getppid());
    }
    fprintf(stdout,"\n");

    sleep(600);

    return 0;
}
