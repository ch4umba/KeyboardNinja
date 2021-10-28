//
// Created by cool8 on 24.10.2021.
//

#ifndef KEYBOARDNINJA_TEXTS_H
#define KEYBOARDNINJA_TEXTS_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Texts {
private:
    vector<string> text;

public:
    int countOfSymbols = 30;

    Texts();
    Texts(const string&);
    bool addText(const string&);
    void setTextToWrite(string&);
    void removeAllTexts();
    void repairText();
};

#endif // KEYBOARDNINJA_TEXTS_H
