#include <ratexpr/fraction.hpp>
#include <iostream>
#include <stdexcept>

int main () {
    using ratexpr::Fraction;

    Fraction a(1, 2), b(1, 3);

    std::cout << Fraction(6, -8) << ", " << Fraction(10, 4) << "\n";
    std::cout << a + b << ", " << a - b << ", " << a*b << ", " << a / b << "\n";
    std::cout << a + 2u << " и " << 2u + a << "\n";
    std::cout << a - 2u << " и " << 2u - a << "\n";
    std::cout << a / 2u << " и " << 2u / a << "\n";

    Fraction acc = 0;
    acc += a; acc += b; acc *= 6u;
    std::cout << acc << "\n";
    
    try {
        Fraction f(1, 0);
    } catch (const std::invalid_argument &er) {
        std::cout << "std::invalid_argument : " << er.what() << "\n";
    }

    try {
        std::cout << a / 0u;
    } catch (const std::invalid_argument &er) {
        std::cout << "std::invalid_argument : " << er.what() << "\n";
    }
}
