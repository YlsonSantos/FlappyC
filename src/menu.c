#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

#define MAX_PLAYERS 10
#define SCORE_FILE "scores.csv"

typedef struct {
    char name[50];
    int score;
} Player;

Player highScores[MAX_PLAYERS];
int scoreCount = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void loadScores() {
    FILE *file = fopen(SCORE_FILE, "r");
    if (file) {
        while (fscanf(file, "%49[^,],%d\n", highScores[scoreCount].name, &highScores[scoreCount].score) == 2) {
            scoreCount++;
        }
        fclose(file);
    }
}

void saveScoresToFile() {
    FILE *file = fopen(SCORE_FILE, "w");
    if (file) {
        for (int i = 0; i < scoreCount; i++) {
            fprintf(file, "%s,%d\n", highScores[i].name, highScores[i].score);
        }
        fclose(file);
    }
}

void showMenu() {
    clearScreen();
    printf("Menu Inicial\n");
    printf("1. Jogar\n");
    printf("2. Pontuacoes\n");
    printf("3. Sair\n");
}

void saveScore(const char* name, int score) {
    if (scoreCount < MAX_PLAYERS) {
        strncpy(highScores[scoreCount].name, name, 50);
        highScores[scoreCount].score = score;
        scoreCount++;
    } else {
        printf("Limite de pontuacoes alcancado.\n");
    }
    saveScoresToFile();
}

void showScores() {
    clearScreen();

    for (int i = 0; i < scoreCount - 1; i++) {
        for (int j = i + 1; j < scoreCount; j++) {
            if (highScores[i].score < highScores[j].score) {
                Player temp = highScores[i];
                highScores[i] = highScores[j];
                highScores[j] = temp;
            }
        }
    }

    printf("\nRanking de Pontuacoes:\n");
    if (scoreCount == 0) {
        printf("Nenhuma pontuação salva.\n");
    } else {
        for (int i = 0; i < scoreCount; i++) {
            printf("%d. %s - %d pontos\n", i + 1, highScores[i].name, highScores[i].score);
        }
    }

    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
    getchar();
}