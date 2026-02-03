#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
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

// Function to convert array to Doubly Linked List
Node* arrayToDLL(int arr[], int n) {
    if (n == 0) return NULL;

    // Create head node
    Node* head = new Node(arr[0]);
    Node* current = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Function to print Doubly Linked List (forward)
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToDLL(arr, n);

    cout << "Doubly Linked List: ";
    printDLL(head);

    return 0;
}
