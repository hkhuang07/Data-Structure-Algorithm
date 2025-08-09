#include <stdio.h>

/**
 * @brief Recursively calculates the sum of all integers from 1 to n.
 * @param n The upper limit of the summation.
 * @return The sum of numbers from 1 to n.
 */
int sum_recursive(int n) {
    // Base case: If n is 0, the sum is 0.
    if (n == 0) {
        return 0;
    }
    // Recursive step: sum(n) = n + sum(n-1)
    return n + sum_recursive(n - 1);
}

int main() {
    int n;
    printf("Enter a non-negative integer to sum up to: ");
    scanf("%d", &n);

    // Input validation: Ensure the number is non-negative.
    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    int total_sum = sum_recursive(n);
    printf("The sum of integers from 1 to %d is: %d\n", n, total_sum);

    return 0;
}
