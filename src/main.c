// src/main.c

#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x, y;
} Position;

Position snake[100];
int snakeLength = 1;
Position food;
int score = 0;
int direction = 'd'; // Direção inicial (d para direita)
bool isGameOver = false; // Estado do jogo

void initGame();
void generateFood();
void updateGame();
void drawWalls();

int main() {
    initKeyboard();
    initGame();

    while (!isGameOver) {
        int key = getKeyPress();
        if (key != -1) {
            direction = key; // Atualiza a direção com a tecla pressionada
        }
        
        clearScreen();
        drawWalls(); // Desenha as paredes
        updateGame();
        displayScore(score);
        for (int i = 0; i < snakeLength; i++) {
            drawSnake(snake[i].x, snake[i].y);
        }
        drawFood(food.x, food.y);
        delay(200); // Ajuste de velocidade
    }

    closeKeyboard();
    printf("Game Over! Score: %d\n", score); // Mensagem de fim de jogo
    return 0;
}

void initGame() {
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    generateFood();
}

void generateFood() {
    food.x = (rand() % (WIDTH - 2)) + 1;  // Gera comida entre as colunas 1 e WIDTH - 2
    food.y = (rand() % (HEIGHT - 3)) + 2; // Gera comida entre as linhas 2 e HEIGHT - 2
}

void updateGame() {
    Position newHead = snake[0];

    // Movimenta a cobrinha na direção atual
    if (direction == 'w') newHead.y -= 1; // Cima
    if (direction == 's') newHead.y += 1; // Baixo
    if (direction == 'a') newHead.x -= 1; // Esquerda
    if (direction == 'd') newHead.x += 1; // Direita

    // Verifica colisão com paredes
    if (newHead.x <= 0 || newHead.x >= WIDTH - 1 || newHead.y <= 0 || newHead.y >= HEIGHT - 1) {
        isGameOver = true; // Cobra colidiu com a parede, fim do jogo
        return;
    }

    // Verifica colisão com comida
    if (newHead.x == food.x && newHead.y == food.y) {
        score++;
        snakeLength++;
        generateFood();
    }

    // Atualiza a posição da cobra
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0] = newHead;
}

void drawWalls() {
    // Desenha a parede superior e inferior
    for (int x = 0; x < WIDTH; x++) {
        printf("\033[%d;%dH#", 0, x);         // Parede superior
        printf("\033[%d;%dH#", HEIGHT - 1, x); // Parede inferior
    }
    // Desenha a parede esquerda e direita
    for (int y = 0; y < HEIGHT; y++) {
        printf("\033[%d;%dH#", y, 0);         // Parede esquerda
        printf("\033[%d;%dH#", y, WIDTH - 1); // Parede direita
    }
}
