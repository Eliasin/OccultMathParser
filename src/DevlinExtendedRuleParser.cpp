#include "DevlinExtendedRuleParser.hpp"
#include "MathExpressions.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

namespace OM {

    static void ignoreSpaces(const char*& c) {
        while (*c == ' ') { c++; }
    }

    int getNum(const char*& c) {
        int results = 0;
        int fact = 1;
        std::string s;
        if (*c == '-') {
            fact = -1;
            c++;
        }
        while (std::isdigit(*c)) {
            s += *c;
            c++;
            std::cout << *c;
        }
        unsigned int place = s.size();
        for (char c : s) {
            results += (c - '0') * place;
        }
        return results * fact;

    }

    static Fraction parseFraction(const char*& c) {
        bool negNum = false;
        bool negDen = false;
        if (*c == '(') {
            negNum = true;
            c++;
        }
        int n = strtol(c, const_cast<char**>(&c), 10);
        if (negNum) {
            if (*c != ')') {
                throw InvalidFormatException("No closing brace.");
            }
            else if (n > 0) {
                throw InvalidFormatException("Unnecessary braces.");
            }
            else {
                c++;
            }
        }
        if (*c != '/') {
            throw InvalidFormatException("Non fraction operand.");
        }
        c++;
        if (*c == '(') {
            negDen = true;
            c++;
        }
        int d = strtol(c, const_cast<char**>(&c), 10);
        if (negDen) {
            if (*c != ')') {
                throw InvalidFormatException("No closing brace.");
            }
            else if (d > 0) {
                throw InvalidFormatException("Unnecessary braces.");
            }
            else {
                c++;
            }
        }
        return { n, d };
    }

    static char parseOperator(const char*& c) {
        if (*c != '/' && *c != '*' && *c != '+' && *c != '-') {
            throw InvalidFormatException("Invalid operator.");
        }
        c++;
        return *(c - 1);
    }

    static void writeExpression(std::string& s, const Fraction& f1, char op, const Fraction& f2) {
        s += f1.format().toString() + " " + op + " " + f2.format().toString() + " ";
    }

    std::string DevlinExtendedParser::parse(const std::string& s) const {
        std::string output;

        const char* c = s.c_str();

        Fraction buf1;
        Fraction buf2;
        char op;

        while (*c != '\0') {
            buf1 = parseFraction(c);
            ignoreSpaces(c);
            op = parseOperator(c);
            buf2 = parseFraction(c);
            if (op == '-') {
                op = '+';
                buf2 * Fraction(-1, 1);
            }
            writeExpression(output, buf1, op, buf2);
            ignoreSpaces(c);
        }

        return output;
    }

}
