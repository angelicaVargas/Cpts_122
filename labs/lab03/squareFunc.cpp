#include <iostream>

using namespace std;

int square(int number) 
{
    if(number > 46340) {
        return -1;
    }
    else {
    int result = 0;

    result = number * number;

    return result;
    }
}