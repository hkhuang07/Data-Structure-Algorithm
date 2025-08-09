#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the minimum number of coins to make change
void findMinCoins(std::vector<int>& coins, int amount) {
    // Sort coins in descending order for the greedy approach
    std::sort(coins.rbegin(), coins.rend());

    std::cout << "Amount to change: " << amount << std::endl;
    std::cout << "Available coins: ";
    for (int coin : coins) {
        std::cout << coin << " ";
    }
    std::cout << std::endl;

    std::cout << "\nOptimal change:" << std::endl;
    
    // Vector to store the count of each coin used
    std::vector<int> coinCounts(coins.size(), 0);

    // Greedy algorithm: iterate through coins from largest to smallest
    for (int i = 0; i < coins.size(); ++i) {
        // While the current coin can be used to make change
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCounts[i]++;
        }
    }

    // Print the result
    int totalCoins = 0;
    for (int i = 0; i < coins.size(); ++i) {
        if (coinCounts[i] > 0) {
            std::cout << "  - " << coinCounts[i] << " coin(s) of value " << coins[i] << std::endl;
            totalCoins += coinCounts[i];
        }
    }
    std::cout << "\nTotal number of coins used: " << totalCoins << std::endl;
}

// Main function to run the program
int main() {
    // Example 1: Standard coin system
    std::vector<int> standardCoins = {1, 2, 5, 10, 20, 50, 100};
    int amount1 = 93;
    findMinCoins(standardCoins, amount1);

    std::cout << "\n----------------------------------------\n";
    
    // Example 2: Another coin system
    std::vector<int> otherCoins = {1, 5, 10, 25};
    int amount2 = 42;
    findMinCoins(otherCoins, amount2);

    return 0;
}