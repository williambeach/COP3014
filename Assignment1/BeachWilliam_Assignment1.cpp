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
void conversionSelect(int choice);
void dollarsToChange();
void changeToDollars();
void changeConverter(int change, int modulo, int marker, int array[], int divisorArray[]);

int main() {
    int choice;
    intro(&choice);
    while (choice == 1 || choice == 2) {
        conversionSelect(choice);
        intro(&choice);
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

void conversionSelect(int choice){
    if (choice == 1){
        dollarsToChange();
    } else {
        changeToDollars();
    }
}

void dollarsToChange(){
    float dollars;
    int change, modulo = 1, marker = 0;
    int array[] = {0, 0, 0, 0};
    int divisorArray[] = {25, 10, 5, 1};
    cout << "Please enter number of dollars and change: " << endl;
    cout << "In format '$x.xx' \n";
    cout << "Then press enter\n\n";
    cin >> dollars;
    cout << "\n\n";
    cout << "You entered: $" << dollars;
    cout << "\n\n";
    change = dollars * 100;
    changeConverter(change, modulo, marker, array, divisorArray);
    cout << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << endl;
}

void changeToDollars(){
    float change;
    cout << "Please enter number of quarters, dimes, nickles and pennies" << endl;
    cout << "in the format <quarters> <dimes> <nickels> <pennies>\n";
    cout << "with a space between each denomination\n\n";
    
}

void changeConverter(int change, int modulo, int marker, int array[], int divisorArray[]) {
    if (modulo == 0){
        return;
    } else {
       array[marker] = change / divisorArray[marker];
       change = change % divisorArray[marker];
       modulo = change;
       marker += 1;
       return changeConverter(change, modulo, marker, array, divisorArray);

    }
}