#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Define the binary tree class
template <typename T>
class BinaryTree {
public:
    Node<T>* root;

    // Constructor to initialize the binary tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a new node in the binary tree
    void insert(T value) {
        root = insertRec(root, value);
    }

private:
    // Helper function to insert a new node recursively
    Node<T>* insertRec(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    cout << "Binary tree created with root value: " << tree.root->data << endl;
    return 0;
}
