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
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(1);

        if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position.x + 5, position.y + 5);

        isActive = false;
    }


    void handleInput(sf::Uint32 unicode) {
        if (unicode == '\b' && !text.getString().isEmpty()) { // Handle backspace
            std::string str = text.getString();
            str.pop_back();
            text.setString(str);
        } else if (unicode < 128 && unicode > 31) { // Handle printable characters
            text.setString(text.getString() + static_cast<char>(unicode));
        }
    }

    // void handleEvent(const sf::Event& event) {
    //    //     if (event.type == sf::Event::MouseButtonPressed) {
    //    //         isActive = box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
    //    //     } else if (event.type == sf::Event::TextEntered && isActive) {
    //    //         if (event.text.unicode == '\b' && !text.getString().isEmpty()) {
    //    //             std::string str = text.getString();
    //    //             str.pop_back();
    //    //             text.setString(str);
    //    //         } else if (event.text.unicode < 128 && event.text.unicode > 31) { // Ignore non-printable characters
    //    //             text.setString(text.getString() + static_cast<char>(event.text.unicode));
    //    //         }
    //    //     }
    //    // }
    //    //
    //    // void draw(sf::RenderWindow& window) {
    //    //     window.draw(box);
    //    //     window.draw(text);
    //    // }

    std::string getText() const {
        return text.getString();
    }
};