#include "EndScreen.h"
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
    Renderer renderer(600, 800, title, board);

    Game game(board);
    EndScreen screen(currentState);

    while (renderer.isOpen()) {
        sf::Event event;
        while (renderer.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderer.close();
                game.gameRunning = false;
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
                    if (!game.gameRunning) {
                        renderer.clear();
                        game.start();
                    }
                    while (game.gameRunning) {
                        while (renderer.pollEvent(event)) {
                            renderer.handeEventsGame(event, game.bird);
                            if (event.type == sf::Event::Closed) {
                                renderer.close();
                                game.gameRunning = false;
                            }
                        }
                        game.update();
                        renderer.renderGame(game.bird, game.pipes, game.score);
                    }
                    currentState = GameState::EndScreen;
                    break;
                case GameState::EndScreen: {
                    renderer.handleEventsEndScreen(event, screen.buttons);
                    renderer.renderEndScreen(game.score, screen.buttons);
                }
            }
        }
    }

    return 0;
}

