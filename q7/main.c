#include <stdio.h>

unsigned long checks = 0;

/* Original prime checking method */
int original_prime(unsigned long n)
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

/* Redesigned prime checking method */
int redesigned_prime(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    checks++;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i <= n / i; i += 2)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};
    unsigned long original_count, redesigned_count;
    int i;

    printf("Q7 - ORIGINAL VS REDESIGNED PRIME TEST\n");

    for (i = 0; i < 4; i++)
    {
        original_prime(numbers[i]);
        original_count = checks;

        redesigned_prime(numbers[i]);
        redesigned_count = checks;

        printf("\nNumber: %lu\n", numbers[i]);
        printf("Original divisions: %lu\n", original_count);
        printf("Redesigned divisions: %lu\n", redesigned_count);
    }

    return 0;
}
