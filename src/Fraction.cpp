#include "Fraction.hpp"

#include "gcd.hpp"

namespace OM {

    std::string Fraction::toString() const noexcept {
        return std::to_string(n) + "/" + std::to_string(d);
    }

    const Fraction Fraction::simplify() const noexcept {
        int gcd_ = gcd(n, d);
        return { n / gcd_, d / gcd_ };
    }

    const Fraction Fraction::flipNegative() const noexcept {
        return (*this) * Fraction(-1, -1);
    }

    const Fraction Fraction::negativeToNumerator() const noexcept {
        if (d < 0) {
            return flipNegative();
        }
        return *this;
    }

    const Fraction Fraction::format() const noexcept {
        return simplify().negativeToNumerator();
    }

    bool Fraction::operator==(const Fraction& f) const noexcept {
        Fraction t, o;
        t = this->simplify();
        o = f.simplify();
        return t.n == o.n && t.d == o.d;
    }

    const Fraction Fraction::operator*(const Fraction& f) const noexcept {
        Fraction multiply = { n * f.n, d * f.d };
        return multiply;
    }


    const Fraction Fraction::operator/(const Fraction& f) const noexcept {
        Fraction divide = { this->d * f.n, this->n * f.d };
        return divide;
    }

    const Fraction Fraction::operator+(const Fraction& f) const noexcept {
        Fraction add = { (this->n * f.d) + (f.n * this->d), this->d * f.d };
        return add;
    }

    const Fraction Fraction::operator-(const Fraction& f) const noexcept {
        Fraction sub = { (this->n * f.d) - (f.n * this->d), this->d * f.d };
        return sub;
    }

}
