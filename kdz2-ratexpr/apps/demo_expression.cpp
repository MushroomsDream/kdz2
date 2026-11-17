#include "ratexpr/expression.hpp"
#include <iostream>
#include <memory>

int main () {
    using ratexpr::Expression;
    using ratexpr::Const;
    using ratexpr::BinaryExpression;
    using ratexpr::Add;
    using ratexpr::Sub;
    using ratexpr::Mul;
    using ratexpr::Div;
    using ratexpr::Fraction;
    using ratexpr::Negative;

    auto e = std::make_unique<Mul>(
        std::make_unique<Add>(std::make_unique<Const>(Fraction(1, 2)),
        std::make_unique<Const>(Fraction(1, 3))
        ), std::make_unique<Sub>(std::make_unique<Const>(Fraction(3)), std::make_unique<Const>(Fraction(1, 4)))
    );

    std::cout << *e << " = " << e->evaluate() << "\n";

    auto e1 = std::make_unique<Negative>(std::make_unique<Div>(
        std::make_unique<Const>(Fraction(2)),
        std::make_unique<Const>(Fraction(3))));

    std::cout << *e1 << " = " << e1->evaluate() << "\n";
}
