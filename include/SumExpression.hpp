#ifndef SUM_EXPRESSION
#define SUM_EXPRESSION

#include "Expression.hpp"

namespace OM {
    class SumExpression : public Expression {
        std::unique_ptr<Expression> left;
        std::unique_ptr<Expression> right;
    public:
        SumExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right) : left(std::move(left)), right(std::move(right)) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
