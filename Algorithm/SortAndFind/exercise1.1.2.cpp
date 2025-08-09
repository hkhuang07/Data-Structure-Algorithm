/*
    Cài đặt thuật toán tìm kiếm tuyến tính, tìm kiếm nhị phân
    Và thêm chức năng kiểm tra mảng để chọn thuật toán phù hợp
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::sort

#define MAX 32

bool isSortedAscending(const std::vector<int>& arr);
void generateRandomArray(std::vector<int>& arr, int n);
void generateSortedArray(std::vector<int>& arr, int n);
void printArray(const std::vector<int>& arr);
int linearSearch(const std::vector<int>& arr, int x);
int binarySearch(const std::vector<int>& arr, int x);

int main() {
    std::vector<int> a;
    int n, choice, x;

    std::cout << "Choose array type:\n";
    std::cout << "1. Random array\n";
    std::cout << "2. Sorted array (ascending)\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter the number of elements (max " << MAX << "): ";
        std::cin >> n;
        if (n < 1 || n > MAX) {
            std::cout << "Invalid size. Using default 10 elements.\n";
            n = 10;
        }
        a.resize(n);
        generateRandomArray(a, n);
    } else if (choice == 2) {
        std::cout << "Enter the number of elements (max " << MAX << "): ";
        std::cin >> n;
        if (n < 1 || n > MAX) {
            std::cout << "Invalid size. Using default 10 elements.\n";
            n = 10;
        }
        a.resize(n);
        generateSortedArray(a, n);
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    std::cout << "\nGenerated array:\n";
    printArray(a);

    std::cout << "\nEnter a number to search for: ";
    std::cin >> x;

    // Kiểm tra và chọn thuật toán tìm kiếm
    if (isSortedAscending(a)) {
        std::cout << "\nArray is sorted. Using Binary Search...\n";
        int index = binarySearch(a, x);
        if (index != -1) {
            std::cout << "Element " << x << " found at index: " << index << ".\n";
        } else {
            std::cout << "Element " << x << " not found in the array.\n";
        }
    } else {
        std::cout << "\nArray is not sorted. Using Linear Search...\n";
        int index = linearSearch(a, x);
        if (index != -1) {
            std::cout << "Element " << x << " found at index: " << index << ".\n";
        } else {
            std::cout << "Element " << x << " not found in the array.\n";
        }
    }

    return 0;
}

// Kiểm tra mảng tăng dần
bool isSortedAscending(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Tạo mảng ngẫu nhiên
void generateRandomArray(std::vector<int>& arr, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, n);

    for (int i = 0; i < n; i++) {
        arr[i] = distrib(gen);
    }
}

// Tạo mảng tăng dần
void generateSortedArray(std::vector<int>& arr, int n) {
    generateRandomArray(arr, n); // Tạo mảng ngẫu nhiên trước
    std::sort(arr.begin(), arr.end()); // Sau đó sắp xếp lại
}

// In mảng
void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Tìm kiếm tuyến tính
int linearSearch(const std::vector<int>& arr, int x) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return i; // Trả về chỉ số
        }
    }
    return -1; // Không tìm thấy
}

// Tìm kiếm nhị phân
int binarySearch(const std::vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

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