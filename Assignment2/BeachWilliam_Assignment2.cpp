/*
*
William Beach
COP3014
February 12, 2023
Assignment 2 - Loan Calculator that outputs amortized monthly breakdown to file
*
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;


const int NUM_OF_COLUMNS = 5;


// function that greets user and keeps main function clean
void greetUser(string &quit);

// input function that prompts for user input for priciple, interest rate, and length of loan
void getInputs(double &principal, double &interestRate, int &yearsOfLoan);

// function that calculates and updates value of M (monthly payments)
double calcMonthlyPayment(double principal, double interestRate, int yearsOfLoan, int &monthsOfLoan);

// function that calculates interest and balance for each month
void calcInterestAndBalance(double principal, double interestRate, double monthlyPayment, double paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan);

// function that keeps track of total payment and total interest paid 
void calcTotalPayment(double monthlyPayment, double principal, int monthsOfLoan);

// function which displays the table to console and writes table to a file
void output(double paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan);

int main(){
    double principal, monthlyPayment, monthlyInterest, interestRate;
    int yearsOfLoan, monthsOfLoan;
    string quit;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    greetUser(quit);
    while (quit != "quit"){
        getInputs(principal, interestRate, yearsOfLoan);
        monthlyPayment = calcMonthlyPayment(principal, interestRate, yearsOfLoan, monthsOfLoan);
        double paymentArray[monthsOfLoan][NUM_OF_COLUMNS];
        calcInterestAndBalance(principal, interestRate, monthlyPayment, paymentArray, monthsOfLoan);
        output(paymentArray, monthsOfLoan);
        calcTotalPayment(monthlyPayment, principal, monthsOfLoan);
        greetUser(quit);
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

void getInputs(double &principal, double &interestRate, int &yearsOfLoan){
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

double calcMonthlyPayment(double principal, double interestRate, int yearsOfLoan, int &monthsOfLoan){
    monthsOfLoan = yearsOfLoan * 12;
    double monthlyInterest = interestRate / 12.0;
    double monthlyPayment;
    monthlyPayment = principal * ((monthlyInterest * (pow((1+monthlyInterest), monthsOfLoan))) / ((pow((1+monthlyInterest), monthsOfLoan)) - 1));
    return monthlyPayment;
}

void calcInterestAndBalance(double principal, double interestRate, double monthlyPayment, double paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan){
    int i, j;
    double beginningBalance = principal;
    for (i = 0; i < monthsOfLoan; i++){
        double month = i + 1;
        double interest = (beginningBalance * interestRate) / 12.0;
        double paymentAfterInterest = monthlyPayment - interest;
        double endingBalance = beginningBalance - paymentAfterInterest;
        paymentArray[i][0] = month;
        paymentArray[i][1] = beginningBalance;
        paymentArray[i][2] = interest;
        paymentArray[i][3] = paymentAfterInterest;
        paymentArray[i][4] = endingBalance;
        beginningBalance = endingBalance;
    }
}

void calcTotalPayment(double monthlyPayment, double principal, int monthsOfLoan){
    cout << "\n\nPayment Every Month: $" << monthlyPayment << "\n\n";
    cout << "Total of " << monthsOfLoan << " Payments: $" << monthlyPayment * monthsOfLoan << "\n\n";
    cout << "Total Interest: $" << (monthlyPayment * monthsOfLoan) - principal << "\n\n";
}

void output(double paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan){
    int i;
    cout << "Month      " << "Beginning Balance     " << "Interest      " << "Principal     " << "Ending Balance\n\n";
    for (i = 0; i < monthsOfLoan; i++){
        if (i >= 9 && i <= 10){
            cout << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "        $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            cout << "\n\n";
        } else if (i >= 11 && i <= 12){
            cout << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "         $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            cout << "\n\n";
        } else if (i >= 13 && i <= 22){
            cout << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "          $" << 
            paymentArray[i][2] << "         $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            cout << "\n\n";
        } else if (i == 23){
            cout << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "           $" << 
            paymentArray[i][2] << "          $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            cout << "\n\n";
        }
        else {
            cout << "  " << (int)paymentArray[i][0] << "            $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "        $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            cout << "\n\n";
        }
    }
    ofstream output_file("loan_breakdown.txt");
    output_file.setf(ios::fixed);
    output_file.setf(ios::showpoint);
    output_file.precision(2);
    output_file << "Month      " << "Beginning Balance     " << "Interest      " << "Principal     " << "Ending Balance\n\n";
    for (i = 0; i < monthsOfLoan; i++){
        if (i >= 9 && i <= 10){
            output_file << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "        $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            output_file << "\n\n";
        } else if (i >= 11 && i <= 12){
            output_file << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "         $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            output_file << "\n\n";
        } else if (i >= 13 && i <= 22){
            output_file << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "          $" << 
            paymentArray[i][2] << "         $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            output_file << "\n\n";
        } else if (i == 23){
            output_file << "  " << (int)paymentArray[i][0] << "           $" << 
            paymentArray[i][1] << "           $" << 
            paymentArray[i][2] << "          $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            output_file << "\n\n";
        }
        else {
            output_file << "  " << (int)paymentArray[i][0] << "            $" << 
            paymentArray[i][1] << "         $" << 
            paymentArray[i][2] << "        $" << paymentArray[i][3] << "        $" << 
            paymentArray[i][4];
            output_file << "\n\n";
        }
    }
    output_file.close();
}