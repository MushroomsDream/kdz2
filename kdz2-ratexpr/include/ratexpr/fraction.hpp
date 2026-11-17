#pragma once
#include <cstdint>
#include <iostream>

namespace ratexpr {
    class Fraction {
        std::int64_t numerator, denominator;

        std::int64_t gcd(std::int64_t x, std::int64_t y);
        void to_norm();

        public:
        Fraction();

        Fraction(std::int64_t numerator, std::int64_t denominator = 1);
        
        Fraction& operator+=(const Fraction& o);
        Fraction& operator+=(std::uint32_t k);
        
        Fraction& operator-=(const Fraction& o);
        Fraction& operator-=(std::uint32_t k);

        Fraction& operator*=(const Fraction& o);
        Fraction& operator*=(std::uint32_t k);
        
        Fraction& operator/=(const Fraction& o);
        Fraction& operator/=(std::uint32_t k);
        

        Fraction operator-() const;
        
        friend Fraction operator+(const Fraction& a, const Fraction& b);
        friend Fraction operator+(const Fraction& a, std::uint32_t k);
        friend Fraction operator+(std::uint32_t k, const Fraction& b);

        friend Fraction operator-(const Fraction& a, const Fraction& b);
        friend Fraction operator-(const Fraction& a, std::uint32_t k);
        friend Fraction operator-(std::uint32_t k, const Fraction& b);

        friend Fraction operator*(const Fraction& a, const Fraction& b);
        friend Fraction operator*(const Fraction& a, std::uint32_t k);
        friend Fraction operator*(std::uint32_t k, const Fraction& b);

        friend Fraction operator/(const Fraction& a, const Fraction& b);
        friend Fraction operator/(const Fraction& a, std::uint32_t k);
        friend Fraction operator/(std::uint32_t k, const Fraction& b);
        
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    };
}
// namespace ratexpr