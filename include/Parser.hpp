#ifndef PARSER
#define PARSER

#include <exception>

#include "MathExpressions.hpp"

namespace OM {
    class Parser {
    public:
        virtual std::unique_ptr<Expression> parse(const std::string& s) const=0;
    };

    class InvalidFormatException : public std::exception {};
}

#endif
