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

void Game::gameLoop() {
    using namespace std::chrono;
    auto lastTime = steady_clock::now();
    bird.x = 10;
    bird.y = 10;
    pipes.clear();
    score.reset();
    std::string name = getName();

    while (gameRunning) {
        auto currentTime = steady_clock::now();
        float deltaTime = duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        update(deltaTime);


        std::this_thread::sleep_for(milliseconds(100));
    }
    endGame(name);
}
void Game::update(float deltaTime) {
    bird.updatePosition(deltaTime);
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
        if (!pipes.empty() && bird.x == pipes.front().x + 1) {
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
void Game::endGame(std::string name) {
    board.add(name, score.getScore());
    std::cout << "Game is over" << std::endl;
    std::cout << "Your total score is " << score.getScore() << std::endl;
    EndScreen endScreen;
    char option = endScreen.show();
    if (option == 'e') {
        exit(0);
    }
    else if (option == 'm') {
        gameRunning = true;
        showMenu();
    }
    else if (option == 'r') {
        gameRunning = true;
        //gameLoop();
    }
    else {
        std::cout << "Wrong option" << std::endl;
    }
}

