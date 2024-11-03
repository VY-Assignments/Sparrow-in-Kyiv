#include "Button.h"
#include <iostream>
#include <stdexcept>

#include "Menu.h"
enum class GameState;

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

DifficultyButton::DifficultyButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, int& difficulty, GameState& state)
    : Button(label, size, position), difficulty(difficulty), state(state) {}

void DifficultyButton::onClick() {
    state = GameState::Game;
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

LeaderBoardButton::LeaderBoardButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state)
    : Button(label, size, position), state(state) {}

void LeaderBoardButton::onClick() {
    std::cout << "Leaderboard button clicked. isDisplayed set to true." << std::endl;
    state = GameState::LeaderBoard;
}

BackButton::BackButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state)
    : Button(label, size, position), state(state) {}

void BackButton::onClick() {
    std::cout << "yes";
    state = GameState::Menu;
}
