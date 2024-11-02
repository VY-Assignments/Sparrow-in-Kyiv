#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Leaderboard.h"
#include "Menu.h"
#include "Game.h"
#include "EndScreen.h"

class Renderer {
    Menu& menu;
    Game& game;
    LeaderBoard& board;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text menuText;
    sf::Text scoreText;
    sf::Text endScreenText;
    sf::Text leaderboardText;

    sf::CircleShape birdShape;
    sf::RectangleShape pipeShape;
public:
    Renderer(int width, int height, const std::string &title, LeaderBoard &board, Menu &menu);

    ~Renderer();

    void clear();
    void handleEvents(const sf::Event& event);
    void renderMenu();
    void renderGame(Game& game);
    void renderBorder();
    void renderBird();
    void renderPipe();
    void renderScore();
    // void renderEndScreen(Score& score);
    void renderLeaderboard();

    bool pollEvent(sf::Event& event);
    bool isOpen() const;
    void close();
};