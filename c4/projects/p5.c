#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Enter the UPC: ");
    scanf("%1d%5d%5d", &a, &b, &c);
    printf("%d%d%d\n", a, b, c);
    return 0;
}