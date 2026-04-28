#include<iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top = -1;

public:
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack is full\n";
        } else {
            arr[++top] = x;
            cout << "Value Entered Successfully\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Deleted value: " << arr[top--] << endl;
        }
    }

    void peek() {   // renamed from Top()
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top is: " << arr[top] << endl;
        }
    }
   void display() {
    if (top == -1) {
        cout << "Stack is Underflow\n";
    } else {
        cout << "Stack (Bottom → top):\n";
        for (int i = 0; i <= top; i++) {
            cout << arr[i]; cout << " -> ";
        }
        cout << endl;
    }
}

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack sk;

    sk.push(1);
    sk.push(2);
    sk.push(3);
    sk.push(4);
    sk.display();
    sk.peek();
    sk.pop();
    sk.peek();
    sk.display();
    return 0;
}