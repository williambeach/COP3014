/*
*
*
William Beach 
COP3014 - Assignment 5 - interface file
04/09/2023
*
*
*/

#include <iostream>
#include <string>
using namespace std;

// rat = rational; rat1, rat2, etc = rational1, rational2...

class Rational{
    public:
        //constructor: 2 arguments; creates rational object: num = numerator / den = denominator
	    Rational(int num, int den) : numerator(num), denominator(den){};
        //constructor: 1 argument; creates rational object: num = numerator / den = denominator defaults to 1
        Rational(int num): numerator(num), denominator(1){};
        //default constructor: no arguments; creates rational object: numerator = 0 / denominator = 1
	    Rational() : numerator(0), denominator(1){};
        //cout or file ptr << Rational object --> prints to output stream rational number in format 'numerator/denominator'
	    friend ostream& operator <<(ostream& out, Rational& rational);
        //initializes Rational object with input stream in format 'numerator/denominator'
        friend istream& operator >>(istream& in, Rational& rational);
        //multiplies numerator of Rational object by a negative 1; -rational = -1 * rational.numerator
        friend Rational operator -(const Rational& rat);
        //sum two Rational objects and return the result; rational1 + rational2
        friend Rational operator +(const Rational& rat1, const Rational& rat2);
        //subtract two Rational objects and return the result; rational1 - rational2
        friend Rational operator -(const Rational& rat1, const Rational& rat2);
        //multiply two Rational objects and return the result; rational1 * rational2
        friend Rational operator *(const Rational& rat1, const Rational& rat2);
        //divide two Rational objects and return result; rational1 / rational2
        friend Rational operator /(const Rational& rat1, const Rational& rat2);
        //return true if rational1 < rational2
        friend bool operator <(const Rational& rat1, const Rational& rat2);
        //return true if rational1 > rational2
        friend bool operator >(const Rational& rat1, const Rational& rat2);
        //return true if rational1 == rational2
        friend bool operator ==(const Rational& rat1, const Rational& rat2);
        //return true if rational1 not equal to rational2
        friend bool operator !=(const Rational& rat1, const Rational& rat2);
        //return true if rational1 less than or equal to rational2
        friend bool operator <=(const Rational& rat1, const Rational& rat2);
        //return true if rational1 greater than or equal to rational2
        friend bool operator >=(const Rational& rat1, const Rational& rat2);
    private:
	    int numerator;
	    int denominator;
};