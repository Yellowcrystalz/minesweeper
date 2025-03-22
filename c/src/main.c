#include "board.h"

#define HEIGHT          8
#define WIDTH           8
#define NUM_OF_BOMBS    10

int main(void)
{
    int8_t board[HEIGHT * WIDTH] = {0};

    InitializeBoard(board, HEIGHT, WIDTH, NUM_OF_BOMBS);
    DisplayBoard(board, HEIGHT, WIDTH);

    return 0;
}
