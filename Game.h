#pragma once
#include <string>
#include "Leaderboard.h"
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
    std::vector<Pipe> pipesEasy;
    std::vector<Pipe> pipesMedium;
    std::vector<Pipe> pipesHard;
    Score score;
    Game();
    void start();
    void update();
    void updateScore();
    void setDifficulty(int level);
    std::vector<Pipe> pipes;
    std::vector<Pipe> currentPipes;
    PipePool pipePool;
    int currentPipeIndex;
    int nextPipeTime;
    int gameTicks;
};
