/*
 * Check the functionality of the sorting algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

int main(void)
{
    int loops = 10;
    int array_size = 10;
    int max_size = 1 << 6;
    srand((unsigned int)time(NULL));
    unsigned int *array = malloc(sizeof(unsigned int) * array_size);
    if (!array)
        exit(1);
    for (int i = 0; i < loops; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            array[j] = rand() % max_size;
            printf("%d ", array[j]);
        }

        quickSort(array, array_size);
        printf("--> ");
        for (int j = 0; j < array_size; j++)
        {
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    free(array);
    return 0;
}
