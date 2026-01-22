/*
Problem: Introduction to Linked List
Approach: Create nodes and traverse the list
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
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

// Function to insert at end
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

// Iterative approach to count nodes
int countNodesIterative(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Recursive approach to count nodes
int countNodesRecursive(Node* head) {
    // Base case
    if (head == nullptr) {
        return 0;
    }
    
    // Recursive case
    return 1 + countNodesRecursive(head->next);
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

int main() {
    Node* head = nullptr;
    
    // Create a linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    
    cout << "Linked List: ";
    display(head);
    
    // Count nodes using iterative method
    int count1 = countNodesIterative(head);
    cout << "Number of nodes (Iterative): " << count1 << endl;
    
    // Count nodes using recursive method
    int count2 = countNodesRecursive(head);
    cout << "Number of nodes (Recursive): " << count2 << endl;
    
    // Test with empty list
    Node* emptyList = nullptr;
    cout << "\nEmpty list node count: " << countNodesIterative(emptyList) << endl;
    
    return 0;
}