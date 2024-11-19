#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "menu.h"  

#define pipeCount 3

Bird bird;
PIX *pipes;
int score = 0;
int *passed;

int gameTime = 0;
int delayTime = 200;
float accelerationFactor = 0.95;

char playerName[50];  

void initGame() {
    bird.x = 10;
    bird.y = 10;

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

void playAgain() {
    int choice;
    printf("\nVoltar ao menu\n");
    printf("1. Sim\n2. Ver pontuacoes\n3. Sair\n");
    scanf("%d", &choice);

    if (choice == 1) {
        score = 0;
        initGame();
    } else if (choice == 2) {
        showScores();
    } else {
        printf("Saindo do jogo...\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL));

    loadScores();

    int choice;
    while (1) {
        showMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Digite seu nome: ");
            getchar();  
            fgets(playerName, 50, stdin);
            playerName[strcspn(playerName, "\n")] = 0;  

            initGame();
            printf("Pressione Espaço para pular.\n");

            while (1) {
                updateGame();
                checkScore();
                Draw(bird, pipes, pipeCount, score);

                if (checkCollision()) {
                    printf("\nGame Over!\n");
                    printf("Pontuacao final: %d\n", score);

                    saveScore(playerName, score);

                    playAgain(); 
                    break;
                }

                gameTime++;
                if (gameTime % 30 == 0) {
                    delayTime *= accelerationFactor;
                }

                delay(delayTime);
            }

        } else if (choice == 2) {
            showScores();
        } else if (choice == 3) {
            printf("Saindo do jogo...\n");
            break;
        } else {
            printf("Opção invalida! Tente novamente.\n");
        }
    }

    freeMemory();
    return 0;
}