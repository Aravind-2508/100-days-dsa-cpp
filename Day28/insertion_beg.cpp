#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert at the beginning
void insertAtBeginning(Node*& head, int data) {
    // Create a new node
    Node* newNode = new Node(data);
    
    // Point new node's next to current head
    newNode->next = head;
    
    // Update head to point to new node
    head = newNode;
    
    cout << "Inserted " << data << " at the beginning" << endl;
}

// Function to display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;  // Initialize empty list
    
    // Insert elements at the beginning
    insertAtBeginning(head, 10);
    display(head);
    
    insertAtBeginning(head, 20);
    display(head);
    
    insertAtBeginning(head, 30);
    display(head);
    
    insertAtBeginning(head, 40);
    display(head);
    
    return 0;
}