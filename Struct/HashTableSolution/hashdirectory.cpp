#include <iostream>
#include <string>
#include <list>
#include <vector>

#define TABLE_SIZE 10

// 1. Define the Key-Value Pair structure
struct KeyValuePair {
    std::string key;
    std::string value;
};

// 2. Define the Hash Table structure
struct HashTable {
    std::vector<std::list<KeyValuePair> > table;

    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // 3. Hash function to convert a string into an index
    int hashFunction(const std::string& key) {
        int hash = 0;
        // S? d?ng vòng l?p for truy?n th?ng
        for (std::string::const_iterator it = key.begin(); it != key.end(); ++it) {
            hash += *it;
        }
        return hash % TABLE_SIZE;
    }

    // 4. Insert a key-value pair into the hash table
    void insert(const std::string& key, const std::string& value) {
        int index = hashFunction(key);
        bool found = false;
        
        // S? d?ng iterator d? ki?m tra va ch?m và c?p nh?t
        std::list<KeyValuePair>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                it->value = value; // Update the value
                found = true;
                break;
            }
        }
        
        // If key not found, add a new pair
        if (!found) {
            table[index].push_back({key, value});
        }
    }

    // 5. Search for a key and return its value
    std::string search(const std::string& key) {
        int index = hashFunction(key);
        
        // S? d?ng iterator d? tìm ki?m
        std::list<KeyValuePair>::const_iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value;
            }
        }
        return "Definition not found.";
    }
    
    // Function to display the hash table (for debugging)
    void display() {
        std::cout << "\n--- Dictionary Hash Table Contents ---" << std::endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Index " << i << ": ";
            if (!table[i].empty()) {
                // S? d?ng iterator d? hi?n th? n?i dung
                std::list<KeyValuePair>::const_iterator it;
                for (it = table[i].begin(); it != table[i].end(); ++it) {
                    std::cout << "[" << it->key << ": " << it->value << "] ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "--------------------------------------" << std::endl;
    }
};

// 6. Main function to demonstrate the dictionary application
int main() {
    HashTable dictionary;

    // A. Insert some words and their definitions
    dictionary.insert("apple", "A common edible fruit.");
    dictionary.insert("computer", "An electronic device for storing and processing data.");
    dictionary.insert("algorithm", "A set of rules for solving a problem.");
    dictionary.insert("data", "Facts or information used to calculate, reason, or analyze.");
    dictionary.insert("stack", "A data structure following the LIFO principle.");
    dictionary.insert("queue", "A data structure following the FIFO principle.");

    // B. Search for definitions
    std::cout << "\n--- Dictionary Lookup ---" << std::endl;
    std::string word1 = "apple";
    std::cout << "Definition of '" << word1 << "': " << dictionary.search(word1) << std::endl;

    std::string word2 = "algorithm";
    std::cout << "Definition of '" << word2 << "': " << dictionary.search(word2) << std::endl;

    std::string word3 = "chair";
    std::cout << "Definition of '" << word3 << "': " << dictionary.search(word3) << std::endl;

    // C. Display the hash table structure
    dictionary.display();

    return 0;
}
