#pragma once
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Pipe.h"

class Bird {
    std::vector<sf::Texture> textures;
    sf::Texture texture;
    const int gravity = 1;
    const int lift = -5;
    void loadTextures();
public:
    sf::Sprite sprite;
    int speed = 0;
    int x = 100;
    int y = 100;
    Bird() {
        loadTextures();
        sprite.setTexture(textures[0]);
        sprite.setScale(100.0f / textures[0].getSize().x,
                        60.0f / textures[0].getSize().y);
        sprite.setPosition(x, y);


    };
    void flap();
    void updatePosition();
    bool checkCollissions(Pipe& pipe);
    bool checkCollisionWithBorders();
    void reset();
};