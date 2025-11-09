#include <stdio.h>

int main(void)
{
    int nr_of_days = 0;
    int starting_day = 0;

    printf("Enter number of days in month: ");
    scanf("%d", &nr_of_days);

    printf("Enter starting day of the week (1 = Sun, 7 = Sat): ");
    scanf("%d", &starting_day);

    for(int i = 1; i < starting_day; i++)
    {
        printf("   ");
    }

    for(int i = 1; i <= nr_of_days; i++)
    {
        printf("%2d ", i);

        starting_day++;
        if (starting_day > 7)
        {
            printf("\n");
            starting_day = 1;
        }
    }
    printf("\n");

    return 0;
}