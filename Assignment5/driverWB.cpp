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
#include "rationalsWB.hpp"

int main() {
    using namespace std;
    using namespace rationalbeach;
    
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

    Rational rat4(3,2);
    
    return 0;
}