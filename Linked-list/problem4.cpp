#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} // Constructor for convenience
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head=NULL;
    }

    // Public wrapper to reverse the list
    void reverse() {
        head = reverseIterative(head);
    }

    Node* reverseIterative(Node* headNode) {
        Node* prev = nullptr;
        Node* curr = headNode;
        Node* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next; 
            curr->next = prev;     
            prev = curr;           
            curr = nextNode;       
        }
        return prev; 
    }

    // Helper to add data
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Helper to see the results
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.display();
    ll.reverse();
    ll.display();

}