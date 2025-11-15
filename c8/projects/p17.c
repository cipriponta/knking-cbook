#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define MATRIX_SIZE (99)
#define EXTRA_DEBUG (false)

void clear_magic_square(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE])
{
    for (uint8_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (uint8_t j = 0; j < MATRIX_SIZE; j++)
        {
            magic_square[i][j] = 0;
        }
    }    
}

void print_magic_square(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size)
{

    for (uint8_t i = 0; i < magic_square_size; i++)
    {
        for (uint8_t j = 0; j < magic_square_size; j++)
        {
            printf("%4d ", magic_square[i][j]);
        }
        printf("\n");
    }    
    printf("\n");

}

void print_magic_square_step(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size, uint8_t step)
{
#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
    printf("\n---------- Step: %4d ----------->\n", step);
    print_magic_square(magic_square, magic_square_size);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
}

void generate_magic_square(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size)
{
    uint8_t starting_row = 0;
    uint8_t starting_col = magic_square_size / 2;

    magic_square[starting_row][starting_col] = 1;
    print_magic_square_step(magic_square, magic_square_size, 1);

    if (magic_square_size > 1)
    {
        for (uint16_t i = 2; i <= magic_square_size * magic_square_size; i++)
        {
            uint8_t next_row = starting_row;
            uint8_t next_col = starting_col;

            if (next_row - 1 < 0)
            {
                next_row = magic_square_size - 1;
            }
            else
            {
                next_row--;
            }

            if (next_col + 1 >= magic_square_size)
            {
                next_col = 0;
            }
            else
            {
                next_col++;
            }

            if (magic_square[next_row][next_col] != 0)
            {
                if (starting_row + 1 >= magic_square_size)
                {
                    next_row = 0;
                }
                else
                {
                    next_row = starting_row + 1;
                }
                next_col = starting_col;
            }

            starting_row = next_row;
            starting_col = next_col;

            magic_square[starting_row][starting_col] = i;
            print_magic_square_step(magic_square, magic_square_size, i);
        }
    }
}

bool check_rows(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size, uint16_t *row_sum)
{
    assert(row_sum != NULL);

    bool first_row_sum = true;

    for(uint8_t i = 0; i < magic_square_size; i++)
    {
        uint16_t curr_row_sum = 0;

        for(uint8_t j = 0; j < magic_square_size; j++)
        {
            curr_row_sum += magic_square[i][j];
        }

#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
        printf("Row sum: %d\n", curr_row_sum);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)

        if (first_row_sum)
        {
            *row_sum = curr_row_sum;
        }
        else
        {
            if (!first_row_sum && (*row_sum != curr_row_sum))
            {
                return false;
            }
            else
            {
                *row_sum = curr_row_sum;
            }
        }
    }

    return true;
}

bool check_cols(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size, uint16_t *col_sum)
{
    assert(col_sum != NULL);

    bool first_col_sum = true;

    for(uint8_t j = 0; j < magic_square_size; j++)
    {
        uint16_t curr_col_sum = 0;

        for(uint8_t i = 0; i < magic_square_size; i++)
        {
            curr_col_sum += magic_square[i][j];
        }

#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
        printf("Col sum: %d\n", curr_col_sum);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)

        if (first_col_sum)
        {
            *col_sum = curr_col_sum;
        }
        else
        {
            if (!first_col_sum && (*col_sum != curr_col_sum))
            {
                return false;
            }
            else
            {
                *col_sum = curr_col_sum;
            }
        }
    }

    return true;
}

bool check_diags(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size, uint16_t *diag_sum)
{
    assert(diag_sum != NULL);

    uint16_t first_diag_sum = 0;
    uint16_t second_diag_sum = 0;

    for (uint8_t i = 0; i < magic_square_size; i++)
    {
        for (uint8_t j = 0; j < magic_square_size; j++)
        {
            if (i == j)
            {
                first_diag_sum += magic_square[i][j];
            }

            if (i + j == magic_square_size - 1)
            {
                second_diag_sum += magic_square[i][j];
            }
        }
    }

#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
    printf("First diag: %d, second diag: %d\n", first_diag_sum, second_diag_sum);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)

    *diag_sum = first_diag_sum;
    return (first_diag_sum == second_diag_sum);
}

void check_magic_square(uint16_t magic_square[MATRIX_SIZE][MATRIX_SIZE], uint8_t magic_square_size)
{
    uint16_t row_sum = 0;
    uint16_t col_sum = 0;
    uint16_t diag_sum = 0;

    clear_magic_square(magic_square);
    generate_magic_square(magic_square, magic_square_size);

    if (check_rows(magic_square, magic_square_size, &row_sum) &&
        check_cols(magic_square, magic_square_size, &col_sum) && 
        check_diags(magic_square, magic_square_size, &diag_sum) &&
        (row_sum == col_sum) &&
        (col_sum == diag_sum))
    {
        printf("Size: %2d  OK\n", magic_square_size);
    }
    else
    {
        printf("Size: %2d NOK\n", magic_square_size);
    }
#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
    print_magic_square(magic_square, magic_square_size);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
}

int main(void)
{
    uint16_t  magic_square[MATRIX_SIZE][MATRIX_SIZE] = {0};

    for(uint8_t i = 1; i <= 99; i += 2)
    {
        check_magic_square(magic_square, i);
    }

    return 0;
}