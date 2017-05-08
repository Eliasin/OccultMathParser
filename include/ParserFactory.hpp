#ifndef PARSER_FACTORY
#define PARSER_FACTORY

#include <memory>
#include <exception>
#include <map>
#include <functional>
#include <vector>

#include "Parser.hpp"

namespace OM {
    class ParserFactory {
        std::map<std::string, std::function<std::unique_ptr<Parser> ()>> parsers;
    public:
        ParserFactory();
        std::vector<std::string> getParsers() const;
        std::unique_ptr<Parser> construct(const std::string& s) const;
    };

    class NoSuchParserException : public std::exception {};
}

#endif
