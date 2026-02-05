#include <bits/stdc++.h>
using namespace std;
struct node{
    int data ;
    node* next;
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
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i=1; i<arr.size(); i++){
        node * temp = new node(arr[i],nullptr,prev);
        prev -> next = temp ;
        prev = temp;
    }
    return head;
}
void print(node * head){
    while(head != NULL){
        cout<<head -> data <<" ";
        head = head -> next;
    }
}
node* insertBeforeHead(node * head, int val){
    if(head == NULL ){
        node* newhead = new node(val);
        return newhead;
    }
    node * newhead = new node(val , head, nullptr);
    head -> back = newhead;
    return newhead;
}
node* insertBeforeTail(node* head, int val){
    if(head == NULL){
        node* newhead = new node(val);
        return newhead;
    }
    node* temp = head;
    while(temp -> next!= NULL){
        temp = temp -> next;
    }
    node* prev = temp ->back;
    node* newnode = new node(val,temp,prev);
    prev ->next = newnode;
    temp -> back = newnode;
    return head;
}
node* insertBeforeKthElement(node* head,int k , int val){
    if(head == NULL){
        node* newhead = new node(val);
        return newhead;
    }
    if(head -> next == NULL){
        return insertBeforeHead(head,val);
        
    }
    node* temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    node* prev = temp -> back;
    node* newnode = new node(val,temp,prev);
    prev ->next = newnode;
    temp ->back = newnode;
    return head;
    
}

int main(){
    vector <int> arr= {1,2,3,4,6};
    node* head = array2dll(arr);
    cout<<head->data <<endl;
    print(head);
    cout<<endl;
    head = insertBeforeHead(head,0); //before head
    print(head);
    cout<<endl;
    head = insertBeforeTail(head,5); //befor tail
    print(head);
    cout<<endl;
    head = insertBeforeKthElement(head,4,25); //position
    print(head);
    cout<<endl;
}









