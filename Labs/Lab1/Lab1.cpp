/*
*
William Beach 
COP3014 - Lab 1
02/16/2023
Program that gets input from user to calculate Hat size, jacket size, and waist size currently and in 10+ years
*
*/


#include <iostream>
#include <fstream>
using namespace std;


void getInputs(int &height, int &weight, int &age);
void hatSize(int weight, int height, double &hat);
void jacketSize(int weight, int height, int age, double &jacket, double &jacket10Yrs);
void waistInInches(int weight, int age, double &waist, double &waist10Yrs);
void outputToFileAndConsole(double hat, double jacket, double jacket10Yrs, double waist, double waist10Yrs);

int main(){
  int height, weight, age;
  double hat, jacket, jacket10Yrs, waist, waist10Yrs;
  char quit = 'y';
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  while (quit == 'y' || quit == 'Y'){
    getInputs(height, weight, age);
    hatSize(weight, height, hat);
    jacketSize(weight, height, age, jacket, jacket10Yrs);
    waistInInches(weight, age, waist, waist10Yrs);
    outputToFileAndConsole(hat, jacket, jacket10Yrs, waist, waist10Yrs);
    cout << "Enter Y or y to repeat, any other character ends: \n";
    cin >> quit;
  }


  return 0;
}



void getInputs(int &height, int &weight, int &age){
    cout << "Enter your height in inches, weight in pounds, and age in years and I will give you your hat size, jacket size(inches at chest) and your waist size in inches.\n\n";
    cout << "I will also give you your hat size, jacket size, and waist size 10 years into the future.\n\n";
    cin >> height >> weight >> age;
    cout << "\n\n";
}

void hatSize(int weight, int height, double &hat){
  hat = ((double)weight / (double)height) * 2.9;
}

void jacketSize(int weight, int height, int age, double &jacket, double &jacket10Yrs){
  int adjustment;
  int agePlus10 = age + 10;
  if ((age - 30) >= 10){ 
    adjustment = age - 30; 
    adjustment = adjustment / 10; 
  } else {
    adjustment = 0;
  }
  jacket = (((double)height * (double)weight) / 288.0) + (double)(adjustment * 1.0/8.0);
  if ((agePlus10 - 30) >= 10){ 
    adjustment = agePlus10 - 30; 
    adjustment = adjustment / 10; 
  } else {
    adjustment = 0;
  }
  jacket10Yrs = (((double)height * (double)weight) / 288.0) + (double)(adjustment * 1.0/8.0);
}



void waistInInches(int weight, int age, double &waist, double &waist10Yrs){
  int adjustment;
  int agePlus10 = age + 10;
  if (age >= 30){
    adjustment = age - 28;
    adjustment = adjustment / 2;
  } else {
    adjustment = 0;
  }
  waist = ((double)weight / 5.7) + (double)adjustment * 1.0 / 10.0;
  if (agePlus10 >= 30){
    adjustment = agePlus10 - 28;
    adjustment = adjustment / 2;
  } else {
    adjustment = 0;
  }
  waist10Yrs = ((double)weight / 5.7) + (double)adjustment * 1.0 / 10.0;
}

void outputToFileAndConsole(double hat, double jacket, double jacket10Yrs, double waist, double waist10Yrs){
    ofstream myfile("clothingsizes.txt");
    myfile.setf(ios::fixed, ios::showpoint);
    myfile.precision(2);
    myfile << "Current Clothing Measurements:\n\n";
    myfile << "Hat size = " << hat << "\n\n";
    myfile << "Jacket size = " << jacket << "\n\n";
    myfile << "Waist size = " << waist << "\n\n";
    myfile << "Clothing Measurements in 10 Years:\n\n";
    myfile << "Hat size = " << hat << "\n\n";
    myfile << "Jacket size = " << jacket10Yrs << "\n\n";
    myfile << "Waist size = " << waist10Yrs << "\n\n";
    cout << "Current Clothing Measurements\n\n";
    cout << "Hat size = " << hat << "\n\n";
    cout << "Jacket size = " << jacket << "\n\n";
    cout << "Waist size = " << waist << "\n\n";
    cout << "Clothing Measurements in 10 Years\n\n";
    cout << "Hat size = " << hat << "\n\n";
    cout << "Jacket size = " << jacket10Yrs << "\n\n";
    cout << "Waist size = " << waist10Yrs << "\n\n";
}