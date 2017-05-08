#include "DifferenceExpression.hpp"

namespace OM {

    const Fraction DifferenceExpression::evaluate() const noexcept {
        return { left->evaluate() - right->evaluate() };
    }

    std::string DifferenceExpression::toString() const noexcept {
        return left->toString() + " - " + right->toString();
    }

}
