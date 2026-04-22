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

    // Private helper: This does the actual heavy lifting
    node* reverseRecursiveHelper(node* curr) {
        // Base case: if list is empty or has only one node
        if (curr == NULL || curr->next == NULL) {
            return curr;
        }

        // Recursive step: reverse the rest of the list
        node* newHead = reverseRecursiveHelper(curr->next);

        // The "Magic" part:
        // Make the next node point back to the current node
        curr->next->next = curr;
        // Break the old forward link to avoid cycles
        curr->next = NULL;

        return newHead;
    }

public:
    singlelist() { head = tail = NULL; }

    void insertBack(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Public wrapper function
    void reverse() {
        if (head == NULL) return;
        
        // Before reversing, the current head will become the new tail
        tail = head; 
        
        // Update head to the node returned by recursion
        head = reverseRecursiveHelper(head);
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
    sl.insertBack(10);
    sl.insertBack(20);
    sl.insertBack(30);

    cout << "Original: ";
    sl.display();

    sl.reverse();

    cout << "Reversed: ";
    sl.display();

    return 0;
}