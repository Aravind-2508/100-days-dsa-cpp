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
    
    // 1. Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }
    
    // 2. Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If list is empty
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " at end (first node)" << endl;
            return;
        }
        
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        cout << "Inserted " << value << " at end" << endl;
    }
    
    // 3. Insert at a specific position (1-indexed)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        
        // Insert at beginning
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at position " << position << endl;
            return;
        }
        
        // Traverse to position-1
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        // If position is out of bounds
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }
        
        // Insert the node
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // 4. Insert after a specific value
    void insertAfterValue(int value, int afterValue) {
        Node* temp = head;
        
        // Search for the node with afterValue
        while (temp != nullptr && temp->data != afterValue) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Value " << afterValue << " not found in list!" << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << afterValue << endl;
    }
    
    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    
    cout << "=== Linked List Insertion Operations ===" << endl << endl;
    
    // Insert at end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    cout << endl;
    
    // Insert at beginning
    list.insertAtBeginning(5);
    list.display();
    cout << endl;
    
    // Insert at specific position
    list.insertAtPosition(15, 3);
    list.display();
    cout << endl;
    
    // Insert after a value
    list.insertAfterValue(25, 20);
    list.display();
    cout << endl;
    
    // Edge cases
    list.insertAtPosition(1, 1);  // Insert at beginning using position
    list.display();
    cout << endl;
    
    list.insertAtPosition(100, 10);  // Position out of bounds
    list.display();
    
    return 0;
}
```

**Key Points About Pointer Updates:**

1. **Insert at Beginning**: Update `newNode->next` first, then update `head`
2. **Insert at End**: Traverse to last node, then update its `next` pointer
3. **Insert at Position**: Navigate to (position-1), then update pointers in correct order
4. **Critical Order**: Always set `newNode->next` before updating the previous node's `next`

**Output:**
```
=== Linked List Insertion Operations ===

Inserted 10 at end (first node)
Inserted 20 at end
Inserted 30 at end
List: 10 -> 20 -> 30 -> NULL

Inserted 5 at beginning
List: 5 -> 10 -> 20 -> 30 -> NULL

Inserted 15 at position 3
List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

Inserted 25 after 20
List: 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> NULL

Inserted 1 at position 1
List: 1 -> 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> NULL

Position out of bounds!
List: 1 -> 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> NULL