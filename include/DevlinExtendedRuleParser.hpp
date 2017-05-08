#ifndef DEVLIN_EXTENDED_PARSER
#define DEVLIN_EXTENDED_PARSER

#include "Parser.hpp"

namespace OM {

    class DevlinExtendedParser : public Parser {
    public:
        std::unique_ptr<Expression> parse(const std::string& s) const override;
    };

}

#endif
