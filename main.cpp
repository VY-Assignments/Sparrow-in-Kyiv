#include <iostream>

#include "Game.h"
#include "Menu.h"
#include "Leaderboard.h"
#include "Renderer.h"


int main() {
    GameState currentState = GameState::Menu;
    std::string title = "Sparrow in Kyiv";
    int difficulty = 0;
    LeaderBoard board(currentState);
    Menu menu(difficulty, currentState);
    Renderer renderer(700, 900, title, board);
    Game game(board);


    while (renderer.isOpen()) {
        sf::Event event;
        while (renderer.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderer.close();
            }
            switch (currentState) {
                case GameState::Menu:
                    renderer.renderMenu(menu.buttons);
                    renderer.handleEventsMenu(event, menu.buttons);
                    break;
                case GameState::LeaderBoard:
                    renderer.renderLeaderboard(board);
                    renderer.handleEventsLeaderBoard(event, board.button);
                    break;
                case GameState::Game:
                    renderer.renderGame(game.bird, game.pipes, game.score);
                    renderer.handeEventsGame(event, game.bird);
                    if (!game.gameRunning) {
                        game.setDifficulty(difficulty);
                    }
                    game.gameLoop();
                    break;
            }
        }
    }

    return 0;
}

