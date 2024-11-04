#include "Game.h"
#include <thread>
#include "EndScreen.h"

Game::Game(LeaderBoard& inBoard)
    : difficulty(0), board(inBoard), bird(Bird()), pipePool(10) {
}
void Game::start() {
    bird.reset();
    pipes.clear();
    score.reset();
    currentPipeIndex = 0;
    nextPipeTime = 0;
    gameTicks = 0;
    gameRunning = true;
    currentPipes = pipesEasy;
}

void Game::update() {
    bird.updatePosition();

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
        } else {
            ++it;
        }
    }

    if (gameTicks >= nextPipeTime) {

        Pipe& bottomPipe = pipePool.getPipe();


        Pipe& topPipe = pipePool.getPipe();


        pipes.emplace_back(bottomPipe);
        pipes.emplace_back(topPipe);

        nextPipeTime += 200;

    }

    if (bird.checkCollisionWithBorders()) {
        gameRunning = false;
        return;
    }

    gameTicks++;
}
void Game::updateScore() {
    score.increaseScore();
}

void Game::setDifficulty(int level) {
    difficulty = level;
}
