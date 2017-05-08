#include "LiteralExpression.hpp"

namespace OM {

    const Fraction LiteralExpression::evaluate() const noexcept {
        return fraction;
    }

    std::string LiteralExpression::toString() const noexcept {
        return fraction.toString();
    }
}
