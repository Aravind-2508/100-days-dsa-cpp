#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Function to delete the first occurrence of 'key'
    void deleteByValue(int key) {
        // 1. If list is empty
        if (head == nullptr) return;

        // 2. If the head node itself needs to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp; // Free memory
            return;
        }

        // 3. Search for the key while keeping track of the previous node
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        // 4. Key not found in the list
        if (current == nullptr) return;

        // 5. Unlink the node and free memory
        prev->next = current->next;
        delete current; 
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};