#include <iostream>

#include "MainMenu.hpp"

typedef std::unique_ptr<OM::Expression> uPtrExpression;

int main() {
    OM::MainMenu menu(std::cin, std::cout);
    menu.init();
    return 0;
}
