#include <stdio.h>

int main(void)
{
    int gsi_prefix, group_id, pub_code, item_nr, check_digit;
    
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_id, &pub_code, &item_nr, &check_digit);

    printf("GSI prefix: %d\n", gsi_prefix);
    printf("Group identifier: %d\n", group_id);
    printf("Publisher code: %d\n", pub_code);
    printf("Item number: %d\n", item_nr);
    printf("Check digit: %d\n", check_digit);

    return 0;
}