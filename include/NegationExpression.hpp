#ifndef NEGATION_EXPRESSION
#define NEGATION_EXPRESSION

#include <memory>

#include "Expression.hpp"

namespace OM {
    class NegationExpression : public Expression {
        std::unique_ptr<Expression> operand;
    public:
        NegationExpression(std::unique_ptr<Expression>&& operand) : operand(std::move(operand)) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
