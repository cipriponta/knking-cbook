#include <stdio.h>

int main()
{
    float x = 123.4567;
    printf("%-8.1e\n", x);
    printf("%10.6e\n", x);
    printf("%-8.3f\n", x);
    printf("%6.0f\n", x);

    return 0;
}