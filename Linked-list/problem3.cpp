#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    // If the list is empty
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now pointing to the middle node
    return slow;
}

// Helper to print and test
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "List: ";
    printList(head);

    Node* middle = findMiddle(head);
    if (middle) {
        std::cout << "The middle element is: " << middle->data << std::endl;
    }

    return 0;
}