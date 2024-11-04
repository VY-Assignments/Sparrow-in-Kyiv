#include "Pipe.h"

Pipe::Pipe(int startX, int startY, int pipeGap) : x(startX), y(startY), gap(pipeGap) {}
void Pipe::updatePosition() {
    x -= 1;
}
bool Pipe::isOffScreen() {
    return x + width < 0;
}
