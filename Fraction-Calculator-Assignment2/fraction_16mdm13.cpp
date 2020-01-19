//
// Created by daniyal on 2019-10-12.
// Netid: 16mdm13
// Student #: 20064993
//

#include "fraction_16mdm13.h"

using namespace std;

Fraction::Fraction(){
    numer = 0;
    denom = 1;
}

Fraction::Fraction(const int& numerator){
    numer = numerator;
    denom = 1;
}

Fraction::Fraction(const int& numerator, const int& denominator){
    if (denominator == 0){
        throw FractionException ("Cannot have zero as a denominator");
    }
    int divider = GCD(abs(numerator), abs(denominator));
    if (denominator < 0){
        numer = -numerator/divider;
        denom = -denominator/divider;
    } else {
        numer = numerator/divider;
        denom = denominator/divider;
    }
}

int Fraction::numerator() const { return numer; }
int Fraction::denominator() const { return denom; }
int Fraction::GCD (const int n, const int m) {
    if ((m <= n) && (n%m == 0)){
        return m;
    }else if(n < m){
        return GCD(m, n);
    }else{
        return GCD(m, n%m);
    }
}
Fraction operator+ (const Fraction& frac1, const Fraction& frac2) {
    if (frac1.denominator() == frac2.denominator()){
        return Fraction(frac1.numerator()+frac2.numerator(), frac1.denominator());
    } else {
        return Fraction((frac1.numerator()*frac2.denominator())+(frac2.numerator()*frac1.denominator()), frac1.denominator()*frac2.denominator());
    }
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2) {
    if (frac1.denominator() == frac2.denominator()){
        return Fraction(frac1.numerator()-frac2.numerator(), frac1.denominator());
    } else {
        return Fraction((frac1.numerator()*frac2.denominator())-(frac2.numerator()*frac1.denominator()), frac1.denominator()*frac2.denominator());
    }
}

Fraction operator* (const Fraction& frac1, const Fraction& frac2) {
    return Fraction(frac1.numerator()*frac2.numerator(), frac1.denominator()*frac2.denominator());
}

Fraction operator/ (const Fraction& frac1, const Fraction& frac2) {
    return Fraction(frac1.numerator()*frac2.denominator(), frac1.denominator()*frac2.numerator());
}

Fraction& Fraction::operator+=(const Fraction& fraction) {
    *this = *this + fraction;
    return *this;
}
bool operator==(const Fraction& frac1, const Fraction& frac2){ return ((frac1.numerator() == frac2.numerator()) && (frac1.denominator() == frac2.denominator())); }
bool operator!=(const Fraction& frac1, const Fraction& frac2){ return !(frac1 == frac2); }
bool operator< (const Fraction& frac1, const Fraction& frac2){ return (static_cast<float>(frac1.numerator())/frac1.denominator()) < (static_cast<float>(frac2.numerator())/frac2.denominator()); }
bool operator> (const Fraction& frac1, const Fraction& frac2){ return (static_cast<float>(frac1.numerator())/frac1.denominator()) > (static_cast<float>(frac2.numerator())/frac2.denominator()); }
bool operator<= (const Fraction& frac1, const Fraction& frac2){ return (static_cast<float>(frac1.numerator())/frac1.denominator()) <= (static_cast<float>(frac2.numerator())/frac2.denominator()); }
bool operator>= (const Fraction& frac1, const Fraction& frac2){ return (static_cast<float>(frac1.numerator())/frac1.denominator()) >= (static_cast<float>(frac2.numerator())/frac2.denominator()); }
Fraction Fraction::operator-() {
    Fraction result(-numer,denom);
    return result;
}
Fraction& Fraction::operator++() {
    numer += denom;
    return *this;
}
Fraction Fraction::operator++(int frac) {
    Fraction result(numer,denom);
    numer += denom;
    return result;
}

ostream& operator<<(ostream &os, const Fraction& frac) {
    os << frac.numerator() << '/' << frac.denominator();
    return os;
}

istream& operator>>(istream &input, Fraction& frac) {
    string inputString;
    input >> inputString;
    auto idx = inputString.find("/");
    try {
        if (idx != string::npos) {
            frac.numer = stoi(inputString.substr(0, static_cast<int>(idx)));
            frac.denom = stoi(inputString.substr(static_cast<int>(idx) + 1, string::npos));
        } else {
            frac.numer = stoi(inputString);
            frac.denom = 1;
        }
    } catch (...) {
        throw FractionException("Incorrect Fraction format inputted");
    }
    return input;
}

// FractionException error class that prints out an error message that is passed in
FractionException::FractionException(const string &msg) : msg_(msg) {}

string FractionException::what() const {
    return msg_;
}