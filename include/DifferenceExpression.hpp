#ifndef DIFFERENCE_EXPRESSION
#define DIFFERENCE_EXPRESSION

#include "Expression.hpp"

namespace OM {
    class DifferenceExpression : public Expression {
        std::unique_ptr<Expression> left;
        std::unique_ptr<Expression> right;
    public:
        DifferenceExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right) : left(std::move(left)), right(std::move(right)) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
