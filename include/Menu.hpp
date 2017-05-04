#ifndef MENU
#define MENU

#include <iostream>
#include <functional>

namespace OM {
    typedef std::function<void ()> Runnable;

    class Menu {
    public:
        virtual init()=0;
        virtual setOnExit(const Runnable& runnable);
    };
}


#endif
