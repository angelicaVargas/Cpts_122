#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {

    int user_number = 0;
    int old_number = 0;
    int count = 0;
    int largest_number = 0;
    int sum = 0;

    while(1) {
    cout << "Enter a positive number to continue or a negative number to exit: ";
    cin >> user_number;


    if(user_number > 0) {
            if(user_number > old_number) {
                largest_number = user_number;
            }
            else {
                largest_number = old_number;
            }
        sum = user_number + old_number;
        old_number = user_number;
    count++;
    }

    cout << "The largest number seen was " << largest_number << endl;
    cout << "The total value of all numbers is " << sum << endl;
    cout << "The count of the numbers entered is " << count << endl;
    }
    return 0;
}