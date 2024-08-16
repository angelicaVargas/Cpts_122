#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    int user_number;
    int binary_number[64];
    int position;

    cout << "Enter a number: ";
    cin >> user_number;

    while(user_number > 0) {

        binary_number[position] = user_number % 2; //mod number (result is either 1 or 0)
        user_number = user_number / 2; 
        position++;
    }

    for(int i = position - 1; i >= 0; i--) { //iterates elements of an array backward
        cout << binary_number[i];
    }

    return 0;
}
