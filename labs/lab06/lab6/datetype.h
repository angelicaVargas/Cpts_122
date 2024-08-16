#include<iostream>
#include <string>

using std::string;

class DateType {
public:
    void setDate(int month, int day, int year);
    int isLeapYear(int year);
    int daysInMonth(int month, int year);
    int validateMonth(int month);
    int validateYear(int year);
    int validateDate(int month, int day, int year);

    void setDay(int day);
    int getDay();
    void setMonth(int month);
    int getMonth();
    void setYear(int year);
    int getYear();
    int daysPassedInYear(int month, int day, int year);
    int daysRemainingInYear(int month, int day, int year);
    string toString();
    DateType(int month, int day, int year);

    DateType operatorAdd(int daysInput);
    int operatorSubtract(DateType date, DateType date3);

private:
    int month;
    int day;
    int year;
};