#pragma once
#include <string>
#include <unordered_map>

class LeaderBoard {
    std::string filePath = "statistics.txt";
    std::unordered_map<std::string, int> scores;
public:
    void display();
    void getScoreByName(std::string name);
    void add(std::string name, int score);
    void loadScores();
};
