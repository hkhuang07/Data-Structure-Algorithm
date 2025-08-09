/*
    Cài đặt thuật toán tìm kiếm tuyến tính, tìm kiếm nhị phân
    Bằng ngôn ngữ C
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 32

// Khai báo các hàm
void generateRandomArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void printArray(const int arr[], int n);
int isSortedAscending(const int arr[], int n);
int linearSearch(const int arr[], int n, int x);
int binarySearch(const int arr[], int n, int x);


int main() {
    int *arr;
    int n, choice, x;
    
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid size. Using default 10 elements.\n");
        n = 10;
    }
    
    // Cấp phát bộ nhớ động cho mảng
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nChoose array type:\n");
    printf("1. Random array\n");
    printf("2. Sorted array (ascending)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        generateRandomArray(arr, n);
    } else if (choice == 2) {
        generateRandomArray(arr, n);
        bubbleSort(arr, n); // Sắp xếp mảng ngẫu nhiên để có mảng tăng dần
    } else {
        printf("Invalid choice. Exiting.\n");
        free(arr);
        return 1;
    }

    printf("\nGenerated array:\n");
    printArray(arr, n);

    printf("\nEnter a number to search for: ");
    scanf("%d", &x);

    // Kiểm tra và chọn thuật toán tìm kiếm
    if (isSortedAscending(arr, n)) {
        printf("\nArray is sorted. Using Binary Search...\n");
        int index = binarySearch(arr, n, x);
        if (index != -1) {
            printf("Element %d found at index: %d.\n", x, index);
        } else {
            printf("Element %d not found in the array.\n", x);
        }
    } else {
        printf("\nArray is not sorted. Using Linear Search...\n");
        int index = linearSearch(arr, n, x);
        if (index != -1) {
            printf("Element %d found at index: %d.\n", x, index);
        } else {
            printf("Element %d not found in the array.\n", x);
        }
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}

// Hàm tạo mảng ngẫu nhiên
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

// Hàm sắp xếp nổi bọt (Bubble Sort) để tạo mảng tăng dần
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm in mảng
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm kiểm tra mảng có tăng dần không
int isSortedAscending(const int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // Mảng không tăng dần
        }
    }
    return 1; // Mảng tăng dần
}

// Hàm tìm kiếm tuyến tính
int linearSearch(const int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Trả về chỉ số
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm nhị phân
int binarySearch(const int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // Tìm thấy, trả về chỉ số
        } else if (arr[mid] < x) {
            left = mid + 1; // Tìm kiếm ở nửa bên phải
        } else {
            right = mid - 1; // Tìm kiếm ở nửa bên trái
        }
    }
    
    return -1; // Không tìm thấy
}