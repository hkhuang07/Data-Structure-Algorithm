#include <iostream>
#include <queue>
#include <stack>

// C?u tr�c m?t node c?a c�y nh? ph�n
struct Node {
    int data;
    Node* left;
    Node* right;

    // H�m kh?i t?o d? t?o m?t node m?i
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// H�m t?o m?t node m?i
Node* createNode(int value) {
    return new Node(value);
}

// H�m x�y d?ng c�y m?u
Node* buildSampleTree() {
    // C�y m?u s? c� c?u tr�c nhu sau:
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

// H�m duy?t c�y theo chi?u r?ng (BFS - Breadth-First Search)
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

        // �?y c�c node con v�o queue theo th? t? t? tr�i sang ph?i
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

// H�m duy?t c�y theo chi?u s�u (DFS - Depth-First Search)
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

        // �?y node con ph?i v�o stack tru?c d? tham node con tr�i tru?c
        if (current->right != NULL) {
            s.push(current->right);
        }
        if (current->left != NULL) {
            s.push(current->left);
        }
    }
    std::cout << std::endl;
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

int main() {
    Node* root = buildSampleTree();

    std::cout << "Tree Traversal Example:" << std::endl;

    // Ch?y thu?t to�n BFS
    bfsTraversal(root);

    // Ch?y thu?t to�n DFS
    dfsTraversal(root);

    // Gi?i ph�ng b? nh? sau khi s? d?ng
    deleteTree(root);

    return 0;
}
