#ifndef MENU
#define MENU

#include <iostream>
#include <functional>

namespace OM {
    typedef std::function<void ()> Runnable;

    class Menu {
    public:
        virtual void init()=0;
        virtual void setOnExit(const Runnable& runnable) noexcept;
    };
}


#endif
