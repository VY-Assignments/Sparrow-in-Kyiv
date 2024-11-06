#pragma once
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Pipe.h"

class Bird {
    std::vector<sf::Texture> textures;
    sf::Texture texture;
    const int gravity = 1;
    const int lift = -13;
    void loadTextures();
    int tick = 0;
public:
    sf::Sprite sprite;
    int speed = 0;
    int x = 100;
    int y = 100;
    Bird();
    void flap();
    void updatePosition();
    // bool checkCollissions(Pipe& pipe);
    bool checkCollisionWithBorders();
    sf::Color getPixelColor(const sf::Image& image, const sf::Sprite& sprite, int x, int y);
    bool pixelPerfectCollision(const sf::Sprite& sprite2);
    void reset();
    void setSprite();
};