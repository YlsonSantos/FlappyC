// src/keyboard.c

#include "keyboard.h"
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void initKeyboard() {
#ifdef _WIN32
    // No need to initialize on Windows when using conio.h
#else
    static struct termios old, current;
    tcgetattr(STDIN_FILENO, &old);
    current = old;
    current.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &current);
#endif
}

void closeKeyboard() {
#ifdef _WIN32
    // No need to close on Windows when using conio.h
#else
    struct termios old;
    tcgetattr(STDIN_FILENO, &old);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
#endif
}

int getKeyPress() {
#ifdef _WIN32
    if (_kbhit()) {
        return _getch();
    } else {
        return -1;  // No key pressed
    }
#else
    int ch = getchar();
    return ch;
#endif
}
