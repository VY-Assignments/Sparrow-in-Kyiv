#include "Pipe.h"

#include <iostream>

Pipe::Pipe(std::string kind, bool isTop)
    : kind(kind), isTop(isTop) {

    bool textureLoaded;

    if (isTop)
        textureLoaded = texture.loadFromFile(kind+"Top.png");
    else
        textureLoaded = texture.loadFromFile(kind+".png");

    if (!textureLoaded) {
        std::cerr << "No texture loaded for " << kind << (isTop ? " top" : " bottom") << " pipe." << std::endl;
        return;
    }

    sprite.setTexture(texture);
    if (kind == "flag") sprite.setScale(100.0f / texture.getSize().x, 240.0f / texture.getSize().y);
    else if (kind == "mother") sprite.setScale(100.0f / texture.getSize().x, 250.0f / texture.getSize().y);
    else if (kind == "veza") sprite.setScale(50.0f / texture.getSize().x, 260.0f / texture.getSize().y);
    else if (kind == "korona") sprite.setScale(150.0f / texture.getSize().x, 250.0f / texture.getSize().y);
    else if (kind == "lavra") sprite.setScale(300.0f / texture.getSize().x, 200.0f / texture.getSize().y);
    else if (kind == "zoloti") sprite.setScale(250.0f / texture.getSize().x, 140.0f / texture.getSize().y);
    else if (kind == "triumf") sprite.setScale(170.0f / texture.getSize().x, 250.0f / texture.getSize().y);
    else if (kind == "palaz") sprite.setScale(400.0f / texture.getSize().x, 120.0f / texture.getSize().y);
    else if (kind == "kse") sprite.setScale(240.0f / texture.getSize().x, 230.0f / texture.getSize().y);
    else if (kind == "kmda") sprite.setScale(280.0f / texture.getSize().x, 190.0f / texture.getSize().y);
    else if (kind == "hymera") sprite.setScale(240.0f / texture.getSize().x, 180.0f / texture.getSize().y);
    else if (kind == "arka") sprite.setScale(250.0f / texture.getSize().x, 150.0f / texture.getSize().y);
    else if (kind == "river") sprite.setScale(330.0f / texture.getSize().x, 180.0f / texture.getSize().y);

    if (isTop) {
        y = 0;
    } else {
        y = 760 - sprite.getGlobalBounds().height;
    }

    sprite.setPosition(x, y);
}


void Pipe::updatePosition() {
    x -= 1;
    sprite.setPosition(x, y);
}

bool Pipe::isOffScreen() {
    return x + sprite.getGlobalBounds().width < 0;
}

std::vector<sf::FloatRect> Pipe::getPipeHitboxes() {
    std::vector<sf::FloatRect> hitboxes;
    sf::FloatRect bounds = sprite.getGlobalBounds();

    float halfWidth = bounds.width / 2;
    float halfHeight = bounds.height / 2;

    float thirdWidth = bounds.width / 3;
    float thirdHeight = bounds.height / 3;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            hitboxes.emplace_back(
                bounds.left + col * thirdWidth,   // x position
                bounds.top + row * thirdHeight,   // y position
                thirdWidth,                       // width
                thirdHeight                       // height
            );
        }
    }

    return hitboxes;
}