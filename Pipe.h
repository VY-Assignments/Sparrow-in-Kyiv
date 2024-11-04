#pragma once
class Pipe {
public:
    int height;
    int width = 50;
    int gap;
    int x;
    int y;
    Pipe(int startX, int startY, int pipeGap);
    void updatePosition();
    bool isOffScreen();
};
