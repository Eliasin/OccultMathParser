#include "ProductExpression.hpp"

namespace OM {

    const Fraction ProductExpression::evaluate() const noexcept {
        return { left->evaluate() * right->evaluate() };
    }

    std::string ProductExpression::toString() const noexcept {
        return left->toString() + " * " + right->toString();
    }

}
