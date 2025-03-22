#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"

void InitializeBoard(int8_t* board, uint8_t height, uint8_t width, uint8_t num_of_bombs)
{
    srand(time(0));

    uint8_t max = height * width;
    uint8_t bomb_count = num_of_bombs;
    uint8_t bomb_index = {0};

    while (bomb_count > 0) {
        bomb_index = rand() % (max - 1);

        if (board[bomb_index] == 0) {
            board[bomb_index] = -1;
            bomb_count--;
        }
    }
}

void DisplayBoard(int8_t* board, uint8_t height, uint8_t width)
{
    for (int i = 0; i < height * width; i++) {
        printf("%d ", board[i]);

        if (i % width == width - 1) {
            printf("\n");
        }
    }
}
