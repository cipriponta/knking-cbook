#include <stdio.h>

int main(void)
{
    int amount = 0;
    int bills[] = {20, 10, 5, 1};
    int remaining_amount = 0;

    printf("Enter amount: ");
    scanf("%d", &amount);

    remaining_amount = amount;

    for(int i = 0; i < sizeof(bills) / sizeof(bills[0]); i++)
    {
        printf("$%02d bills: %d\n", bills[i], remaining_amount / bills[i]);
        remaining_amount %= bills[i];
    }

    return 0;
}