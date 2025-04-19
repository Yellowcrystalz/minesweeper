#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdint.h>

void InitializeBoard(int8_t *board, uint8_t height, uint8_t width, uint8_t num_of_bombs);
void DisplayBoard(int8_t *board, int8_t *hidden_board, uint8_t height, uint8_t width);
bool RevealBoard(int8_t *board, int8_t *hidden_board, uint8_t height, uint8_t width, uint16_t reveal_index);

#endif // !BOARD_H
