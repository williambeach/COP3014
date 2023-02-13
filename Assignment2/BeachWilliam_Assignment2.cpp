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
#include <string.h>
using namespace std;

ofstream output_file; // create an output file object



// function that greets user and keeps main function clean
void greetUser(string &quit);

// input function that prompts for user input for priciple, interest rate, and length of loan
void getInputs(double &principal, float &interestRate, int &yearsOfLoan);

// function that calculates and updates value of M (monthly payments)
double calcMonthlyPayments(double principal, float interestRate, int yearsOfLoan);

// 

int main(){
    double principal, monthlyPayment;
    float interestRate;
    int yearsOfLoan;
    string quit;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    while (quit != "quit"){
        greetUser(quit);
        if (quit == "quit"){
            break;
        } else{
            getInputs(principal, interestRate, yearsOfLoan);
            calcMonthlyPayments(principal, interestRate, yearsOfLoan);

        }
        
    }

    return 0;
}

void greetUser(string &quit){
    cout << "\n\n";
    cout << "--------------------------------------------\n";
    cout << "--------------------------------------------\n";
    cout << "    Calculate Your Monthly Loan Payments\n";
    cout << "--------------------------------------------\n";
    cout << "--------------------------------------------\n\n";
    cout << "Please enter 'quit' to end program\n";
    cout << "Or 'start' to begin loan program\n\n";
    cin >> quit;
}

void getInputs(double &principal, float &interestRate, int &yearsOfLoan){
    cout << "\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "       Thank you for choosing start\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "     How much would you like to borrow?: \n\n";
    cout << "----------------> $";
    cin >> principal;
    cout << "\n\n";
    cout << "--------------------------------------------\n\n";
    cout << "         You entered $" << principal << endl << endl; 
    cout << "--------------------------------------------\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "       Enter the annual interest rate: \n\n";
    cout << "----------------> ";
    cin >> interestRate;
    cout << "\n\n";
    cout << "--------------------------------------------\n\n";
    cout << "              You entered: " << interestRate << "%\n\n"; 
    interestRate = interestRate / 100.0;
    cout << "--------------------------------------------\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "  How many years is the life of the loan: \n\n";
    cout << "----------------> ";
    cin >> yearsOfLoan;
    cout << "\n\n";
    cout << "--------------------------------------------\n\n";
    cout << "              You entered: " << yearsOfLoan << " years\n\n"; 
    cout << "--------------------------------------------\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "\n\n";
}

/* 

M = P ((r(1+r)^n) / (((1+r)^n) - 1))

where M == monthly payment amount ($USD)
n == length of loan (in months)
P == principal amount of loan (user inputted) ($USD) (desired amount to borrow from creditor)
r == monthly interest, (annual interest rate (user inputted) / 12.0) 

*/

double calcMonthlyPayments(double principal, float interestRate, int yearsOfLoan){
    int numberOfMonths = yearsOfLoan * 12;
    double monthlyInterest = interestRate / 12.0;
    double monthlyPayments;
    monthlyPayments = principal * ((monthlyInterest * (pow((1+monthlyInterest), numberOfMonths))) / ((pow((1+monthlyInterest), numberOfMonths)) - 1));
    return monthlyPayments;
}