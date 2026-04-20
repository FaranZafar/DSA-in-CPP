#include<iostream>
#include<string>
using namespace std;

class node {
public:
    char data;
    node* prev;
    node(char val) {
        data = val;
        prev = NULL;
    }
};

class stacklist {
private:
    node* tail;
public:
    stacklist() { tail = NULL; }

    void push(char x) {
        node* newNode = new node(x);
        if (tail == NULL) {
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail = newNode;
    }

    void pop() {
        if (tail == NULL) return;
        node* temp = tail;
        tail = tail->prev;
        delete temp;
    }

    char top() {
        return (tail != NULL) ? tail->data : '\0';
    }

    bool isEmpty() {
        return tail == NULL;
    }

    // Helper to determine operator priority
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }

    string conversionpost(string infix) {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            // 1. If operand, add to result
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                postfix += c;
            }
            // 2. If '(', push to stack
            else if (c == '(') {
                push(c);
            }
            // 3. If ')', pop until '('
            else if (c == ')') {
                while (!isEmpty() && top() != '(') {
                    postfix += top();
                    pop();
                }
                pop(); // remove '('
            }
            // 4. If operator
            else {
                while (!isEmpty() && precedence(top()) >= precedence(c)) {
                    postfix += top();
                    pop();
                }
                push(c);
            }
        }

        // Pop remaining operators
        while (!isEmpty()) {
            postfix += top();
            pop();
        }
        return postfix;
    }
};

int main() {
    stacklist s;
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << s.conversionpost(exp) << endl;
    return 0;
}