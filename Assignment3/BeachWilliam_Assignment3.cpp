/*
*
William Beach
COP3014 - Assignment 3 - Creation and testing of class COP3014 in C++
02/26/2023
*
*/

#include <iostream>
#include <string.h>
using namespace std;





class COP3014{
    public:
        
        COP3014 createStudent(); // user input constructor method
        COP3014(); // default constructor
        COP3014(string first_name, string last_name, string z_number, double quiz_1,
        double quiz_2, double quiz_3, double mid_term, double final_score); // constructor with parameters
        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_zNumber(string z_Number);
        void set_quiz1(double quiz_1);
        void set_quiz2(double quiz_2);
        void set_quiz3(double quiz_3);
        void set_midterm(double mid_term);
        void set_final(double final_score);
        
        string get_first_name();
        string get_last_name();
        string get_zNumber();
        double get_quiz1();
        double get_quiz2();
        double get_quiz3();
        double get_midterm();
        double get_final();

        void computeTotalGrade();
        void computeTotalLetterGrade();
        void isAbsent();
        void output();

    private:
        
        string firstName, lastName, zNumber;
        double quiz1, quiz2, quiz3, midterm, final, total_grade;
        char final_letter_grade;

};


int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    COP3014 joe, william("william", "beach", "z23194964", 20, 10, 20, 80, 90); //declare two student objects using default and parameter constructors
    COP3014 student = student.createStudent(); // create student using user input

    joe.output(); // output student scores and grades
    william.output();
    student.output();
    
    return 0;
}

COP3014 COP3014::createStudent(){
    string first, last, zNumber;
    double quiz1, quiz2, quiz3, midterm, final;
    cout << "Enter Student First Name: ";
    cin >> first;
    cout << "\nEnter Student Last Name: ";
    cin >> last;
    cout << "\nEnter Student Z Number: ";
    cin >> zNumber;
    cout << "\nEnter quiz 1 score: ";
    cin >> quiz1;
    cout << "\nEnter quiz2 score: ";
    cin >> quiz2;
    cout << "\nEnter quiz3 score: ";
    cin >> quiz3;
    cout << "\nEnter midterm score: ";
    cin >> midterm;
    cout << "\nEnter final exam score: ";
    cin >> final;
    cout << endl << endl;
    return COP3014(first, last, zNumber, quiz1, quiz2, quiz3, midterm, final);
}

COP3014::COP3014(){
    firstName = "John";
    lastName = "Smith";
    zNumber = "z12345678";
    quiz1 = 20;
    quiz2 = 20;
    quiz3 = 20;
    midterm = 100;
    final = 100;
}

COP3014::COP3014(string first_name, string last_name, string z_number, double quiz_1,
        double quiz_2, double quiz_3, double mid_term, double final_score){
            firstName = first_name;
            lastName = last_name;
            zNumber = z_number;
            quiz1 = quiz_1;
            quiz2 = quiz_2;
            quiz3 = quiz_3;
            midterm = mid_term;
            final = final_score;
        }

void COP3014::set_first_name(string first_name){
    firstName = first_name;
}

void COP3014::set_last_name(string last_name){
    lastName = last_name;
}

void COP3014::set_zNumber(string z_number){
    zNumber = z_number;
}

void COP3014::set_quiz1(double quiz_1){
    quiz1 = quiz_1;
}

void COP3014::set_quiz2(double quiz_2){
    quiz2 = quiz_2;
}

void COP3014::set_quiz3(double quiz_3){
    quiz3 = quiz_3;
}

void COP3014::set_midterm(double mid_term){
    midterm = mid_term;
}

void COP3014::set_final(double final_score){
    final = final_score;
}

string COP3014::get_first_name(){
    return firstName;
}

string COP3014::get_last_name(){
    return lastName;
}

string COP3014::get_zNumber(){
    return zNumber;
}

double COP3014::get_quiz1(){
    return quiz1;
}

double COP3014::get_quiz2(){
    return quiz2;
}

double COP3014::get_quiz3(){
    return quiz3;
}

double COP3014::get_midterm(){
    return midterm;
}

double COP3014::get_final(){
    return final;
}

void COP3014::computeTotalGrade(){
    total_grade = ((quiz1 + quiz2 + quiz3) / 3.0) + (midterm * 0.3) + (final * 0.5); 
}

void COP3014::computeTotalLetterGrade(){
    if (total_grade > 100 || total_grade < 0){
        cout << "Finish Inputting All Grades" << endl;
    } else if (total_grade >= 90 && total_grade <= 100){
        final_letter_grade = 'A';
    } else if (total_grade >= 80 && total_grade < 90){
        final_letter_grade = 'B';
    } else if (total_grade >= 70 && total_grade < 80){
        final_letter_grade = 'C';
    } else if (total_grade >= 60 && total_grade < 70){
        final_letter_grade = 'D';
    } else {
        final_letter_grade = 'F';
    }
}


void COP3014::isAbsent(){
    char absent;
    cout << "Was " << this->firstName << " absent for either midterm or final?\n";
    cout << "Enter 'm' (midterm) or 'f' (final) or 'n' (neither) : ";
    cin >> absent;
    if (absent == 'm'){
        final_letter_grade = 'F';
        midterm = 0;
    } else if (absent == 'f'){
        final_letter_grade = 'F';
        final = 0;
    } else if (absent == 'n') {
        return;
    } else {
        cout << "Not a valid response";
    }
}

void COP3014::output(){
    computeTotalGrade();
    computeTotalLetterGrade();
    isAbsent();
    cout << endl << endl;
    cout << firstName << " " << lastName << " - " << zNumber;
    cout << endl << endl;
    cout.width(20);
    cout << " ";
    cout << "Quiz 1: " << quiz1 << endl;
    cout.width(20);
    cout << " ";
    cout << "Quiz 2: " << quiz2 << endl;
    cout.width(20);
    cout << " ";
    cout << "Quiz 3: " << quiz3 << endl;
    cout.width(20);
    cout << " ";
    cout << "Midterm: " << midterm << endl;
    cout.width(20);
    cout << " ";
    cout << "Final: " << final << endl;
    cout.width(20);
    cout << " ";
    cout << "Total grade: " << total_grade << endl;
    cout.width(20);
    cout << " ";
    cout << "Final grade: " << final_letter_grade << endl << endl;
}

