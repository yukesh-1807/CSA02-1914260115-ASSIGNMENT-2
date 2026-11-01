
#include <stdio.h>

int main()
{
    int price, qty, senior;
    int count = 0;
    int i;

    double gross, discount, tax, total, net;

    printf("JAN AUSHADHI PHARMACY BILLING\n");
    printf("-----------------------------\n");

    for (i = 1; i <= 3; i++)
    {
        printf("\nEnter details for Bill %d\n", i);

        printf("Enter price: ");
        scanf("%d", &price);

        printf("Enter quantity: ");
        scanf("%d", &qty);

        printf("Senior citizen? (1 = Yes, 0 = No): ");
        scanf("%d", &senior);

        /* Original buggy calculation */
        int buggy_total =
            price * qty - price * qty * 15 / 100 * senior
            + price * qty * 5 / 100;

        int buggy_net;

        buggy_net = (buggy_total > 1000)
                    ? buggy_total - 50
                    : buggy_total;

        /* Correct calculation */
        gross = (double)price * qty;

        if (senior == 1)
            discount = gross * 0.15;
        else
            discount = 0.0;

        tax = (gross - discount) * 0.05;

        total = gross - discount + tax;

        net = (total > 1000.0)
              ? total - 50.0
              : total;

        count++;

        printf("\n--- BILL %d RESULT ---\n", i);

        printf("Original Total : Rs. %d\n", buggy_total);
        printf("Original Net   : Rs. %d\n", buggy_net);

        printf("Gross Amount   : Rs. %.2f\n", gross);
        printf("Discount       : Rs. %.2f\n", discount);
        printf("GST            : Rs. %.2f\n", tax);
        printf("Correct Total  : Rs. %.2f\n", total);
        printf("Correct Net    : Rs. %.2f\n", net);
    }

    printf("\nTotal Bills Processed: %d\n", count);

    return 0;
}
