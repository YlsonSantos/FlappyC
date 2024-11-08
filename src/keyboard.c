// src/keyboard.c
#include <windows.h>
#include "keyboard.h"

int isSpacePressed() {
    return GetAsyncKeyState(VK_SPACE);
}
