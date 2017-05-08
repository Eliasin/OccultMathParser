#include <iostream>

#include "MainMenu.hpp"

int main() {
    OM::MainMenu menu(std::cin, std::cout);
    menu.init();
    return 0;
}
