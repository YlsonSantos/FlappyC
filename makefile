CC = gcc
CFLAGS = -Wall -Iinclude -g
SRC = src/main.c src/keyboard.c src/screen.c src/timer.c
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
EXEC = $(BUILD_DIR)/flappy_bird.exe 

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean