#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height, const std::string& title, LeaderBoard& board): window(sf::VideoMode(width, height), title), board(board){
    window.setFramerateLimit(40);
    if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    if (!menuTexture.loadFromFile("menu.png")) {
        std::cerr << "No menu" << std::endl;
    }
    menuSprite.setTexture(menuTexture);
    menuSprite.setScale(static_cast<float>(window.getSize().x) / menuTexture.getSize().x,
    static_cast<float>(window.getSize().y) / menuTexture.getSize().y );
    menuSprite.setPosition(0, 0);

    if (!boardTexture.loadFromFile("board.png")) {
        std::cerr << "No menu" << std::endl;
    }
    boardSprite.setTexture(boardTexture);
    boardSprite.setScale(static_cast<float>(window.getSize().x) / boardTexture.getSize().x,
    static_cast<float>(window.getSize().y) / boardTexture.getSize().y );
    boardSprite.setPosition(0, 0);

    if (!gameTexture.loadFromFile("game.png")) {
        std::cerr << "Failed to load background image" << std::endl;
    }
    gameSprite.setTexture(gameTexture);
    gameSprite.setScale(static_cast<float>(window.getSize().x) / gameTexture.getSize().x,
    static_cast<float>(window.getSize().y) / gameTexture.getSize().y );
    gameSprite.setPosition(0, 0);

    if (!startScreenTexture.loadFromFile("startScreen.png")) {
        std::cerr << "Failed to load background image" << std::endl;
    }
    startScreenSprite.setTexture(startScreenTexture);
    startScreenSprite.setScale(static_cast<float>(window.getSize().x) / startScreenTexture.getSize().x,
    static_cast<float>(window.getSize().y) / startScreenTexture.getSize().y );
    startScreenSprite.setPosition(0, 0);

    if (!endScreenTexture.loadFromFile("endScreen.png")) {
        std::cerr << "Failed to load background image" << std::endl;
    }
    endScreenSprite.setTexture(endScreenTexture);
    endScreenSprite.setScale(static_cast<float>(window.getSize().x) / endScreenTexture.getSize().x,
    static_cast<float>(window.getSize().y) / endScreenTexture.getSize().y );
    endScreenSprite.setPosition(0, 0);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    leaderboardText.setFont(font);
    leaderboardText.setCharacterSize(20);
    leaderboardText.setFillColor(sf::Color::White);
    leaderboardText.setPosition(100, 100);
}

Renderer::~Renderer() {
    window.close();
}

void Renderer::clear() {
    window.clear();
}
void Renderer::handleEventsMenu(const sf::Event& event, std::vector<Button*>& buttons, TextField& namePlace) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (namePlace.box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                namePlace.isActive = true;
            } else {
                namePlace.isActive = false;
            }

            for (Button* button : buttons) {
                if (button->sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    button->onClick();
                }
            }
        }
    } else if (event.type == sf::Event::TextEntered && namePlace.isActive) {
        namePlace.handleInput(event.text.unicode);
    }
}

void Renderer::handleEventsLeaderBoard(const sf::Event &event, BackButton button) {
    if (button.sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        button.onClick();
    }
}

void Renderer::handeEventsGame(const sf::Event &event, Bird& bird) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            bird.flap();
        }
    }
}

void Renderer::handleEventsEndScreen(const sf::Event& event, std::vector<Button*> buttons) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (Button* button : buttons) {
                if (button->sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    button->onClick();
                }
            }
        }
    }
}

void Renderer::renderMenu(std::vector<Button*> buttons, TextField& namePlace) {
    clear();
    window.draw(menuSprite);
    for (Button* button : buttons) {
        button->draw(window);
    }
    window.draw(namePlace.box);
    window.draw(namePlace.text);
    window.display();
}

void Renderer::renderLeaderboard(LeaderBoard& board) {
    clear();
    window.draw(boardSprite);
    std::vector<std::pair<std::string, int>> scores = board.display();
    for (size_t i = 0; i < scores.size(); ++i) {
        const auto& playerName = scores[i].first;
        int score = scores[i].second;
        leaderboardText.setString(playerName + ": " + std::to_string(score));
        leaderboardText.setCharacterSize(24);
        leaderboardText.setFillColor(sf::Color::Black);
        leaderboardText.setPosition(100, 50 + i * 30);
        window.draw(leaderboardText);
    }
    board.button.draw(window);
    window.display();
}

void Renderer::renderEndScreen(Score& score, std::vector<Button*> buttons) {
    clear();
    window.draw(endScreenSprite);
    window.draw(scoreText);
    for (Button* button : buttons) {
        button->draw(window);
    }
    window.display();
}

bool Renderer::isOpen() const {
    return window.isOpen();
}

bool Renderer::pollEvent(sf::Event &event) {
    return window.pollEvent(event);
}

void Renderer::close() {
    window.close();
}

void Renderer::renderGame(Bird& bird, std::vector<Pipe>& pipes, Score& score) {
    clear();
    window.draw(gameSprite);
    window.draw(bird.sprite);

    for (auto& pipe : pipes) {
        window.draw(pipe.sprite);
    }

    scoreText.setString("Score: " + std::to_string(score.getScore()));
    window.draw(scoreText);
    window.display();
}

void Renderer::renderStartScreen() {
    clear();
    window.draw(startScreenSprite);
    window.display();
}