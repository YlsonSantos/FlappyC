# Makefile

CC = gcc
CFLAGS = -Wall -Iinclude -g
SRC = src/main.c src/keyboard.c src/screen.c src/timer.c
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
EXEC = $(BUILD_DIR)/flappy_bird.exe  # Nome do seu executável

# Diretórios de saída
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Regra principal de compilação
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Compilar arquivos .c para .o
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretórios de build e obj, se necessário
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Limpar arquivos de compilação
clean:
	rm -rf $(BUILD_DIR)

# Regras padrões
.PHONY: clean