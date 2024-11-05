#pragma once
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Pipe.h"

class Bird {
    std::vector<sf::Texture> textures;
    sf::Texture texture;
    const int gravity = 1;
    const int lift = -11;
    void loadTextures();
public:
    sf::Sprite sprite;
    int speed = 0;
    int x = 100;
    int y = 100;
    Bird();
    void flap();
    void updatePosition();
    bool checkCollissions(Pipe& pipe);
    bool checkCollisionWithBorders();
    void reset();
    void setSprite();
};