/* 

** Assignment 1 **

Purpose: 

1. To generate a coin dispenser machine that converts 
dollar amounts to change and vice-versa.

Author: William Beach

Last Edited: January 20, 2023

I built both problems into the main function as option selections^^

*/

#include <iostream>
using namespace std;


//function prototype declarations
void intro(int *ptr);
void outro();
void conversionSelect(int choice);
void dollarsToChange();
void changeToDollars();
void changeConverter(int change, int modulo, int counter, int array[], int divisorArray[]);

int main() {
    int choice;
    intro(&choice); //ask user which conversion they want dollars -> coins or coins -> dollars
    while (choice == 1 || choice == 2) { // hit a different key to end program
        conversionSelect(choice); // conditional selector 
        intro(&choice); // ask user until they want to end program
    }
    outro(); // say goodbye
    return 0;
}


void intro(int *ptr){ // welcome user, get choice
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

void outro() { // say goodbye to user
    cout << "----------------------------------------------------\n";
    cout << "Thank you for using our change dispenser/converter\n\n";
}

void conversionSelect(int choice){ // chooses which conversion function to run
    if (choice == 1){
        dollarsToChange();
    } else {
        changeToDollars();
    }
}

void dollarsToChange(){ // converts dollars to change amounts 
    float dollars;
    int change, modulo = 1, counter = 0;
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
    changeConverter(change, modulo, counter, array, divisorArray); // recursive function to convert to change
    cout << "Original Amount: $" << dollars << endl;
    cout << "\nThis is equal to " << array[0] << " quarters, " << array[1] << " dimes, " << array[2] 
    << " nickels, and " << array[3] << " pennies" << endl; 
}

void changeToDollars(){ //converts from change to dollar amount
    int quarters, dimes, nickels, pennies;
    float total;
    cout << "Enter number of quarters, dimes, nickles and pennies" << endl;
    cout << "with format <quarters> <dimes> <nickels> <pennies>\n";
    cout << "with a space between each denomination\n\n";
    cin >> quarters >> dimes >> nickels >> pennies;
    total = ((quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies)) / 100.0;
    cout << "\n\n";
    cout << "\nYou entered " << quarters << " quarters, " << dimes << " dimes, " << nickels 
    << " nickels, and " << pennies << " pennies" << endl;
    cout << "This is equal to $" << total;

}
// converts dollar amt to change by using recursive modulo basecase and counter to fetch and store array data
void changeConverter(int change, int modulo, int counter, int array[], int divisorArray[]) {
    if (modulo == 0){
        return;
    } else {
       array[counter] = change / divisorArray[counter];
       change = change % divisorArray[counter];
       modulo = change;
       counter += 1;
       return changeConverter(change, modulo, counter, array, divisorArray);
    }
}

