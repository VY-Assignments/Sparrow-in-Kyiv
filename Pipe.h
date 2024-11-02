#pragma once
class Pipe {
public:
    int height;
    int width;
    int gap;
    int x;
    int y;
    Pipe(int startX, int startY, int pipeGap);
    void updatePosition(float deltaTime);
    bool isOffScreen();
};
