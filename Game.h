#pragma once
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Pipe.h"
#include "Score.h"
#include <vector>

class LeaderBoard;
const int maxWidth = 600;
const int maxHeight = 800;

class Game {

    int difficulty;

    int pipeSpawnCounter = 0;
    LeaderBoard& board;
public:
    bool gameRunning = false;
    Bird bird;
    std::vector<Pipe> pipes;
    Score score;
    Game(LeaderBoard& board);
    void start();
    //void gameLoop();
    void update();
    bool checkCollisions();
    void updateScore();
    void setDifficulty(int level);
    void showMenu();
    void endGame(std::string name);
    std::string getName();
};
