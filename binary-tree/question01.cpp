#include <iostream>
#include <vector>

using namespace std;

// Definition of the Binary Tree Node
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

// Function to build the tree from preorder vector
// Use -1 to represent a NULL node
Node* buildTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return nullptr;
    }

    // Create the root with current index data
    Node* root = new Node(nodes[index++]);

    // Recursively build left and right subtrees
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);

    return root;
}

// Helper function to verify the tree (Preorder Print)
void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Example Preorder Sequence: 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1
    // -1 represents 'NULL'
    vector<int> nodes = {1, 2, 4, 3,-1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node* root = buildTree(nodes, index);

    cout << "Preorder traversal of built tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}