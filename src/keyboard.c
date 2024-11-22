#ifdef _WIN32
#include <windows.h>
#include "keyboard.h"

int isSpacePressed() { // GetAsyncKeyState verifica o estado da tecla espaço.
    return GetAsyncKeyState(VK_SPACE);
}
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "keyboard.h"

int isSpacePressed() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch == ' ') {
        return 1; 
    }
    return 0;
}
#endif
