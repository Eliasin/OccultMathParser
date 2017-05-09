#include "Parser.hpp"

namespace OM {

    const char* InvalidFormatException::what() const noexcept {
        return s.c_str();
    }

}
