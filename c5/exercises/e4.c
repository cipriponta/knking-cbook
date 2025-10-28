#include <stdio.h>

int main(void)
{
    int i, j;

    printf("i = ");
    scanf("%d", &i);

    printf("j = ");
    scanf("%d", &j);

    printf("%d\n", (i > j) - (i < j));

    return 0;
}