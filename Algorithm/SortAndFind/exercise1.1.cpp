/*
Implementation of Sorting Algorithms in C
Author: Huynh Quoc Huy
This program demonstrates several sorting algorithms.
The user can input an array of integers, and the program will sort the array using the selected sorting algorithm.
The program includes functions to input an array, print the array, and perform the sorting algorithms.
*/

#include <stdio.h>
#define MAX 32

// Function prototypes
void InputArray(int arr[], int n);
void PrintArray(int arr[], int n);
void swap(int* a, int* b);

// Basic Sorting Algorithms
void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void InterchangeSort(int arr[], int n);
void BubbleSort(int arr[], int n);

// Advanced Sorting Algorithms
void ShellSort(int arr[], int n); // New function
void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);
void QuickSort(int arr[], int low, int high);
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);

int main() {
    int arr[MAX];
    int n, choice;

    do {
        printf("Enter the number of elements in the array (max %d): ", MAX);
        scanf("%d", &n);
        if (n < 1 || n > MAX) {
            printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX);
            return 1;
        }

        InputArray(arr, n);

        printf("Original array:\n");
        PrintArray(arr, n);

        printf("\n\nChoose a sorting algorithm:\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Interchange Sort\n");
        printf("4. Bubble Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Heap Sort\n");
        printf("8. Shell Sort\n"); // Added ShellSort to the menu
        printf("9. Exit\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 9);

    switch (choice) {
        case 1:
            printf("\nSorting using Selection Sort...\n");
            SelectionSort(arr, n);
            PrintArray(arr, n); // Added PrintArray to all cases for consistency
            printf("\n");
            break;
        case 2:
            printf("\nSorting using Insertion Sort...\n");
            InsertionSort(arr, n);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 3:
            printf("\nSorting using Interchange Sort...\n");
            InterchangeSort(arr, n);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 4:
            printf("\nSorting using Bubble Sort...\n");
            BubbleSort(arr, n);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 5:
            printf("\nSorting using Merge Sort...\n");
            MergeSort(arr, 0, n - 1);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 6:
            printf("\nSorting using Quick Sort...\n");
            QuickSort(arr, 0, n - 1);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 7:
            printf("\nSorting using Heap Sort...\n");
            HeapSort(arr, n);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 8: // New case for Shell Sort
            printf("\nSorting using Shell Sort...\n");
            ShellSort(arr, n);
            PrintArray(arr, n);
            printf("\n");
            break;
        case 9:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a number between 1 and 9.\n");
            return 1;
    }
}

/**
 * @brief Swaps two integer values.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Gets user input for array elements.
 * @param arr The array to be filled.
 * @param n The number of elements to input.
 */
void InputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

/**
 * @brief Prints the elements of an array.
 * @param arr The array to be printed.
 * @param n The number of elements in the array.
 */
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]=%2d  ", i, arr[i]);
    }
}

/**
 * @brief Sorts an array using the Selection Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void SelectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void InsertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
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
 * @param n The number of elements in the array.
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
 * @param n The number of elements in the array.
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
 * @brief Sorts an array using the Shell Sort algorithm.
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void ShellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order.
        // Keep adding one more element until the entire array is gap sorted.
        for (int i = gap; i < n; i++) {
            // Store arr[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

/**
 * @brief Merges two subarrays of arr[].
 * The first subarray is arr[left..mid].
 * The second subarray is arr[mid+1..right].
 */
void Merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Sorts an array using the Merge Sort algorithm.
 * @param arr The array to be sorted.
 * @param left The starting index of the subarray.
 * @param right The ending index of the subarray.
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
 * @brief Partitions the array and returns the pivot index for Quick Sort.
 */
int partition(int arr[], int low, int high) {
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
 * @param arr The array to be sorted.
 * @param low The starting index.
 * @param high The ending index.
 */
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

/**
 * @brief Turns a subtree rooted with node i into a max heap.
 * @param arr The array representing the heap.
 * @param n The size of the heap.
 * @param i The root index of the subtree.
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
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void HeapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}
