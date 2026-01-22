/*
Problem: Introduction to Linked List
Approach: Create nodes and traverse the list
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    
    if (head == nullptr) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete a node with given value
Node* deleteNode(Node* head, int key) {
    if (head == nullptr) return nullptr;
    
    // If head needs to be deleted
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    // Search for the node to be deleted
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }
    
    // If node found, delete it
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    
    return head;
}

int main() {
    Node* head = nullptr;
    
    // Insert elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    
    cout << "Linked List: ";
    display(head);
    
    // Delete a node
    head = deleteNode(head, 20);
    cout << "After deleting 20: ";
    display(head);
    
    return 0;
}