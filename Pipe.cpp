#include "Pipe.h"

#include <iostream>

Pipe::Pipe(int startX, std::string kind, bool isTop)
    : x(startX), kind(kind), isTop(isTop) {

    bool textureLoaded = false;

    if (kind == "green") {
        if (isTop)
            textureLoaded = texture.loadFromFile("C:/Users/kovko/PycharmProjects/Paradigms_Assignment5/asmt-5-game-engine-koalla05/cmake-build-debug/greenPipeTop.png");
        else
            textureLoaded = texture.loadFromFile("C:/Users/kovko/PycharmProjects/Paradigms_Assignment5/asmt-5-game-engine-koalla05/cmake-build-debug/greenPipe.png");
    }
    else if (kind == "yellow") {
        if (isTop)
            textureLoaded = texture.loadFromFile("C:/Users/kovko/PycharmProjects/Paradigms_Assignment5/asmt-5-game-engine-koalla05/cmake-build-debug/yellowPipeTop.png");
        else
            textureLoaded = texture.loadFromFile("C:/Users/kovko/PycharmProjects/Paradigms_Assignment5/asmt-5-game-engine-koalla05/cmake-build-debug/yellowPipe.png");
    }

    if (!textureLoaded) {
        std::cerr << "No texture loaded for " << kind << (isTop ? " top" : " bottom") << " pipe." << std::endl;
        return;
    }

    sprite.setTexture(texture);
    if (kind == "green") sprite.setScale(100.0f / texture.getSize().x, 250.0f / texture.getSize().y);
    else if (kind == "yellow") sprite.setScale(100.0f / texture.getSize().x, 150.0f / texture.getSize().y);

    if (isTop) {
        y = 0;
    } else {
        y = 800 - sprite.getGlobalBounds().height;
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