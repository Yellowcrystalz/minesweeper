#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdint.h>

void GetNeighborIndicies(int16_t *neighbor_indicies, uint8_t height, uint8_t width, uint16_t tile_index);
void InitializeBoard(int8_t *board, int8_t *visible_board, uint8_t height, uint8_t width, uint8_t num_of_bombs);
void DisplayBoard(int8_t *board, int8_t *hidden_board, uint8_t height, uint8_t width);
bool RevealTile(int8_t *board, int8_t *visible_board, uint8_t height, uint8_t width, uint16_t reveal_index);

#endif // !BOARD_H
