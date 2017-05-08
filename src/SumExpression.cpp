#include "SumExpression.hpp"

namespace OM {

    const Fraction SumExpression::evaluate() const noexcept {
        return { left->evaluate() + right->evaluate() };
    }

    std::string SumExpression::toString() const noexcept {
        return left->toString() + " + " + right->toString();
    }

}
