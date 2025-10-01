CC = gcc
CFLAGS = -Wall -Wextra -O2
BIN = list
SRC = main.c list.c
DEPS = list.h

all: $(BIN)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm $(BIN)
