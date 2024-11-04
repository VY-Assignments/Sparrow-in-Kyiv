#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Pipe {


public:
    bool isTop;
    sf::Texture texture;
    sf::Sprite sprite;
    Pipe(int startX, std::string kind, bool isTop);
    void updatePosition();
    bool isOffScreen();
    int getY() const { return y; }
    int x, y;
    std::string kind;
    bool scored = false;
};
