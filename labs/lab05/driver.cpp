/*
* Name: Angelica Vargas 
* Lab: 05
* Date: March 10, 2020
* Description: The user enters a date and the program determines whether the date is valid.
* Then, it determines if the date is a leap year, how many days are in the month, how many days
* have passed and how many remain in the year.
* Then, you enter a date and it 
*/

#include <iostream>
#include "datetype.h"

using namespace std;

int main(int argc, char const *argv[]) {

    int day;
    int month;
    int year;

    cout << "Enter a date (month-day-year)" << endl;

    cin >> month;
    cin >> day;
    cin >> year;

    DateType date(month, day, year);

//determine if values entered are valid
    if((date.validateDate(month, day, year) == 1)) {
        cout << "The date " << date.toString() << " is valid" << endl;
    }
    else {
        cout << "The date " << date.toString() << " is not valid" << endl;
        return 0;
    }

    cout << "-----------------" << endl;
    cout << "Checking if the year is a leap year..." << endl;


//determine if the year is leap year
    if(date.isLeapYear(year) == 1) {
        cout << "The year " << year << " is a leap year" << endl;
    }
    else {
        cout << "The year " << year << " is not a leap year" << endl;
    }
    cout << "-----------------" << endl;

//return the number of days in the month
    cout << "The month has " << date.daysInMonth(month, year) << " days" << endl;
    cout << "-----------------" << endl;

//Return the number of days that have passed in the year
    cout << "Total numbers of days passed: " << date.daysPassedInYear(month, day, year) << endl;
    cout << "-----------------" << endl;

//return the number of days remaining in the year
    cout << "Total number of days remaining: " << date.daysRemainingInYear(month, day, year) << endl;
    cout << "-----------------" << endl;

//add number of days to the current date and print the date
    int daysInput = 0;
    cout << "Enter the amount of days you want to add to the current date: " << endl;
    cin >> daysInput;

    DateType date2(month, day, year);

    date2 = date.operatorAdd(daysInput);
    cout << "Date after the days added is " << date2.toString() << endl;
    cout << "-----------------" << endl;

//getting number of days between 2 DateTypes

    int day3;
    int month3;
    int year3;

    cout << "Enter another date (month-day-year) to find the number of days in between: " << endl;

    cin >> month3;
    cin >> day3;
    cin >> year3;

    DateType date3(month3, day3, year3);

    if((date3.validateDate(month3, day3, year3) == 1)) {
        cout << "The date " << date3.toString() << " is valid" << endl;
    }
    else {
        cout << "The date " << date3.toString() << " is not valid" << endl;
        return 0;
    }

    int daysDifference = date.operatorSubtract(date, date3);

    cout << "Difference between two dates is: " << daysDifference << endl;
}
