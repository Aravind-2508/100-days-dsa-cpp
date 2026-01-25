/*
Problem: Convert array to linked list and return head
Approach: Create nodes iteratively and link them
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    
    int data ;
    Node* next;
    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node (int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertarr2ll(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int> arr= {1,2,3,4};
    //node y = node(arr[0],nullptr);
    Node* head = convertarr2ll(arr);
    Node* temp = head;
    
    cout<<head->data;
    
}