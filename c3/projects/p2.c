#include <stdio.h>

int main(void)
{
    int id, months, days, years;
    float price;

    printf("Enter item number: ");
    scanf("%d", &id);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &months, &days, &years);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%.2d/%.2d/%.4d\n", id, price, months, days, years);

    return 0;
}