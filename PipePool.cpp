#include "PipePool.h"

#include <iostream>

PipePool::PipePool() {
    // pool1.emplace_back(600, "green", false);
    // pool2.emplace_back(600, "green", true);
    // pool3.emplace_back(600, "yellow", false);
    // pool4.emplace_back(600, "yellow", true);
    pipe1 = new Pipe(600, "green", false);
    pipe2 = new Pipe(600, "green", true);
    pipe3 = new Pipe(600, "yellow", false);
    pipe4 = new Pipe(600, "yellow", true);

}

Pipe& PipePool::getPipe() {
    switch (diff) {
        case 1:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separately)
                return (*pipe3);
                case 1:
                    currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separately)
                return (*pipe4);
            }
        break;

        case 2:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separately)
                return (*pipe1);
                case 1:
                    currentIndex = (currentIndex + 1) % 2; // number of different pipes (top and bottom separately)
                return (*pipe2);
            }
        break;

        case 3:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separately)
                return (*pipe1);
                case 1:
                    currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separately)
                return (*pipe2);
                case 2:
                    currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separately)
                return (*pipe3);
                case 3:
                    currentIndex = (currentIndex + 1) % 4; // number of different pipes (top and bottom separately)
                return (*pipe4);
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

