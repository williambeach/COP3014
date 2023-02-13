/*
*
William Beach
COP3014
February 12, 2023
Assignment 2 - Loan Calculator that outputs amortized breakdown to file
*
*/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

ofstream output_file; // create an output file object



/* 

M = P ((r(1+r)^n) / (((1+r)^n) - 1))

where M == monthly payment amount ($USD)
n == LENGTH_OF_LOAN (in months)
P == principal amount of loan (user inputted) ($USD) (desired amount to borrow from creditor)
r == monthly interest, (annual interest rate (user inputted) / 12.0) 

*/

