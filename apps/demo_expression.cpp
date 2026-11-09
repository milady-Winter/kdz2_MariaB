#include"ratexpr/expression.hpp"
#include"ratexpr/fraction.hpp"
#include<iostream>
#include<memory>
using namespace ratexpr;
int main(){
    std::unique_ptr<Add> a =
        std::make_unique<Add>(std::make_unique<Const>(Fraction(1, 2)),
                              std::make_unique<Const>(Fraction(1, 3)));
    std::unique_ptr<Sub> b =
        std::make_unique<Sub>(std::make_unique<Const>(Fraction(3)),
                              std::make_unique<Const>(Fraction(1, 4)));
    std::unique_ptr<Mul> res = std::make_unique<Mul>(std::move(a), std::move(b));
    std::cout<<res->evaluate() <<'\n';
    Fraction fr(2,3);
    //Const c(fr);
    std::cout<<std::make_unique<Negative>(std::make_unique<Const>(fr))->evaluate()<<'\n';
}