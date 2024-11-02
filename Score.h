#pragma once

class Score {
    int currentScore = 0;
public:
    void increaseScore();
    void display() const;
    void reset();
    int getScore();
};