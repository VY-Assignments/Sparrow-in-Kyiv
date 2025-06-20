#include "Leaderboard.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

LeaderBoard::LeaderBoard(GameState& state) : state(state), button("Back", {200, 670}, state) {
}

std::vector<std::pair<std::string, int>> LeaderBoard::display() {
    loadScores();
    std::vector<std::pair<std::string, int>> bestScores(scores.begin(), scores.end());

    std::sort(bestScores.begin(), bestScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    if (bestScores.size() > 10) {
        bestScores.resize(10);
    }

    return bestScores;
}

// void LeaderBoard::getScoreByName(std::string name) {
//     std::cout << scores[name] << std::endl;
// }

void LeaderBoard::add(std::string name, int score) {
    if (name == "") name = "Noname";
    if (scores.empty())loadScores();
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




