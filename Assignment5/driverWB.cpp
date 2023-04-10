/*
*
*
William Beach 
COP3014 - Assignment 5 - driver file
04/09/2023
*
*
*/

#include <iostream>
#include <string>
#include "rationalsWB.h"

int main() {
    using namespace std;
    using namespace rationalbeach;
    cout.setf(ios::boolalpha);
    
    Rational rat1, rat2, rat3;
    cout << "Enter two rational numbers: ";
    cin >> rat1 >> rat2;
    rat3 = rat1 + rat2;
    cout << rat1 << " + " << rat2 << " = " << rat3 << endl;
    rat3 = rat1 - rat2;
    cout << rat1 << " - " << rat2 << " = " << rat3 << endl;
    rat3 = rat1 * rat2;
    cout << rat1 << " * " << rat2 << " = " << rat3 << endl;
    rat3 = rat1 / rat2;
    cout << rat1 << " / " << rat2 << " = " << rat3 << endl;
    cout << rat1 << " < " << rat2 << " = " << (rat1 < rat2) << endl;
    cout << rat1 << " > " << rat2 << " = " << (rat1 > rat2) << endl;
    cout << rat1 << " == " << rat2 << " = " << (rat1 == rat2) << endl;
    cout << rat1 << " != " << rat2 << " = " << (rat1 != rat2) << endl;
    cout << rat1 << " <= " << rat2 << " = " << (rat1 <= rat2) << endl;
    cout << rat1 << " >= " << rat2 << " = " << (rat1 >= rat2) << endl;

    //calling the two integer parameter constructor passes denominator to notZero function to test for division by zero
    Rational rat4(3, 2);
    cout << rat4 << endl;

    // test division with zero in numerator
    Rational rat5, rat6;
    Rational rat7 = rat5 / rat6;
    cout << rat7 << endl;

    // negative numerator and denominator
    Rational rat8(-1, -8), rat9(-2, -9);
    Rational rat10 = rat8 / rat9;
    cout << rat10;
    return 0;
}
    
