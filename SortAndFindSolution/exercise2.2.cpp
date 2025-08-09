/*
    Xây dựng và cài đặt thuật toán
    a. Tìm và trả về phần tử lớn nhất
    b. Đếm và trả về số lượng số nguyên tố
    c. Tìm và trả về vị trí phần tử nguyên tố đầu tiên
    d. Dãy con tăng dài nhất trong 1 dãy các phần tử cho trước được cài đặt bằng mảng
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // Dùng cho INT_MIN

using namespace std;

// Khai báo các hàm
int findMax(const vector<int>& arr);
bool isPrime(int n);
int countPrimeNumbers(const vector<int>& arr);
int firstPrimePosition(const vector<int>& arr);
void longestIncreasingSubarray(const vector<int>& arr);

int main() {
    int n;

    //Input n
    cout << "Enter the number of elements: ";
    cin >> n;
    //Check n must greater than 0
    if (n <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }

    //Array arr with vector (dynamic array) datatype
    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Hiển thị mảng đã nhập
    cout << "\nYour array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // a. Find element with max value
    cout << "\n--- Part a: Find Max Element ---" << endl;
    cout << "The max element is: " << findMax(arr) << endl;

    // b. Count prime number quantity
    cout << "\n--- Part b: Count Prime Numbers ---" << endl;
    cout << "Number of prime elements: " << countPrimeNumbers(arr) << endl;

    // c. Find  first prime position 
    cout << "\n--- Part c: Find First Prime Position ---" << endl;
    int primePos = firstPrimePosition(arr);
    if (primePos != -1) {
        cout << "First prime number " << arr[primePos] << " is at position: " << primePos << endl;
    } else {
        cout << "No prime number found in the array." << endl;
    }
    
    // d. Find longest increasing sub array
    cout << "\n--- Part d: Longest Increasing Subarray ---" << endl;
    longestIncreasingSubarray(arr);

    return 0;
}

// a. Find max
int findMax(const vector<int>& arr) {
    if (arr.empty()) {
        return INT_MIN; //Return milimum value if array is empty
    }
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Hàm kiểm tra một số có phải số nguyên tố không
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// b. Quantity of prime number
int countPrimeNumbers(const vector<int>& arr) {
    int count = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}

// c. Fist prime position
int firstPrimePosition(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (isPrime(arr[i])) {
            return i;
        }
    }
    return -1; //return false (not found)
}

// d. Find longest increasing subarray
void longestIncreasingSubarray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "The array is empty." << endl;
        return;
    }

    int maxLength = 1;
    int currentLength = 1;
    int endIndex = 0; //end position of sub array

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            currentLength++; //current length +1 if element i < element i+1
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength; //update currentlenght if it greater than maxlength
                endIndex = i - 1; //update endindex = last position of subarray which have max increase lenght
            }
            currentLength = 1; //reset current length
        }
    }

    // Check case:  longest increasing subarray in last array 
    if (currentLength > maxLength) {
        maxLength = currentLength;
        endIndex = arr.size() - 1;
    }

    int startIndex = endIndex - maxLength + 1;

    cout << "The longest increasing subarray has length: " << maxLength << endl;
    cout << "The subarray is: ";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}