#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "board.h"

int main()
{
    generateBombs(10, 0, 0);
    displayBoard(true);

    return 0;
}