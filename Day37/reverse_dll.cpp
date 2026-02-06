#include <bits/stdc++.h>
using namespace std;
struct node{
    int data ;
    node* next ;
    node* back;
    node(int data1, node* next1, node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1){
        data = data1;
    }
};
void print(node* head){
    while(head != NULL){
        cout<<head -> data <<" ";
        head = head -> next ;
    }
}
node* array2dll(vector<int> arr){
    node* head = new node(arr[0]);
    node * prev = head;
    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i],nullptr, prev);
         prev -> next = temp;
         prev = temp ;
        
    }
    return head;
}
node* reversedll(node* head){
    if(head == NULL || head -> next == NULL) return head ;
    node * last = NULL;
    node* temp = head;
    while(temp != NULL){
        last = temp -> back;
        temp -> back = temp -> next;
        temp -> next = last ;
        temp = temp -> back;
    }
    return last -> back;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    node* head = new node(arr[0]);
    cout<<head -> data <<endl;
    head = array2dll(arr);
    print(head);
    cout<<endl;
    head = reversedll(head);
    print(head);
    cout<<endl;
}