#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <divisor> <dividend>\n", argv[0]);
        return 1;
    }

    int divisor = atoi(argv[1]);
    int dividend = atoi(argv[2]);

    printf("Checker process [%d]: Starting.\n", getpid());
    if (dividend % divisor == 0)
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), dividend, divisor);
        printf("Checker process [%d]: Returning 1.\n", getpid());
        return 1;
    }
    else
    {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", getpid(), dividend, divisor);
        printf("Checker process [%d]: Returning 0.\n", getpid());
        return 0;
    }
}