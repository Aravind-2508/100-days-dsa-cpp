#include <iostream>
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

    // 1. Insert at the Front (Beginning)
    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at the End (Tail)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
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

    // 3. Insert After a Specific Value
    void insertAfterValue(int target, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) return; // Target not found

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
};