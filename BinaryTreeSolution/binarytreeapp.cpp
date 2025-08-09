#include <iostream>
#include <algorithm> // For std::max

// 1. �?nh nghia c?u tr�c c?a m?t node trong c�y nh? ph�n
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

// 2. H�m x�y d?ng c�y m?u
Node* buildSampleTree() {
    // Tree structure:
    /*
             1
            / \
           2   3
          / \   \
         4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

// 3. H�m t�m ki?m m?t gi� tr? trong c�y nh? ph�n
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    // Search in the left and right subtrees
    return search(root->left, value) || search(root->right, value);
}

// 4. H�m t�nh chi?u cao c?a c�y
// Chi?u cao c?a m?t c�y l� s? c?nh tr�n du?ng di d�i nh?t t? g?c d?n m?t n�t l�.
int treeHeight(Node* root) {
    if (root == NULL) {
        return -1; // Chi?u cao c?a c�y r?ng l� -1
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// H�m d? gi?i ph�ng b? nh? c?a c�y
void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 5. H�m main d? ch?y chuong tr�nh v� hi?n th? k?t qu?
int main() {
    Node* root = buildSampleTree();

    std::cout << "Binary Tree Application Example:" << std::endl;

    // Test the search function
    int searchValue1 = 5;
    int searchValue2 = 10;
    std::cout << "\nSearching for value " << searchValue1 << ": " << (search(root, searchValue1) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for value " << searchValue2 << ": " << (search(root, searchValue2) ? "Found" : "Not Found") << std::endl;

    // Test the treeHeight function
    std::cout << "\nThe height of the tree is: " << treeHeight(root) << std::endl;

    // Free memory
    deleteTree(root);
    std::cout << "Successfully freed the tree's memory." << std::endl;

    return 0;
}
