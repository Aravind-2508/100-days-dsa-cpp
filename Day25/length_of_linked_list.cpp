/*
Problem: Find the length of a linked list
Approach: Traverse the list and count nodes
Time Complexity: O(n)
Space Complexity: O(1)
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
    vector<int> arr= {21,2,3,4};
    //node y = node(arr[0],nullptr);
    Node* head = convertarr2ll(arr);
    Node* temp = head;
    int c;
    while(temp){
        c++;
        temp = temp -> next;
    }
    cout<<c;
}