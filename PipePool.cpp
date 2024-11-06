#include "PipePool.h"

#include <iostream>

PipePool::PipePool() {
    // pool1.emplace_back(600, "green", false);
    // pool2.emplace_back(600, "green", true);
    // pool3.emplace_back(600, "yellow", false);
    // pool4.emplace_back(600, "yellow", true);


    pipe1 = new Pipe( "veza", false);
    pipe2 = new Pipe("veza", true);
    pipe3 = new Pipe("flag", false);
    pipe4 = new Pipe("flag", true);
    pipe5 = new Pipe("mother", false);
    pipe6 = new Pipe("mother", true);
    pipe13 = new Pipe("korona", false);
    pipe14 = new Pipe("korona", true);

    pipe9 = new Pipe("lavra", false);
    pipe10 = new Pipe("lavra", true);
    pipe11 = new Pipe("arka", false);
    pipe12 = new Pipe("arka", true);
    pipe7 = new Pipe("triumf", false);
    pipe8 = new Pipe("triumf", true);
    pipe15 = new Pipe("zoloti", false);
    pipe16 = new Pipe("zoloti", true);

    pipe17 = new Pipe("palaz", false);
    pipe18 = new Pipe("palaz", true);
    pipe19 = new Pipe("kmda", false);
    pipe20 = new Pipe("kmda", true);
    pipe21 = new Pipe("kse", false);
    pipe22 = new Pipe("kse", true);
    pipe23 = new Pipe("river", false);
    pipe24 = new Pipe("river", true);
    pipe25 = new Pipe("hymera", false);
    pipe26 = new Pipe("hymera", true);
}

Pipe& PipePool::getPipe() {
    switch (diff) {
        case 1:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe17);
                case 1:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe18);
                case 2:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe19);
                case 3:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe20);
                case 4:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe21);
                case 5:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe22);
                case 6:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe23);
                case 7:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe24);
                case 8:
                    currentIndex = (currentIndex + 1) % 10;
                return (*pipe25);
                case 9:
                    currentIndex = (currentIndex + 1) % 10; // number of different pipes (top and bottom separately)
                return (*pipe26);
            }
        break;

        case 2:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe9);
                case 1:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe10);
                case 2:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe11);
                case 3:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe12);
                case 4:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe13);
                case 5:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe14);
                case 6:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe15);
                case 7:
                    currentIndex = (currentIndex + 1) % 8; // number of different pipes (top and bottom separately)
                return (*pipe16);
            }
        break;

        case 3:
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe1);
                case 1:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe2);
                case 2:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe3);
                case 3:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe4);
                case 4:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe5);
                case 5:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe6);
                case 6:
                    currentIndex = (currentIndex + 1) % 8;
                return (*pipe7);
                case 7:
                    currentIndex = (currentIndex + 1) % 8; // number of different pipes (top and bottom separately)
                return (*pipe8);
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

