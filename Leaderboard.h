#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "Button.h"


class LeaderBoard {
    std::string filePath = "statistics.txt";
    std::unordered_map<std::string, int> scores;
    GameState& state;
    void loadScores();
    //void getScoreByName(std::string name);
public:
    LeaderBoard(GameState& state);
    BackButton button;
    std::vector<std::pair<std::string, int>> display();
    void add(std::string name, int score);
};
