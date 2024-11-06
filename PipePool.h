#pragma once

#include <vector>
#include "Pipe.h"

class PipePool {
public:
    PipePool();
    void chooseLevel(int level);
    Pipe& getPipe();
    void resetPipe(Pipe& pipe);
    void reset();
private:
    int diff = 0;
    std::vector<Pipe>* pool{};
    Pipe* pipe1;
    Pipe* pipe2;
    Pipe* pipe3;
    Pipe* pipe4;
    Pipe* pipe5;
    Pipe* pipe6;
    Pipe* pipe7;
    Pipe* pipe8;
    Pipe* pipe9;
    Pipe* pipe10;
    Pipe* pipe11;
    Pipe* pipe12;
    Pipe* pipe13;
    Pipe* pipe14;
    Pipe* pipe15;
    Pipe* pipe16;
    Pipe* pipe17;
    Pipe* pipe18;
    Pipe* pipe19;
    Pipe* pipe20;
    Pipe* pipe21;
    Pipe* pipe22;
    Pipe* pipe23;
    Pipe* pipe24;
    Pipe* pipe25;
    Pipe* pipe26;
    size_t currentIndex = 0;
};
