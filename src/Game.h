//
// Created by cool8 on 24.10.2021.
//

#ifndef KEYBOARDNINJA_GAME_H
#define KEYBOARDNINJA_GAME_H

#include "Texts.h"
#include <algorithm>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>

class Game {
private:
    Texts texts;
    vector<pair<int, string>> results;
    static bool comparator(pair<int, string>&, pair<int, string>&);

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
    double goPrint(const string&);
    static double wtime();
    void menu();
    void settings();
    void addResult(int&);
    void showRecords();
    void readRecordsFromFile();
    void saveRecordsInFile();
};

#endif
