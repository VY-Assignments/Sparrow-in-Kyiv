#pragma once

class Score {
    int currentScore = 0;
public:
    void increaseScore();
    void reset();
    int getScore();
};