#include <stdbool.h>
#include <stdint.h>

#include "board.h"

#define HEIGHT          4
#define WIDTH           4
#define NUM_OF_BOMBS    2

int main(void)
{
    int8_t hidden_board[HEIGHT * WIDTH] = {false};
    int8_t board[HEIGHT * WIDTH] = {0};

    InitializeBoard(board, HEIGHT, WIDTH, NUM_OF_BOMBS);
    RevealBoard(board, hidden_board, HEIGHT, WIDTH, 9);
    DisplayBoard(board, hidden_board, HEIGHT, WIDTH);

    return 0;
}
