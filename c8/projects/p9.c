#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <inttypes.h>
#include <assert.h>

#define BOARD_SIZE  (10)
#define EMPTY_SLOT  ('.')
#define EXTRA_DEBUG (false)

typedef enum
{
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
    MAX_DIRECTIONS,
} MoveDirection_t;

void reset_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (uint8_t i = 0; i < BOARD_SIZE; i++) 
    {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) 
        {
            board[i][j] = EMPTY_SLOT;
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (uint8_t i = 0; i < BOARD_SIZE; i++) 
    {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

const char* get_directions_str(MoveDirection_t direction)
{
    switch (direction)
    {
        case DIRECTION_UP:
            return "UP";
        case DIRECTION_DOWN:
            return("DOWN ");
        case DIRECTION_LEFT:
            return("LEFT ");
        case DIRECTION_RIGHT:
            return("RIGHT ");
        default:
            return("INVALID_MOVE");
    }
}

void print_directions(MoveDirection_t directions[], uint8_t directions_size)
{
#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
    for (uint8_t i = 0; i < directions_size; i++)
    {
        printf("%s ", get_directions_str(directions[i]));
    }
    printf("\n");
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
}

void get_available_directions(char board[BOARD_SIZE][BOARD_SIZE], uint8_t row, uint8_t col, MoveDirection_t directions[], uint8_t *directions_size)
{
    assert(directions_size != NULL);

    *directions_size = 0;

    if ((row - 1 >= 0) && (EMPTY_SLOT == board[row - 1][col]))
    {
        directions[*directions_size] = DIRECTION_UP;
        (*directions_size)++;
    }

    if ((row + 1 < BOARD_SIZE) && (EMPTY_SLOT == board[row + 1][col]))
    {
        directions[*directions_size] = DIRECTION_DOWN;
        (*directions_size)++;
    }

    if ((col + 1 < BOARD_SIZE) && (EMPTY_SLOT == board[row][col + 1]))
    {
        directions[*directions_size] = DIRECTION_RIGHT;
        (*directions_size)++;
    }

    if ((col - 1 >= 0) && (EMPTY_SLOT == board[row][col - 1]))
    {
        directions[*directions_size] = DIRECTION_LEFT;
        (*directions_size)++;
    }
}

MoveDirection_t get_random_direction(MoveDirection_t directions[], uint8_t directions_size)
{
    return directions[rand() % directions_size];
}

void fill_slot(char board[BOARD_SIZE][BOARD_SIZE], uint8_t row, uint8_t col, char sym)
{
    board[row][col] = sym;

#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
    printf("\n------ Sym: %c ------\n", sym);
    print_board(board);
    printf("------ Sym: %c ------\n", sym);
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true) 
}

void fill_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    uint8_t starting_row = 0;
    uint8_t starting_column = 0;

    fill_slot(board, starting_row, starting_column, 'A');

    for(char sym = 'B'; sym <= 'Z'; sym++)
    {
        MoveDirection_t directions[MAX_DIRECTIONS] = {0};
        uint8_t directions_size = 0;

        get_available_directions(board, starting_row, starting_column, directions, &directions_size);
        print_directions(directions, directions_size);

        if (directions_size <= 0)
        {
            printf("Premature termination\n");
            return;
        }

        MoveDirection_t direction = get_random_direction(directions, directions_size);

#if defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)
        printf("Chosen direction: %s\n", get_directions_str(direction));
#endif // defined(EXTRA_DEBUG) && (EXTRA_DEBUG == true)

        switch (direction)
        {
            case DIRECTION_UP:
                starting_row--;
                break;
            case DIRECTION_DOWN:
                starting_row++;
                break;
            case DIRECTION_LEFT:
                starting_column--;
                break;
            case DIRECTION_RIGHT:
                starting_column++;
                break;
            default:
                printf("Invalid Direction\n");
                return;
        }

        fill_slot(board, starting_row, starting_column, sym);
    }
}

int main(void)
{
    char board[BOARD_SIZE][BOARD_SIZE] = {0};

    srand((unsigned)time(NULL));

    reset_board(board);
    print_board(board);

    fill_board(board);
    printf("\n");
    print_board(board);

    return 0;
}