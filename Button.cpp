#include "Button.h"
#include <iostream>
#include <stdexcept>

Button::Button(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position)
    : label(label) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Green);

    if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 10, position.y + 10);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

DifficultyButton::DifficultyButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, int& difficulty)
    : Button(label, size, position), difficulty(difficulty) {}

void DifficultyButton::onClick() {
    if (label == "Easy") {
        difficulty = 1;
    }
    else if (label == "Medium") {
        difficulty = 2;
    }
    else {
        difficulty = 3;
    }
}

LeaderBoardButton::LeaderBoardButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, bool& isDisplayed)
    : Button(label, size, position), isDisplayed(isDisplayed) {}

void LeaderBoardButton::onClick() {
    std::cout << "Leaderboard button clicked. isDisplayed set to true." << std::endl;
    isDisplayed = true;
}

BackButton::BackButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, bool& isDisplayed)
    : Button(label, size, position), isDisplayed(isDisplayed) {}

void BackButton::onClick() {
    isDisplayed = false;
}
