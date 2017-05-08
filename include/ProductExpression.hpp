#ifndef PRODUCT_EXPRESSION
#define PRODUCT_EXPRESSION

#include "Expression.hpp"

namespace OM {
    class ProductExpression : public Expression {
        std::unique_ptr<Expression> left;
        std::unique_ptr<Expression> right;
    public:
        ProductExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right) : left(std::move(left)), right(std::move(right)) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
