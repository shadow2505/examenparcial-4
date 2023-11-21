#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000
#define RUNS 100

void insertionSort(int arr[], int n) {
    for (int i = 1, key, j; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = high, temp;
        for (int i = low; i < high; i++) {
            if (arr[i] < arr[pi]) {
                temp = arr[i];
                arr[i] = arr[low];
                arr[low] = temp;
                low++;
            }
        }
        temp = arr[pi];
        arr[pi] = arr[low];
        arr[low] = temp;
        pi = low;

        quickSort(arr, low - 1, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0, temp; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int originalArray[SIZE], sortedArray[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
        originalArray[i] = rand() % 10000;

    double insertionSortTimes[RUNS], quickSortTimes[RUNS], bubbleSortTimes[RUNS];

    for (int i = 0; i < RUNS; i++) {
        for (int j = 0; j < SIZE; j++)
            sortedArray[j] = originalArray[j];
        clock_t start = clock();
        insertionSort(sortedArray, SIZE);
        clock_t end = clock();
        insertionSortTimes[i] = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < RUNS; i++) {
        for (int j = 0; j < SIZE; j++)
            sortedArray[j] = originalArray[j];
        clock_t start = clock();
        quickSort(sortedArray, 0, SIZE - 1);
        clock_t end = clock();
        quickSortTimes[i] = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < RUNS; i++) {
        for (int j = 0; j < SIZE; j++)
            sortedArray[j] = originalArray[j];
        clock_t start = clock();
        bubbleSort(sortedArray, SIZE);
        clock_t end = clock();
        bubbleSortTimes[i] = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    }

    double avgInsertionSort = 0, minInsertionSort = insertionSortTimes[0], maxInsertionSort = insertionSortTimes[0];
    double avgQuickSort = 0, minQuickSort = quickSortTimes[0], maxQuickSort = quickSortTimes[0];
    double avgBubbleSort = 0, minBubbleSort = bubbleSortTimes[0], maxBubbleSort = bubbleSortTimes[0];

    for (int i = 0; i < RUNS; i++) {
        avgInsertionSort += insertionSortTimes[i];
        avgQuickSort += quickSortTimes[i];
        avgBubbleSort += bubbleSortTimes[i];

        minInsertionSort = (insertionSortTimes[i] < minInsertionSort) ? insertionSortTimes[i] : minInsertionSort;
        maxInsertionSort = (insertionSortTimes[i] > maxInsertionSort) ? insertionSortTimes[i] : maxInsertionSort;

        minQuickSort = (quickSortTimes[i] < minQuickSort) ? quickSortTimes[i] : minQuickSort;
        maxQuickSort = (quickSortTimes[i] > maxQuickSort) ? quickSortTimes[i] : maxQuickSort;

        minBubbleSort = (bubbleSortTimes[i] < minBubbleSort) ? bubbleSortTimes[i] : minBubbleSort;
        maxBubbleSort = (bubbleSortTimes[i] > maxBubbleSort) ? bubbleSortTimes[i] : maxBubbleSort;
    }

    avgInsertionSort /= RUNS;
    avgQuickSort /= RUNS;
    avgBubbleSort /= RUNS;

    printf("Insertion Sort:\n");
    printf("Promedio: %.2f ms\n", avgInsertionSort);
    printf("Mínimo: %.2f ms\n", minInsertionSort);
    printf("Máximo: %.2f ms\n\n", maxInsertionSort);

    printf("Quick Sort:\n");
    printf("Promedio: %.2f ms\n", avgQuickSort);
    printf("Mínimo: %.2f ms\n", minQuickSort);
    printf("Máximo: %.2f ms\n\n", maxQuickSort);

    printf("Bubble Sort:\n");
    printf("Promedio: %.2f ms\n", avgBubbleSort);
    printf("Mínimo: %.2f ms\n", minBubbleSort);
    printf("Máximo: %.2f ms\n", maxBubbleSort);

    return 0;
}

