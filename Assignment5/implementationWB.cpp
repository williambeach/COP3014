/*
*
*
William Beach 
COP3014 - Assignment 5 - implementation file
04/09/2023
*
*
*/

#include <iostream>
#include <string>
#include "rationalsWB.hpp"
using namespace std;

namespace{
    void notZero(int denominator){
      if (denominator == 0){
        cout << "Denominator equals zero, can't divide by zero" << endl;
        cout << "Exiting program" << endl;
        exit(1);
      }
    }
}

namespace rationalbeach{

    Rational::Rational(int num, int den){
      notZero(den);
      this->numerator = num;
      this->denominator = den;
    }

    ostream& operator <<(ostream& out, Rational& rational){
      out << rational.numerator << "/" << rational.denominator;
      return out;
    }

    istream& operator >>(istream& in, Rational& rational){
      string input;
      int index;
      getline(in, input);
      index = input.find("/", 0);
      int num = stoi(input.substr(0, index));
      int den = stoi(input.substr(index+1, input.length()));
      rational.numerator = num;
      rational.denominator = den;
      return in;
    }

    Rational operator -(const Rational& rat){
      Rational temp;
      temp.numerator = -rat.numerator;
      return temp;
    }

    Rational operator +(const Rational& rat1, const Rational& rat2){
      Rational temp;
      temp.numerator = (rat1.numerator * rat2.denominator) + (rat1.denominator * rat2.numerator);
      temp.denominator = rat1.denominator * rat2.denominator;
      return temp;
    }

    Rational operator -(const Rational& rat1, const Rational& rat2){
      Rational temp;
      temp.numerator = (rat1.numerator * rat2.denominator) - (rat1.denominator * rat2.numerator);
      temp.denominator = rat1.denominator * rat2.denominator;
      return temp;
    }

    Rational operator *(const Rational& rat1, const Rational& rat2){
      Rational temp;
      temp.numerator = rat1.numerator * rat2.numerator;
      temp.denominator = rat1.denominator * rat2.denominator;
      return temp;
    }

    Rational operator /(const Rational& rat1, const Rational& rat2){
      Rational temp;
      temp.numerator = rat1.numerator * rat2.denominator;
      temp.denominator = rat2.numerator * rat1.denominator;
      return temp;
    }

    bool operator <(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) < (rat2.numerator * rat1.denominator);
    }

    bool operator >(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) > (rat2.numerator * rat1.denominator);
    }

    bool operator ==(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) == (rat2.numerator * rat1.denominator);
    }

    bool operator !=(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) != (rat2.numerator * rat1.denominator);
    }

    bool operator <=(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) <= (rat2.numerator * rat1.denominator);
    }

    bool operator >=(const Rational& rat1, const Rational& rat2){
      return (rat1.numerator * rat2.denominator) >= (rat2.numerator * rat1.denominator);
    }

}