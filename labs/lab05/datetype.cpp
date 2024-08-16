#include <iostream>
#include <string>

#include "datetype.h"
#include "strconvert.h"

using namespace std;

const int daysAndMonth[13] = {0, //placed so we can start at 1
                                  31, //January
                                  28, //February
                                  31, //March
                                  30, //April
                                  31, //May
                                  30, //June
                                  31, //July
                                  31, //August
                                  30, //September
                                  31, //October
                                  30, //November
                                  31}; //December

//function finds whether a year is a leap year and returns 1, if true. 0 if false
int DateType::isLeapYear(int year) {

    if(year % 400 == 0) {
        return 1;
    }
    else if(year % 100 == 0) {
        return -1;
    }
    else if(year % 4 == 0) {
        return 1;
    }
    else {
        return -1;
    }
}

//validates the month entered
int DateType::validateMonth(int month) {
    if(month >= 1 && month <= 12) {
        return 1;
    }
    else {
        cout << "Month not valid" << endl;
        return -1;
    }
}

//validates the year entered
int DateType::validateYear(int year) {
    if(year > 0) {
        return 1;
    }
    else {
        cout << "Year not valid" << endl;
        return -1;
    }
}

//finds how many days are in the month (uses the array declared above)
int DateType::daysInMonth(int month, int year) {

    int days;

    if((month == 2 ) && (isLeapYear(year) == 1)) {
        days = daysAndMonth[month] + 1;
    }
    else {
        days = daysAndMonth[month];
    }
    return days;
}

//determines whether the date entered is valid 
int DateType::validateDate(int month, int day, int year) {

    if(day <= (daysInMonth(month, year)) && (validateMonth(month) == 1) && (validateYear(year) == 1)) {
        return 1;
    }
    else {
        return -1;
    }
}

//set date if everything is valid
void DateType::setDate(int month, int day, int year) {
    if(validateDate(month, day, year) == 1) {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    else {
        cout << "The date inputted is not valid" << endl;
    }
}

void DateType::setDay(int day) {
    if(validateDate(month, day, year) == 1) {
        this->day = day;
    }
    else {
        cout << "Invalid date" << endl;
    }
}

int DateType::getDay() {
    return this->day;
}

void DateType::setMonth(int month) {
    if(validateMonth(month) == 1) {
        this->month = month;
    }
    else {
        cout << "Invalid month" << endl;
    }
}

int DateType::getMonth() {
    return this->month;
}

void DateType::setYear(int year) {
    if(validateYear(year) == 1) {
        this->year = year;
    }
    else {
        cout << "Invalid year" << endl;
    }
}

int DateType::getYear() {
    return this->year;
}

string DateType::toString() {
    string result = patch::to_string(month) + "-" + patch::to_string(day) + "-" + patch::to_string(year);
    return result;
}

DateType::DateType(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
}

//determines how many days passed in the year (not counting the current day)
int DateType::daysPassedInYear(int month, int day, int year) {
    int daysPassed = 0;
    int monthIndex = 1;

    for(monthIndex = 1; monthIndex < month; monthIndex++) {
        daysPassed = daysPassed + daysAndMonth[monthIndex];
    }

    if(isLeapYear(year) == 1) {
        daysPassed = daysPassed + 1;
    }
    return daysPassed + (day - 1);
}

//determines how many days remain in the year (not counting the current day)
int DateType::daysRemainingInYear(int month, int day, int year) {
    int daysRemaining = 0;
    int daysInYear = 365;

    if(isLeapYear(year) == 1) {
        daysInYear = daysInYear + 1;
    }

    int daysPassed = daysPassedInYear(month, day, year);

    daysRemaining = daysInYear - daysPassed;

    return daysRemaining;
}

DateType DateType::operatorAdd(int daysInput) {
    int year = this -> year;
    int month = this -> month;
    int day = this -> day;

    int monthDays = daysInMonth(month, year);
    int totalDays = 0;
    int finalDays = 0;
    int totalMonth = 0;

    totalDays = daysInput + day;

    if(totalDays > monthDays) {
        finalDays = totalDays % monthDays;
        totalMonth = totalDays/monthDays;

        totalMonth = month + totalMonth;
    }
    else {
        finalDays = totalDays;
    }
    return DateType(totalMonth, finalDays, year);
 }

int DateType::operatorSubtract(DateType date, DateType date3) {
    int month1 = date.month;
    int day1 = date.day;
    int year1 = date.year;

    int month2 = date3.month;
    int day2 = date3.day;
    int year2 = date3.year;

    long int total1 = 0;
    total1 = year1 * 365 + day1;

    for(int i = 0; i < month1 - 1; i++) {
        total1 += daysAndMonth[i];
    }

    if(isLeapYear(year1) == 1) {
        total1 = total1 + 1;
    }

    long int total2 = 0;
    total2 = year2 * 365 + day2;

    for(int i = 0; i < month2 - 1; i++) {
        total2 += daysAndMonth[i];
    }
    
    if(isLeapYear(year2) == 1) {
        total2 = total2 + 1;
    }

    return(total2 - total1);
}
