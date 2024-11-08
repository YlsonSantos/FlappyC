#ifndef SCREEN_H
#define SCREEN_H

#define xSize 32
#define ySize 16

typedef struct {
    int x;
    int y;
} Bird;

typedef struct {
    int x;
    int y;
} PIX;

void Draw(Bird bird, PIX pipes[], int pipeCount, int score);

#endif
