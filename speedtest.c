/*
 * Test the speed of the sorting algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

int main(void)
{
    int loops = 10;
    int array_size = 10000;
    int max_size = 1 << 16;
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

        clock_t start = clock();
        bubbleSort(array, array_size);
        clock_t end = clock();
        double run_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d. %f\n", i + 1, run_time);
        run_times += run_time;
    }
    double average_time = run_times / loops;
    printf("Average: %f\n", average_time);

    free(array);
    return 0;
}
