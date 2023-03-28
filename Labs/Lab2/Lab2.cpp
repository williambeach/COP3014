/*
*
William Beach 
Lab 2 - Classes, constructors, Money class practice lab
03/16/23
*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class Money{

    public:
    //constructor definitions
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    Money add(const Money &object) const;
    bool equal(const Money &object) const;
    Money subtract(const Money &object) const;
    double getValue() const;
    void setValue();
    void output();
    void output(ostream &out);
    void input(istream &in);

    private:
    //total dollars and cents are stored as cents
    int cents;


};





int main(){
    //set console output to two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //create output files for output and input
    ofstream outfile("money.txt"), createFile("newfile.txt");
    createFile << "-$450.00";
    createFile.close();
    ifstream readCreateFile("newfile.txt");
    //set file output to two decimal places
    outfile.setf(ios::fixed);
    outfile.setf(ios::showpoint);
    outfile.precision(2);

    //use of overloaded constructor functions to create instances of Money class
    Money bankAccount1, bankAccount2(453453, 300000), bankAccount3,
    bankAccount4(4564561); 

    bankAccount3 = bankAccount1.add(bankAccount2);
    cout << bankAccount3.equal(bankAccount2) << endl;
    cout << bankAccount3.getValue() << endl;
    
    bankAccount3 = bankAccount1.subtract(bankAccount2);
    cout << bankAccount3.equal(bankAccount2) << endl;
    cout << bankAccount1.getValue() << endl;
    cout << bankAccount4.getValue() << endl;
    
    bankAccount3.setValue();
    cout << bankAccount3.getValue() << endl;
    
    bankAccount3.output();
    bankAccount3.output(outfile);
    bankAccount1.input(readCreateFile);
    cout << bankAccount1.getValue() << endl;
    
    createFile.close();
    outfile.close();

    return 0;
}

Money::Money(long dollars, int cents){
    this -> cents = cents + dollars * 100;
}


Money::Money(long dollars){
    this -> cents = dollars * 100;
}

Money::Money(){
    this -> cents = 0;
}

Money Money::add(const Money &object) const{
    Money instance;
    instance.cents = this -> cents + object.cents;
    return instance;
}

bool Money::equal(const Money &object) const{
    return this -> cents == object.cents;
}

Money Money::subtract(const Money &object) const{
    Money instance;
    instance.cents = this -> cents - object.cents;
    return instance;
}

double Money::getValue() const{
    return this -> cents / 100.0;
}

void Money::setValue(){
    cout << "Enter number of pennies: ";
    cin >> this -> cents;
}

void Money::output(){
    cout << "Money: $" << this -> getValue() << endl;
}

void Money::output(ostream &out){
    this -> output();
}

void Money::input(istream &in){
    string input;
    in >> input;
    double amount;
    if (input[0] == '-'){
        amount = -1 * stod(input.substr(2));
    } else {
        amount = stod(input.substr(1));
    }
    this -> cents = amount * 100;
}