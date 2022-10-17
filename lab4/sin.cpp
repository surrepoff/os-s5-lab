#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    double angle = (double)(rand() % 628) / 100 - 3.14;
    fprintf(stdout,
            "SIN I am %i | My parent is %i | Group is %i | Session id is %i | sin(%lf) = %lf\n",
            (int)getpid(),
            (int)getppid(),
            (int)getpgid(getpid()),
            (int)getsid(getpid()),
            angle,
            sin(angle));

    return 0;
}
