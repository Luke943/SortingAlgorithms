## Description

Various sorting and searching algorithms implemented in C.
All designed for 32-bit unsigned integers.

Quick sort performs around 33% faster than the standard library `qsort`.

## Usage

The code for the algorithms (with brief descriptions) is found in `sorting.c` and their declarations are in `sorting.h`.

The `Makefile` (configured for `gcc`) creates a `build` directory with `sorting.o` and executables for the tests.

## Algorithms

The table below shows all the sorting algorithms included and some performance information. $n$ represents the size of the array to sort.


| Name | Sorting type | Time Complexity | Memory Usage | Notes |
| :---: | :---: | :---: | :---: | :---: |
| Bubble sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and very slow.
| Selection sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and slow.
| Insertion sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and slow.
| Quick sort | Divide & Conquer | $O(n \log n)^*$ | $O(n)$ | Fast. Recursive calls can cause stack overflow for large $n$.
| Merge sort | Divide & Conquer | $O(n \log n)$ | $O(n)$ | Fast. Assigns extra memory for merging.
| Counting sort | Distributing | $O(n + r)$ | $O(n + r)$ | Only suitable when  $r$ (range of values in array) is small as assigns memory for counts.
| Radix sort† | Distributing |  $O(n \cdot w)$ | $O(n + w)$ | The fastest. Assigns extra memory of key length $w$ for counts.

**Average time. Worst case is quadratic.*

*†Implemented here with fixed radix of 256.*

### Other

Also includes a Binary search, which finds an element in a sorted array in $O(\log n)$ time.

## Speed Comparison

All tests have been carried out with randomly generated 32-bit unsigned integers and run for multiple loops. The figures below are the average time in seconds each algorithm took to sort an array of the given size.

| Array Size | Bubble | Selection | Insertion | Quick | Merge | Radix |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1,000       | 0.00424 | 0.00167 | 0.00150 | 0.00015 | 0.00028 | 0.00006 |
| 10,000      | 0.38433 | 0.12574 | 0.09030 | 0.00113 | 0.00205 | 0.00027 |
| 100,000     | 41.6200 | 12.3096 | 8.66620 | 0.01414 | 0.02435 | 0.00358 |
| 1,000,000   | -       | -       | -       | 0.14400 | 0.24440 | 0.03303 |
| 10,000,000  | -       | -       | -       | 1.69358 | 2.79440 | 0.33190 |
| 100,000,000 | -       | -       | -       | 19.1590 | 30.2030 | 3.26100 |
