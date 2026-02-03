#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to traverse DLL forward
void forwardTraversal(Node* head) {
    Node* temp = head;
    cout << "Forward Traversal: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse DLL backward
void backwardTraversal(Node* tail) {
    Node* temp = tail;
    cout << "Backward Traversal: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    // Creating DLL manually: 10 <-> 20 <-> 30
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    Node* tail = third;

    forwardTraversal(head);
    backwardTraversal(tail);

    return 0;
}
