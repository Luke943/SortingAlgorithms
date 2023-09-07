/*
 * Test the speed of the sorting algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../sorting.h"

int main(void)
{
    // printf("RAND_MAX = %d\n", RAND_MAX);
    int loops = 10;
    int array_size = 100000;
    // int max_size = 1 << 16;
    printf("Run %d loops, %d elements\n", loops, array_size);
    srand((unsigned int)time(NULL));
    unsigned int *array = malloc(sizeof(unsigned int) * array_size);
    if (!array)
        exit(1);
    float run_times = 0;
    float min_time = 1000000000;
    float max_time = 0;
    for (int i = 0; i < loops; i++)
    {
        for (int j = 0; j < array_size; j++)
            array[j] = rand();
        clock_t start = clock();
        quickSort(array, array_size);
        clock_t end = clock();
        double run_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        // printf("%d. %f\n", i + 1, run_time);
        run_times += run_time;
        if (run_time < min_time)
            min_time = run_time;
        if (run_time > max_time)
            max_time = run_time;
    }
    double average_time = run_times / loops;
    printf("Average: %f\n", average_time);
    printf("Min: %f\n", min_time);
    printf("Max: %f\n", max_time);

    free(array);
    return 0;
}
