#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class singlelist {
private:
    node* head;
    node* tail;

public:
    singlelist() {
        head = tail = NULL;
    }

    // Fixed logic to properly append to the end
    void insertBack(int val) {
        node* newNode = new node(val);
        if (head == NULL) { // Use == for comparison
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Value " << val << " entered" << endl;
    }

    // Reverses the list and updates the class head/tail pointers
    void reverseIterative() {
        node* prev = NULL;
        node* curr = head;
        node* next = NULL;

        // The tail after reversing will be the current head
        tail = head;

        while (curr != NULL) {
            next = curr->next;  // Store next
            curr->next = prev;  // Reverse link
            prev = curr;        // Move prev forward
            curr = next;        // Move curr forward
        }
        head = prev; // Update head to the new front
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    singlelist sl;
    sl.insertBack(2);
    sl.insertBack(3);
    sl.insertBack(4);
    sl.insertBack(5);

    cout << "Original list: ";
    sl.display();

    sl.reverseIterative();

    cout << "Reversed list: ";
    sl.display();

    return 0;
}