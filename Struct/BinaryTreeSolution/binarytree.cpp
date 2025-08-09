#include <iostream>

// 1. Definition of a binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// 2. Function to insert a new node into a Binary Search Tree (BST)
Node* insertNode(Node* root, int value) {
    // If the tree is empty, create a new node and assign it as the root
    if (root == NULL) {
        return new Node(value);
    }

    // If the value is less than the current node's data, insert into the left subtree
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // If the value is greater than or equal, insert into the right subtree
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// 3. In-order traversal function
// Traverses left -> root -> right. The result is a sorted list of numbers.
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to free memory (important to prevent memory leaks)
void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 4. Main function to run the program
int main() {
    Node* root = NULL;

    // Insert elements into the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the elements of the tree in order
    std::cout << "The elements of the tree are printed in ascending order (In-order traversal):" << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    // Free the tree's memory after use
    deleteTree(root);
    std::cout << "Successfully freed the tree's memory." << std::endl;

    return 0;
}
