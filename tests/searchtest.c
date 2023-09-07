/*
 * Test for binary search algorithm
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../sorting.h"

int linearSearch(unsigned int *array, int size, int value);

int main(void)
{
    int loops = 10;
    int array_size = 10;
    int max_size = array_size;
    srand((unsigned int)time(NULL));
    unsigned int *array = malloc(sizeof(unsigned int) * array_size);
    if (!array)
        exit(1);
    for (int i = 0; i < loops; i++)
    {
        for (int j = 0; j < array_size; j++)
            array[j] = rand() % max_size;
        unsigned int target = rand() % max_size;
        quickSort(array, array_size);
        for (int j = 0; j < array_size; j++)
            printf("%d ", array[j]);
        printf("-> find %d -> ", target);
        int index = binarySearch(array, array_size, target);
        if (index >= 0)
        {
            if (array[index] == target)
                printf("PASSED: found at %d\n", index);
            else
                printf("FAILED: returned %d, but value is %d\n", index, array[index]);
        }
        else
        {
            int expected = linearSearch(array, array_size, target);
            if (index == expected)
                printf("PASSED: not there\n");
            else
                printf("FAILED: returned %d, expected %d\n", index, expected);
        }
    }

    free(array);
    return 0;
}

int linearSearch(unsigned int *array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}