#include <cstdint>
#include <iostream>
#include <ratexpr/fraction.hpp>
#include <stdexcept>

namespace ratexpr {

    std::int64_t Fraction::gcd(std::int64_t x, std::int64_t y) {
            x = std::abs(x);
            y = std::abs(y);
            
            while (y != 0) {
                std::int64_t temp = y;
                y = x % y;
                x = temp;
            }

            return x;
        }

    void Fraction::to_norm() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        std::int64_t k = gcd(numerator, denominator);

        numerator /= k;
        denominator /= k;
    }

    Fraction::Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction::Fraction(std::int64_t numerator, std::int64_t denominator){
        if (denominator == 0)
            throw std::invalid_argument("деление на 0");
        
        this->numerator = numerator;
        this->denominator = denominator;

        this->to_norm();
    }

    //+=
    Fraction& Fraction::operator+=(const Fraction& o) {
        numerator = numerator*o.denominator + o.numerator*denominator;
        denominator = denominator*o.denominator; 
        this->to_norm();

        return *this;
    }// и так же -=, *=, /=
    Fraction& Fraction::operator+=(std::uint32_t k) {
        numerator = numerator + k*denominator;
        this->to_norm();

        return *this;
    }
    // и так же -=, *=, /=

    //-=
    Fraction& Fraction::operator-=(const Fraction& o) {
        numerator = numerator*o.denominator - o.numerator*denominator;
        denominator = denominator*o.denominator; 
        this->to_norm();

        return *this;
    }
    Fraction& Fraction::operator-=(std::uint32_t k) {
        numerator = numerator - k*denominator;
        this->to_norm();

        return *this;
    }

    Fraction& Fraction::operator*=(const Fraction& o) {
        numerator *= o.numerator;
        denominator *= o.denominator; 
        this->to_norm();

        return *this;
    }
    Fraction& Fraction::operator*=(std::uint32_t k) {
        numerator *= k;
        this->to_norm();

        return *this;
    }
    
    Fraction& Fraction::operator/=(const Fraction& o) {
        if (o.numerator == 0)
            throw std::invalid_argument("деление на 0");
        
        std::int64_t nw_numerator = numerator * o.denominator;
        std::int64_t nw_denominator = denominator * o.numerator;
        
        numerator = nw_numerator;
        denominator = nw_denominator;

        this->to_norm();

        return *this;
    }
    Fraction& Fraction::operator/=(std::uint32_t k) {
        if (k == 0)
            throw std::invalid_argument("деление на 0");
        
        denominator *= k;
        this->to_norm();

        return *this;
    }

    Fraction Fraction::operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction operator+(const Fraction& a, const Fraction& b) {
        Fraction r(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator); 
        r.to_norm();
        return r;
    }
    Fraction operator+(const Fraction& a, std::uint32_t k) {
        Fraction r(a.numerator + k * a.denominator, a.denominator);
        r.to_norm();
        return r;
    }
    Fraction operator+(std::uint32_t k, const Fraction& b) {
        Fraction r(k * b.denominator + b.numerator, b.denominator);
        r.to_norm();
        return r;
    }

    Fraction operator-(const Fraction& a, const Fraction& b) {
        Fraction r(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator); 
        r.to_norm();
        return r;
    }
    Fraction operator-(const Fraction& a, std::uint32_t k) {
        Fraction r(a.numerator - k * a.denominator, a.denominator);
        r.to_norm();
        return r;
    }
    Fraction operator-(std::uint32_t k, const Fraction& b) {
        Fraction r(k * b.denominator - b.numerator, b.denominator);
        r.to_norm();
        return r;
    }

    Fraction operator*(const Fraction& a, const Fraction& b) {
        Fraction r(a.numerator * b.numerator, a.denominator * b.denominator); 
        r.to_norm();
        return r;
    }
    Fraction operator*(const Fraction& a, std::uint32_t k) {
        Fraction r(a.numerator * k, a.denominator);
        r.to_norm();
        return r;
    }
    Fraction operator*(std::uint32_t k, const Fraction& b) {
        Fraction r(k * b.numerator, b.denominator);
        r.to_norm();
        return r;
    }

    Fraction operator/(const Fraction& a, const Fraction& b) {
        if (b.numerator == 0)
            throw std::invalid_argument("деление на 0");
        
        Fraction r(a.numerator * b.denominator, a.denominator * b.numerator); 
        r.to_norm();
        return r;
    }
    Fraction operator/(const Fraction& a, std::uint32_t k) {
        if (k == 0)
            throw std::invalid_argument("деление на 0");
        
        Fraction r(a.numerator, a.denominator * k);
        r.to_norm();
        return r;
    }
    Fraction operator/(std::uint32_t k, const Fraction& b) {
        if (b.numerator == 0)
            throw std::invalid_argument("деление на 0");
        
        Fraction r(k*b.denominator, b.numerator);
        r.to_norm();
        return r;
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << f.numerator << "/" << f.denominator;

        return os;
    }
}