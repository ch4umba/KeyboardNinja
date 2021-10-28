//
// Created by cool8 on 24.10.2021.
//

#include "Game.h"

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

double Game::wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

Game::Game()
{
    texts.addText("text.txt");
    readRecordsFromFile();
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
    cout << "2. Records" << endl;
    cout << "3. Settings" << endl;
    cout << "4. Exit" << endl;
}

void Game::showSettings()
{
    cout << "1. Add text" << endl;
    cout << "2. Clear all texts" << endl;
    cout << "3. Change number of characters in a line" << endl;
    cout << "4. Back" << endl;
}

void Game::start()
{
    clrscr();
    cout << "Press any key for start!";
    getch();
    getch();
    clrscr();

    string text;
    texts.setTextToWrite(text);
    setBGColor(7);
    setFGColor(0);
    cout << text;
    double time = goPrint(text);
    int symbolsPerMinute = static_cast<int>(
            (text.size() - (text.size() / texts.countOfSymbols)) / time * 60);
    setBGColor(0);
    setFGColor(7);
    clrscr();
    cout << "Your result:" << symbolsPerMinute << " symbols per minute" << endl;
    addResult(symbolsPerMinute);
}

double Game::goPrint(const string& text)
{
    double time = wtime();
    gotoXY(0, 0);
    char alpha;
    bool isCorrectAlpha;
    setBGColor(2);
    setFGColor(7);
    cout << text[0];
    gotoXY(1, 1);
    for (int i = 1, k = 0;;) {
        for (int j = 1;;) {
            if (k == text.size()) {
                return wtime() - time;
            }
            if (text[k] == '\n') {
                j = 1;
                gotoXY(j, ++i);
                ++k;
                setBGColor(2);
                setFGColor(7);
                cout << text[k];
                gotoXY(j, i);
            }
            alpha = getch();
            isCorrectAlpha = checkAlpha(text[k], alpha);

            if (!isCorrectAlpha) {
                setBGColor(1);
                setFGColor(7);
                cout << text[k];
                gotoXY(j, i);
            } else {
                setBGColor(7);
                setFGColor(2);
                cout << text[k];
                gotoXY(++j, i);
                ++k;
                setBGColor(2);
                setFGColor(7);
                cout << text[k];
                gotoXY(j, i);
            }
        }
    }
}

void Game::menu()
{
    int c = 0;
    while (true) {
        clrscr();
        showMenu();
        cout << ">";
        cin >> c;
        switch (c) {
        case 1:
            start();
            break;
        case 2:
            showRecords();
            break;
        case 3:
            settings();
            break;
        case 4:
            saveRecordsInFile();
            return;
        default:
            cout << "ERROR!";
            cout << endl;
            sleep(1);
        }
    }
}

void Game::settings()
{
    int c = 0;
    int tmp = -1;
    string file;
    while (true) {
        clrscr();
        showSettings();
        cout << ">";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Input filename:";
            cin >> file;
            if (texts.addText(file)) {
                cout << "texts added successfully!";
            } else {
                cout << "ERROR!";
            }
            cout << endl;
            sleep(1);
            break;
        case 2:
            texts.removeAllTexts();
            cout << "All texts are removed!";
            cout << endl;
            sleep(1);
            break;
        case 3:
            cout << "Enter the new size symbols in line (20 - 120):";
            cin >> tmp;
            if (tmp < 20 || tmp > 120) {
                cout << "ERROR!";
                cout << endl;
                sleep(1);
                break;
            }
            texts.countOfSymbols = tmp;
            break;
        case 4:
            return;
        default:
            cout << endl;
            cout << "ERROR!";
            sleep(1);
        }
    }
}

bool Game::comparator(pair<int, string>& a, pair<int, string>& b)
{
    return a.first > b.first;
}

void Game::addResult(int& symbolsPerMinute)
{
    cout << "Do you want to save the result? [Y/N]:";
    char choice;
    cin >> choice;
    if (choice == 'Y') {
        string name;
        cout << "Your Name:";
        cin.get();
        getline(cin, name);
        if (results.size() < 10) {
            results.emplace_back(symbolsPerMinute, name);
        } else {
            make_pair(symbolsPerMinute, name) = results[9];
        }
        sort(results.begin(), results.end(), comparator);
    }
}

void Game::showRecords()
{
    clrscr();
    getch();
    cout << "Result\t\t\t"
         << "Name\n";
    for (int i = 0; i < results.size(); i++) {
        cout << results[i].first << "\t\t\t" << results[i].second << endl;
    }
    cout << "Press any key to continue...";
    cin.get();
    clrscr();
}

void Game::saveRecordsInFile()
{
    ofstream fout("records.dat");
    if (fout.good()) {
        for (int i = 0; i < 10; i++) {
            fout << results[i].first << "\t\t\t" << results[i].second << endl;
        }
    }
}

void Game::readRecordsFromFile()
{
    int res;
    string name;
    ifstream fin("records.dat");
    if (fin.good()) {
        while (!fin.eof()) {
            fin >> res;
            fin.get();
            fin.get();
            fin.get();
            getline(fin, name);
            if (name.back() == '\r') {
                name.pop_back();
            }
            results.push_back(make_pair(res, name));
        }
    }
}