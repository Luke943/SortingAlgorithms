#ifndef SORTING_H
#define SORTING_H

// Sorts array in place using bubble sort.
void bubbleSort(unsigned int *array, unsigned int size);

// Sorts array in place using selection sort.
void selectionSort(unsigned int *array, unsigned int size);

// Sorts array in place using insertion sort.
void insertionSort(unsigned int *array, unsigned int size);

// Sorts array in place using quick sort.
void quickSort(unsigned int *array, unsigned int size);

// Sorts array in place using merge sort. Assigns some extra memory.
void mergeSort(unsigned int *array, unsigned int size);

// Sorts array in place using counting sort. Impractical - can require huge amount of memory.
void countingSort(unsigned int *array, unsigned int size);

// Sorts array in place using radix sort (with radix of 256).
void radixSort(unsigned int *array, unsigned int size);

// Finds the index of a value in an already sorted array (or -1 if not found)
int binarySearch(unsigned int *sortedArray, unsigned int size, unsigned int value);

#endif
