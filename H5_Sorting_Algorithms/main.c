#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "countSort.h"

void generateRandomNumbers(int* arr, int size, int lower, int upper) {
	for (int i = 0; i < size; ++i) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}
}

int* copyArray(const int* source, int size) {
	int* copy = malloc(size * sizeof(int));
	if (copy == NULL) {
		printf("Memory allocation for copy failed.\n");
		return NULL;
	}

	for (int i = 0; i < size; ++i) {
		copy[i] = source[i];
	}

	return copy;
}

int main() {
	// Initializing the random number generator
	srand(time(0));

	// The number of elements in the array
	int size = 1000000;

	// Allocating memory for the array
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	// Defining the lower and upper bounds for random numbers
	int lower = 1, upper = 1000;

	// Generating random numbers and storing them in the array
	generateRandomNumbers(arr, size, lower, upper);

	int* baseArrForInsertionSort = copyArray(arr, size);
	if (baseArrForInsertionSort == NULL) {
		free(baseArrForInsertionSort); // Free the previous copy
		return 1;
	}

	int* baseArrForSelectionSort = copyArray(arr, size);
	if (baseArrForSelectionSort == NULL) {
		// Handle the error
		free(baseArrForSelectionSort); // Free the previous copy
		return 1;
	}

	int* baseArrForMergeSort = copyArray(arr, size);
	if (baseArrForMergeSort == NULL) {
		// Handle the error
		free(baseArrForMergeSort); // Free the previous copy
		return 1;
	}

	int* baseArrForCountSort = copyArray(arr, size);
	if (baseArrForCountSort == NULL) {
		// Handle the error
		free(baseArrForCountSort); // Free the previous copy
		return 1;
	}

	clock_t StartInsertionSort = clock();
	executeInsertionSort(baseArrForInsertionSort, size);
	clock_t EndInsertionSort = clock();

	clock_t StartSelectionSortChatGPT = clock();
	executeSelectionSort(baseArrForSelectionSort, size);
	clock_t EndSelectionSortChatGPT = clock();

	clock_t StartMergeSortChatGPT = clock();
	executeMergeSort(baseArrForMergeSort, size);
	clock_t EndMergeSortChatGPT = clock();

	clock_t StartCountSortChatGPT = clock();
	executeCountSort(baseArrForCountSort, size);
	clock_t EndCountSortChatGPT = clock();

	// Calculate the execution time in seconds
	double insertionSort_execution_time = (double)(EndInsertionSort - StartInsertionSort) / CLOCKS_PER_SEC;
	double selectionSort_execution_time = (double)(EndSelectionSortChatGPT - StartSelectionSortChatGPT) / CLOCKS_PER_SEC;
	double mergeSort_execution_time = (double)(EndMergeSortChatGPT - StartMergeSortChatGPT) / CLOCKS_PER_SEC;
	double countSort_execution_time = (double)(EndCountSortChatGPT - StartCountSortChatGPT) / CLOCKS_PER_SEC;

	printf("Numbers in array to sort: %d\n", size);
	printf("Execution time for InsertionSort: %.6f seconds\n", insertionSort_execution_time);
	printf("Execution time for SelectionSort: %.6f seconds\n", selectionSort_execution_time);
	printf("Execution time for MergeSort: %.6f seconds\n", mergeSort_execution_time);
	printf("Execution time for CountSort: %.6f seconds\n", countSort_execution_time);

	// Freeing the allocated memory
	free(baseArrForInsertionSort);
	free(baseArrForSelectionSort);
	free(baseArrForMergeSort);
	free(arr);

	return 0;
}
