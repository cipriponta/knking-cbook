#include <stdio.h>

int main(void)
{
    printf("int: %ld\n", sizeof(int));
    printf("short: %ld\n", sizeof(short));
    printf("long: %ld\n", sizeof(long));
    printf("long long: %ld\n", sizeof(long long));

    printf("float: %ld\n", sizeof(float));
    printf("double: %ld\n", sizeof(double));
    printf("long double: %ld\n", sizeof(long double));
}