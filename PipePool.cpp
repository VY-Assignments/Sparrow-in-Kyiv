#include "PipePool.h"

PipePool::PipePool(size_t poolSize) : currentIndex(0) {
    pool.reserve(poolSize);
    for (size_t i = 0; i < poolSize; i+=4) {
        pool.emplace_back(600, "green", false); // You can initialize with default values or leave it
        pool.emplace_back(600, "green", true);
        pool.emplace_back(600, "yellow", false); // You can initialize with default values or leave it
        pool.emplace_back(600, "yellow", true);
    }
}

Pipe& PipePool::getPipe() {
    Pipe& pipe = pool[currentIndex];
    currentIndex = (currentIndex + 1) % pool.size(); // Cycle through the pool
    return pipe;
}

void PipePool::resetPipe(Pipe& pipe) {
    // Reset the pipe's properties as needed before reusing
    pipe.scored = false; // Assuming you have a reset method in your Pipe class
}