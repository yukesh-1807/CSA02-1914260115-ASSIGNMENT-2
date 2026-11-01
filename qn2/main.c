
#include <stdio.h>

int calls = 0;

int verify_card(int disability)
{
    calls++;
    return disability;
}

int main(void)
{
    int senior, eligible, disability;
    int i, concession1 = 0, concession2 = 0;
    int first_calls, second_calls;

    /* Test short-circuit behaviour */
    calls = 0;
    printf("0 && verify = %d\n", 0 && verify_card(1));
    printf("Calls after &&: %d\n", calls);

    calls = 0;
    printf("1 || verify = %d\n", 1 || verify_card(1));
    printf("Calls after ||: %d\n", calls);

    /* 1000 sample passengers */
    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        senior = (i % 2 == 0);
        eligible = (i % 3 == 0);
        disability = (i % 10 == 0);

        if ((senior && eligible) ||
            verify_card(disability))
            concession1++;
    }

    first_calls = calls;

    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        senior = (i % 2 == 0);
        eligible = (i % 3 == 0);
        disability = (i % 10 == 0);

        if (verify_card(disability) ||
            (senior && eligible))
            concession2++;
    }

    second_calls = calls;

    printf("\nPassenger count: 1000\n");
    printf("First condition order calls: %d\n", first_calls);
    printf("Second condition order calls: %d\n", second_calls);
    printf("Concessions in first order: %d\n", concession1);
    printf("Concessions in second order: %d\n", concession2);

    return 0;
}
