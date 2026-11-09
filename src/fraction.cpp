#include "ratexpr/fraction.hpp"
#include <cstdlib>
#include <ostream>
#include <stdexcept>

namespace ratexpr {

    std::int64_t Fraction::nod(std::int64_t a, std::int64_t b) {
        if (b == 0)
            return a;
        return nod(b, a % b);
    }

    std::int64_t Fraction::nok(std::int64_t a, std::int64_t b) {
        return a * b / nod(a, b);
    }

    void Fraction::cut() {
        std::int64_t k = nod(std::abs(num), std::abs(den));
        num /= k;
        den /= k;
        if (den < 0) {
            den *= (-1);
            num *= (-1);
        }
    }

    Fraction::Fraction() {
        num = 0;
        den = 1;
    }

    Fraction::Fraction(std::int64_t numerator, std::int64_t denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("zero denominator");
        }
        num = numerator;
        den = denominator;
        cut();
    }

    Fraction& Fraction::operator+=(const Fraction& o) {
        std::int64_t nk = nok(den, o.den);
        std::int64_t ms = nk / den, mo = nk / o.den;
        num = num * ms + o.num * mo;
        den = nk;
        cut();
        return *this;
    }

    Fraction& Fraction::operator-=(const Fraction& o) {
        std::int64_t nk = nok(den, o.den);
        std::int64_t ms = nk / den, mo = nk / o.den;
        num = num * ms - o.num * mo;
        den = nk;
        cut();
        return *this;
    }

    Fraction& Fraction::operator*=(const Fraction& o) {
        num = num * o.num;
        den *= o.den;
        cut();
        return *this;
    }

    Fraction& Fraction::operator/=(const Fraction& o) {
        if (o.num == 0) {
            throw std::invalid_argument("division by zero");
        }
        std::int64_t n = num * o.den;
        std::int64_t d = den * o.num;
        num = n;
        den = d;
        cut();
        return *this;
    }

    Fraction& Fraction::operator+=(std::uint32_t k) { return *this += Fraction(k); }
    Fraction& Fraction::operator-=(std::uint32_t k) { return *this -= Fraction(k); }
    Fraction& Fraction::operator*=(std::uint32_t k) { return *this *= Fraction(k); }
    Fraction& Fraction::operator/=(std::uint32_t k) { return *this /= Fraction(k); }

    Fraction Fraction::operator-() const { return Fraction(num * (-1), den); }

    Fraction operator+(const Fraction& a, const Fraction& b) {
        Fraction res(a.num * b.den + b.num * a.den, a.den * b.den);
        return res;
    }
    Fraction operator+(const Fraction& a, std::uint32_t k) {
        return a + Fraction(k);
    }
    Fraction operator+(std::uint32_t k, const Fraction& b) {
        return Fraction(k) + b;
    }

    Fraction operator-(const Fraction& a, const Fraction& b) {
        Fraction res(a.num * b.den - b.num * a.den, a.den * b.den);
        return res;
    }
    Fraction operator-(const Fraction& a, std::uint32_t k) {
        return a - Fraction(k);
    }
    Fraction operator-(std::uint32_t k, const Fraction& b) {
        return Fraction(k) - b;
    }

    Fraction operator*(const Fraction& a, const Fraction& b) {
        Fraction res(a.num * b.num, a.den * b.den);
        return res;
    }
    Fraction operator*(const Fraction& a, std::uint32_t k) {
        return a * Fraction(k);
    }
    Fraction operator*(std::uint32_t k, const Fraction& b) {
        return Fraction(k) * b;
    }

    Fraction operator/(const Fraction& a, const Fraction& b) {
        Fraction res(a.num * b.den, a.den * b.num);
        return res;
    }
    Fraction operator/(const Fraction& a, std::uint32_t k) {
        return a / Fraction(k);
    }
    Fraction operator/(std::uint32_t k, const Fraction& b) {
        return Fraction(k) / b;
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.num;
        if (f.den != 1) {
            os << '/' << f.den;
        }
        return os;
    }

} // namespace ratexpr