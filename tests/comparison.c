/*
 * Test to compare quickSort to standard library qsort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "../sorting.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    srand(time(NULL));
    unsigned int arraySize = 100000;
    unsigned int numIterations = 10;
    unsigned int *yourArray = malloc(sizeof(unsigned int) * arraySize);
    unsigned int *qsortArray = malloc(sizeof(unsigned int) * arraySize);
    if (!yourArray || !qsortArray)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    double totalYourSortTime = 0.0;
    double totalQSortTime = 0.0;
    double minYourSortTime = DBL_MAX;
    double minQSortTime = DBL_MAX;
    double maxYourSortTime = 0.0;
    double maxQSortTime = 0.0;
    clock_t start, end;
    for (unsigned int iteration = 0; iteration < numIterations; iteration++)
    {
        for (unsigned int i = 0; i < arraySize; i++)
        {
            yourArray[i] = rand();
            qsortArray[i] = yourArray[i];
        }

        start = clock();
        quickSort(yourArray, arraySize);
        end = clock();
        double yourSortTime = (double)(end - start) / CLOCKS_PER_SEC;
        totalYourSortTime += yourSortTime;
        if (yourSortTime < minYourSortTime)
            minYourSortTime = yourSortTime;
        if (yourSortTime > maxYourSortTime)
            maxYourSortTime = yourSortTime;

        start = clock();
        qsort(qsortArray, arraySize, sizeof(unsigned int), compare);
        end = clock();
        double qsortTime = (double)(end - start) / CLOCKS_PER_SEC;
        totalQSortTime += qsortTime;
        if (qsortTime < minQSortTime)
            minQSortTime = qsortTime;
        if (qsortTime > maxQSortTime)
            maxQSortTime = qsortTime;
    }

    double avgYourSortTime = totalYourSortTime / numIterations;
    double avgQSortTime = totalQSortTime / numIterations;

    printf("\nPerformance Comparison (%d elements):\n", arraySize);
    printf("--------------------------------------------------------\n");
    printf("           |  Average Time  |  Min Time  |  Max Time  |\n");
    printf("--------------------------------------------------------\n");
    printf("quickSort  |    %8.6f    |  %8.6f  |  %8.6f  |\n", avgYourSortTime, minYourSortTime, maxYourSortTime);
    printf("qsort      |    %8.6f    |  %8.6f  |  %8.6f  |\n", avgQSortTime, minQSortTime, maxQSortTime);
    printf("--------------------------------------------------------\n");

    free(yourArray);
    free(qsortArray);

    return 0;
}
