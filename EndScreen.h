#pragma once
#include <vector>

#include "Button.h"


enum class GameState;

class EndScreen {
    GameState& state;
    std::vector<Button*> buttons;
public:

    EndScreen(GameState& state): state(state) {
        buttons.push_back(new MenuButton("Menu", {60, 565},  state));
        buttons.push_back(new RestartButton("Restart", {340, 75},  state));
        buttons.push_back(new EndButton("Exit", {60, 670}, state));
    }

    std::vector<Button *> &getButtons() {
        return buttons;
    }

    ~EndScreen() {
        for (Button* button : buttons) {
            delete button;
        }
    }
};
