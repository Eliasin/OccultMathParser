#ifndef DEVLIN_EXTENDED_PARSER
#define DEVLIN_EXTENDED_PARSER

#include "Parser.hpp"

namespace OM {

    class DevlinExtendedParser : public Parser {
    public:
        std::string parse(const std::string& s) const override;
    };

}

#endif
