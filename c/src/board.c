#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"


void GetNeighborIndicies(int16_t *neighbor_indicies, uint8_t height, uint8_t width, uint16_t tile_index)
{
    uint8_t x = tile_index % width;
    uint8_t y = tile_index / width;

    int8_t offset[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int8_t x_offset = 0;
    int8_t y_offset = 0;
    
    uint16_t index = 0;

    for (uint8_t i = 0; i < 8; i++) {
        x_offset = x + offset[(i + 2) % 8];
        y_offset = y + offset[i];

        if (
            x_offset < 0 ||
            y_offset < 0 ||
            x_offset >= width ||
            y_offset >= height
        ) {
            neighbor_indicies[i] = -1;
        }
        else {
            index = (y_offset * width) + x_offset;
            neighbor_indicies[i] = index;
        }
    }
}


void IncrementBombs(int8_t *board, uint8_t height, uint8_t width, uint16_t bomb_index)
{
    int16_t neighbor_indicies[8] = {0};
    GetNeighborIndicies(neighbor_indicies, height, width, bomb_index);

    for (uint8_t i = 0; i < 8; i++) {
        if (neighbor_indicies[i] == -1 || board[neighbor_indicies[i]] == -1) {
            continue;
        }

        board[neighbor_indicies[i]]++;
    }
}


void InitializeBoard(int8_t *board, int8_t *visible_board, uint8_t height, uint8_t width, uint8_t num_of_bombs)
{
    srand(time(0));

    uint16_t max = height * width;
    uint8_t bomb_count = num_of_bombs;
    uint16_t bomb_index = {0};

    while (bomb_count > 0) {
        bomb_index = rand() % max;

        if (board[bomb_index] == 0) {
            board[bomb_index] = -1;
            bomb_count--;
        }
    }

    for (uint16_t i = 0; i < max; i++) {
        if (board[i] == -1) {
            IncrementBombs(board, height, width, i);
        }

        visible_board[i] = -2;
    }
}


void DisplayBoard(int8_t *board, int8_t *visible_board, uint8_t height, uint8_t width)
{
    for (uint16_t i = 0; i < height * width; i++) {
        if (visible_board[i] == -2) {
            printf("%3s", "[]");
        }
        else {
            printf("%3d", visible_board[i]);
        }

        if (i % width == width - 1) {
            printf("\n");
        }
    }

    printf("\n");
    for (uint16_t i = 0; i < height * width; i++) {
        printf("%3d", board[i]);

        if (i % width == width - 1) {
            printf("\n");
        }
    }
}


bool RevealTile(int8_t *board, int8_t *visible_board, uint8_t height, uint8_t width, uint16_t reveal_index)
{
    if (visible_board[reveal_index] != -2) {
        return false;
    }
    else {
        visible_board[reveal_index] = board[reveal_index];
    }

    if (board[reveal_index] == -1) {
        return true;
    }
    else if (board[reveal_index] > 0) {
        return false;
    }

    bool gameover_check = false;

    int16_t neighbor_indicies[8] = {0};
    GetNeighborIndicies(neighbor_indicies, height, width, reveal_index);

    for (uint8_t i = 0; i < 8; i++) {
        if (neighbor_indicies[i] == -1) {
            continue;
        }

        gameover_check |= RevealTile(board, visible_board, height, width, neighbor_indicies[i]);
    }

    return gameover_check;
}
