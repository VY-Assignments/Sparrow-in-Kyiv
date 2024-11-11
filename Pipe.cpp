#include "Pipe.h"

#include <iostream>

Pipe::Pipe(std::string kind, bool isTop): kind(kind), isTop(isTop) {

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
    else if (kind == "veza") sprite.setScale(90.0f / texture.getSize().x, 260.0f / texture.getSize().y);
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
    x -= 2;
    sprite.setPosition(x, y);
}

bool Pipe::isOffScreen() const {
    return x + sprite.getGlobalBounds().width < 0;
}

