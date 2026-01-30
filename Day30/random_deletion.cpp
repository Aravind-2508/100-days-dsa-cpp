#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteRandom(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    int length = getLength(*head);
    int randomPos = rand() % length;
    
    if (randomPos == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }
    
    Node* temp = *head;
    for (int i = 0; i < randomPos - 1; i++) {
        temp = temp->next;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    srand(time(0));
    
    Node* head = nullptr;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    cout << "Original List: ";
    display(head);
    
    deleteRandom(&head);
    cout << "After random deletion: ";
    display(head);
    
    return 0;
}