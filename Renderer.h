#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Pipe.h"
#include "Score.h"
#include "TextField.h"

enum class GameAction { Flap, Exit, None };
class Renderer {
    LeaderBoard& board;
    sf::RenderWindow window;
    sf::Font font;
    sf::Texture menuTexture;
    sf::Sprite menuSprite;

    sf::Texture boardTexture;
    sf::Sprite boardSprite;

    sf::Texture startScreenTexture;
    sf::Sprite startScreenSprite;

    sf::Texture gameTexture;
    sf::Sprite gameSprite;

    sf::Texture endScreenTexture;
    sf::Sprite endScreenSprite;

    sf::Text scoreText;
    sf::Text leaderboardText;


public:
    Renderer(int width, int height, const std::string &title, LeaderBoard &board);

    ~Renderer();

    void clear();
    void handleEventsMenu(const sf::Event& event, std::vector<Button*>& buttons, TextField& namePlace);
    void handleEventsLeaderBoard(const sf::Event& event, BackButton buttons);
    void handeEventsGame(const sf::Event &event, Bird& bird);
    void renderMenu(std::vector<Button*> buttons, TextField& namePlace);
    void renderLeaderboard(LeaderBoard& board);
    void renderGame(Bird& bird, std::vector<Pipe>& pipes, Score& score);
    void renderEndScreen(Score& score, std::vector<Button*> buttons);
    void handleEventsEndScreen(const sf::Event& event, std::vector<Button*> buttons);
    void renderStartScreen();

    bool pollEvent(sf::Event& event);
    bool isOpen() const;
    void close();
};