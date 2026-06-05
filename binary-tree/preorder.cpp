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

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Iterative Preorder Traversal (Root, Left, Right)
    void preorderTraversal() {
        if (root == nullptr) return;

        // Create a stack and push the root
        std::stack<Node*> s;
        s.push(root);

        // Pop all items one by one
        while (!s.empty()) {
            // Pop the top item and print it
            Node* current = s.top();
            std::cout << current->data << " ";
            s.pop();

            // Push right child first so that left child is processed first
            if (current->right != nullptr) {
                s.push(current->right);
            }
            // Push left child
            if (current->left != nullptr) {
                s.push(current->left);
            }
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

    std::cout << "Iterative Preorder Traversal (Root-Left-Right): " << std::endl;
    bst.preorderTraversal();

    return 0;
}
