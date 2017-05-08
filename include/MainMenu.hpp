#ifndef MAIN_MENU
#define MAIN_MENU

#include <iostream>
#include "Menu.hpp"

 namespace OM {

     class MainMenu final : public Menu {
         std::istream& in;
         std::ostream& out;
         Runnable onExit;
     public:
         MainMenu(std::istream& in, std::ostream& out) : in(in), out(out), onExit([] ()->void {}) {};
         void init() override;
         void setOnExit(const Runnable& runnable) noexcept override;
     };

 }

#endif
