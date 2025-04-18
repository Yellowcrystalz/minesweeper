#include "board.h"

#define HEIGHT          16
#define WIDTH           30
#define NUM_OF_BOMBS    99

int main(void)
{
    int8_t board[HEIGHT * WIDTH] = {0};

    InitializeBoard(board, HEIGHT, WIDTH, NUM_OF_BOMBS);
    DisplayBoard(board, HEIGHT, WIDTH);

    return 0;
}
