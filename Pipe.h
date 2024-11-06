#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Pipe {
public:
    bool isTop;
    sf::Texture texture;
    sf::Sprite sprite;
    Pipe(std::string kind, bool isTop);
    void updatePosition();
    bool isOffScreen() const;
    int x = 600;
    int y;
    std::string kind;
    bool scored = false;
};
