#include <stdio.h>

#define MATRIX_SIZE (4)

int main(void)
{
    int arr[MATRIX_SIZE][MATRIX_SIZE] = {0};

    // Read the array
    printf("Enter the numbers from 1 to 16 in any order: ");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the array
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    // Compute row sums
    printf("Row sums: ");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            row_sum += arr[i][j];
        }
        printf("%d ", row_sum);
    }
    printf("\n");

    // Compute column sums
    printf("Column sums: ");
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            col_sum += arr[i][j];
        }
        printf("%d ", col_sum);
    }
    printf("\n");

    // Compute left diagonal
    int first_diagonal = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i == j)
            {
                first_diagonal += arr[i][j];
            }
        }
    }
    
    // Compute right diagonal
    int second_diagonal = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if ((i + j + 1) == MATRIX_SIZE)
            {
                second_diagonal += arr[i][j];
            }
        }
    }

    printf("Diagonal sums: %d %d\n", first_diagonal, second_diagonal);

    return 0;
}