CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -I./include
SRC = ./src/*.c
OUT = ./bin/main

$(OUT):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -fr $(OUT)

.PHONY: all clean
