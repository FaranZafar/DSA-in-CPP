#include <iostream>
#include <stack>

// Represents a single node in the tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    // Iterative Insert
    void insert(int val) {
        Node* newNode = new Node(val);

        // If the tree is empty, new node becomes the root
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        // Traverse down the tree to find the correct empty spot
        while (current != nullptr) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Attach the new node to the parent
        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Iterative Inorder Traversal (Left, Root, Right)
    void inorderTraversal() {
        if (root == nullptr) return;

        std::stack<Node*> s;
        Node* current = root;

        while (current != nullptr || !s.empty()) {
            // Reach the leftmost Node of the current Node
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            // Current must be NULL at this point
            current = s.top();
            s.pop();

            std::cout << current->data << " ";

            // We have visited the node and its left subtree. Now, it's the right subtree's turn
            current = current->right;
        }
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Building the tree:
    //       50
    //      /  \
    //    30    70
    //   /  \
    // 20    40
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);

    std::cout << "Iterative Inorder Traversal (Sorted Output): " << std::endl;
    bst.inorderTraversal();

    return 0;
}