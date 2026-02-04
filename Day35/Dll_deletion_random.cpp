#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next ;
    node* back;
    node(int data1, node* next1, node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
node* array2dll(vector<int> arr){
    node * head = new node(arr[0]);
    node * prev = head;
    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i],nullptr,prev);
        prev -> next = temp;
        prev = temp ;
    }
    return head;
}
void print(node* head){
    while(head != NULL){
        cout<<head -> data <<" ";
        head = head -> next;
    }
}
node* deleteHead(node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    node* prev = head;
    head = head -> next;
    head -> back = nullptr ;
    prev -> next = nullptr;
    delete prev;  // free(temp);
    return head;
}
node* deleteTail(node* head){
    node* tail = head;
    while(tail -> next -> next != NULL){
        tail = tail -> next;
    }
    tail ->next -> back = nullptr;
    tail ->next = nullptr;
    
    
    return head;
}
node* deleteK(node* head, int k){
    if(head == NULL || head -> next == NULL) return NULL;
    node* temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    node* prev = temp -> back;
    node* front = temp -> next;
    if(prev==NULL && front == NULL){
        delete head;
        return NULL;
    }
    if(prev == NULL){
        return deleteHead(head);
        
    }
    if(front ==NULL){
        return deleteTail(head);
    }
    prev ->next = front;
    front -> back = prev;
    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp ;
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    node* head = array2dll(arr);
    cout<<head->data<<endl;
    print(head);
    cout<<endl;
    head = deleteHead(head);
    print(head);
    cout<<endl;
    head = deleteTail(head);
    print(head);
    cout<<endl;
    head = deleteK(head,2);
    print(head);
}