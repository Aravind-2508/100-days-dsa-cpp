#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    
    // Helper function to insert at end (for testing)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // 1. Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning" << endl;
        delete temp;
    }
    
    // 2. Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        // If only one node exists
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        // Traverse to second last node
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        Node* lastNode = temp->next;
        cout << "Deleted " << lastNode->data << " from end" << endl;
        temp->next = nullptr;
        delete lastNode;
    }
    
    // 3. Delete from a specific position (1-indexed)
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        // Delete first node
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted " << temp->data << " from position " << position << endl;
            delete temp;
            return;
        }
        
        // Traverse to (position-1)th node
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        // Check if position is valid
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        
        // Delete the node at position
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << position << endl;
        delete nodeToDelete;
    }
    
    // 4. Delete node with a specific value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        // If head node contains the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << value << endl;
            delete temp;
            return;
        }
        
        // Search for the node with the value
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        // If value not found
        if (temp->next == nullptr) {
            cout << "Value " << value << " not found in list!" << endl;
            return;
        }
        
        // Delete the node
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << value << endl;
        delete nodeToDelete;
    }
    
    // 5. Delete all nodes with a specific value
    void deleteAllByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        
        int count = 0;
        
        // Delete from head if it contains the value
        while (head != nullptr && head->data == value) {
            Node* temp = head;