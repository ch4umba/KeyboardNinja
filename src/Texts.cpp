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

void Texts::addText(const string& file)
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

void Texts::setTextToWrite(string& textToWrite)
{
    textToWrite = text[rand() % text.size()];
}
