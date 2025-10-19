#include <stdio.h>

#define NUMBER_OF_MONTHS (3)
#define MONTHS_IN_YEAR (12.0f)

#define TO_PERCENT(X) ((X) / 100.00f)

int main(void)
{
    float loan_amount = 0.0f;
    float interest_rate = 0.0f;
    float monthly_payment = 0.0f;
    float balance = 0.0f;
    float monthly_interest_rate = 0.0f;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_amount);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    balance = loan_amount;
    monthly_interest_rate = TO_PERCENT(interest_rate) / MONTHS_IN_YEAR;

    for(int i = 0; i < NUMBER_OF_MONTHS; i++)
    {
        balance = balance - monthly_payment + balance * monthly_interest_rate;
        printf("Balance remaining after payment #%d: %.2f\n", i + 1, balance);
    }

    return 0;
}