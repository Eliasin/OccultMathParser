#ifndef DEVLIN_PARSER
#define DEVLIN_PARSER

#include "Parser.hpp"

namespace OM {
    class DevlinParser : public Parser {
        bool isValidCharacter(char c) const;
    public:
        std::string parse(const std::string& s) const override;
    };
}

#endif
