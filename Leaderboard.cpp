#include "Leaderboard.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void LeaderBoard::display() {
    loadScores();
    std::vector<std::pair<std::string, int>> bestScores(scores.begin(), scores.end());

    std::sort(bestScores.begin(), bestScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::cout << "Top 10 Scores:\n";
    for (size_t i = 0; i < std::min(bestScores.size(), size_t(10)); ++i) {
        std::cout << bestScores[i].first << ": " << bestScores[i].second << std::endl;
    }
}

void LeaderBoard::getScoreByName(std::string name) {
    std::cout << scores[name] << std::endl;
}

void LeaderBoard::add(std::string name, int score) {
    if (scores.find(name) == scores.end() || score > scores[name]) {
        scores[name] = score;
    }

    std::ofstream file(filePath);
    for (const auto& entry : scores) {
        file << entry.first << " " << entry.second << std::endl;
    }
}

void LeaderBoard::loadScores() {
    std::ifstream file(filePath);
    std::string name;
    int score;

    while (file >> name >> score) {
        scores[name] = score;
    }
}



