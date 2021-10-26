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
    string textToWrite = "";
public:
    Texts();
    Texts(string file);
};


#endif //KEYBOARDNINJA_TEXTS_H
