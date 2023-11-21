#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000
#define RUNS 100

int main() {
    int sortedArray[SIZE];

    srand((unsigned)time(NULL));

    for (int i = 0; i < SIZE; i++)
        sortedArray[i] = i;

    double sequentialSearchTimes[RUNS], binarySearchTimes[RUNS];

    for (int i = 0; i < RUNS; i++) {
        int target = rand() % SIZE;

        clock_t start = clock();

        int sequentialIndex = -1;
        for (int j = 0; j < SIZE; j++) {
            if (sortedArray[j] == target) {
                sequentialIndex = j;
                break;
            }
        }

        clock_t end = clock();
        sequentialSearchTimes[i] = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < RUNS; i++) {
        int target = rand() % SIZE;

        clock_t start = clock();

        int low = 0, high = SIZE - 1, binaryIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sortedArray[mid] == target) {
                binaryIndex = mid;
                break;
            } else if (sortedArray[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        clock_t end = clock();
        binarySearchTimes[i] = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    }

    double avgSequentialSearch = 0, minSequentialSearch = sequentialSearchTimes[0], maxSequentialSearch = sequentialSearchTimes[0];
    for (int i = 0; i < RUNS; i++) {
        avgSequentialSearch += sequentialSearchTimes[i];
        minSequentialSearch = (sequentialSearchTimes[i] < minSequentialSearch) ? sequentialSearchTimes[i] : minSequentialSearch;
        maxSequentialSearch = (sequentialSearchTimes[i] > maxSequentialSearch) ? sequentialSearchTimes[i] : maxSequentialSearch;
    }
    avgSequentialSearch /= RUNS;

    double avgBinarySearch = 0, minBinarySearch = binarySearchTimes[0], maxBinarySearch = binarySearchTimes[0];
    for (int i = 0; i < RUNS; i++) {
        avgBinarySearch += binarySearchTimes[i];
        minBinarySearch = (binarySearchTimes[i] < minBinarySearch) ? binarySearchTimes[i] : minBinarySearch;
        maxBinarySearch = (binarySearchTimes[i] > maxBinarySearch) ? binarySearchTimes[i] : maxBinarySearch;
    }
    avgBinarySearch /= RUNS;

    printf("Busqueda Secuencial:\n");
    printf("Promedio: %.5f ms\n", avgSequentialSearch);
    printf("Minimo: %.5f ms\n", minSequentialSearch);
    printf("Maximo: %.5f ms\n\n", maxSequentialSearch);

    printf("Busqueda Binaria:\n");
    printf("Promedio: %.5f ms\n", avgBinarySearch);
    printf("Minimo: %.5f ms\n", minBinarySearch);
    printf("Maximo: %.5f ms\n", maxBinarySearch);

    return 0;
}

