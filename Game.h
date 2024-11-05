#pragma once
#include "Bird.h"
#include "Pipe.h"
#include "Score.h"
#include <vector>
#include "PipePool.h"

class LeaderBoard;
const int maxWidth = 600;
const int maxHeight = 800;

class Game {
    int difficulty;
    int pipeSpawnCounter = 0;
public:
    bool gameRunning = false;
    Bird bird;
    Score score;
    Game();
    void start();
    void update();
    void updateScore();
    void setDifficulty(int level);
    std::vector<Pipe> pipes;
    PipePool pipePool;
    int currentPipeIndex;
    int nextPipeTime;
    int gameTicks;
    void setPool(PipePool& pipepool);
};
