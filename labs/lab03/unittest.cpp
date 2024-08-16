#include <iostream>
#include "squareFunc.h"

using namespace std;

bool testSquareFunc()
{
    bool result = true;

    int testResult = square(3);

    if(result && testResult != 9)
    {
        result = false;
    }

    testResult = square(-4);
    if(result && testResult != 16)
    {
        result = false;
    }

    testResult = square(47000);
    if(result && testResult != 2209000000)
    {
        cout << testResult << endl;
        result = false;
    }

    return result;
}