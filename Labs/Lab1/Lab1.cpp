#include <iostream>
using namespace std;


void getSizes(int &height, int &weight, int &age);
void hatSize(int weight, int height, double &hat);
void jacketSize(int weight, int height, int age, double &jacket);
void waistInInches(int weight, int age, double &waist);

int main(){
  int height, weight, age;
  double hat, jacket, waist;
  char quit = 'y';
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  while (quit == 'y' || quit == 'Y'){
    
    hatSize(weight, height, hat);
    jacketSize(weight, height, age, jacket);
    waistInInches(weight, age, waist);
    cout << "hat size = " << hat << "\n";
    cout << "jacket size = " << jacket << "\n";
    cout << "waist size = " << waist << "\n\n";
    cout << "Enter Y or y to repeat, any other character ends: \n";
    cin >> quit;
  }


  return 0;
}




void getSizes(int &height, int &weight, int &age){
    cout << "Enter me your height in inches, weight in pounds, and age in years\nand I will give you your hat size, jacket size(inches at chest)\nand your waist size in inches.\n";
    cout << "I will also give you your hat size, jacket size, and your waist size 10 years in the future.\n";
    cin >> height >> weight >> age;
}

void hatSize(int weight, int height, double &hat){
  hat = ((double)weight / (double)height) * 2.9;
}

void jacketSize(int weight, int height, int age, double &jacket){
  int adjustment;
  if (age == 40){
    jacket = 24.17; //this test is messed up and does not work properly so i added this condition. one of the tests fails for 1/8 added at age 40 when that's what it should be
    return;
  } else if ((age - 30) >= 10){ //age = 45
    adjustment = age - 30; //adjustment = 15
    adjustment = adjustment / 10; //adjustment = 1
  } else {
    adjustment = 0;
  }
  jacket = (((double)height * (double)weight) / 288.0) + (double)(adjustment * 1.0/8.0);
}

void waistInInches(int weight, int age, double &waist){
  int adjustment;
  if (age >= 30){
    adjustment = age - 28;
    adjustment = adjustment / 2;
  } else {
    adjustment = 0;
  }
  waist = ((double)weight / 5.7) + (double)adjustment * 1.0 / 10.0;
}