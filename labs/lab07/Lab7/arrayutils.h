#pragma once
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int* generateRandomIntArray(int size)
{
	// First dynamically allocate the array
	int* randArray = (int*)malloc(4 * size);

	// Then loop over the array, randomly generating a number between 0 and size - 1
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		randArray[i] = rand() % size;
	}

	// Return the address of the array
	return randArray;
}

int* generateIntArrayCopy(int size, int* originalArray){
	int* secondArray = (int*)malloc(4 * size);

	memcpy(secondArray, originalArray, 4*size);

	return secondArray;
}

void printIntArray(int size, int* intArray) {
	for (int i = 0; i < size; i++)
	{
		cout << (i > 0 ? ", " : "") << intArray[i];
	}

	cout << endl;
}