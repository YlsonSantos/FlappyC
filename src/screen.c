#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"

#define GREEN       "\e[32m"
#define YELLOW      "\e[33m"
#define NC          "\e[0m"

void Draw(Bird bird, PIX pipes[], int pipeCount, int score) { // Função que desenha o jogo na tela.
    char buff[5000];
    strcpy(buff, "\e[17A");

    printf("Score: %d\n", score);
    for (int y = 0; y <= ySize; y++) { // Loop para desenhar o eixo Y da tela.
        for (int x = 0; x <= xSize; x++) { // Loop para desenhar o eixo X da tela.
            if (y == 0 || y == ySize || x == 0 || x == xSize) {
                strcat(buff, NC "[]");
                continue;
            }

            int Draw = 0;
            for (int i = 0; i < pipeCount; i++) { // Verifica se há canos (obstaculos) na posição atual.
                if (pipes[i].x == x) { // Verifica se a posição X do cano coincide com a posição atual.
                    if (y < pipes[i].y - 2 || y > pipes[i].y + 2) {
                        strcat(buff, GREEN "[]");
                        Draw = 1;
                        break;
                    }
                }
            }

            if (Draw == 0) { // Se não houve objeto desenhado verifica a posição do pássaro.
                if (bird.y == y && bird.x == x) { 
                    strcat(buff, YELLOW "O>");
                } else {
                    strcat(buff, NC "  ");
                }
            }
        }
        strcat(buff, "\n");
    }

    printf("%s", buff);
}
