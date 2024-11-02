#include "Game.h"

class EndScreen {
    int score = 0;
public:
    void show();
    void goMenu();
    void endGame();
    void restartGame();
};

int main() {
    Game game;
    game.start();
    return 0;
}

