#ifndef PARSER
#define PARSER

#include <exception>

#include "MathExpressions.hpp"

namespace OM {
    class Parser {
    public:
        virtual std::string parse(const std::string& s) const=0;
    };

    class InvalidFormatException : public std::exception {
        std::string s;
    public:
        InvalidFormatException() : s("Exception occurred") {}
        InvalidFormatException(const std::string&& what) : s(what) {}
        const char* what() const noexcept override;
    };
}

#endif
