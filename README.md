## Description

Various sorting and searhing algorithms implemented in C.
All designed for 32-bit unsigned integers.
The code for the algorithms is found in `sorting.c` and their declarations are in `sorting.h`.

## Algorithms

The table below shows all the sorting algorithms included and some performance information. $n$ represents the size of the array to sort.


| Name | Sorting type | Time Complexity | Memory Usage | Notes |
| :---: | :---: | :---: | :---: | :---: |
| Bubble sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and very slow.
| Selection sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and slow.
| Insertion sort | Comparison | $O(n^2)$ | $O(n)$ | Basic and slow.
| Quick sort | Comparison |  $O(n \log n)^*$ | $O(n)$ | Fast. Recursive calls can cause stack overflow for large $n$.
| Merge sort | Comparison |  $O(n \log n)$ | $O(n)$ | Fast. Assigns some extra memory.
| Counting sort | Distributing |  $O(n + r)$ | $O(n + r)$ | Only suitable when  $r$ (range of values in array) is small as assigns memory for counts.
| Radix sort† | Distributing |  $O(n \cdot w)$ | $O(n + w)$ | The fastest. Assigns extra memory of key length $w$ for counts.

**Typical case is $O(n \log n)$, but worst case will be $O(n^2)$.*

*†Implemented here with fixed key length of 256.*

### Other

Also includes a Binary search, which finds an element in a sorted array in $O(\log n)$ time.

## Speed Test

All tests have been carried out with randomly generated 32-bit unsigned integers and run for multiple loops. The figures below are the average time in seconds each algorithm took to sort an array of the given size.

| Array Size | Bubble | Selection | Insertion | Quick | Merge | Radix |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1,000       | 0.00424 | 0.00167 | 0.00150 | 0.00015 | 0.00028 | 0.00006 |
| 10,000      | 0.38433 | 0.12574 | 0.09030 | 0.00113 | 0.00205 | 0.00027 |
| 100,000     | 41.6200 | 12.3096 | 8.66620 | 0.01414 | 0.02435 | 0.00358 |
| 1,000,000   | -       | -       | -       | 0.1440‡ | 0.24440 | 0.03303 |
| 10,000,000  | -       | -       | -       | -       | 2.79440 | 0.33190 |
| 100,000,000 | -       | -       | -       | -       | 30.2030 | 3.26100 |
| 1,000,000,000 | -     | -       | -       | -       | -       | 34.6535 |

*‡Around this size quick sort becomes unstable as the recursive calls can cause a stack overflow.*

## Files

- `sorting.c` - Contains function definitions for sorting algorithms.
- `sorting.h` - Corresponding header file with function declarations.
- `sorttest.c` - Tests the algorithms sort correctly.
- `searchtest.c` - Tests the search algorithms.
- `speedtest.c` - Times the execution speed of the algorithms.
