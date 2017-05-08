#ifndef DEVLIN_PARSER
#define DEVLIN_PARSER

#include "Parser.hpp"

namespace OM {
    class DevlinParser : public Parser {

    public:
        std::unique_ptr<Expression> parse(const std::string& s) const override;
    };
}

#endif
