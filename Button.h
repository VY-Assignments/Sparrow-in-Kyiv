#pragma once
#include <string>
#include <SFML/Graphics.hpp>

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
    bool& isDisplayed;
public:
    LeaderBoardButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, bool& isDisplayed);
    void onClick() override;
};

class BackButton : public Button {
    bool& isDisplayed;
public:
    BackButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, bool& isDisplayed);
    void onClick() override;
};



class DifficultyButton : public Button {
    int& difficulty;
public:
    DifficultyButton(const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position, int& difficulty);
    void onClick() override;
};