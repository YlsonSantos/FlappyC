#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>  // Pode ser removido se for necessário usar Linux/macOS
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#define pipeCount 3

Bird bird;
PIX *pipes;  // Usando ponteiro para PIX
int score = 0;
int *passed;  // Usando ponteiro para o array 'passed'

int gameTime = 0;
int delayTime = 200;
float accelerationFactor = 0.95;

void initGame() {
    bird.x = 10;
    bird.y = 10;

    // Aloca dinamicamente o array de pipes e o array 'passed'
    pipes = (PIX *)malloc(pipeCount * sizeof(PIX));
    passed = (int *)malloc(pipeCount * sizeof(int));

    if (pipes == NULL || passed == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < pipeCount; i++) {
        pipes[i].x = 25 + 15 * i;
        pipes[i].y = (rand() % 7) + 5;
        passed[i] = 0;
    }
}

void freeMemory() {
    // Libera a memória alocada dinamicamente
    free(pipes);
    free(passed);
}

void updateGame() {
    if (isSpacePressed()) {
        bird.y -= 2;
    }

    bird.y++;

    for (int i = 0; i < pipeCount; i++) {
        pipes[i].x--;

        if (pipes[i].x == -1) {
            pipes[i].x = pipes[(i + 2) % 3].x + 15;
            pipes[i].y = (rand() % 7) + 5;
            passed[i] = 0;
        }
    }
}

int checkCollision() {
    if (bird.y >= ySize) return 1;
    if (bird.y <= 0) return 1;

    for (int i = 0; i < pipeCount; i++) {
        if (bird.x >= pipes[i].x && bird.x <= pipes[i].x + 2 &&
            (bird.y < pipes[i].y - 2 || bird.y > pipes[i].y + 2)) {
            return 1;
        }
    }

    return 0;
}

void checkScore() {
    for (int i = 0; i < pipeCount; i++) {
        if (bird.x > pipes[i].x + 2 && passed[i] == 0) {
            score++;
            passed[i] = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    initGame();

    printf("Pressione Espaço para pular e 'Q' para sair.\n");

    while (1) {
        if (GetAsyncKeyState(0x51)) break;

        updateGame();
        checkScore();
        Draw(bird, pipes, pipeCount, score);

        if (checkCollision()) {
            printf("\nGame Over!\n");
            printf("Pontuacao final: %d\n", score);
            break;
        }

        gameTime++;
        if (gameTime % 30 == 0) {
            delayTime *= accelerationFactor;
        }

        delay(delayTime);
    }

    freeMemory();  // Libera a memória antes de sair

    return 0;
}