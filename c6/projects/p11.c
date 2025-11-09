#include <stdio.h>

int main(void)
{
    double e = 1.0;
    int n;
    long long fact = 1;

    printf("n = ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        fact *= i;
        e += 1.0 / fact;
    }

    printf("%f\n", e);
}