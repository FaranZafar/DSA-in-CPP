#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// 2a. Insertion 
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// 1. Traversals (Preorder, Inorder, Postorder) 
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) { // Also handles 2c and 6c (ascending order) 
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 2b. Searching a node 
Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// 6b. Find Minimum Value 
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// 6b. Find Maximum Value 
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

// 3. Counting Functions 
int countTotalNodes(Node* root) { // 3a [cite: 13]
    if (!root) return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int countLeafNodes(Node* root) { // 3b [cite: 14]
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeafNodes(Node* root) { // 3c [cite: 15]
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// 4a. Height of tree [cite: 17]
int getHeight(Node* root) {
    if (!root) return -1; // Edges count. Use 0 if counting nodes for height.
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// 4b. Depth of a given node [cite: 18]
int getDepth(Node* root, int val, int depth = 0) {
    if (!root) return -1;
    if (root->data == val) return depth;
    int leftDepth = getDepth(root->left, val, depth + 1);
    if (leftDepth != -1) return leftDepth;
    return getDepth(root->right, val, depth + 1);
}

// 5. Deletion in BST 
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: Leaf node or Case 2: One child [cite: 20, 21]
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children [cite: 22]
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 7. Menu-driven program 
int main() {
    Node* root = nullptr; // 6a. Create a BST [cite: 24]
    int choice, val;

    do {
        cout << "\n--- BST MENU ---"
             << "\n1. Insert Node"
             << "\n2. Delete Node"
             << "\n3. Search Node"
             << "\n4. Count Nodes (Total, Leaf, Non-Leaf)"
             << "\n5. Display Traversals (Pre, In, Post)"
             << "\n6. Find Min and Max"
             << "\n7. Height & Node Depth"
             << "\n8. Exit"
             << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                cout << "Inserted.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                if (search(root, val)) {
                    root = deleteNode(root, val);
                    cout << "Deleted.\n";
                } else cout << "Value not found.\n";
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val)) cout << "Found!\n";
                else cout << "Not found.\n";
                break;
            case 4:
                cout << "Total Nodes: " << countTotalNodes(root) << "\n";
                cout << "Leaf Nodes: " << countLeafNodes(root) << "\n";
                cout << "Non-Leaf Nodes: " << countNonLeafNodes(root) << "\n";
                break;
            case 5:
                cout << "Preorder: "; preorder(root); cout << "\n";
                cout << "Inorder (Ascending): "; inorder(root); cout << "\n";
                cout << "Postorder: "; postorder(root); cout << "\n";
                break;
            case 6: {
                Node* minN = findMin(root);
                Node* maxN = findMax(root);
                if (minN) cout << "Min value: " << minN->data << ", Max value: " << maxN->data << "\n";
                else cout << "Tree is empty.\n";
                break;
            }
            case 7:
                cout << "Height of tree: " << getHeight(root) << "\n";
                cout << "Enter node value to find its depth: ";
                cin >> val;
                cout << "Depth of node: " << getDepth(root, val) << "\n";
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}