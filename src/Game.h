//
// Created by cool8 on 24.10.2021.
//

#ifndef KEYBOARDNINJA_GAME_H
#define KEYBOARDNINJA_GAME_H

#include "Texts.h"
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

class Game {
private:
    Texts texts;

public:
    Game();
    bool checkAlpha(const char&, const char&);
    int getch();
    void menu();
};

#endif
