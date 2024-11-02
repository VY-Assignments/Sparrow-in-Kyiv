#pragma once
#include <string>
#include "Leaderboard.h"
#include "Bird.h"
#include "Pipe.h"
#include "Score.h"
#include <vector>

#include "Renderer.h"

class LeaderBoard;
const int maxWidth = 40;
const int maxHeight = 20;

class Game {

    int difficulty;
    bool gameRunning = true;
    int pipeSpawnCounter = 0;
    LeaderBoard& board;
public:
    Bird* bird;
    std::vector<Pipe> pipes;
    Score score;
    bool isDisplayed;
    Game(LeaderBoard& board, bool isDisplayed);
    void gameLoop(Renderer& render);
    void update(float deltaTime);
    bool checkCollisions();
    void updateScore();
    void draw();
    void handleInput(Renderer& render);
    void setDifficulty(int level);
    void showMenu();
    void endGame(std::string name);
    std::string getName();
};
