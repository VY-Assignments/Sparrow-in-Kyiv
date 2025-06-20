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
                    renderer.renderMenu(menu.getButtons(), menu.getTextField());
                    renderer.handleEventsMenu(event, menu.getButtons(), menu.getTextField());
                    break;
                case GameState::LeaderBoard:
                    renderer.renderLeaderboard(board);
                    renderer.handleEventsLeaderBoard(event, board.button);
                    break;
                case GameState::Game:
                    scoreSubmitted = false;
                    if (!game.gameRunning) {
                        renderer.clear();
                        game.setDifficulty(difficulty);
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
                            renderer.handeEventsGame(event, game.getBird());
                            if (event.type == sf::Event::Closed) {
                                renderer.close();
                                game.gameRunning = false;
                            }
                        }
                        game.update();
                        renderer.renderGame(game.getBird(), game.getPipes(), game.getInstScore());
                    }
                    currentState = GameState::EndScreen;
                    break;
                case GameState::EndScreen: {
                    gameStarted = false;
                    if (!scoreSubmitted) {
                        board.add(menu.getTextField().getText(), game.getScore());
                        scoreSubmitted = true;
                    }
                    renderer.handleEventsEndScreen(event, screen.getButtons());
                    renderer.renderEndScreen(game.getScore(), screen.getButtons());
                }
            }
        }
    }

    return 0;
}

