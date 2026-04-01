#include <iostream>
using namespace std;

#define MAX 100 // Defining the maximum size of the stack

class Stack {
    int arr[MAX];
    int topIndex;

public:
    Stack() { 
        topIndex = -1; // Stack is empty initially
    }

    // Push: Adds an element to the top
    void push(int val) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        arr[++topIndex] = val;
        cout << val << " pushed into stack." << endl;
    }

    // Pop: Removes the top element
    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        topIndex--;
    }

    // Top: Returns the top element without removing it
    void getTop() {
        if (topIndex < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
    }

    bool isEmpty() {
        return (topIndex < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.getTop();
    s.pop();
    s.getTop();

    return 0;
}