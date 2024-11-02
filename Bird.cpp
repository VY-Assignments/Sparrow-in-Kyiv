#include "Bird.h"
#include "Pipe.h"
#include <iostream>

#include "Game.h"


void Bird::flap() {
    speed = lift;
    std::cout << x << y << std::endl;
}
bool ::Bird::checkColissions(Pipe &pipe) {
    return pipe.x == x && (pipe.y > y || pipe.y + pipe.gap < y);
}

bool Bird::checkColisionWithBorders() {
    return y <= 0 || y >= maxHeight;
}

void ::Bird::updatePosition(float deltaTime) {
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight;
}

