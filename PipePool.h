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
    std::vector<Pipe> pool1;
    std::vector<Pipe> pool2;
    std::vector<Pipe> pool3;
    std::vector<Pipe> pool4;
    size_t currentIndex = 0;
};
