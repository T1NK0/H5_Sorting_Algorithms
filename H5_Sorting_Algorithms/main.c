#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selectionSort.h"

void generateRandomNumbers(int* arr, int size, int lower, int upper) {
	for (int i = 0; i < size; ++i) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}
}

int main() {

	// Initialiserer tilf�ldig nummergenerator
	srand(time(0));

	// Antallet af elementer i arrayet
	int size = 1000;

	// Allokerer hukommelse til arrayet
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("Hukommelse kunne ikke allokeres.\n");
		return 1;
	}

	// Definerer de nedre og �vre gr�nser for tilf�ldige tal
	int lower = 1, upper = 1000;

	// Genererer tilf�ldige tal og gemmer dem i arrayet
	generateRandomNumbers(arr, size, lower, upper);

	// Udskriver elementerne i arrayet
	printf("Tilf�ldige tal i arrayet: ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Hello World!\n");

	executeSelectionSort(arr, size);

	// Frig�r hukommelsen
	free(arr);

	return 0;
}