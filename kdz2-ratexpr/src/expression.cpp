#include "ratexpr/expression.hpp"
#include <utility>
#include <ostream>
#include <memory>

namespace ratexpr {

std::ostream& operator<<(std::ostream& os, const Expression& e) {
    e.print(os);

    return os;
}


Const::Const(const Fraction& value) {
    this->value = value;
}

Fraction Const::evaluate () const {
    return value;
}

void Const::print(std::ostream& os) const {
    os << value;
}



Negative::Negative(std::unique_ptr<Expression> operand) : operand(std::move(operand)) {}

Fraction Negative::evaluate () const {
    return -(operand->evaluate());
}

void Negative::print(std::ostream& os) const {
    os << "(-";
    operand->print(os);
    os << ")";
}



BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs) {
    this->lhs = std::move(lhs);
    this->rhs = std::move(rhs);
}

void Add::print(std::ostream& os) const {
    os << "(";
    lhs->print(os);
    os << " + ";
    rhs->print(os);
    os << ")";
}

Fraction Add::evaluate() const {
    return lhs->evaluate() + rhs->evaluate();
}


void Sub::print(std::ostream& os) const {
    os << "(";
    lhs->print(os);
    os << " - ";
    rhs->print(os);
    os << ")";
}

Fraction Sub::evaluate() const {
    return lhs->evaluate() - rhs->evaluate();
}


void Mul::print(std::ostream& os) const {
    os << "(";
    lhs->print(os);
    os << " * ";
    rhs->print(os);
    os << ")";
}

Fraction Mul::evaluate() const {
    return lhs->evaluate() * rhs->evaluate();
}

void Div::print(std::ostream& os) const {
    os << "(";
    lhs->print(os);
    os << " / ";
    rhs->print(os);
    os << ")";
}

Fraction Div::evaluate() const {
    return lhs->evaluate() / rhs->evaluate();
}

}
// namespace ratexpr