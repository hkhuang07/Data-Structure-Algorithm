#include <iostream>
#include <queue>
#include <stack>

// C?u trúc m?t node c?a cây nh? phân
struct Node {
    int data;
    Node* left;
    Node* right;

    // Hàm kh?i t?o d? t?o m?t node m?i
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Hàm t?o m?t node m?i
Node* createNode(int value) {
    return new Node(value);
}

// Hàm xây d?ng cây m?u
Node* buildSampleTree() {
    // Cây m?u s? có c?u trúc nhu sau:
    /*
             1
            / \
           2   3
          / \ / \
         4  5 6  7
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

// Hàm duy?t cây theo chi?u r?ng (BFS - Breadth-First Search)
void bfsTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    std::cout << "BFS Traversal (Level-by-Level): ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        // Ð?y các node con vào queue theo th? t? t? trái sang ph?i
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

// Hàm duy?t cây theo chi?u sâu (DFS - Depth-First Search)
void dfsTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    std::stack<Node*> s;
    s.push(root);

    std::cout << "DFS Traversal (Depth-First): ";
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        std::cout << current->data << " ";

        // Ð?y node con ph?i vào stack tru?c d? tham node con trái tru?c
        if (current->right != NULL) {
            s.push(current->right);
        }
        if (current->left != NULL) {
            s.push(current->left);
        }
    }
    std::cout << std::endl;
}

// Hàm d? gi?i phóng b? nh? c?a cây
void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Node* root = buildSampleTree();

    std::cout << "Tree Traversal Example:" << std::endl;

    // Ch?y thu?t toán BFS
    bfsTraversal(root);

    // Ch?y thu?t toán DFS
    dfsTraversal(root);

    // Gi?i phóng b? nh? sau khi s? d?ng
    deleteTree(root);

    return 0;
}
