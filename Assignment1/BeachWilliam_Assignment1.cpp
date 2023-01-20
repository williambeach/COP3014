/* 

** Assignment 1 **

Purpose: 

1. To generate a coin dispenser machine that converts 
dollar amounts to change and vice-versa.

Author: William Beach

Last Edited: January 19, 2023

*/

#include <iostream>
using namespace std;

void intro(int *ptr);
void outro();
void conversionSelect(int choice, float *dollars, float *change);
float dollarsToChange();
float changeToDollars();

int main() {
    int choice;
    float dollars, change;
    intro(&choice);
    while (choice == 1 || choice == 2) {
        conversionSelect(choice, &dollars, &change);
    }
    
    outro();
    return 0;
}


void intro(int *ptr){
    cout << endl;
    cout << " __________________________________________\n";
    cout << "|                                          |\n";
    cout << "|        Welcome to the Coin Dispenser     |\n";
    cout << "|__________________________________________|\n";
    cout << "\n\n";
    cout << "Press <1> and hit enter for Dollars to Change Conversion\n";
    cout << "Press <2> and hit enter for Change to Dollars Conversion\n";
    cout << "Press any other character and hit enter to end Coin Dispenser\n";
    cout << "\n\n" ;
    cin >> *ptr;
    cout << "\n\n" ;
    cout << "You pressed: " << *ptr;
    cout << "\n\n";
}

void outro() {
    cout << "Thank you for using our change dispenser/converter\n\n";
}

void conversionSelect(int choice, float *dollars, float *change){
    switch (choice){
        case 1:
            *dollars = dollarsToChange();
            break;
        case 2:
            //*change = changeToDollars();
            break;
    }
}

float dollarsToChange(){
    float dollars;
    cout << "Please enter number of dollars and change: " << endl;
    cout << "In format '$x.xx' \n";
    cout << "Then press enter\n\n";
    cin >> dollars;
    cout << "\n\n";
    cout << dollars;
    cout << "\n\n";
}