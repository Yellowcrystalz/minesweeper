#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "board.h"

int grid[HEIGHT][WIDTH] = { 0 };

Board* setBoard()
{

}

void GenerateBombs(int num_bomb, uint8_t first_row, uint8_t first_col)
{
    uint8_t numBombsPlaced = 0;
    srand(time(0));

    while(numBombsPlaced < num_bomb)
    {
        uint8_t row = rand() % HEIGHT;
        uint8_t col = rand() % WIDTH;

        if
        (
            grid[row][col] != -1 && 
            (col != first_col && row != first_row)
        )
        {
            grid[row][col] = -1;
            incrementSurronding(row, col);
            numBombsPlaced++;
        }
    }
}

void IncrementSurronding(uint8_t row, uint8_t col)
{
    int8_t offset[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int8_t row_offset = {0};
    int8_t col_offset = {0};

    for(int i = 0; i < 8; i++) {
        row_offset = row + offset[i];
        col_offset = col + offset[(i + 6) % 8];

        if
        (
            row_offset > -1 &&
            col_offset > -1 &&
            row_offset < HEIGHT &&
            col_offset < WIDTH &&
            grid[row_offset][col_offset] != -1
        )
        {
            grid[row_offset][col_offset]++;
        }
    }
}

void DisplayBoard(bool hidden)
{
    for(int row = 0; row < HEIGHT; row++)
    {
        for(int col = 0; col < WIDTH; col++)
        {
            switch(grid[row][col])
            {
                case -1:
                    printf("[X]");
                    break;
                case 0:
                    printf("[ ]");
                    break;
                default:
                    printf("[%d]", grid[row][col]);
            }
        }

        printf("\n");
    }
}