//
// Created by cool8 on 24.10.2021.
//

#ifndef KEYBOARDNINJA_GAME_H
#define KEYBOARDNINJA_GAME_H

#include <iostream>
#include "Texts.h"
#include <termios.h>
#include <sys/ioctl.h>

class Game {
private:
    Texts texts;
public:
    Game();
    bool checkAlpha(const char&, const char&);
    int getch();
};


#endif
