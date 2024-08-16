/*
* Name: Angelica Vargas 
* Lab: 01
* Date: January 28, 2021
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(int argc, char const *argv[])
{
    string firstName;

    cout << "Please enter your first name: ";
    cin >> firstName;

    string greeting = "Hello " + firstName;
    cout << greeting << endl;

    cout << "Your name is " << firstName.size() << " letters long.\n";

    return 0;
}