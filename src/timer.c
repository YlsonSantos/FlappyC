#include "timer.h"

#ifdef _WIN32
#include <windows.h>
void delay(int ms) {  // Define a função, que recebe um parâmetro "ms" (milissegundos) e pausa a execução por esse tempo.
    Sleep(ms);
}
#else
#include <unistd.h>
void delay(int ms) {
    usleep(ms * 1000); 
}
#endif
