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
        if (*c != '/' && *c != ' ' && *c != '\0') {
            throw InvalidFormatException("Invalid operand, found invalid character: ");
        }
        else if (*c == ' ' || *c == '\0') {
            return { n, 1 };
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

    static bool isOperator(char c) {
        return c == '/' || c == '*' || c == '+' || c == '-';
    }

    static char parseOperator(const char*& c) {
        if (!isOperator(*c)) {
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

        unsigned int operators = 0;
        unsigned int operands = 0;

        while (true) {
            if (operators > 9) {
                throw InvalidFormatException("Too many operators, max is 9");
            }
            buf1 = parseFraction(c);
            operands++;
            ignoreSpaces(c);
            if (!(*c) && operands >= 2 && operators >= 1) {
                output += buf1.format().toString();
                break;
            }
            op = parseOperator(c);
            operators++;
            ignoreSpaces(c);
            buf2 = parseFraction(c);
            operands++;
            if (op == '-') {
                op = '+';
                buf2 = buf2 * Fraction(-1, 1);
            }
            ignoreSpaces(c);
            writeExpression(output, buf1, op, buf2);

            if (!(*c)) {
                break;
            }
            output += parseOperator(c);
            output += ' ';
            ignoreSpaces(c);
        }
        return output;
    }

}
