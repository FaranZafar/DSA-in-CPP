#include <iostream>

// Definition of the BST Node
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
private:
    Node* root;

    // Helper function for Insertion (Recursive)
    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        // Duplicates are not allowed in this basic BST implementation
        return node;
    }

    // Helper function for Search (Recursive)
    bool searchHelper(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;

        if (val < node->data) {
            return searchHelper(node->left, val);
        } else {
            return searchHelper(node->right, val);
        }
    }

    // Helper function to find Min (Iterative - leftmost node)
    Node* findMinHelper(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to find Max (Iterative - rightmost node)
    Node* findMaxHelper(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Helper function for Deletion (Recursive)
    Node* deleteHelper(Node* node, int val) {
        if (node == nullptr) return nullptr;

        // Step 1: Navigate to the node to be deleted
        if (val < node->data) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->data) {
            node->right = deleteHelper(node->right, val);
        } 
        // Step 2: Found the node! Handle the 3 deletion cases
        else {
            // Case 1: Leaf node (No children)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: Node with only one child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node with two children
            else {
                // Find the Inorder Successor (smallest in the right subtree)
                Node* temp = findMinHelper(node->right);
                // Copy the successor's data to this node
                node->data = temp->data;
                // Delete the successor node
                node->right = deleteHelper(node->right, temp->data);
            }
        }
        return node;
    }

    // Helper function for Inorder Traversal (Left, Root, Right)
    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr;
    }

    // 1. Insertion
    void insert(int val) {
        root = insertHelper(root, val);
    }

    // 2. Search
    bool search(int val) {
        return searchHelper(root, val);
    }

    // 3. Find Min
    int findMin() {
        Node* minNode = findMinHelper(root);
        if (minNode != nullptr) return minNode->data;
        throw std::runtime_error("Tree is empty!");
    }

    // 4. Find Max
    int findMax() {
        Node* maxNode = findMaxHelper(root);
        if (maxNode != nullptr) return maxNode->data;
        throw std::runtime_error("Tree is empty!");
    }

    // 5. Deletion
    void remove(int val) {
        root = deleteHelper(root, val);
    }

    // 6. Traversal (Inorder prints BST elements in sorted order)
    void displayInorder() {
        inorderHelper(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    std::cout << "--- Inserting Elements: 50, 30, 20, 40, 70, 60, 80 ---\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal (Sorted): ";
    bst.displayInorder();

    std::cout << "\n--- Search, Min & Max ---\n";
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << "\n";
    std::cout << "Minimum value: " << bst.findMin() << "\n";
    std::cout << "Maximum value: " << bst.findMax() << "\n";

    std::cout << "\n--- Deletion Operations ---\n";
    
    std::cout << "Deleting 20 (Leaf Node)...\n";
    bst.remove(20);
    std::cout << "Inorder Traversal: ";
    bst.displayInorder();

    std::cout << "Deleting 30 (Node with single child 40)...\n";
    bst.remove(30);
    std::cout << "Inorder Traversal: ";
    bst.displayInorder();

    std::cout << "Deleting 50 (Root Node with two children)...\n";
    bst.remove(50);
    std::cout << "Inorder Traversal: ";
    bst.displayInorder();

    return 0;
}