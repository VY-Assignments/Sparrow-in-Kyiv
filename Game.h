#pragma once
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Pipe.h"
#include "Score.h"
#include <vector>

class LeaderBoard;
const int maxWidth = 40;
const int maxHeight = 20;

class Game {

    int difficulty;

    int pipeSpawnCounter = 0;
    LeaderBoard& board;
public:
    bool gameRunning = true;
    Bird bird;
    std::vector<Pipe> pipes;
    Score score;
    Game(LeaderBoard& board);
    void gameLoop();
    void update(float deltaTime);
    bool checkCollisions();
    void updateScore();
    void setDifficulty(int level);
    void showMenu();
    void endGame(std::string name);
    std::string getName();
};
