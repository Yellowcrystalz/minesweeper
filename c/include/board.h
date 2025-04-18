#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

void InitializeBoard(int8_t *board, uint8_t height, uint8_t width, uint8_t num_of_bombs);
void DisplayBoard(int8_t *board, uint8_t height, uint8_t width);

#endif // !BOARD_H
