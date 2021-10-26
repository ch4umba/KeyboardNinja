#include "Game.h"
#include <ctime>

int main() {
    srand(time(NULL));
    Texts t("text.txt");
    Game game;
    char k = game.getch();
    return 0;
}
