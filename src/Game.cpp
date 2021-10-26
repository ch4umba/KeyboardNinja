//
// Created by cool8 on 24.10.2021.
//

#include "Game.h"

Game::Game()
{
    texts.addText("text.txt");
}

int Game::getch(void)
{
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

bool Game::checkAlpha(const char& correctAlpha, const char& inAlpha)
{
    return correctAlpha == inAlpha;
}

void Game::showMenu()
{
    cout << "1. Start" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Exit" << endl;
}

void Game::showSettings()
{
    cout << "1. Add text" << endl;
    cout << "2. Clear all texts" << endl;
    cout << "3. Change number of characters in a line" << endl;
    cout << "4. Back" << endl;
}

double Game::wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void Game::start()
{
    clrscr();
    cout << "Press any key for start!";
    getch();
    clrscr();

    string text;
    texts.setTextToWrite(text);
    cout << text;
    goPrint(text);
}

double Game::goPrint(const string& text)
{
    double time = wtime();
    gotoXY(0, 0);
    char alpha;

    for (int i = 1, k = 0;;) {
        for (int j = 1;;) {
            if (k == text.size()) {
                return;
            }
            if (text[k] == '\n') {
                j = 1;
                gotoXY(j, ++i);
                ++k;
            }
            alpha = getch();
            if (checkAlpha(text[k], alpha)) {
                gotoXY(++j, i);
                ++k;
            }
        }
    }
    return wtime() - time;
}

void Game::printText(const string& printText)
{
    for (int i = 0; i < printText.size(); i++) {
        if (i % 60 == 0 && i != 0) {
            while (i < printText.size() && printText[i] != ' ') {
                cout << printText[i];
                i++;
            }
            cout << endl;
        }
        cout << printText[i];
    }
}

int Game::clrscr()
{
    return printf("\E[H\E[J");
}

int Game::setFGColor(int color)
{
    return printf("\E[3%dm", color);
}

int Game::setBGColor(int color)
{
    return printf("\E[4%dm", color);
}

int Game::gotoXY(int y, int x)
{
    return printf("\E[%d;%dH", x, y);
}