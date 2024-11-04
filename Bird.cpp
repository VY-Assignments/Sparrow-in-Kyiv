#include "Bird.h"
#include "Pipe.h"
#include "Game.h"

void Bird::loadTextures() {
    std::vector<std::string> textureFiles = {
        "bird.png",
        "birdF.png",
    };

    for (const auto& file : textureFiles) {
        sf::Texture texture;
        if (!texture.loadFromFile(file)) {
            std::cerr << "Failed to load texture: " << file << std::endl;
        } else {
            textures.push_back(texture);
        }
    }
}


void Bird::reset() {
    x = 100;
    y = 100;
    sprite.setTexture(textures[0]);
    sprite.setPosition(x, y);
    speed = 0;
}

void Bird::flap() {
    speed = lift;
    //sprite.setTexture(textures[1]);
}
bool ::Bird::checkCollissions(Pipe &pipe) {
    return sprite.getGlobalBounds().intersects(pipe.sprite.getGlobalBounds());
}

bool Bird::checkCollisionWithBorders() {
    sf::FloatRect birdBounds = sprite.getGlobalBounds();
    sf::Vector2u windowSize = {600, 800};
    if (birdBounds.top <= 0 || birdBounds.top + birdBounds.height >= windowSize.y) {
        return true;
    }
    return false;
}

void ::Bird::updatePosition() {
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight;
    sprite.setPosition(x, y);
}

