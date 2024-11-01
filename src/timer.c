// src/timer.c

#include "timer.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds); // No Windows, usa Sleep
#else
    usleep(milliseconds * 1000); // Em sistemas POSIX, usa usleep
#endif
}
