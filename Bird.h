#pragma once
#include "Pipe.h"

class Bird {
    int speed = 0;
    const int gravity = 1;
    const int lift = -5;
public:
    int x;
    int y;
    Bird(int inX, int inY): x(inX), y(inY){};
    void flap();
    void updatePosition();
    bool checkColissions(Pipe& pipe);
    bool checkColisionWithBorders();
    void reset();
};