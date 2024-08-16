#include "arrayutils.h"
#include "sorting_algorithms.h"

#include <chrono>

using namespace std::chrono;

int ARRAY_SIZE = 10000;

int main(int argc, char* argv)
{
	/*bubbleSort(ARRAY_SIZE, workingArray);*/
	//printIntArray(ARRAY_SIZE, workingArray);

	//add a loop that repeats the bubble sort algorithm some number of times
	for (int ARRAY_SIZE = 100; ARRAY_SIZE <= 1000000; ARRAY_SIZE = ARRAY_SIZE * 10) {

		int* array = generateRandomIntArray(ARRAY_SIZE);
		int* workingArray = generateIntArrayCopy(ARRAY_SIZE, array);

		cout << "Copy done" << endl;
		auto start = high_resolution_clock::now();

		bubbleSort(ARRAY_SIZE, workingArray);

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);

		cout << ARRAY_SIZE << ": " << duration.count() << " microseconds" << endl;
	}
	//divide the time observed by the number of times the loop ran to get the average run time of one sort of the array

	cout << "Bubble sort completed" << endl;

	return 0;
}