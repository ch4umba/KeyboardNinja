//
// Created by cool8 on 24.10.2021.
//

#include "Texts.h"

Texts::Texts() {}

Texts::Texts(string file) {
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


