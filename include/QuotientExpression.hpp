#ifndef QUOTIENT_EXPRESSION
#define QUOTIENT_EXPRESSION

#include <memory>

#include "Expression.hpp"

namespace OM {
    class QuotientExpression : public Expression {
        std::unique_ptr<Expression> left;
        std::unique_ptr<Expression> right;
    public:
        QuotientExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right) : left(std::move(left)), right(std::move(right)) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
