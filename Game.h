#pragma once
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Game.h"
#include "Pipe.h"
#include "Score.h"
#include <vector>

const int maxWidth = 40;
const int maxHeight = 20;

class Game {
    Bird* bird;
    std::vector<Pipe> pipes;
    int difficulty;
    Score score;
    bool gameRunning = true;
    int pipeSpawnCounter = 0;
    LeaderBoard board;
public:
    Game(LeaderBoard& board);
    void start();
    void gameLoop();
    void update(float deltaTime);
    bool checkCollisions();
    void updateScore();
    void draw();
    void handleInput();
    void setDifficulty(int level);
    void showMenu();
    void endGame(std::string name);
    std::string getName();
};
