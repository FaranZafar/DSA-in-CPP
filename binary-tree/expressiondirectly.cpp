#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Node structure for our expression tree
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

class DirectExpressionTree {
private:
    // Helper to define operator precedence
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Helper to pop an operator and two nodes, connect them, and push back
    void buildSubtree(std::stack<Node*>& nodes, std::stack<char>& ops) {
        char op = ops.top();
        ops.pop();

        Node* newNode = new Node(op);

        // Right child is popped first (LIFO order)
        if (!nodes.empty()) {
            newNode->right = nodes.top();
            nodes.pop();
        }
        if (!nodes.empty()) {
            newNode->left = nodes.top();
            nodes.pop();
        }

        nodes.push(newNode);
    }

public:
    Node* root;

    DirectExpressionTree() {
        root = nullptr;
    }

    // Direct Infix to Expression Tree Conversion
    void buildFromInfix(const std::string& infix) {
        std::stack<Node*> nodes;
        std::stack<char> ops;

        for (size_t i = 0; i < infix.length(); ++i) {
            char c = infix[i];

            // Skip spaces
            if (isspace(c)) continue;

            // Scenario 1: Operand -> create node and push to node stack
            if (isalnum(c)) {
                nodes.push(new Node(c));
            }
            // Scenario 2: Opening parenthesis -> push to operator stack
            else if (c == '(') {
                ops.push(c);
            }
            // Scenario 3: Closing parenthesis -> process everything up to '('
            else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    buildSubtree(nodes, ops);
                }
                if (!ops.empty()) ops.pop(); // Remove the '('
            }
            // Scenario 4: Operator
            else {
                // While top operator has higher/equal precedence, process it first
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    buildSubtree(nodes, ops);
                }
                ops.push(c);
            }
        }

        // Process any remaining operators left in the stack
        while (!ops.empty()) {
            buildSubtree(nodes, ops);
        }

        // The last remaining node is the root of the entire tree
        if (!nodes.empty()) {
            root = nodes.top();
        }
    }

    // Iterative Preorder Traversal to verify structure (Root -> Left -> Right)
    void printPreorder() {
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
    DirectExpressionTree tree;
    
    // Infix expression with mixed precedence and parentheses
    std::string infix = "a+(b*c)";
    
    std::cout << "Converting Infix Directly: " << infix << std::endl;
    tree.buildFromInfix(infix);

    // Tree Structure Layout:
    //       +
    //      / \
    //     a   *
    //        / \
    //       b   c

    std::cout << "Iterative Preorder Result: ";
    tree.printPreorder(); // Expected Output: + a * b c

    return 0;
}