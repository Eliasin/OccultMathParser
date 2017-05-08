#include "MainMenu.hpp"

#include <algorithm>
#include <vector>

#include "MainMenuExceptions.hpp"
#include "Parser.hpp"
#include "ParserFactory.hpp"

namespace OM {

    static inline void clearScreen() {
        #if defined(__linux__) || defined(__CYGWIN__)
            system("clear");
        #elif defined (_WIN32) || defined(_WIN64)
            system("cls");
        #endif
    }

    static inline void waitForKey() {
        #if defined(__linux__) || defined(__CYGWIN__)
            std::cout << "Press enter to continue." << std::flush;
            system("read");
        #elif defined(_WIN32) || defined(_WIN64)
            system("PAUSE");
        #endif
        std::cout << std::endl;
    }

    void MainMenu::init() {
        ParserFactory parserFactory;
        std::unique_ptr<Parser> parser{ nullptr };
        while (true) {
            try {
                std::vector<std::string> parsers = parserFactory.getParsers();
                out << "Available Parsers:" << std::endl;
                for (auto key : parsers) {
                    out << key << std::endl;
                }

                out << "Please enter your choice of parser: ";
                std::string input;
                std::getline(in, input, '\n');
                parser = std::move(parserFactory.construct(input));
                clearScreen();
                out << '\n' << input << " parser chosen." << std::endl;
                waitForKey();
                clearScreen();
                break;
            }
            catch (NoSuchParserException& e) {
                out << "No such parser ruleset!" << std::endl;
                waitForKey();
                clearScreen();
            }
        }
        try {
            while (true) {
                out << "Please enter the expression to be simplified: ";
                std::string input;
                std::getline(in, input, '\n');

                try {
                    auto result = parser->parse(input);
                    out << result->evaluate().format().toString() << std::endl;
                }
                catch (InvalidFormatException& e) {
                    out << e.what();
                    waitForKey();
                    clearScreen();
                }

            }
        }
        catch (const ExitException& e) {}
        onExit();
    }

    void MainMenu::setOnExit(const Runnable& runnable) noexcept {
        onExit = runnable;
    }

}
