#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "board.h"

#define HEIGHT          4
#define WIDTH           4
#define NUM_OF_BOMBS    2

int main(void)
{
    int8_t board[HEIGHT * WIDTH] = {0};
    int8_t visible_board[HEIGHT * WIDTH] = {0};

    InitializeBoard(board, visible_board, HEIGHT, WIDTH, NUM_OF_BOMBS);
    RevealTile(board, visible_board, HEIGHT, WIDTH, 9);
    DisplayBoard(board, visible_board, HEIGHT, WIDTH);

    return 0;
}
