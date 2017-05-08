#ifndef EXPRESSION
#define EXPRESSION

#include <memory>
#include <string>

#include "Fraction.hpp"

namespace OM {

    class Expression {
    public:
        virtual const Fraction evaluate() const noexcept=0;
        virtual std::string toString() const noexcept=0;
    };

}

#endif
