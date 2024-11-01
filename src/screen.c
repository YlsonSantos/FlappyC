// src/screen.c

#include "screen.h"
#include <stdio.h>

void clearScreen() {
    printf("\033[H\033[J");  // Comando ANSI para limpar a tela
}

void drawSnake(int x, int y) {
    printf("\033[%d;%dHO", y, x); // Desenha a cobra na posição (x, y) usando 'O'

}

void drawFood(int x, int y) {
    printf("\033[%d;%dH*", y, x); // Desenha a comida na posição (x, y)
}

void displayScore(int score) {
    printf("\033[0;0HScore: %d\n", score); // Exibe a pontuação no topo
}
