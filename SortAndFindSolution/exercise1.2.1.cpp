/*
Implementation of Sorting Algorithms Performance Comparison in C
Author: Huynh Quoc Huy
This program demonstrates and compares the performance of several sorting algorithms.
It generates a random array, sorts it using different algorithms, and measures the execution time for each.
The program includes functions to generate an array, copy an array, and perform various sorting algorithms.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ELEMENTS 50000 // Max array size to test performance
#define NUM_ELEMENTS 5000 // Default array size for demonstration

// Function prototypes
void GenerateRandomArray(int arr[], int n);
void CopyArray(int source[], int dest[], int n);
void PrintArray(int arr[], int n);
void swap(int *a, int *b);

// Sorting Algorithms
void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void InterchangeSort(int arr[], int n);
void BubbleSort(int arr[], int n);
void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);
void QuickSort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);

int main() {
    int arr[MAX_ELEMENTS];
    int tempArr[MAX_ELEMENTS];
    int n = NUM_ELEMENTS;
    clock_t start_time, end_time;
    double cpu_time_used;

    srand(time(NULL));

    // Generate a random array once
    GenerateRandomArray(arr, n);

    // Print the first 10 elements of the original array for verification
    printf("Original array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n\n");

    // === Algorithm Comparison ===

    // 1. Selection Sort
    CopyArray(arr, tempArr, n);
    printf("1. Running Selection Sort with n=%d...\n", n);
    start_time = clock();
    SelectionSort(tempArr, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 2. Insertion Sort
    CopyArray(arr, tempArr, n);
    printf("2. Running Insertion Sort with n=%d...\n", n);
    start_time = clock();
    InsertionSort(tempArr, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 3. Interchange Sort
    CopyArray(arr, tempArr, n);
    printf("3. Running Interchange Sort with n=%d...\n", n);
    start_time = clock();
    InterchangeSort(tempArr, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 4. Bubble Sort
    CopyArray(arr, tempArr, n);
    printf("4. Running Bubble Sort with n=%d...\n", n);
    start_time = clock();
    BubbleSort(tempArr, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 5. Merge Sort
    CopyArray(arr, tempArr, n);
    printf("5. Running Merge Sort with n=%d...\n", n);
    start_time = clock();
    MergeSort(tempArr, 0, n - 1);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 6. Quick Sort
    CopyArray(arr, tempArr, n);
    printf("6. Running Quick Sort with n=%d...\n", n);
    start_time = clock();
    QuickSort(tempArr, 0, n - 1);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    // 7. Heap Sort
    CopyArray(arr, tempArr, n);
    printf("7. Running Heap Sort with n=%d...\n", n);
    start_time = clock();
    HeapSort(tempArr, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("...\n");
    printf("Execution time: %f seconds\n\n", cpu_time_used);

    return 0;
}

// === Utility and Sorting Functions ===

/**
 * @brief Generates an array with random integer values.
 * @param arr The array to be filled.
 * @param n The number of elements.
 */
void GenerateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

/**
 * @brief Copies elements from a source array to a destination array.
 * @param source The source array.
 * @param dest The destination array.
 * @param n The number of elements to copy.
 */
void CopyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

/**
 * @brief Prints the elements of an array.
 * @param arr The array to be printed.
 * @param n The number of elements.
 */
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Swaps the values of two integers.
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Sorts an array using the Selection Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements.
 */
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Optimized to perform a single swap per outer loop
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements.
 */
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Sorts an array using the Interchange Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements.
 */
void InterchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

/**
 * @brief Sorts an array using the Bubble Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements.
 */
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}

/**
 * @brief Merges two sorted subarrays.
 */
void Merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

/**
 * @brief Sorts an array using the Merge Sort algorithm.
 */
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

/**
 * @brief Partitions an array for Quick Sort.
 */
int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * @brief Sorts an array using the Quick Sort algorithm.
 */
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

/**
 * @brief Turns a subtree into a max heap.
 */
void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

/**
 * @brief Sorts an array using the Heap Sort algorithm.
 */
void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}
