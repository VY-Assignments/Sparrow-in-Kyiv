#include <iostream>
#include <vector>

class Pipe {
    int height;
    int width;
    int gap;

public:
    int x;
    int y;
    Pipe(): x(0), y(5) {}
    void updatePosition(float deltaTime);
    bool isOffScreen();
};

class Bird {
    float speed;
    float velocity;
    const int gravity = 1;
    const int lift = 1;
public:
    int x;
    int y;
    Bird(int inX, int inY): x(inX), y(inY){};
    void flap();
    void updatePosition(float deltaTime);
    bool checkColissions(Pipe* pipe) {
        if (pipe -> x == x && pipe -> y == y) {
            return true;
        }
        return false;
    }
};

class Score {
    int currentScore;
public:
    void increaseScore() {
        currentScore++;
    }
    void display() {
        std::cout << currentScore << std::endl;
    }
};

class EndScreen {
    int score = 0;
public:
    void show();
    void goMenu();
    void endGame();
    void restartGame();
};

class Game {
    Bird* bird;
    std::vector<Pipe*> pipes;
    int difficulty;
    Score score;
    bool pipeInterval = true;
public:
    Game() {
        bird = new Bird(10, 10);
    }
    void start() {
        if (pipeInterval) {
            pipes.push_back(new Pipe());
        }
    }
    void update(float deltaTime);
    bool checkCollisions() {
        for (auto& pipe: pipes) {
            if (bird->checkColissions(pipe)) {
                endGame();
            }
            else {
                updateScore();
            }
        }

    };
    void updateScore() {
        score.increaseScore();
    }
    void draw();
    void handleInput();
    void setDifficulty(int& level);
    void showMenu();
    void endGame();
};

int main() {
    Game game;
    game.start();
    return 0;
}

