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
        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_zNumber(string zNumber);
        void set_quiz1(double quiz1);
        void set_quiz2(double quiz2);
        void set_quiz3(double quiz3);
        void set_midterm(double midterm);
        void set_final(double final);
        void computeTotalGrade();
        void computeTotalLetterGrade();
        void isAbsent();
        void output();

        string get_first_name();
        string get_last_name();
        string get_zNumber();
        double get_quiz1();
        double get_quiz2();
        double get_quiz3();
        double get_midterm();
        double get_final();

    private:
        string first_name, last_name, z_number;
        double quiz1, quiz2, quiz3, midterm, final, total_grade, total_letter_grade;

};

void COP3014::set_first_name(string first_name){
    first_name = first_name;
}

void COP3014::set_last_name(string last_name){
    last_name = last_name;
}

void COP3014::set_zNumber(string zNumber){
    z_number = zNumber;
}

void COP3014::set_quiz1(double quiz1){
    quiz1 = quiz1;
}