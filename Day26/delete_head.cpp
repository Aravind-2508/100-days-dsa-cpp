#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }
};
node* array2ll(vector<int>arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1; i<arr.size(); i++){
        node * temp = new node (arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}
node* removeshead(node* head){
    if(head == NULL) return head;
    node* temp = head;
    head = head -> next;
    //free(temp);
    delete temp;
    return head;
}

int main(){
    vector<int>arr={1,2,3,4};
    node* head = array2ll(arr);
    head = removeshead(head);
    print(head);
}