#include "Bird.h"
#include "Pipe.h"
#include <iostream>

#include "Game.h"


void Bird::flap() {
    speed = lift;
    std::cout << x << y << std::endl;
}
bool ::Bird::checkColissions(Pipe &pipe) {
    if ((pipe.x == x && (pipe.y > y || pipe.y + pipe.gap < y)) || (y <= 0 || y >= maxHeight)) {
        return true;
    }
    return false;
}

void ::Bird::updatePosition(float deltaTime) {
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight - 1;
}

