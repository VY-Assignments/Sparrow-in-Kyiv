#pragma once
#include "Pipe.h"

class Bird {
    int speed = 0;
    const int gravity = 1;
    const int lift = -3;
public:
    int x;
    int y;
    Bird(int inX, int inY): x(inX), y(inY){};
    void flap();
    void updatePosition(float deltaTime);
    bool checkColissions(Pipe& pipe);
};