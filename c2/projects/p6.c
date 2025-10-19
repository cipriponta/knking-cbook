#include <stdio.h>

#define HORNER_RULE(X) (((((3 * (X) + 2) * (X) - 5) * (X) - 1) * (X) + 7) * (X) - 6)

int main(void)
{
    int x = 0;

    printf("x = ");
    scanf("%d", &x);
    printf("Result: %d", HORNER_RULE(x));

    return 0;
}