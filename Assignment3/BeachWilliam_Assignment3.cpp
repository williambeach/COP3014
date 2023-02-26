/*
*
William Beach
COP3014 - Assignment 3 - Creation and test of class COP3014 in C++
02/26/2023
*
*/

#include <iostream>
#include <string.h>
using namespace std;


class COP3014{
    public:
        void set_zNumber(double &zNumber);
        void set_grades(double &quiz1, double &quiz2, double &quiz3, double &midterm, double &final);
        
    

    private:
    string first_name, last_name, z_number;
    double quiz1, quiz2, quiz3, midterm, final, total_grade, total_letter_grade;

};