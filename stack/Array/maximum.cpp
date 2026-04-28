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
    
    void maxmum(){
        int max=arr[0];
        for (int  i = 0; i <=top; i++)
        {
            if (arr[i]>max)
            {
                max=arr[i];
            }
            
        }
        cout<<"Maximum value is :"<<max<<endl;
        
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
        cout << "Stack (Top → Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " -> ";
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
    sk.peek();
    sk.display();
    sk.maxmum();
    return 0;
}