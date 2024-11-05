#pragma once
#include <vector>

#include "Button.h"


enum class GameState;

class EndScreen {
    GameState& state;
public:
    std::vector<Button*> buttons;
    EndScreen(GameState& state): state(state) {
        buttons.push_back(new MenuButton("Menu", {60, 565},  state));
        buttons.push_back(new RestartButton("Restart", {340, 75},  state));
        buttons.push_back(new EndButton("Exit", {60, 670}, state));
    }
};
