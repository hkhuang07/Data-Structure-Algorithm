#include <stdio.h>
#include <stdlib.h> // For calloc and free

// Global array to store calculated Fibonacci values (memoization table)
int *memo;

/**
 * @brief Calculates the nth Fibonacci number using recursion with memoization.
 * * @param n The position in the Fibonacci sequence (n > 0).
 * @return The value of the nth Fibonacci number.
 */
int fibonacci_recursive_memo(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // Check if the value has already been calculated
    if (memo[n] != 0) {
        return memo[n];
    }
    
    // Calculate and store the result before returning
    memo[n] = fibonacci_recursive_memo(n - 1) + fibonacci_recursive_memo(n - 2);
    return memo[n];
}

/**
 * @brief Prints the Fibonacci sequence up to the nth term.
 * * @param n The number of terms to print.
 */
void print_fibonacci_sequence(int n) {
    if (n <= 0) {
        return;
    }
    
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci_recursive_memo(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms to find: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate and initialize memoization table with zeros
    memo = (int *)calloc(n + 1, sizeof(int));
    if (memo == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    // The base cases for the Fibonacci sequence are F(0)=0 and F(1)=1
    // The previous code had a base case error (F(1)=1, F(2)=1).
    // F(0)=0 is a more standard and robust base case.
    // However, since the user's code starts from n=1, we will set F(1)=1 and handle n=0 gracefully.
    memo[1] = 1;

    int fib_value = fibonacci_recursive_memo(n);
    printf("The %dth value in the Fibonacci sequence is: %d\n", n, fib_value);
    
    print_fibonacci_sequence(n);
    
    // Free the allocated memory
    free(memo);
    return 0;
}
