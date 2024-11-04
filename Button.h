#pragma once
#include <string>
#include <SFML/Graphics.hpp>
enum class GameState;

class Button {
protected:
    sf::Font font;
public:
    std::string label;
    sf::RectangleShape shape;
    sf::Text text;

    Button(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position);
    virtual void onClick() = 0;
    void draw(sf::RenderWindow& window);
    virtual ~Button() {}
};

class LeaderBoardButton : public Button {
    GameState& state;
public:
    LeaderBoardButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state);
    void onClick() override;
};

class BackButton : public Button {
    GameState& state;
public:
    BackButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state);
    void onClick() override;
};



class DifficultyButton : public Button {
    GameState& state;
    int& difficulty;
public:
    DifficultyButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, int& difficulty, GameState& state);
    void onClick() override;
};

class MenuButton: public Button {
    GameState& state;
public:
    MenuButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state);
    void onClick() override;
};

class RestartButton: public Button {
    GameState& state;
public:
    RestartButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state);
    void onClick() override;
};

class EndButton: public Button {
    GameState& state;
public:
    EndButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, GameState& state);
    void onClick() override;
};