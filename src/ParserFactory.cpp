#include "ParserFactory.hpp"

#include <algorithm>
#include <memory>

#include "DevlinRuleParser.hpp"
#include "DevlinExtendedRuleParser.hpp"

namespace OM {

    ParserFactory::ParserFactory() {

        std::function<std::unique_ptr<Parser> ()> devlinGen = [] () {
            return std::unique_ptr<Parser>(new DevlinParser());
        };
        std::function<std::unique_ptr<Parser> ()> devlinExtendedGen = [] () {
            return std::unique_ptr<Parser>(new DevlinExtendedParser());
        };
        parsers["devlin"] = devlinGen;
        parsers["devlin_extended"] = devlinExtendedGen;
    }

    std::vector<std::string> ParserFactory::getParsers() const {
        std::vector<std::string> keys;
        std::for_each(parsers.begin(), parsers.end(), [&] (const std::pair<std::string, std::function<std::unique_ptr<Parser> ()>>& i)->void { keys.push_back(i.first); });
        return keys;
    }

    std::unique_ptr<Parser> ParserFactory::construct(const std::string& s) const {
        if (parsers.count(s) == 0) {
            throw NoSuchParserException();
        }
        return std::move(parsers.at(s)());

    }

}
