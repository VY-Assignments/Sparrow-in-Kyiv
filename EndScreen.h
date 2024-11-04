#pragma once
#include <vector>

#include "Button.h"


enum class GameState;

class EndScreen {
    GameState& state;
public:
    std::vector<Button*> buttons;
    EndScreen(GameState& state): state(state) {
        buttons.push_back(new MenuButton("Menu", {100, 100},  state));
        buttons.push_back(new RestartButton("Restart", {100, 160},  state));
        buttons.push_back(new EndButton("Exit", {100, 220}, state));
    }
};
