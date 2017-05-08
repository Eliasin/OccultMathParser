#include "MainMenu.hpp"
#include "MainMenuExceptions.hpp"

namespace OM {

    void MainMenu::init() {
        try {
            while (true) {

            }
        }
        catch (const ExitException& e) {}
        onExit();
    }

    void MainMenu::setOnExit(const Runnable& runnable) noexcept {
        onExit = runnable;
    }

}
