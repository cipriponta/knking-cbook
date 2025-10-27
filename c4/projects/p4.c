#include <stdio.h>

int main(void)
{
    int a;

    printf("a = ");
    scanf("%d", &a);
    printf("a in base 8 = %#o\n", a);

    return 0;
}