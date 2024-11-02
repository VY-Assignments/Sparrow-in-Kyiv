#include "Game.h"
#include <iostream>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

Game::Game() {
    bird = new Bird(10, 10);
}
void Game::start() {
    std::cout << "Starting Game" << std::endl;
    gameLoop();
}
void Game::gameLoop() {
    using namespace std::chrono;
    auto lastTime = steady_clock::now();

    while (gameRunning) {
        auto currentTime = steady_clock::now();
        float deltaTime = duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        handleInput();
        update(deltaTime);
        draw();

        std::this_thread::sleep_for(milliseconds(100));
    }
    endGame();
}
void Game::update(float deltaTime) {
    bird->updatePosition(deltaTime);
    for (auto it = pipes.begin(); it != pipes.end();) {
        it -> updatePosition(deltaTime);
        if (it->isOffScreen()) {
            it = pipes.erase(it);
        } else {
            ++it;
        }
    }
    if (checkCollisions()) {
        gameRunning = false;
    }
    else {
        if (!pipes.empty() && bird->x == pipes.front().x + 1) {
            updateScore();
        }
    }
    if (++pipeSpawnCounter >= 15) {
        pipes.emplace_back(maxWidth - 1, rand() % (maxHeight - 10), 6);
        pipeSpawnCounter = 0;
    }
};
bool Game::checkCollisions() {
    for (auto& pipe: pipes) {
        if (bird->checkColissions(pipe)) {
            return true;
        }
    }
    return false;
}
void Game::updateScore() {
    score.increaseScore();
}
void Game::draw() {
    system("cls");
    std::cout << "Flappy Bird Game" << std::endl;
    for (int i = 0; i < maxWidth; i++) {
        for (int j = 0; j < maxHeight; j++) {
            if (bird -> y == i && bird -> x == j) {
                std::cout << "B"; // Bird
            } else {
                bool isPipe = false;
                for (const auto& pipe : pipes) {
                    if (pipe.x == j && (i < pipe.y || i > pipe.y + pipe.gap)) {
                        std::cout << "|";
                        isPipe = true;
                        break;
                    }
                }
                if (!isPipe) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    score.display();
}
void Game::handleInput() {
    char input;
    std::cout << "Press 'f' to flap, or 'q' to quit: ";
    std::cin >> input;

    if (input == 'f') {
        bird->flap();
        std::cout << "Flap" << std::endl;
    } else if (input == 'q') {
        gameRunning = false;
        std::cout << "Quitting game..." << std::endl;
    } else {
        std::cout << "Invalid command." << std::endl;
    }

}
void Game::setDifficulty(int& level) {

}
void Game::showMenu() {

}
void Game::endGame() {
    std::cout << "Game Over" << std::endl;
}

