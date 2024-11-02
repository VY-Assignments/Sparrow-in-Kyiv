#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "Button.h"

class LeaderBoard {
    std::string filePath = "statistics.txt";
    std::unordered_map<std::string, int> scores;

public:
    LeaderBoard();
    bool isDisplayed;
    BackButton button;
    std::vector<std::pair<std::string, int>> display();
    void getScoreByName(std::string name);
    void add(std::string name, int score);
    void loadScores();
};
