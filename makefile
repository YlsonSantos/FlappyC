# Makefile

CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/keyboard.c src/screen.c src/timer.c
OBJ = $(SRC:.c=.o)
EXEC = snake_game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
