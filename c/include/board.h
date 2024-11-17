#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdint.h>

#define HEIGHT  8
#define WIDTH   8

typedef struct Board
{
    int         num_bits;
    int         size;
    uint64_t    *bits;
} Bitboard;

void GenerateBombs(int num_bomb, uint8_t first_row, uint8_t first_col);
void IncrementSurronding(uint8_t row, uint8_t col);
void DisplayBoard(bool hidden);

#endif