#include "Bird.h"
#include "Pipe.h"
#include <iostream>

#include "Game.h"

void Bird::reset() {
    x = 10;
    y = 10;
}

void Bird::flap() {
    speed = lift;
}
bool ::Bird::checkColissions(Pipe &pipe) {
    float birdRadius = 10;
    int birdLeft = (x * 10);
    int birdRight = (x * 10) + 2 * birdRadius;
    int birdTop = (y * 10);
    int birdBottom = (y * 10) + 2 * birdRadius;

    // Pipe boundaries
    int pipeLeft = pipe.x;
    int pipeRight = pipe.x + pipe.width;
    int pipeTop = pipe.y;
    int pipeBottom = pipe.y + pipe.gap;
    std::cout << pipeLeft << "," << pipeRight << "," << pipeTop << "," << pipeBottom << "," << pipe.gap <<std::endl;
    std::cout << pipeTop << std::endl;
    bool horizontalCollisions = birdRight >= pipeLeft && birdLeft <= pipeRight;
    bool sideCollision = (birdTop <= pipeTop || birdBottom >= pipeBottom);

    if (horizontalCollisions && sideCollision) {
        std::cout << "Collision detected!" << " Bird: " << birdLeft << "," << birdTop << "," << birdBottom<< " Pipe: " << pipeLeft << "," << pipeTop << " " << pipe.y << std::endl;
        return true; // Collision detected
    }

    return false; // No collision
}

bool Bird::checkColisionWithBorders() {
    if ((y * 10) <= 0 || (y * 10 + 2 * 10) >= maxHeight) {
         std::cout << "yes" << y;
    }

    return (y * 10) <= 0 || (y * 10) >= maxHeight - 10;

}

void ::Bird::updatePosition() {
    speed += gravity;
    y += speed;
    if (y < 0) y = 0;
    if (y >= maxHeight) y = maxHeight;
}

