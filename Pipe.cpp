#include "Pipe.h"

Pipe::Pipe(int startX, int startY, int pipeGap) : x(startX), y(startY), gap(pipeGap) {}
void Pipe::updatePosition(float deltaTime) {
    x -= 1;
}
bool Pipe::isOffScreen() {
    return x < 0;
}
