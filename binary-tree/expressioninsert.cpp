#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Node structure for the Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() {
        root = nullptr;
    }

    // Iterative operation to build (insert into) the Expression Tree from a Postfix string
    void buildFromPostfix(const std::string& postfix) {
        std::stack<Node*> s;

        // Traverse through all characters of the postfix expression
        for (char c : postfix) {
            // If the character is an operand (number/letter), create a leaf node and push to stack
            if (isalnum(c)) {
                Node* newNode = new Node(c);
                s.push(newNode);
            }
            // If the character is an operator
            else if (isOperator(c)) {
                Node* newNode = new Node(c);

                // Pop the top two nodes to become children of the operator node
                // CRITICAL: The first popped element is the RIGHT child due to stack LIFO order
                if (!s.empty()) {
                    newNode->right = s.top();
                    s.pop();
                }
                if (!s.empty()) {
                    newNode->left = s.top();
                    s.pop();
                }

                // Push the newly formed subtree back onto the stack
                s.push(newNode);
            }
        }

        // The final remaining node on the stack is the root of the complete expression tree
        if (!s.empty()) {
            root = s.top();
        }
    }

    // Iterative Preorder Traversal to verify the tree structure (Root -> Left -> Right)
    void iterativePreorder() {
        if (root == nullptr) return;

        std::stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            std::cout << current->data << " ";
            s.pop();

            if (current->right != nullptr) s.push(current->right);
            if (current->left != nullptr) s.push(current->left);
        }
        std::cout << std::endl;
    }
};

int main() {
    ExpressionTree et;
    
    // Mathematical expression in Postfix: "ab+c*" (Equivalent to: (a + b) * c)
    std::string postfix = "ab+c*";
    
    std::cout << "Building Expression Tree from Postfix: " << postfix << std::endl;
    et.buildFromPostfix(postfix);

    // Visualizing layout: 
    //       *
    //      / \
    //     +   c
    //    / \
    //   a   b

    std::cout << "Iterative Preorder Verification (Prefix form): ";
    et.iterativePreorder(); // Expected Output: * + a b c

    return 0;
}