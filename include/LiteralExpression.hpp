#ifndef LITERAL_EXPRESSION
#define LITERAL_EXPRESSION

#include <memory>
#include "Expression.hpp"

namespace OM {
    class LiteralExpression : public Expression {
        Fraction fraction;
    public:
        LiteralExpression(Fraction&& fraction) : fraction(fraction) {}
        virtual const Fraction evaluate() const noexcept override;
        virtual std::string toString() const noexcept override;
    };
}

#endif
