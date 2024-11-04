#include "Button.h"
#include <iostream>
#include <stdexcept>

#include "Menu.h"
enum class GameState;

Button::Button(const std::string& label, const sf::Vector2f& position)
    : label(label) {
    if (!texture.loadFromFile("button.png")) {
        throw std::runtime_error("Failed to load texture");
    }

    sprite.setTexture(texture);
    sprite.setScale(200.f / texture.getSize().x, 80.f / texture.getSize().y);
    sprite.setPosition(position);

    if (!font.loadFromFile("brushed.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(position.x + sprite.getGlobalBounds().width / 2, position.y + sprite.getGlobalBounds().height / 2);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(text);
}

DifficultyButton::DifficultyButton(const std::string& label, const sf::Vector2f& position, int& difficulty, GameState& state)
    : Button(label, position), difficulty(difficulty), state(state) {}

void DifficultyButton::onClick() {
    state = GameState::Game;
    if (label == "Easy") {
        difficulty = 1;
        std::cout << "yes";
    }
    else if (label == "Medium") {
        difficulty = 2;
    }
    else {
        difficulty = 3;
    }
}

LeaderBoardButton::LeaderBoardButton(const std::string& label, const sf::Vector2f& position, GameState& state)
    : Button(label, position), state(state) {}

void LeaderBoardButton::onClick() {
    std::cout << "Leaderboard button clicked. isDisplayed set to true." << std::endl;
    state = GameState::LeaderBoard;
}

BackButton::BackButton(const std::string& label, const sf::Vector2f& position, GameState& state)
    : Button(label, position), state(state) {}

void BackButton::onClick() {
    std::cout << "yes";
    state = GameState::Menu;
}

MenuButton::MenuButton(const std::string &label, const sf::Vector2f &position, GameState &state): Button(label, position), state(state) {}

void MenuButton::onClick() {
    state = GameState::Menu;
}
RestartButton::RestartButton(const std::string &label, const sf::Vector2f &position, GameState &state): Button(label, position), state(state) {}

void RestartButton::onClick() {
    state = GameState::Game;
}

EndButton::EndButton(const std::string &label, const sf::Vector2f &position, GameState &state): Button(label, position), state(state) {}

void EndButton::onClick() {
    exit(0);
}