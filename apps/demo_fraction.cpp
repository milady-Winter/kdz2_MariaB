#include<iostream>
#include"ratexpr/fraction.hpp"

using ratexpr::Fraction;

void cnt(int u){
    Fraction h(1, 2), a(2*u);
    std::cout<<h+a<<" "<<a+h<<'\n';
    std::cout << h - a << " " << a - h << '\n';
    std::cout << h / a << " " << a / h << '\n';
    Fraction acc;
    acc += Fraction(1, 2);
    acc += Fraction(1, 3);
    acc *= 6u;
    std::cout<<"acc = " << acc << '\n';
}
void mis1(){
    try {
        std::cout << Fraction(1, 0) << '\n';
    } catch (const std::invalid_argument& err) {
        std::cout<<"Invalid argument:" << err.what()<<'\n';
    }
}
void mis2(int u){
    try {
        std::cout << Fraction(1, 2) / (0 * u);
    } catch (const std::invalid_argument& err) {
        std::cout << "Invalid argument:" << err.what() << '\n';
    }
}
void chk_err() { std::cout << Fraction(1, 2) * -1; }
int main() {
    std::cout << Fraction(6, -8) << " " << Fraction(10, 4) << '\n';
    std::cout << Fraction(1, 2) + Fraction(1, 3) << " "  << Fraction(1, 2) - Fraction(1, 3) << " " << Fraction(1,2) * Fraction(1,3) << " " << Fraction(1,2) / Fraction(1,3) << '\n';
    int u;
    std::cin>>u;
    cnt(u);
    mis1();
    mis2(u);
    //chk_err();
}
