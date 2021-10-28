//
// Created by cool8 on 24.10.2021.
//

#include "Texts.h"

Texts::Texts() = default;

Texts::Texts(const string& file)
{
    ifstream fin(file);
    if (fin.good()) {
        string tmp;
        while (!fin.eof()) {
            getline(fin, tmp);
            tmp.pop_back();
            text.push_back(tmp);
        }
    }
}

bool Texts::addText(const string& file)
{
    ifstream fin(file);
    if (fin.good()) {
        string tmp;
        while (!fin.eof()) {
            getline(fin, tmp);
            tmp.pop_back();
            text.push_back(tmp);
        }
        return true;
    }
    return false;
}

void Texts::setTextToWrite(string& textToWrite)
{
    textToWrite = text[rand() % text.size()];
    int k = 0;
    for (int i = 0; i != textToWrite.size(); i++, k++) {
        if (k % countOfSymbols == 0 && k != 0) {
            while (i < textToWrite.size() && textToWrite[i] != ' ') {
                i++;
                k++;
            }
            textToWrite.insert(++i, 1, '\n');
            k = 0;
        }
    }
}

void Texts::removeAllTexts()
{
    text.clear();
}

void Texts::repairText()
{
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < text[i].size(); j++) {
            if (text[i][j] == '\n') {
                text[i].erase(j, 1);
            }
        }
    }
}
