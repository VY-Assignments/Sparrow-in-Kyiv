#pragma once
#include <iostream>

#include "Leaderboard.h"

class Menu {
public:
    int chooseDifficulty() {
        int level;
        std::cout << "Plase choose difficulty: 1, 2, or 3" << std::endl;
        std::cin >> level;
        return level;
    }
    void viewScoreBoard(LeaderBoard& leaderboard) {
        char answer;
        std::cout << "Do you want to view leader board?" << std::endl;
        std::cin >> answer;
        if (answer == 'y') {
            leaderboard.display();
        }
    }
};