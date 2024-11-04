#include "Renderer.h"

#include <iostream>

Renderer::Renderer(int width, int height, const std::string& title, LeaderBoard& board): window(sf::VideoMode(width, height), title), board(board){
    window.setFramerateLimit(25);
    if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    menuText.setFont(font);
    menuText.setCharacterSize(30);
    menuText.setFillColor(sf::Color::Black);
    menuText.setString("Press 1, 2, or 3 for difficulty\nPress 'L' to view leaderboard\nPress 'Q' to quit");
    menuText.setPosition(100, 100);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    endScreenText.setFont(font);
    endScreenText.setCharacterSize(30);
    endScreenText.setFillColor(sf::Color::White);

    leaderboardText.setFont(font);
    leaderboardText.setCharacterSize(20);
    leaderboardText.setFillColor(sf::Color::White);
    leaderboardText.setPosition(100, 100);

    birdShape.setRadius(10);
    birdShape.setFillColor(sf::Color::Yellow);

    pipeShape.setFillColor(sf::Color::Green);
}

Renderer::~Renderer() {
    window.close();
}

void Renderer::clear() {
    window.clear(sf::Color::White);
}
void Renderer::handleEventsMenu(const sf::Event& event, std::vector<Button*> buttons) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (Button* button : buttons) {
                if (button->shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    button->onClick();
                }
            }
        }
    }
}

void Renderer::handleEventsLeaderBoard(const sf::Event &event, BackButton button) {
    if (button.shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
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
                if (button->shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    button->onClick();
                }
            }
        }
    }
}

void Renderer::renderMenu(std::vector<Button*> buttons) {
    clear();
    menuText.setPosition(10, 10);
    window.draw(menuText);
    for (Button* button : buttons) {
        button->draw(window);
    }
    window.display();
}

void Renderer::renderLeaderboard(LeaderBoard& board) {
    clear();
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
    window.draw(scoreText);
    endScreenText.setPosition(10, 40);
    window.draw(endScreenText);
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
    window.clear(sf::Color::White);

    sf::CircleShape birdShape(10);
    birdShape.setFillColor(sf::Color::Yellow);
    birdShape.setPosition(bird.x * 10, bird.y * 10);
    window.draw(birdShape);

    for (const auto& pipe : pipes) {
        drawPipe(pipe);
    }

    scoreText.setString("Score: " + std::to_string(score.getScore()));
    window.draw(scoreText);

    window.display();
}

// void Renderer::renderBorder() {
//     // Draw border rectangle
//     sf::RectangleShape border(sf::Vector2f(maxWidth * 20, maxHeight * 20));
//     border.setOutlineColor(sf::Color::Black);
//     border.setOutlineThickness(5);
//     border.setFillColor(sf::Color::Transparent);
//     window.draw(border);
// }
//
// void Renderer::renderBird(const Bird& bird) {
//     sf::CircleShape birdShape(10); // Shape for the bird
//     birdShape.setFillColor(sf::Color::Yellow);
//     birdShape.setPosition(bird.x * 20, bird.y * 20); // Scale position for rendering
//     window.draw(birdShape);
// }
//
// void Renderer::renderPipes(const std::vector<Pipe>& pipes) {
//     for (const auto& pipe : pipes) {
//         sf::RectangleShape pipeShape(sf::Vector2f(20, maxHeight * 20)); // Assuming pipe width is 20
//         pipeShape.setFillColor(sf::Color::Green);
//         pipeShape.setPosition(pipe.x * 20, 0); // Position pipe
//         window.draw(pipeShape);
//
//         // Draw gap in the pipe
//         sf::RectangleShape gap(sf::Vector2f(20, (pipe.y + pipe.gap) * 20)); // Gap height
//         gap.setFillColor(sf::Cyan);
//         gap.setPosition(pipe.x * 20, pipe.y * 20);
//         window.draw(gap);
//     }
// }
//
// void Renderer::renderScore(const Score& score) {
//     // You can use a text object to display the score
//     sf::Font font;
//     if (!font.loadFromFile("path/to/font.ttf")) {
//         // Handle error
//     }
//
//     sf::Text scoreText;
//     scoreText.setFont(font);
//     scoreText.setString("Score: " + std::to_string(score.getScore()));
//     scoreText.setCharacterSize(24);
//     scoreText.setFillColor(sf::Color::Black);
//     scoreText.setPosition(10, 10); // Position in the window
//
//     window.draw(scoreText);
// }








