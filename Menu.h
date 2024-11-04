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
    Menu(int& level, GameState& state): state(state), nameField({200, 50}, {350, 590}) {
        buttons.push_back(new DifficultyButton("Easy", {100, 420}, level, state));
        buttons.push_back(new DifficultyButton("Medium", {100, 520}, level, state));
        buttons.push_back(new DifficultyButton("Hard", {100, 620}, level, state));
        buttons.push_back(new LeaderBoardButton("Leaderboard", {350, 490}, state));
    }
    ~Menu() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
