#include "Score.h"
#include <iostream>
void Score::increaseScore() {
    currentScore++;
}

void Score::reset() {
    currentScore = 0;
}

int Score::getScore() {
    return currentScore;
}

