
#include <stdio.h>

unsigned long checks = 0;

int is_prime(unsigned long n)
{
    unsigned long i;

    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    int k, p;

    printf("PRIME NUMBER TESTING\n");

    for (k = 0; k < 4; k++)
    {
        p = is_prime(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k],
               p ? "prime" : "not prime",
               checks);
    }

    return 0;
}
