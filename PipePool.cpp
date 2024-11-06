#include "PipePool.h"

#include <iostream>

PipePool::PipePool() {
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
            if (currentIndex % 2 == 1) currentIndex = (std::rand() % 5) * 2;
            else currentIndex++;
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex) ;
                return (*pipe17);
                case 1:
                    currentIndex = (currentIndex) ;
                return (*pipe18);
                case 2:
                    currentIndex = (currentIndex) ;
                return (*pipe19);
                case 3:
                    currentIndex = (currentIndex) ;
                return (*pipe20);
                case 4:
                    currentIndex = (currentIndex) ;
                return (*pipe21);
                case 5:
                    currentIndex = (currentIndex) ;
                return (*pipe22);
                case 6:
                    currentIndex = (currentIndex) ;
                return (*pipe23);
                case 7:
                    currentIndex = (currentIndex);
                return (*pipe24);
                case 8:
                    currentIndex = (currentIndex) ;
                return (*pipe25);
                case 9:
                    currentIndex = (currentIndex) ; // number of different pipes (top and bottom separately)
                return (*pipe26);
            }
        break;

        case 2:
            if (currentIndex % 2 == 1) currentIndex = (std::rand() % 4) * 2;
            else currentIndex++;
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex);
                return (*pipe9);
                case 1:
                    currentIndex = (currentIndex);
                return (*pipe10);
                case 2:
                    currentIndex = (currentIndex);
                return (*pipe11);
                case 3:
                    currentIndex = (currentIndex);
                return (*pipe12);
                case 4:
                    currentIndex = (currentIndex);
                return (*pipe13);
                case 5:
                    currentIndex = (currentIndex);
                return (*pipe14);
                case 6:
                    currentIndex = (currentIndex);
                return (*pipe15);
                case 7:
                    currentIndex = (currentIndex); // number of different pipes (top and bottom separately)
                return (*pipe16);
            }
        break;

        case 3:
            if (currentIndex % 2 == 1) currentIndex = (std::rand() % 4) * 2;
            else currentIndex++;
            switch (currentIndex) {
                case 0:
                    currentIndex = (currentIndex);
                return (*pipe1);
                case 1:
                    currentIndex = (currentIndex);
                return (*pipe2);
                case 2:
                    currentIndex = (currentIndex);
                return (*pipe3);
                case 3:
                    currentIndex = (currentIndex);
                return (*pipe4);
                case 4:
                    currentIndex = (currentIndex);
                return (*pipe5);
                case 5:
                    currentIndex = (currentIndex);
                return (*pipe6);
                case 6:
                    currentIndex = (currentIndex);
                return (*pipe7);
                case 7:
                    currentIndex = (currentIndex); // number of different pipes (top and bottom separately)
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
}

