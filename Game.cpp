#include "Game.h"

sf::Color getPixelColor(const sf::Image& image, const sf::Sprite& sprite, int x, int y) {
    int localX = x - sprite.getGlobalBounds().left;
    int localY = y - sprite.getGlobalBounds().top;

    localX /= sprite.getScale().x;
    localY /= sprite.getScale().y;

    return image.getPixel(localX, localY);
}

bool pixelPerfectCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    sf::FloatRect intersection;

    if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds(), intersection)) {
        const sf::Image& image1 = sprite1.getTexture()->copyToImage();
        const sf::Image& image2 = sprite2.getTexture()->copyToImage();

        for (int x = intersection.left; x < intersection.left + intersection.width; ++x) {
            for (int y = intersection.top; y < intersection.top + intersection.height; ++y) {
                if (getPixelColor(image1, sprite1, x, y).a > 0 &&
                    getPixelColor(image2, sprite2, x, y).a > 0) {
                    return true;
                    }
            }
        }
    }

    return false;
}



Game::Game(): difficulty(0), bird(Bird()) {}
void Game::start() {
    bird.reset();
    pipes.clear();
    score.reset();
    currentPipeIndex = 0;
    nextPipeTime = 0;
    gameTicks = 0;
    gameRunning = true;
    pipePool.reset();
    pipePool.chooseLevel(difficulty);
}

void Game::update() {
    bird.updatePosition();

    for (auto it = pipes.begin(); it != pipes.end();) {
        it->updatePosition();

        if (pixelPerfectCollision(bird.sprite, (*it).sprite)){
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

        int randomOffset = 10 + (std::rand() % 56);
        nextPipeTime += bottomPipe.sprite.getGlobalBounds().width/2 + randomOffset;
    }

    if (bird.checkCollisionWithBorders()) {
        gameRunning = false;
    }
    else {
        gameTicks++;
    }
}
void Game::updateScore() {
    score.increaseScore();
}

void Game::setDifficulty(int level) {
    difficulty = level;
}

void Game::setPool(PipePool& pipepool) {
    pipePool = pipepool;
}
