#include<iostream>
using namespace std;
 
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

};
class Queuelinked {
private:
    node* front;
    node* rear;

public:
    Queuelinked() {
        front = rear = NULL;
    }

    void Enqueue(int val) {
        node* newNode = new node(val);
        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Value entered successfully." << endl;
    }

    void Dequeue() {
        if (front == NULL) {
            cout << "The Queue is empty.." << endl;
            return;
        }
        node* temp = front;
        front = front->next;
        
        // If the queue becomes empty, rear must also be NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        cout << "Value removed successfully." << endl;
    }

    void peek() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Peek Value is: " << front->data << endl;
        }
    }

    void FindMax() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        node* temp = front;
        int maxVal = front->data;
        
        while (temp != NULL) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }
        cout << "Maximum Value is: " << maxVal << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.." << endl;
            return;
        }
        node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int choice;
    Queuelinked ql;
    bool exitProgram = false;

    do {
        cout << "\n--- Queue Operations Menu ---" << endl;
        cout << "1. Create/Add to Queue (Enqueue)" << endl;
        cout << "2. Remove Front Element (Dequeue)" << endl;
        cout << "3. Display Values" << endl;
        cout << "4. Find Maximum" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char cont;
                do {
                    int val;
                    cout << "Enter Value: ";
                    cin >> val;
                    ql.Enqueue(val);
                    cout << "Add another? (y/n): ";
                    cin >> cont;
                } while (cont == 'y' || cont == 'Y');
                break;
            }
            case 2:
                ql.Dequeue(); // Logic to remove front
                break;
            case 3:
                ql.display();
                break;
            case 4:
                ql.FindMax();
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (!exitProgram);

    return 0;
}