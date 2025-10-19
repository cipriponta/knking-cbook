#include <stdio.h>

#define WITH_TAX_ADDED(X) (1.05f * (X))

int main(void)
{
    float amount = 0.0f;

    printf("Enter an amount: ");
    scanf("%f", &amount);
    printf("With tax added: %.2f", WITH_TAX_ADDED(amount));

    return 0;
}