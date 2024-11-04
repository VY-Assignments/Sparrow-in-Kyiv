#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Game.h"
#include "Pipe.h"
#include "Score.h"

enum class GameAction { Flap, Exit, None };
class Renderer {

    LeaderBoard& board;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text menuText;
    sf::Text scoreText;
    sf::Text endScreenText;
    sf::Text leaderboardText;

    sf::CircleShape birdShape;
    sf::RectangleShape pipeShape;

    void drawPipe(const Pipe& pipe) {
        sf::RectangleShape topPipe(sf::Vector2f(50, pipe.y));
        topPipe.setFillColor(sf::Color::Green);
        topPipe.setPosition(pipe.x, 0);


        sf::RectangleShape bottomPipe(sf::Vector2f(50, window.getSize().y - (pipe.y + pipe.gap)));
        bottomPipe.setFillColor(sf::Color::Green);
        bottomPipe.setPosition(pipe.x, pipe.y + pipe.gap);

        window.draw(topPipe);
        window.draw(bottomPipe);
    }

public:
    Renderer(int width, int height, const std::string &title, LeaderBoard &board);

    ~Renderer();

    void clear();
    void handleEventsMenu(const sf::Event& event, std::vector<Button*> buttons);
    void handleEventsLeaderBoard(const sf::Event& event, BackButton buttons);
    void handeEventsGame(const sf::Event &event, Bird& bird);
    void renderMenu(std::vector<Button*> buttons);
    void renderLeaderboard(LeaderBoard& board);
    void renderGame(Bird& bird, std::vector<Pipe>& pipes, Score& score);
    // void renderBorder();
    // void renderBird(const Bird& bird);
    // void renderPipes(const std::vector<Pipe>& pipes);
    // void renderScore(const Score& score);
    void renderEndScreen(Score& score, std::vector<Button*> buttons);
    void handleEventsEndScreen(const sf::Event& event, std::vector<Button*> buttons);


    bool pollEvent(sf::Event& event);
    bool isOpen() const;
    void close();
};