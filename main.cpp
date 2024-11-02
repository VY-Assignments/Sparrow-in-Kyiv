#include "Game.h"
#include "Menu.h"
#include "Leaderboard.h"
#include "Renderer.h"

int main() {
    std::string title = "Sparrow in Kyiv";
    bool isDisplayed = false;
    int difficulty = 0;
    LeaderBoard board;
    Menu menu(board, difficulty);
    Renderer renderer(500, 500, title, board, menu);
    Game game(board, isDisplayed);

    renderer.renderMenu();
    while (renderer.isOpen()) {
        sf::Event event;
        while (renderer.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderer.close();
            }
            renderer.handleEvents(event);
        }
        if (board.isDisplayed) {
            renderer.renderLeaderboard();
        } else if (difficulty != 0) {
            game.setDifficulty(difficulty);
            game.gameLoop(renderer);
            renderer.renderGame(game);

        }
        else {
            renderer.renderMenu();
        }
    }

    return 0;
}

