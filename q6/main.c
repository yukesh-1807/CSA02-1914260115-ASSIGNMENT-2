
#include <stdio.h>

int main(void)
{
    double balance, rate, repayment;
    double interest, total_interest = 0.0;
    double payment;
    int month = 0;
    int limit = 360;

    printf("LOAN REPAYMENT SCHEDULE\n");

    printf("Enter loan amount: ");
    scanf("%lf", &balance);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter monthly repayment: ");
    scanf("%lf", &repayment);

    if (balance <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid loan details.\n");
        return 0;
    }

    if (repayment <= balance * rate / 100.0)
    {
        printf("Repayment is too small to clear the loan.\n");
        return 0;
    }

    printf("\nMonth\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.005)
    {
        if (month >= limit)
        {
            printf("Safety limit reached. Loan not fully repaid.\n");
            break;
        }

        month++;

        interest = balance * rate / 100.0;
        total_interest += interest;
        balance += interest;

        payment = (balance < repayment) ? balance : repayment;
        balance -= payment;

        if (balance < 0.005)
            balance = 0.0;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
               month, interest, payment, balance);
    }

    if (balance == 0.0)
    {
        printf("\nLoan fully repaid.\n");
        printf("Total months: %d\n", month);
        printf("Total interest: Rs. %.2f\n", total_interest);
    }

    return 0;
}
