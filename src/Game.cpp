//
// Created by cool8 on 24.10.2021.
//

#include "Game.h"

Game::Game() { }

int Game::getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(0, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(0, TCSANOW, &oldattr);
    return (ch);
}

bool Game::checkAlpha(const char& correctAlpha, const char& inAlpha) {
    return tolower(correctAlpha) == inAlpha;
}



