#include <stdio.h>

#define EAN_SIZE (12)

int main(void)
{
    int ean[EAN_SIZE];
    int sum_even = 0;
    int sum_odd = 0;
    int check_digit;

    printf("Enter EAN: ");
    for (int i = 0; i < EAN_SIZE; i++)
    {
        scanf("%1d", &ean[i]);
    }
    
    printf("EAN: ");
    for (int i = 0; i < EAN_SIZE; i++)
    {
        printf("%d", ean[i]);
    }
    printf("\n");

    // Compute sums
    for (int i = 0; i < EAN_SIZE; i++)
    {
        if (i % 2 == 0)
        {
            sum_even += ean[i];
        }
        else
        {
            sum_odd += ean[i];
        }
    }

    check_digit = 9 - (sum_odd * 3 + sum_even - 1) % 10;
    printf("check_digit = %d\n", check_digit);

    return 0;
}