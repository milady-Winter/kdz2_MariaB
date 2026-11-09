#include<iostream>
#include"ratexpr/fraction.hpp"

using ratexpr::Fraction;

void cnt(int u){
    Fraction h(1, 2), a(2*u);
    std::cout<<h+a<<" "<<a+h<<'\n';
    std::cout << h - a << " " << a - h << '\n';
    std::cout << h / a << " " << a / h << '\n';
    Fraction acc;
    acc += 1/2;
    acc += 1/3;
    acc *= 6u;
    std::cout<<"acc = " << acc << '\n';
}
void mis(int u){
    std::cout<<Fraction(1,0) << '\n';
    std::cout<<Fraction(1,2) / (0*u);
}
int main() {
    std::cout << Fraction(6, -8) << " " << Fraction(10, 4) << '\n';
    std::cout << Fraction(1, 2) + Fraction(1, 3) << " "  << Fraction(1, 2) - Fraction(1, 3) << " " << Fraction(1,2) * Fraction(1,3) << " " << Fraction(1,2) / Fraction(1,3) << '/n';
    int u;
    std::cin>>u;
    cnt(u);
    mis(u);
}
