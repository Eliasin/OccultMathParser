#include "NegationExpression.hpp"

namespace OM {

    const Fraction NegationExpression::evaluate() const noexcept {
        Fraction negative = { -1, 1 };
        return operand->evaluate() * negative;
    }

    std::string NegationExpression::toString() const noexcept {
        return evaluate().toString();
    }

}
