#include <stdio.h>

int main(void)
{
    int months, days, years;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &months, &days, &years);
    printf("You entered the date %.4d%.2d%.2d\n", years, months, days);

    return 0;
}