#include "PipePool.h"

PipePool::PipePool(size_t poolSize) : currentIndex(0) {
    pool.reserve(poolSize);
    pool.emplace_back(600, "green", false);
    pool.emplace_back(600, "green", true);
    // pool.emplace_back(600, "green", false);
    // pool.emplace_back(600, "green", true);
    // pool.emplace_back(600, "green", false);
    // pool.emplace_back(600, "green", true);
    // pool.emplace_back(600, "green", false);
    // pool.emplace_back(600, "green", true);
    // pool.emplace_back(600, "green", false);
    // pool.emplace_back(600, "green", true);
    pool.emplace_back(600, "yellow", false);
    pool.emplace_back(600, "yellow", true);
    // pool.emplace_back(600, "yellow", false);
    // pool.emplace_back(600, "yellow", true);
    // pool.emplace_back(600, "yellow", false);
    // pool.emplace_back(600, "yellow", true);
    // pool.emplace_back(600, "yellow", false);
    // pool.emplace_back(600, "yellow", true);
    // pool.emplace_back(600, "yellow", false);
    // pool.emplace_back(600, "yellow", true);

}

Pipe& PipePool::getPipe() {
    Pipe& pipe = pool[currentIndex];
    currentIndex = (currentIndex + 1) % pool.size();
    return pipe;
}

void PipePool::resetPipe(Pipe& pipe) {
    pipe.scored = false;
}