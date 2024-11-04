#include "Game.h"
#include <iostream>
#include <chrono>
#include <iostream>
#include <thread>
#include "EndScreen.h"

Game::Game(LeaderBoard& inBoard): difficulty(0), board(inBoard), bird(Bird(10, 10)) {}

std::string Game::getName() {
    std::string name;
    //std::cout << "Enter your name: ";
    //std::cin >> name;
    name = "Alla";
    return name;
}

void Game::start() {
    bird.reset();
    pipes.clear();
    score.reset();
    gameRunning = true;
    std::string name = getName();
}
void Game::update() {
    bird.updatePosition();
    for (auto it = pipes.begin(); it != pipes.end();) {
        it -> updatePosition();
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
        if (!pipes.empty() && bird.x + 20 == pipes.front().x + 1) {
            updateScore();
        }
    }
    if (pipes.empty()) {
        int pipeGap = 250 + rand() % 101;
        int pipeY = rand() % (maxHeight - 350);
        pipes.emplace_back(maxWidth / 2 - 1, pipeY, pipeGap);
    }
    if (pipes.back().x <= maxWidth - 100) {
            int pipeGap = 250 + rand() % 101;
            int pipeY = rand() % (maxHeight - 350);

            pipes.emplace_back(maxWidth - 1, pipeY, pipeGap);

            pipeSpawnCounter = 0;
    }
};
bool Game::checkCollisions() {
    for (auto& pipe: pipes) {
        if (bird.checkColissions(pipe)) {
            return true;
        }
    }
    if (bird.checkColisionWithBorders()) return true;
    return false;
}
void Game::updateScore() {
    score.increaseScore();
}

void Game::setDifficulty(int level) {
    difficulty = level;
}
void Game::showMenu() {
    // Menu menu;
    // menu.viewScoreBoard(board);
    // setDifficulty(menu.chooseDifficulty());
    // start();
}

