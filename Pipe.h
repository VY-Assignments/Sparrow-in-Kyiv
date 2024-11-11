#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

struct Pipe {
    sf::Texture texture;
    sf::Sprite sprite;
    std::string kind;
    int x = 600;
    int y;
    bool isTop;
    bool scored = false;

    Pipe(std::string kind, bool isTop);
    void updatePosition();
    bool isOffScreen() const;
};
