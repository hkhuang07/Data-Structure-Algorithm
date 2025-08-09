#include <iostream>
#include <string>
#include <list>
#include <vector>

#define TABLE_SIZE 20

// 1. Define the Product structure
struct Product {
    int id;
    std::string name;
    int quantity;
};

// 2. Define the Hash Table structure
struct HashTable {
    std::vector<std::list<Product> > table;

    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // 3. Hash function to convert a product ID into an index
    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

    // 4. Insert or update a product in the hash table
    void insert(int id, const std::string& name, int quantity) {
        int index = hashFunction(id);
        bool found = false;
        
        // S? d?ng iterator d? ki?m tra va ch?m và c?p nh?t
        std::list<Product>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == id) {
                it->name = name;
                it->quantity = quantity;
                found = true;
                std::cout << "Product ID " << id << " updated." << std::endl;
                break;
            }
        }
        
        // If not found, add a new product
        if (!found) {
            table[index].push_back({id, name, quantity});
            std::cout << "New product with ID " << id << " inserted." << std::endl;
        }
    }

    // 5. Search for a product by ID and return a pointer to it
    Product* search(int id) {
        int index = hashFunction(id);
        
        // S? d?ng const_iterator d? tìm ki?m
        std::list<Product>::const_iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == id) {
                // Tr? v? con tr? t?i ph?n t? (luu ý: c?n c?n th?n v?i lifetime c?a iterator)
                // Trong tru?ng h?p này, vì ta không xóa, nên an toàn.
                return const_cast<Product*>(&(*it)); 
            }
        }
        return NULL; // Thay th? nullptr b?ng NULL cho C++98
    }
};

// 6. Main function to simulate the inventory system
int main() {
    HashTable inventory;

    std::cout << "--- Inventory Management System ---" << std::endl;

    // A. Add products to the inventory
    inventory.insert(101, "Laptop", 50);
    inventory.insert(205, "Mouse", 150);
    inventory.insert(310, "Keyboard", 75);
    inventory.insert(101, "Laptop", 45); // Update an existing product

    // B. Search for products and check their stock
    std::cout << "\n--- Checking Stock Levels ---" << std::endl;
    int searchId1 = 205;
    Product* foundProduct1 = inventory.search(searchId1);
    if (foundProduct1 != NULL) {
        std::cout << "Product found: " << foundProduct1->name 
                  << " (ID: " << foundProduct1->id 
                  << "), Quantity: " << foundProduct1->quantity << std::endl;
    } else {
        std::cout << "Product with ID " << searchId1 << " not found." << std::endl;
    }
    
    int searchId2 = 500;
    Product* foundProduct2 = inventory.search(searchId2);
    if (foundProduct2 != NULL) {
        std::cout << "Product found: " << foundProduct2->name 
                  << " (ID: " << foundProduct2->id 
                  << "), Quantity: " << foundProduct2->quantity << std::endl;
    } else {
        std::cout << "Product with ID " << searchId2 << " not found." << std::endl;
    }

    return 0;
}
