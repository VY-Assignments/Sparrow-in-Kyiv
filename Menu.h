#pragma once
#include "Button.h"
#include <vector>

#include "TextField.h"

enum class GameState {
    Menu,
    LeaderBoard,
    Game,
    EndScreen,
};

class Menu {
public:
    GameState& state;
    std::vector<Button*> buttons;
    TextField nameField;
    Menu(int& level, GameState& state): state(state), nameField({200, 50}, {100, 500}) {
        buttons.push_back(new DifficultyButton("Easy", {100, 100}, level, state));
        buttons.push_back(new DifficultyButton("Medium", {100, 160}, level, state));
        buttons.push_back(new DifficultyButton("Hard", {100, 220}, level, state));
        buttons.push_back(new LeaderBoardButton("Leaderboard", {100, 280}, state));
    }
    ~Menu() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
