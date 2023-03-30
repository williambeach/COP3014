/*
*
William Beach
COP3014 - Assignment 4
03/27/2023
*
*/


#include <iostream>
#include <string>
using namespace std;


class DayOfYear{
    public:
        DayOfYear();    //initializes day and month to 01/01
        DayOfYear(int the_month, int the_day);
        void input();
        void output();
        void set_date(int new_month, int new_day);  //setter function or mutator function
        //Precondition: new_month and new_day form a possible date.
        //Postcondition: The date is reset according to the arguments.
        int get_month();   //getter function or accessor function
        //Returns the month, 1 for January, 2 for February, etc.
        int get_day();
        //Returns the day of the month.
        friend bool equal(DayOfYear date1,DayOfYear date2);
        //checks for equality of two dates
        friend bool after(DayOfYear date1,DayOfYear date2);
        //checks to see if date1 occurs after date2

    private:
        void check_date();
        int month;
        int day;
};

class DateYear : public DayOfYear{
    public:
        DateYear();
        DateYear(int month, int day, int year);
        void input_date();
        int get_year();
        void set_year(int year);
        void output_date(ostream &out); //you can pass cout or file object
        friend bool DateCompare(const DateYear year1, const DateYear year2);
        int BDCountdown(int month, int day, int year);
    private:
        void check_year(); //no negative years. I consider year 0 to be legitimate. >9999 will overflow 'xxxx' format.
        int year;
};

int main(){

    DateYear myDate1;
    cout << myDate1.get_day() << endl;
    cout << myDate1.get_month() << endl;
    cout << myDate1.get_year() << endl;

    DateYear myDate2(3,3,2023);
    cout << myDate2.get_day() << endl;
    cout << myDate2.get_month() << endl;
    cout << myDate2.get_year() << endl;

    DateYear myDate3;
    myDate3.input_date();
    cout << myDate3.get_month() << endl;
    cout << myDate3.get_day() << endl;
    cout << myDate3.get_year() << endl;

    myDate3.set_year(2060);
    cout << myDate3.get_year() << endl;

    myDate2.output_date(cout);
    
    DateYear myDate4(3,29,2023);

    myDate4.BDCountdown(3,31,2023);
    


    return 0;
}




//DayOfYear class definitions

DayOfYear::DayOfYear(){
    month = 1;
    day = 1;
}

DayOfYear::DayOfYear(int the_month, int the_day){
    month = the_month;
    day = the_day;
    check_date();
}

void DayOfYear::input(){
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date();
}

void DayOfYear::output(){
    cout << "month = " << month << ", day = " << day << endl;
}

void DayOfYear::set_date(int new_month, int new_day){
    month = new_month;
    day = new_day;
    check_date();
}

void DayOfYear::check_date(){
    if ((month < 1) || (month > 12) || (day < 1) || (day > 31)){ 
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}

int DayOfYear::get_month(){
    return month;
}

int DayOfYear::get_day(){
    return day;
}

bool equal(DayOfYear date1,DayOfYear date2){
    return (date1.day == date2.day && date1.month == date2.month);
}

bool after(DayOfYear date1,DayOfYear date2){
    return (date1.month > date2.month) || (date1.month == date2.month && date1.day > date2.day );
}

//DateYear class definitions

DateYear::DateYear(){
    DayOfYear();
    this->year = 2023;
}

DateYear::DateYear(int month, int day, int year) : DayOfYear(month, day){
    this->year = year;
}

void DateYear::input_date(){
    input();
    cout << "Enter the year: ";
    cin >> year;
    check_year();
    
}

void DateYear::check_year(){
    if (year < 0 || year > 9999){
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}

int DateYear::get_year(){
    return this->year;
}

void DateYear::set_year(int year){
    this->year = year;
    check_year();
}

void DateYear::output_date(ostream &out){
    string month, day, year;
    if (this->get_month() >= 1 && this->get_month() <= 9){
        month = "0" + to_string(get_month());
    } else{
        month = to_string(get_month());
    }
    if (this->get_day() >= 1 && this->get_day() <= 9){
        day = "0" + to_string(get_day());
    } else{
        day = to_string(get_day());
    }
    if (this->get_year() >= 0 && this->get_year() <= 9){
        year = "000" + to_string(get_year());
    } else if (this->get_year() >= 10 && this->get_year() <= 99){
        year = "00" + to_string(get_year());
    } else if (this->get_year() >= 100 && this->get_year() <= 999){
        year = "0" + to_string(get_year());
    } else{
        year = to_string(get_year());
    }
    out << month + "/" + day + "/" + year << endl;
}

bool DateCompare(const DateYear year1, const DateYear year2){
    return year1.year == year2.year;
}

int DateYear::BDCountdown(int month, int day, int year){ //calculates days between calling object date and birthday date passed as m,d,y
    int days, i, sub;
    int leapYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int regularYear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DateYear birthday(month, day, year);
    birthday.output_date(cout);
    if (this->get_month() == birthday.get_month() && this->get_day() < birthday.get_day()){
      days = birthday.get_day() - this->get_day();
    } else if (this->get_month() > birthday.get_month()){
        if (birthday.get_year() % 4 == 0 && birthday.get_year() % 100 != 0){ //leap year
          days = leapYear[this->get_month() - 1] - this->get_day();
          for (i = this->get_month(); i < 12; i++){
              days += leapYear[i];
            }
            for (i = 0; i < birthday.get_month(); i++){
              days += leapYear[i];
            }
            sub = leapYear[birthday.get_month() - 1] - birthday.get_day();
            days = days - sub;
        } else{
            days = regularYear[this->get_month() - 1] - this->get_day();
            for (i = this->get_month(); i < 12; i++){
              days += regularYear[i];
            }
            for (i = 0; i < birthday.get_month(); i++){
              days += regularYear[i];
            }
            sub = regularYear[birthday.get_month() - 1] - birthday.get_day();
            days = days - sub;
        }
    } else {
        if (birthday.get_year() % 4 == 0 && birthday.get_year() % 100 != 0){ //leap year
          days = leapYear[this->get_month() - 1] - this->get_day();
          for (i = this->get_month(); i < birthday.get_month(); i++){
              days += leapYear[i];
            }
            sub = leapYear[birthday.get_month() - 1] - birthday.get_day();
            days = days - sub;
        } else{
            days = regularYear[this->get_month() - 1] - this->get_day();
            for (i = this->get_month(); i < birthday.get_month(); i++){
              days += regularYear[i];
            }
            sub = regularYear[birthday.get_month() - 1] - birthday.get_day();
            days = days - sub;
        }
    }
  return days;
}

