#pragma once

void bubbleSort(int size, int* intArray) {
	bool swapped = true;

	while (swapped) {
		swapped = false;

		for (int i = 0; i < size - 1; i++) {
			if (intArray[i] > intArray[i + 1])
			{
				// swap
				int tmp = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}