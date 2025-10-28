#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int hours, minutes;
    bool check_am;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    if (hours < 12)
    {
        check_am = true;
    }
    else
    {
        check_am = false;
    }

    if (hours > 12)
    {
        hours -= 12;
    }
    else if (hours == 0)
    {
        hours = 12;
    }

    printf("Equivalent 12-hour time: %2d:%2d %s\n", hours, minutes, ((check_am) ? ("AM") : ("PM")));

    return 0;
}