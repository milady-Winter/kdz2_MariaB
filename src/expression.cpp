#include"ratexpr/expression.hpp"
#include<utility>

namespace ratexpr {
    Const::Const(const Fraction& value) : val(value) {}
    Fraction Const::evaluate() const{ return val; }
    void Const::print(std::ostream & os) const { os << val;}

    Negative::Negative(std::unique_ptr<Expression> operand)  : val(std::move(operand)) {}
    Fraction Negative::evaluate() const { return -val->evaluate(); }
    void Negative::print(std::ostream& os) const { os << "- " << *val; }

    BinaryExpression::BinaryExpression(
        std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs) : l(std::move(lhs)), r(std::move(rhs)) {}

    Add::Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
        : BinaryExpression(std::move(lhs), std::move(rhs)) {}
    Fraction Add::evaluate() const{
        return (l->evaluate() + r->evaluate());
    }
    void Add::print(std::ostream& os) const { os << "(" << *l << " + " << *r << ")"; }

    Sub::Sub(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
        : BinaryExpression(std::move(lhs), std::move(rhs)) {}
    Fraction Sub::evaluate() const { return (l->evaluate() - r->evaluate()); }
    void Sub::print(std::ostream& os) const {
        os << "(" << *l << " - " << *r << ")";
    }

    Mul::Mul(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
        : BinaryExpression(std::move(lhs), std::move(rhs)) {}
    Fraction Mul::evaluate() const { return (l->evaluate() * r->evaluate()); }
    void Mul::print(std::ostream& os) const {
        os << "(" << *l << " * " << *r << ")";
    }

    Div::Div(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
        : BinaryExpression(std::move(lhs), std::move(rhs)) {}
    Fraction Div::evaluate() const { return (l->evaluate() / r->evaluate()); }
    void Div::print(std::ostream& os) const {
        os << "(" << *l << " / " << *r << ")";
    }
    std::ostream& operator<<(std::ostream& os, const Expression& e){
        e.print(os);
        return os;
    }
}