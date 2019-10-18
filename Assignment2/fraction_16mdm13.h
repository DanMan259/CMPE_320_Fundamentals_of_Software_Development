//
// Created by daniyal on 2019-10-12.
// Netid: 16mdm13
// Student #: 20064993
//
#pragma once

#ifndef ASSIGNMENT2_FRACTION_16MDM13_H
#define ASSIGNMENT2_FRACTION_16MDM13_H

#include <ostream>
#include <iostream>

using namespace std;


class Fraction {
private:
    int numer;  // Stored Numerator
    int denom;  // Stored Denominator
public:
    Fraction(); // No Input Constructor
    Fraction(const int& numerator);     // Single Input Constructor
    Fraction(const int& numerator, const int& denominator);     // Double Input Constructor
    int numerator() const;      // Numerator Accessor
    int denominator() const;    // Denominator Accessor
    static int GCD(int n, int m);   // GCD Algorithm to get the divisor
    // Operator Overloading
    friend Fraction operator+ (const Fraction& frac1, const Fraction& frac2);   // Addition Operator
    friend Fraction operator- (const Fraction& frac1, const Fraction& frac2);   // Subtraction Operator
    friend Fraction operator* (const Fraction& frac1, const Fraction& frac2);   // Multiplication Operator
    friend Fraction operator/ (const Fraction& frac1, const Fraction& frac2);   // Division Operator
    Fraction& operator+=(const Fraction& fraction);     // Addition to existing Operator
    friend bool operator==(const Fraction& frac1, const Fraction& frac2);       // Equals Operator
    friend bool operator!=(const Fraction& frac1, const Fraction& frac2);       // Not Equals Operator Overloading
    friend bool operator< (const Fraction& frac1, const Fraction& frac2);       // Less than
    friend bool operator> (const Fraction& frac1, const Fraction& frac2);       // Greater than
    friend bool operator<=(const Fraction& frac1, const Fraction& frac2);       // Less Than or equal
    friend bool operator>=(const Fraction& frac1, const Fraction& frac2);       // Greater Than or equal
    Fraction operator-();               // Unary Operation
    Fraction& operator++();             // Prefix increment operator.
    Fraction operator++(int frac);      // Postfix increment operator.
    friend ostream& operator << (ostream& out, const Fraction& frac);           // Output bitshift operator
    friend istream& operator >> (istream& input, Fraction& frac);               // Input bitshift operator
};

// Class definition of FractionException Class
class FractionException{
public:
    FractionException (const string& msg);
    string what() const;
private:
    string msg_;
};


#endif //ASSIGNMENT2_FRACTION_16MDM13_H
