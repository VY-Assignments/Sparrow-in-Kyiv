#pragma once

#include "Leaderboard.h"
#include "Button.h"
#include <vector>

class Menu {
    LeaderBoard& board;
public:
    bool isDisplayed;
    int& difficulty;
    std::vector<Button*> buttons;
    Menu(LeaderBoard& board, int& level):isDisplayed(true), board(board), difficulty(level){
        buttons.push_back(new DifficultyButton("Easy", {200, 50}, {100, 100}, difficulty));
        buttons.push_back(new DifficultyButton("Medium", {200, 50}, {100, 160}, difficulty));
        buttons.push_back(new DifficultyButton("Hard", {200, 50}, {100, 220}, difficulty));
        buttons.push_back(new LeaderBoardButton("Leaderboard", {200, 50}, {100, 280}, board.isDisplayed));
    }
    ~Menu() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
