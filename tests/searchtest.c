/*
 * Test for binary search algorithm
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../sorting.h"

int main(void)
{
    int loops = 10;
    int array_size = 15;
    int max_size = array_size;
    srand((unsigned int)time(NULL)); // Initialization, should only be called once.
    unsigned int *array = malloc(sizeof(unsigned int) * array_size);
    if (!array)
        exit(1);
    float run_times;
    for (int i = 0; i < loops; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            array[j] = rand() % max_size;
        }
        unsigned int target = rand() % max_size;
        quickSort(array, array_size);
        for (int j = 0; j < array_size; j++)
            printf("%d ", array[j]);
        printf("--> ");
        int index = binarySearch(array, array_size, target);
        if (index == -1)
        {
            int findIndex = -1;
            for (int j = 0; j < array_size; j++)
            {
                if (array[j] == target)
                {
                    findIndex = j;
                    break;
                }
            }
            printf("%d %d %d\n", target, index, findIndex);
        }
        else
        {
            unsigned int value;
            value = array[index];
            printf("%d %d %d\n", target, index, value);
        }
    }
    free(array);
    return 0;
}
