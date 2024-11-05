#include "PipePool.h"

#include <iostream>

PipePool::PipePool() {
    pool1.emplace_back(600, "green", false);
    pool2.emplace_back(600, "green", true);
    pool3.emplace_back(600, "yellow", false);
    pool4.emplace_back(600, "yellow", true);

    // pool1.emplace_back(600, "green", false);
    // pool1.emplace_back(600, "green", true);
    // pool1.emplace_back(600, "green", false);
    // pool1.emplace_back(600, "green", true);
    // pool1.emplace_back(600, "green", false);
    // // pool1.emplace_back(600, "green", true);
    // // pool1.emplace_back(600, "green", false);
    // // pool1.emplace_back(600, "green", true);
    //
    // pool2.emplace_back(600, "yellow", false);
    // pool2.emplace_back(600, "yellow", true);
    // // pool2.emplace_back(600, "yellow", false);
    // // pool2.emplace_back(600, "yellow", true);
    //
    // pool3.emplace_back(600, "green", false);
    // pool3.emplace_back(600, "green", true);
    // pool3.emplace_back(600, "yellow", false);
    // pool3.emplace_back(600, "yellow", true);

}

Pipe& PipePool::getPipe() {
    if (diff == 1) {
        if (currentIndex == 0) {
            currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool3[0];
            return pipe;
        }
        else if (currentIndex == 1) {
            currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool4[0];
            return pipe;
        }
    }
    else if (diff == 2) {
        if (currentIndex == 0) {
            currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool1[0];
            return pipe;
        }
        else if (currentIndex == 1) {
            currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool2[0];
            return pipe;
        }
    }

    else if (diff == 3) {
        if (currentIndex == 0) {
            currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool1[0];
            return pipe;
        }
        else if (currentIndex == 1) {
            currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool2[0];
            return pipe;
        }
        else if (currentIndex == 2) {
            currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool3[0];
            return pipe;
        }
        else {
            currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separetely)
            Pipe& pipe = pool4[0];
            return pipe;
        }
    }

}

void PipePool::resetPipe(Pipe& pipe) {
    pipe.scored = false;
}
void PipePool::reset() {
    pool = nullptr;
}

void PipePool::chooseLevel(int level) {
    diff = level;
    // if (level == 1) pool = &pool1;
    // else if (level == 2) pool = &pool2;
    // else pool = &pool3;
}

