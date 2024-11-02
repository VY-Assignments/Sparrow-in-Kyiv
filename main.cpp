#include "Game.h"
#include "Menu.h"
#include "Leaderboard.h"


int main() {
    LeaderBoard board;
    Menu menu;
    menu.viewScoreBoard(board);
    Game game(board);
    game.setDifficulty(menu.chooseDifficulty());
    game.start();
    return 0;
}

