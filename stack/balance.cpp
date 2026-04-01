#include <iostream>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* next;
};

// Stack class using Linked List
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(char x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    // Pop operation
    char pop() {
        if (top == NULL) {
            return '\0';
        }
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    // Check if empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Function to check matching brackets
bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// Main function to check balance
bool isBalanced(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty())
                return false;

            char top = s.pop();
            if (!isMatching(top, ch))
                return false;
        }
    }

    return s.isEmpty();
}

// Driver code
int main() {
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced Expression";
    else
        cout << "Not Balanced";

    return 0;
}