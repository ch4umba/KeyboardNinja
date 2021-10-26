//
// Created by cool8 on 24.10.2021.
//

#ifndef KEYBOARDNINJA_GAME_H
#define KEYBOARDNINJA_GAME_H

#include "Texts.h"
#include <iostream>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <termios.h>

class Game {
private:
    Texts texts;
public:
    Game();
    bool checkAlpha(const char&, const char&);
    int getch();
    void showMenu();
    void showSettings();
    void start();
    static int setBGColor(int);
    static int setFGColor(int);
    static int clrscr();
    static int gotoXY(int, int);
    void printText(const string& printText);
    double goPrint(const string&);
    static double wtime();
};

#endif
