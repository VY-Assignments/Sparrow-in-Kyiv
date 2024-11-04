#include "Game.h"
#include <thread>
#include "EndScreen.h"

Game::Game(LeaderBoard& inBoard): difficulty(0), board(inBoard), bird(Bird()) {}

void Game::loadPipes() {

    pipesEasy.emplace_back(600, "green", false); // Bottom green
    pipesEasy.emplace_back(600, "green", true); // Top green
    // pipesEasy.emplace_back(800, "yellow", false); // Bottom yellow
    // pipesEasy.emplace_back(800, "yellow", true); // Top yellow
}


void Game::start() {
    bird.reset();
    pipes.clear();
    score.reset();
    currentPipeIndex = 0;
    nextPipeTime = 0;
    gameTicks = 0;
    gameRunning = true;
    loadPipes();
    currentPipes = pipesEasy;
}
void Game::update() {
    bird.updatePosition();

    if (gameTicks >= nextPipeTime) {
        if (currentPipeIndex >= currentPipes.size()) {
            currentPipeIndex = 0;
        }
        if (!currentPipes.empty() && currentPipeIndex + 1 < currentPipes.size()) {
            Pipe& bottomPipe = currentPipes[currentPipeIndex];
            Pipe& topPipe = currentPipes[currentPipeIndex + 1];
            std::cout << bottomPipe.kind << " " << bottomPipe.isTop << std::endl;
            std::cout << topPipe.kind << " " << topPipe.isTop << std::endl;

            pipes.emplace_back(bottomPipe);
            pipes.emplace_back(topPipe);
            std::cout << "Pipes added: " << pipes.size() << std::endl;

            currentPipeIndex += 2;
            nextPipeTime += 200;
        }


    }

    if (bird.checkCollisionWithBorders()) {
        gameRunning = false;
        return;
    }

    for (auto it = pipes.begin(); it != pipes.end();) {
        it->updatePosition();

        if (bird.checkCollissions(*it)) {
            gameRunning = false;
            return;
        }
        if (!it->isTop && !it->scored && bird.sprite.getGlobalBounds().width > it->x + it->sprite.getGlobalBounds().width) {
            updateScore();
            it->scored = true;
        }
        if (it->isOffScreen()) {
            it = pipes.erase(it);
            std::cout << "Erase, remaining pipes: " << pipes.size() << std::endl;
        } else {
            ++it;
        }
    }

    std::cout << "After loop, pipes size: " << pipes.size() << std::endl;

    gameTicks++;
}

void Game::updateScore() {
    score.increaseScore();
}

void Game::setDifficulty(int level) {
    difficulty = level;
}
