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
    int currentPipeIndex;
    int nextPipeTime;
    int gameTicks;
    PipePool pipePool;
    Bird bird;
    Score score;
    std::vector<Pipe> pipes;
    void updateScore();
    void setPool(PipePool& pipepool);
public:
    bool gameRunning = false;
    Game();
    void start();
    void update();
    void setDifficulty(int level);

    Bird &getBird() {
        return bird;
    }

    Score& getInstScore() {
        return score;
    }

    int getScore() {
        return score.getIntScore();
    }

    std::vector<Pipe> &getPipes() {
        return pipes;
    }
};
