#include "Bird.h"
#include "Pipe.h"
#include "Game.h"

Bird::Bird() {
     {
         loadTextures();
         sprite.setTexture(textures[0]);
         sprite.setScale(100.0f / textures[0].getSize().x,100.0f / textures[0].getSize().y);
         sprite.setPosition(x, y);
     }
}

void Bird::loadTextures() {
    std::vector<std::string> textureFiles = {
        "birdF.png",
        "bird.png",
    };

    for (size_t i = 0; i < textureFiles.size(); ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile(textureFiles[i])) {
            std::cerr << "Failed to load texture: " << textureFiles[i] << std::endl;
        } else {
            textures.push_back(texture);
        }
    }
}


void Bird::reset() {
    x = 100;
    y = 100;
    sprite.setTexture(textures[1]);


    sprite.setPosition(x, y);
    speed = 0;
}

void Bird::flap() {
    speed = lift;
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

void Bird::updatePosition() {
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight;
    sprite.setPosition(x, y);
}

void Bird::setSprite() {
    if (speed < 10) {
        sprite.setTexture(textures[0]);
    } else {
        sprite.setTexture(textures[1]);
    }
}
