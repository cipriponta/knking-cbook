#include <stdio.h>

#define COMPUTE_VOLUME(X) ((4.0f / 3.0f) * 3.14f * (X) * (X) * (X))

int main(void)
{
    float radius = 0.0f;

    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("Volume: %f\n", COMPUTE_VOLUME(radius));

    return 0;
}