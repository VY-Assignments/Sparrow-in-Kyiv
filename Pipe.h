#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Pipe {


public:
    bool isTop;
    sf::Texture texture;
    sf::Sprite sprite;
    Pipe(std::string kind, bool isTop);
    std::vector<sf::FloatRect> getPipeHitboxes();
    void updatePosition();
    bool isOffScreen();
    int x = 600;
    int y;
    std::string kind;
    bool scored = false;
};
