#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextField {
    sf::Font font;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    bool isActive;
    sf::RectangleShape box;
    sf::Text text;
    TextField(const sf::Vector2f& size, const sf::Vector2f& position): position(position), size(size)  {
        box.setPosition(position);
        box.setSize(size);
        box.setFillColor(sf::Color::White);
        sf::Color brown(51, 25, 0);
        box.setOutlineColor(brown);
        box.setOutlineThickness(2);

        if (!font.loadFromFile("alphabetized cassette tapes.ttf")) {
        }
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position.x + 5, position.y - 6);

        isActive = false;
    }


    void handleInput(sf::Uint32 unicode) {
        if (unicode == '\b' && !text.getString().isEmpty()) {
            std::string str = text.getString();
            str.pop_back();
            text.setString(str);
        } else if (unicode < 128 && unicode > 31) {
            text.setString(text.getString() + static_cast<char>(unicode));
        }
    }

    std::string getText() const {
        return text.getString();
    }
};