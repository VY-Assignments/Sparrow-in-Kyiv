#pragma once
#include "Button.h"
#include <vector>

enum class GameState {
    Menu,
    LeaderBoard,
    Game,
    EndScreen,
};

class Menu {
public:
    GameState& state;
    int& difficulty;
    std::vector<Button*> buttons;
    Menu(int& level, GameState& state):difficulty(level), state(state) {
        buttons.push_back(new DifficultyButton("Easy", {200, 50}, {100, 100}, level, state));
        buttons.push_back(new DifficultyButton("Medium", {200, 50}, {100, 160}, level, state));
        buttons.push_back(new DifficultyButton("Hard", {200, 50}, {100, 220}, level, state));
        buttons.push_back(new LeaderBoardButton("Leaderboard", {200, 50}, {100, 280}, state));
    }
    ~Menu() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
