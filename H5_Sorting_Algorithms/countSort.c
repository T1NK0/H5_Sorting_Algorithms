#include <stdio.h>
#include <stdlib.h>
#include "countSort.h"

void executeCountSort(int* arr, int size) {
    if (size <= 1) {
        return; // No need to sort an array with 0 or 1 elements.
    }

    // Find the maximum and minimum values in the array to determine the range.
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of values.
    int range = max - min + 1;

    // Create a count array to store the count of each element.
    int* count = (int*)malloc(range * sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Initialize the count array to 0.
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element.
    for (int i = 0; i < size; i++) {
        count[arr[i] - min]++;
    }

    // Reconstruct the sorted array from the count array.
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + min;
            index++;
            count[i]--;
        }
    }

    // Free the memory allocated for the count array.
    free(count);
}
