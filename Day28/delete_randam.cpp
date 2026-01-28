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
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << data << " at the beginning" << endl;
}

// Function to delete at a random/specific position
void deleteAtPosition(Node*& head, int position) {
    // If list is empty
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    // If deleting the first node (position 0 or 1)
    if (position == 0 || position == 1) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with data: " << temp->data << endl;
        delete temp;
        return;
    }
    
    // Traverse to the node before the position to delete
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    // If position is out of bounds
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    
    // Delete the node at the position
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted node with data: " << nodeToDelete->data << endl;
    delete nodeToDelete;
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

// Main function to demonstrate
int main() {
    Node* head = nullptr;
    
    // Insertion at beginning
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 40);
    display(head);
    
    // Delete at position 2 (0-indexed or 1-indexed based on your preference)
    cout << "\nDeleting at position 2:" << endl;
    deleteAtPosition(head, 2);
    display(head);
    
    // Delete at position 1 (first node)
    cout << "\nDeleting at position 1:" << endl;
    deleteAtPosition(head, 1);
    display(head);
    
    return 0;
}