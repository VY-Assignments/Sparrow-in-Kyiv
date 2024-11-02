#include "Score.h"
#include <iostream>
void Score::increaseScore() {
    currentScore++;
}

void Score::display() const {
    std::cout << "Score " << currentScore << std::endl;
}

void Score::reset() {
    currentScore = 0;
}

int Score::getScore() {
    return currentScore;
}

