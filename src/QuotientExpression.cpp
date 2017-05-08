#include "QuotientExpression.hpp"

namespace OM {

    const Fraction QuotientExpression::evaluate() const noexcept {
        return { (left->evaluate()) / (right->evaluate()) };
    }

    std::string QuotientExpression::toString() const noexcept {
        return left->toString() + " / " + right->toString();
    }

}
