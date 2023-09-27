#include <stdio.h>
#include "selectionSort.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// This function performs the selection sort algorithm on an array of integers.
void executeMikkelSelectionSort(int* arr, int size) {
	// We're going to organize the numbers in the array from smallest to largest.
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;

		for (int j = i + 1; j < size; j++) {
			if (*(arr + j) < *(arr + min_idx)) {
				min_idx = j;
			}
		}

		// Swapping
		swap(arr + min_idx, arr + i);
	}
}

void executeSelectionSort(int* arr, int size) {
	// We start by looking at each number one by one.
	for (int i = 0; i < size - 1; ++i) {
		// We assume the current number we're looking at is the smallest for now.
		int minIndex = i;

		// Now, we search for a smaller number in the rest of the array.
		// We start from the next number (i + 1) because we've already checked the previous ones.
		for (int j = i + 1; j < size; ++j) {
			// If we find a smaller number, we remember its position (index).
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// If we found a smaller number than what we assumed,
		// we swap (exchange) the current number with the smaller one.
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}