#include <stdio.h>

int main(void)
{
    int a, inv_a = 0;

    printf("a = ");
    scanf("%d", &a);

    while (a)
    {

        inv_a = inv_a * 10 + a % 10;
        a /= 10;
    }

    printf("inv_a = %d\n", inv_a);

    return 0;
}