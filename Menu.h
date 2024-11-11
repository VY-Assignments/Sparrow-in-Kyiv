#pragma once
#include "Button.h"
#include <vector>

#include "TextField.h"

enum class GameState {
    Menu = 0,
    LeaderBoard,
    Game,
    EndScreen,
};

class Menu {
    GameState& state;
    std::vector<Button*> buttons;
    TextField nameField;
public:
    
    Menu(int& level, GameState& state): state(state), nameField({200, 50}, {350, 590}) {
        // auto diffButoon = new ...
        // if (diffButton) {
        //     buttons.push_back(diffButton);
        // }
        buttons.push_back(new DifficultyButton("Easy", {100, 420}, level, state));
        buttons.push_back(new DifficultyButton("Medium", {100, 520}, level, state));
        buttons.push_back(new DifficultyButton("Hard", {100, 620}, level, state));
        buttons.push_back(new LeaderBoardButton("Leaderboard", {350, 490}, state));
    }

    TextField &getTextField() {
        return nameField;
    }

    std::vector<Button *> &getButtons() {
        return buttons;
    }
    ~Menu() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
