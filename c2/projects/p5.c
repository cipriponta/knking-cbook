#include <stdio.h>

#define POLYNOM(X) (  3 * (X) * (X) * (X) * (X) * (X) \
                    + 2 * (X) * (X) * (X) * (X) \
                    - 5 * (X) * (X) * (X) \
                    - 1 * (X) * (X) \
                    + 7 * (X) \
                    - 6)

int main(void)
{
    int x = 0;

    printf("x = ");
    scanf("%d", &x);
    printf("Result: %d", POLYNOM(x));

    return 0;
}