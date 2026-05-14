#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Task 2a: Insertion [cite: 9]
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Task 1 & 2c: Traversals [cite: 7, 11]
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Task 2b: Searching [cite: 10]
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}

// Task 6b: Min/Max [cite: 25]
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

Node* maxValueNode(Node* node) {
    Node* current = node;
    while (current && current->right != NULL) current = current->right;
    return current;
}

// Task 3: Counting Nodes [cite: 13, 14, 15]
int countTotal(Node* root) {
    if (!root) return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Task 4: Height & Depth [cite: 17, 18]
int getHeight(Node* root) {
    if (!root) return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Task 5: Deletion (Leaf, 1 child, 2 children) [cite: 19, 20, 21, 22]
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;

    do {
        cout << "\n--- BST MENU ---\n1. Insert\n2. Delete\n3. Search\n4. Count Nodes\n5. Height\n6. Traversals\n7. Min/Max\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Value: "; cin >> val; root = insert(root, val); break;
            case 2: cout << "Value to delete: "; cin >> val; root = deleteNode(root, val); break;
            case 3: cout << "Search value: "; cin >> val; cout << (search(root, val) ? "Found" : "Not Found") << endl; break;
            case 4: 
                cout << "Total: " << countTotal(root) << endl;
                cout << "Leaf: " << countLeaf(root) << endl;
                cout << "Non-Leaf: " << countTotal(root) - countLeaf(root) << endl; 
                break;
            case 5: cout << "Height: " << getHeight(root) << endl; break;
            case 6: 
                cout << "Inorder (Ascending): "; inorder(root); // Task 6c [cite: 26]
                cout << "\nPreorder: "; preorder(root);
                cout << "\nPostorder: "; postorder(root); cout << endl;
                break;
            case 7:
                if (root) {
                    cout << "Min: " << minValueNode(root)->data << endl;
                    cout << "Max: " << maxValueNode(root)->data << endl;
                }
                break;
        }
    } while (choice != 0);
    return 0;
}