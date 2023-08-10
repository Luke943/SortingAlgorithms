/*
 * Contains the definitions of all the sorting functions
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Bubble sort
Iterates through array comparing and swapping adjacent elements.
Then keeps performing iterations until no more changes are made.
 */
void bubbleSort(unsigned int *array, unsigned int size)
{
    bool changeMade = true;
    while (changeMade)
    {
        changeMade = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                unsigned int tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
                changeMade = true;
            }
        }
    }
}

/* Selection sort
Selects the minimum value in a list, swaps it with the 1st value.
Then starts at 2nd position, selects the smallest value in the remaining list, and swaps it with the 2nd element.
Continues iterating through the list until it reaches the end.
 */
void selectionSort(unsigned int *array, unsigned int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        unsigned int smallest = array[i];
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < smallest)
            {
                smallest = array[j];
                index = j;
            }
        }
        unsigned int tmp = array[i];
        array[i] = smallest;
        array[index] = tmp;
    }
}

/* Insertion short
Builds up a sorted array at the beginning of the list.
It begins the sorted array with the first element.
Then inspects the next element and swaps it backwards into the sorted array.
Continues iterating through the whole list.
 */
void insertionSort(unsigned int *array, unsigned int size)
{
    for (int i = 1; i < size; i++)
    {
        unsigned int tmp = array[i];
        for (int j = i; j > 0; j--)
        {
            if (array[j - 1] > tmp)
            {
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
            else
                break;
        }
    }
}

/* Quick sort
A pivot value is chosen in the original array.
The array is then partitioned into two subarrays of values less than and greater than the pivot value.
Then combine the result of recursively calling the quick sort algorithm on both sub-arrays.
Continues until the base case of an empty or single-item array is reached
 */
void quickSort(unsigned int *array, unsigned int size)
{
    if (size > 1)
    {
        unsigned int pivotValue = array[size / 2]; // Midpoint used as pivot
        int i = 0;
        int j = size - 1;
        while (i <= j)
        {
            while (array[i] < pivotValue)
                i++;
            while (array[j] > pivotValue)
                j--;
            if (i <= j)
            {
                unsigned int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        }

        quickSort(array, j + 1);
        quickSort(array + i, size - i);
    }
}

/* Merge sort
Recursively split the array in half until a sub-array with only one element is produced.
Merge each sorted sub-array together to produce the final sorted array.
 */
void mergeSort(unsigned int *array, unsigned int size)
{
    if (size > 1)
    {
        unsigned int firstSize = size / 2;
        unsigned int secondSize = size - firstSize;
        mergeSort(array, firstSize);
        mergeSort(array + firstSize, secondSize);
        unsigned int *buffer = malloc(sizeof(unsigned int *) * firstSize);
        if (!buffer)
            exit(1);
        for (int i = 0; i < firstSize; i++)
            buffer[i] = array[i];
        int i = 0, j = firstSize, k = 0;
        while (i < firstSize && j < size)
        {
            if (buffer[i] <= array[j])
            {
                array[k] = buffer[i];
                i++;
            }
            else
            {
                array[k] = array[j];
                j++;
            }
            k++;
        }
        if (j == size)
        {
            while (i < firstSize)
            {
                array[k] = buffer[i];
                i++;
                k++;
            }
        }
        free(buffer);
    }
}

/* Binary search
Keeps bisecting array until required value is found.
 */
int binarySearch(unsigned int *sortedArray, unsigned int size, unsigned int value)
{
    int low = 0;
    int high = size;
    int mid = size / 2;
    while (low + 1 < high)
    {
        if (sortedArray[mid] == value)
            return mid;
        else if (sortedArray[mid] < value)
        {
            low = mid;
            mid = (mid + high) / 2;
        }
        else
        {
            high = mid;
            mid = (low + mid) / 2;
        }
    }
    return -1;
}

/* Counting sort
Creates array of all possible values and counts how many of each there are.
Then rebuilds sorted array.
 */
void countingSort(unsigned int *array, unsigned int size)
{
    unsigned int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    unsigned int *counts = malloc(sizeof(unsigned int) * max);
    if (!counts)
        exit(1);
    for (int i = 0; i < size; i++)
        counts[array[i]]++;
    int i = 0;
    int j = 0;
    for (int j = 0; j < max; j++)
    {
        for (int k = 0; k < counts[j]; k++)
        {
            array[i] = counts[j];
            i++;
        }
    }
    free(counts);
}

/* Radix sort
Distributes elements into buckets according to their 'radix' and rebuilds the array.
The bucketing process is repeated as many times as needed by the radix (preserving order from previous iteration).
Using radix of 256, so 4 iterations need on 32-bit integers.
 */
void radixSort(unsigned int *array, unsigned int size)
{
    int counts[0x100];
    unsigned int *input = array;
    unsigned int *output = malloc(sizeof(unsigned int) * size);
    if (!output)
        exit(1);
    for (int i = 0; i < 4; i++)
    {
        // Zero the counts
        for (int j = 0; j < 0x100; j++)
            counts[j] = 0;
        // Count
        for (int j = 0; j < size; j++)
            counts[(input[j] >> (i * 8)) & 0xff]++;
        // Make counts cumulative to give indices
        for (int j = 1; j < 0x100; j++)
            counts[j] += counts[j - 1];
        // Build output
        for (int j = size - 1; j >= 0; j--)
        {
            int index = (input[j] >> (i * 8)) & 0xff;
            counts[index]--;
            output[counts[index]] = input[j];
        }
        // Swap input array with output by swapping pointers
        // Happens EVEN number of times so things end where they started
        unsigned int *tmp = input;
        input = output;
        output = tmp;
    }
    free(output);
}
