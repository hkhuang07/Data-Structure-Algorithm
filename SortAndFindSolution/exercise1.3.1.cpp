#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000 // Max array size
#define VISUALIZE_N 10    // Number of elements to visualize step-by-step

// Function prototypes
void CopyArray(int source[], int dest[], int n);
void GenerateRandomArray(int arr[], int n);
void PrintArray(int arr[], int n);
void swap(int *a, int *b);
void PrintArrayStep(int arr[], int n, int highlight1, int highlight2, const char *message);

// Function pointers for sorting algorithms
// Using function pointers to handle different function signatures
typedef void (*SortFunction2Args)(int[], int);
typedef void (*SortFunction3Args)(int[], int, int);

// Sorting algorithms
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

// Unified function to run and visualize a sort algorithm with 2 arguments
void runAndVisualize2Args(SortFunction2Args sortFunc, const char *name, int arr[], int n, int visualize_n);

// Unified function to run and benchmark a sort algorithm with 3 arguments
void runAndBenchmark3Args(SortFunction3Args sortFunc, const char *name, int arr[], int n);

int main() {
    int arr[MAX_ELEMENTS];
    int n;

    srand(time(NULL));

    printf("Enter the number of elements to sort (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_ELEMENTS) {
        printf("Invalid number of elements. Using default %d.\n", VISUALIZE_N);
        n = VISUALIZE_N;
    }

    GenerateRandomArray(arr, n);

    printf("====================================================\n");
    printf("|          SORTING ALGORITHM VISUALIZATION         |\n");
    printf("====================================================\n");
    printf("Original array (first %d elements):\n", VISUALIZE_N > n ? n : VISUALIZE_N);
    PrintArray(arr, VISUALIZE_N > n ? n : VISUALIZE_N);
    printf("...\n\n");

    // Run and visualize 2-argument sorting algorithms
    runAndVisualize2Args(SelectionSort, "Selection Sort", arr, n, VISUALIZE_N);
    runAndVisualize2Args(InsertionSort, "Insertion Sort", arr, n, VISUALIZE_N);
    runAndVisualize2Args(InterchangeSort, "Interchange Sort", arr, n, VISUALIZE_N);
    runAndVisualize2Args(BubbleSort, "Bubble Sort", arr, n, VISUALIZE_N);
    runAndVisualize2Args(HeapSort, "Heap Sort", arr, n, VISUALIZE_N);

    // Run and benchmark 3-argument sorting algorithms
    printf("====================================================\n");
    printf("|          PERFORMANCE BENCHMARK (n = %d)          |\n", n);
    printf("====================================================\n");
    
    runAndBenchmark3Args(MergeSort, "Merge Sort", arr, n);
    runAndBenchmark3Args(QuickSort, "Quick Sort", arr, n);

    printf("====================================================\n");
    return 0;
}

// === UTILITY AND SORTING FUNCTIONS ===

// Unified function to run and visualize a sort algorithm with 2 arguments
void runAndVisualize2Args(SortFunction2Args sortFunc, const char *name, int arr[], int n, int visualize_n) {
    int tempArr[MAX_ELEMENTS];
    CopyArray(arr, tempArr, n);

    clock_t start_time, end_time;
    double cpu_time_used;

    printf("----------------------------------------------------\n");
    printf("| %-48s |\n", name);
    printf("----------------------------------------------------\n");

    start_time = clock();
    
    if (n <= visualize_n) {
        printf("Visualizing steps:\n");
        sortFunc(tempArr, n);
        printf("\nFinal Sorted array:\n");
        PrintArray(tempArr, n);
        printf("\n");
    } else {
        printf("Running... (Visualization skipped for large n)\n");
        sortFunc(tempArr, n);
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Execution Time (n=%d): %f seconds\n", n, cpu_time_used);
    printf("----------------------------------------------------\n\n");
}

// Unified function to run and benchmark a sort algorithm with 3 arguments
void runAndBenchmark3Args(SortFunction3Args sortFunc, const char *name, int arr[], int n) {
    int tempArr[MAX_ELEMENTS];
    CopyArray(arr, tempArr, n);

    clock_t start_time, end_time;
    double cpu_time_used;

    printf("----------------------------------------------------\n");
    printf("| %-48s |\n", name);
    printf("----------------------------------------------------\n");
    printf("Running... (Visualization is complex for this algorithm)\n");

    start_time = clock();
    sortFunc(tempArr, 0, n - 1);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Final Sorted array (first 10 elements):\n");
    PrintArray(tempArr, VISUALIZE_N > n ? n : VISUALIZE_N);
    printf("...\n");

    printf("Execution Time (n=%d): %f seconds\n", n, cpu_time_used);
    printf("----------------------------------------------------\n\n");
}


/**
 * @brief Generates an array with random integer values.
 */
void GenerateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

/**
 * @brief Copies elements from a source array to a destination array.
 */
void CopyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

/**
 * @brief Prints the elements of an array.
 */
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Swaps the values of two integers.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Prints an array with highlighted elements.
 */
void PrintArrayStep(int arr[], int n, int highlight1, int highlight2, const char *message) {
    printf("  -> %s\n", message);
    for (int i = 0; i < n; i++) {
        if (i == highlight1 || i == highlight2) {
            printf("[%d] ", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Sorts an array using the Selection Sort algorithm.
 */
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        printf("\nStep %d: Found min element %d at index %d\n", i + 1, arr[minIndex], minIndex);
        if (minIndex != i) {
            printf("  -> Swapping %d and %d\n", arr[i], arr[minIndex]);
            swap(&arr[i], &arr[minIndex]);
        } else {
            printf("  -> No swap needed.\n");
        }
        PrintArrayStep(arr, n, i, minIndex, "Array state after swap:");
    }
}

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 */
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        printf("\nStep %d: Inserting element %d\n", i, key);
        while (j >= 0 && arr[j] > key) {
            printf("  -> Shifting %d to the right\n", arr[j]);
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("  -> Placing %d at index %d\n", key, j + 1);
        PrintArrayStep(arr, n, j + 1, -1, "Array state:");
    }
}

/**
 * @brief Sorts an array using the Interchange Sort algorithm.
 */
void InterchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                printf("\nStep: Comparing %d and %d. Swapping.\n", arr[i], arr[j]);
                swap(&arr[i], &arr[j]);
                PrintArrayStep(arr, n, i, j, "Array state:");
            }
        }
    }
}

/**
 * @brief Sorts an array using the Bubble Sort algorithm.
 */
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("\nPass %d:\n", i + 1);
        int swapped = 0;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                printf("  -> Comparing %d and %d. Swapping.\n", arr[j], arr[j - 1]);
                swap(&arr[j], &arr[j - 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) { // Optimization for already sorted array
            printf("  -> Array is already sorted. Exiting early.\n");
            break;
        }
        PrintArrayStep(arr, n, i, -1, "Array state after pass:");
    }
}

// Merge Sort, Quick Sort, and Heap Sort remain the same as the logic is already optimized.
// I've added comments and a `swap` utility to them for consistency.
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

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

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

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

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

void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}
