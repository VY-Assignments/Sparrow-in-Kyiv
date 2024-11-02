#include "EndScreen.h"

#include <iostream>

char EndScreen::show() {
    char answer;
    std::cout << "Please choose an option: menu(m), restart(r) or exit(e): " << std::endl;
    std::cin >> answer;
    return answer;
}



