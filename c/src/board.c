#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"


void IncrementBombs(int8_t *board, uint8_t height, uint8_t width, uint16_t bomb_index)
{
    uint8_t x = bomb_index % width;
    uint8_t y = bomb_index / width;

    int8_t offset[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int8_t x_offset = {0};
    int8_t y_offset = {0};
    
    uint16_t index = {0};

    for (uint8_t i = 0; i < 8; i++) {
        x_offset = x + offset[(i + 2) % 8];
        y_offset = y + offset[i];

        if (
            x_offset < 0 ||
            y_offset < 0 ||
            x_offset >= width ||
            y_offset >= height
        ) {
            continue;
        }

        index = (y_offset * width) + x_offset;

        if (board[index] == -1) {
            continue;
        }

        board[index]++;
    }
}


void InitializeBoard(int8_t *board, uint8_t height, uint8_t width, uint8_t num_of_bombs)
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
    }
}


void DisplayBoard(int8_t *board, int8_t *hidden_board, uint8_t height, uint8_t width)
{
    for (uint16_t i = 0; i < height * width; i++) {
        if (hidden_board[i]) {
            printf("%3d", board[i]);
        }
        else {
            printf("%3s", "[]");
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


bool RevealBoard(int8_t *board, int8_t *hidden_board, uint8_t height, uint8_t width, uint16_t reveal_index)
{
    if (hidden_board[reveal_index]) {
        return false;
    }
    else {
        hidden_board[reveal_index] = true;
    }

    if (board[reveal_index] == -1) {
        return true;
    }
    else if (board[reveal_index] > 0) {
        return false;
    }

    bool gameover_check = false;

    uint8_t x = reveal_index % width;
    uint8_t y = reveal_index / width;

    int8_t offset[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int8_t x_offset = {0};
    int8_t y_offset = {0};
    
    uint16_t index = {0};

    for (uint8_t i = 0; i < 8; i++) {
        x_offset = x + offset[(i + 2) % 8];
        y_offset = y + offset[i];

        if (
            x_offset < 0 ||
            y_offset < 0 ||
            x_offset >= width ||
            y_offset >= height
        ) {
            continue;
        }

        index = (y_offset * width) + x_offset;

        gameover_check |= RevealBoard(board, hidden_board, height, width, index);
    }

    return gameover_check;
}
