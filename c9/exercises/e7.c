#include <stdio.h>

int f(int a, int b)
{
    return a + b;
}

int main(void)
{
    int i;
    double x;

    i = f(83, 12);
    printf("%d\n", i);

    x = f(83, 12);
    printf("%f\n", x);

    i = f(3.15, 9.28);
    printf("%d\n", i);

    x = f(3.15, 9.28);
    printf("%f\n", x);

    f(83, 12);

    return 0;
}