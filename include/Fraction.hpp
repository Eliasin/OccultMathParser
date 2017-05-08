#ifndef FRACTION
#define FRACTION

#include <string>

namespace OM {
    struct Fraction {
        int n, d;
        Fraction() : n(1), d(1) {}
        Fraction(int n, int d) : n(n), d(d) {}
        std::string toString() const noexcept;
        const Fraction simplify() const noexcept;
        const Fraction flipNegative() const noexcept;
        const Fraction negativeToNumerator() const noexcept;
        const Fraction format() const noexcept;
        bool operator==(const Fraction& f) const noexcept;
        const Fraction operator+(const Fraction& f) const noexcept;
        const Fraction operator-(const Fraction& f) const noexcept;
        const Fraction operator/(const Fraction& f) const noexcept;
        const Fraction operator*(const Fraction& f) const noexcept;
    };
}

#endif
