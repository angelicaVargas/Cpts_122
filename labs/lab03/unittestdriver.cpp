/*
* Name: Angelica Vargas 
* Lab: 02
* Date: February 4, 2022
*/

#include <iostream>
#include "unittest.h"

using namespace std;

int main(int argc, char const *argv[])
{
    bool squareResult = testSquareFunc();
    cout << "test squareFunc " << (squareResult ? "passed!" : "failed!") << endl;

    return 0;
}