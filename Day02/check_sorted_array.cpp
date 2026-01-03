/*
Problem: Check if the array is sorted
Approach: Linear traversal
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool isSorted = true;
    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i]){
            isSorted = false;
            break;
        }

    }
    if(isSorted){
        cout<<"Sorted" <<endl;
    }
    else{
        cout<<"Not Sorted" <<endl;
    }
}