#ifndef SORTING_H
#define SORTING_H

// Sorts array in place. O(n^2) time complexity.
void bubbleSort(unsigned int *array, unsigned int size);

// Sorts array in place. O(n^2) time complexity.
void selectionSort(unsigned int *array, unsigned int size);

// Sorts array in place. O(n^2) time complexity.
void insertionSort(unsigned int *array, unsigned int size);

// Sorts array in place. O(nlog(n)) on average, but worst-case O(n^2).
void quickSort(unsigned int *array, unsigned int size);

// Sorts array in place. O(nlog(n)) time complexity, but assigns some extra memory.
void mergeSort(unsigned int *array, unsigned int size);

// Sorts array in place. Impractical - requires huge amount of memory depending on max value of array.
void countingSort(unsigned int *array, unsigned int size);

// Sorts array in place. O(nw) time complexity where w is the key length.
void radixSort(unsigned int *array, unsigned int size);

// Finds the index of a value in an already sorted array (or -1 if not found). O(log(n)) time complexity.
int binarySearch(unsigned int *sortedArray, unsigned int size, unsigned int value);

#endif
