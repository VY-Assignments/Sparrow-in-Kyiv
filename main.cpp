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

    Game game;
    EndScreen screen(currentState);
    bool scoreSubmitted = false;
    bool gameStarted = false;

    while (renderer.isOpen()) {
        sf::Event event;
        while (renderer.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderer.close();
                game.gameRunning = false;
            }
            switch (currentState) {
                case GameState::Menu:
                    renderer.renderMenu(menu.buttons, menu.nameField);
                    renderer.handleEventsMenu(event, menu.buttons, menu.nameField);
                    break;
                case GameState::LeaderBoard:
                    renderer.renderLeaderboard(board);
                    renderer.handleEventsLeaderBoard(event, board.button);
                    break;
                case GameState::Game:
                    scoreSubmitted = false;
                    if (!game.gameRunning) {
                        renderer.clear();
                        game.start();

                        while (!gameStarted && renderer.isOpen()) {
                            while (renderer.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    renderer.close();
                                    game.gameRunning = false;
                                    return 0;
                                }
                                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                                    gameStarted = true;
                                    break;
                                }
                            }
                            renderer.clear();
                            renderer.renderStartScreen();
                        }
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
                    gameStarted = false;
                    if (!scoreSubmitted) {
                        board.add(menu.nameField.getText(), game.score.getScore());
                        scoreSubmitted = true;
                    }
                    renderer.handleEventsEndScreen(event, screen.buttons);
                    renderer.renderEndScreen(game.score.getScore(), screen.buttons);
                }
            }
        }
    }

    return 0;
}

