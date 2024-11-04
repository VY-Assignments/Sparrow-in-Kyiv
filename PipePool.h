#pragma once

#include <vector>
#include "Pipe.h"

class PipePool {
public:
    PipePool(size_t poolSize);
    Pipe& getPipe();
    void resetPipe(Pipe& pipe);

private:
    std::vector<Pipe> pool;
    size_t currentIndex;
};
