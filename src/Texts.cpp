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
    int k = 0;
    for (int i = 0; i != textToWrite.size(); i++, k++) {
        if (k % count == 0 && k != 0) {
            while (i < textToWrite.size() && textToWrite[i] != ' ') {
                i++;
                k++;
            }
            textToWrite.insert(++i, 1, '\n');
            k = 0;
        }
    }
}
