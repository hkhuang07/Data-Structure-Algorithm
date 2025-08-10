#include <stdio.h>

/**
 * @brief Calculates the factorial of a given number using recursion.
 * @param n The integer for which to calculate the factorial.
 * @return The factorial of n. Returns 1 for n=0 or n=1.
 */
long long factorial(int n) {
    // Base case: The factorial of 0 and 1 is 1.
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive step: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &n);

    // Input validation: Ensure the number is not negative.
    if (n < 0) {
        printf("Invalid input. Factorial is not defined for negative numbers.\n");
        return 1;
    }

    // Since factorials grow very quickly, using 'long long' is safer to prevent overflow.
    long long result = factorial(n);
    printf("The factorial of %d is: %lld\n", n, result);

    return 0;
}
