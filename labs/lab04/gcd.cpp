#include <iostream>
using namespace std;

/* Determine the greatest common divisor
   of two numbers, e.g. GCD(8, 12) = 4
*/
int GCDCalculator(int inNum1, int inNum2) {
   int gcdVal;     // Holds GCD results

   cout << "===================" << endl;
   cout << "inNum1: " << inNum1 << endl;
   cout << "inNum2: " << inNum2 << endl;
   cout << "===================" << endl;
   
   if(inNum1 == inNum2) {    // Base case: Numbers are equal
      gcdVal = inNum1;       // Return value
   }
   else {                    // Recursive case: subtract smaller from larger
      if (inNum1 > inNum2) { // Call function with new values
         gcdVal = GCDCalculator(inNum1 - inNum2, inNum2);
      }
      else {
         gcdVal= GCDCalculator(inNum1, inNum2 - inNum1);
      }
   }
   
   return gcdVal;
}

int main() {
   int gcdInput1;     // First input to GCD calc
   int gcdInput2;     // Second input to GCD calc
   int gcdOutput;     // Result of GCD
   
   // Print program function
   cout << "Program outputs the greatest \n"
        << "common divisor of two numbers." << endl;
   
   // Prompt user for input
   cout << "Enter first number: ";
   cin >> gcdInput1;
   
   cout << "Enter second number: ";
   cin >> gcdInput2;
   
   // Check user values are > 1, call recursive GCD function
   if ((gcdInput1 < 1) || (gcdInput2 < 1)) {
      cout << "Note: Neither value can be below 1." << endl;
   }
   else {
      gcdOutput = GCDCalculator(gcdInput1, gcdInput2);
      cout << "Greatest common divisor = " << gcdOutput << endl;
   }
   
   return 0;
}