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
void calcInterestAndBalance(double principal, double interestRate, double monthlyPayment, string paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan);

// function that keeps track of total payment and total interest paid 
void calcTotalPayment(double monthlyPayment, double principal, int monthsOfLoan);

// function which displays the table to console and writes table to a file
void outputToFileAndConsole(string paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan);

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
        string paymentArray[monthsOfLoan][NUM_OF_COLUMNS];
        calcInterestAndBalance(principal, interestRate, monthlyPayment, paymentArray, monthsOfLoan);
        outputToFileAndConsole(paymentArray, monthsOfLoan);
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

void calcInterestAndBalance(double principal, double interestRate, double monthlyPayment, string paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan){
    int i, j;
    double beginningBalance = principal;
    for (i = 0; i < monthsOfLoan; i++){
        double month = i + 1;
        double interest = (beginningBalance * interestRate) / 12.0;
        double paymentAfterInterest = monthlyPayment - interest;
        double endingBalance = beginningBalance - paymentAfterInterest;
        paymentArray[i][0] = to_string(month); //convert numbers to strings before storing in array 
        paymentArray[i][1] = "$" + to_string(beginningBalance);
        paymentArray[i][2] = "$" + to_string(interest);
        paymentArray[i][3] = "$" + to_string(paymentAfterInterest);
        paymentArray[i][4] = "$" + to_string(endingBalance);
        beginningBalance = endingBalance;
    }
}

void calcTotalPayment(double monthlyPayment, double principal, int monthsOfLoan){
    cout << "\n\nPayment Every Month: $" << monthlyPayment << "\n\n";
    cout << "Total of " << monthsOfLoan << " Payments: $" << monthlyPayment * monthsOfLoan << "\n\n";
    cout << "Total Interest: $" << (monthlyPayment * monthsOfLoan) - principal << "\n\n";
}



void outputToFileAndConsole(string paymentArray[][NUM_OF_COLUMNS], int monthsOfLoan){
  int dollarLengths[4];
  int i, index;
  cout << "Month";
  cout.width(20);
  cout << "Beginning Balance" ;
  cout.width(13);
  cout << "Interest"; 
  cout.width(14);
  cout << "Principal";
  cout.width(20);
  cout << "Ending Balance\n\n";
  for (i = 0; i < monthsOfLoan; i++){
      cout.width(3);
    if (i >= 9){
      cout << paymentArray[i][0].substr(0,2);
    } else{
      cout << paymentArray[i][0].substr(0,1);
    }
    cout.width(17);
    index = paymentArray[i][1].find("."); //stored numbers as strings so I can use string functions on data before outputting
    cout << paymentArray[i][1].substr(0, index + 3);
    cout.width(17);
    index = paymentArray[i][2].find(".");
    cout << paymentArray[i][2].substr(0, index+3);
    cout.width(14);
    index = paymentArray[i][3].find(".");
    cout << paymentArray[i][3].substr(0, index+3);
    cout.width(16);
    index = paymentArray[i][4].find(".");
    cout << paymentArray[i][4].substr(0, index+3);
    cout << "\n\n";
    }
  ofstream outfile("loanbreakdown.txt");
  outfile.setf(ios::fixed);
  outfile.setf(ios::showpoint);
  outfile.precision(2);
  outfile << "Month";
  outfile.width(20);
  outfile << "Beginning Balance" ;
  outfile.width(13);
  outfile << "Interest"; 
  outfile.width(14);
  outfile << "Principal";
  outfile.width(20);
  outfile << "Ending Balance\n\n";
  for (i = 0; i < monthsOfLoan; i++){
    outfile.width(3);
    if (i >= 9){
      outfile << paymentArray[i][0].substr(0,2);
    } else{
      outfile << paymentArray[i][0].substr(0,1);
    }
    outfile.width(17);
    index = paymentArray[i][1].find(".");
    outfile << paymentArray[i][1].substr(0, index + 3);
    outfile.width(17);
    index = paymentArray[i][2].find(".");
    outfile << paymentArray[i][2].substr(0, index+3);
    outfile.width(14);
    index = paymentArray[i][3].find(".");
    outfile << paymentArray[i][3].substr(0, index+3);
    outfile.width(16);
    index = paymentArray[i][4].find(".");
    outfile << paymentArray[i][4].substr(0, index+3);
    outfile << "\n\n";
    }
}