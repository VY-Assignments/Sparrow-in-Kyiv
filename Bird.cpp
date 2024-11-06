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
        "birdF1.png"
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
// bool ::Bird::checkCollissions(Pipe &pipe) {
//     // return sprite.getGlobalBounds().intersects(pipe.sprite.getGlobalBounds());
// }


sf::Color Bird::getPixelColor(const sf::Image& image, const sf::Sprite& sprite, int x, int y) {
    int localX = x - sprite.getGlobalBounds().left;
    int localY = y - sprite.getGlobalBounds().top;

    localX /= sprite.getScale().x;
    localY /= sprite.getScale().y;

    return image.getPixel(localX, localY);
}

bool Bird::pixelPerfectCollision(const sf::Sprite& sprite2) {
    sf::FloatRect intersection;

    if (!sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds(), intersection)) {
        return false;
    }

    const sf::Image& image1 = sprite.getTexture()->copyToImage();
    const sf::Image& image2 = sprite2.getTexture()->copyToImage();

    for (int x = intersection.left; x < intersection.left + intersection.width; ++x) {
        for (int y = intersection.top; y < intersection.top + intersection.height; ++y) {
            if (getPixelColor(image1, sprite, x, y).a > 0 &&
                getPixelColor(image2, sprite2, x, y).a > 0) {
                return true;
                }
        }
    }

    return false;
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
    tick = (tick + 1) % 13;
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight;
    sprite.setPosition(x, y);
}

void Bird::setSprite() {
    if (speed < 13) {
        if (tick < 7) {
            sprite.setTexture(textures[2]);
        }
        else {
            sprite.setTexture(textures[0]);
        }
    } else {
        sprite.setTexture(textures[1]);
    }
}
