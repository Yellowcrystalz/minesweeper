CC = gcc
CFLAGS = -I./include -g
LDFLAGS = -L./lib
SRC = src/*c
OUT = bin/main
TEST = test/*c
TESTOUT = bin/test

$(OUT):$(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $(OUT)

clean:
	rm -fr bin/*

test:
	$(OUT):$(SRC)
		$(CC) $(CFLAGS) $(LDFLAGS) $(TEST) -o $(TESTOUT)

.PHONY: all clean