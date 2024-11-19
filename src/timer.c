#include "timer.h"

#ifdef _WIN32
#include <windows.h>
void delay(int ms) {
    Sleep(ms);
}
#else
#include <unistd.h>
void delay(int ms) {
    usleep(ms * 1000); 
}
#endif
