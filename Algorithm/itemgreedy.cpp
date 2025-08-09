#include <iostream>
#include <vector>
#include <algorithm>

// Define the Item structure
struct Item {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
};

// Comparison function to sort items by their value-to-weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

// Greedy function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    // Calculate the value-to-weight ratio for each item
    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    // Sort items based on their ratio in descending order
    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    std::cout << "Selecting items for the knapsack (capacity = " << capacity << "):" << std::endl;

    // Iterate through the sorted items and add them to the knapsack
    for (const auto& item : items) {
        // If the entire item can be taken
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
            std::cout << "  - Took full item (Weight: " << item.weight << ", Value: " << item.value << ")" << std::endl;
        } 
        // If only a fraction of the item can be taken
        else {
            int remainingCapacity = capacity - currentWeight;
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += item.value * fraction;
            currentWeight += remainingCapacity;
            std::cout << "  - Took a fraction of item (Weight: " << item.weight << ", Value: " << item.value << ")" << std::endl;
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

// Main function to run the program
int main() {
    // A vector of items {weight, value}
    std::vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);

    std::cout << "\nMaximum value that can be obtained: " << maxValue << std::endl;

    return 0;
}