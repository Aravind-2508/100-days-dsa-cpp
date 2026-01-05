/*
Problem: Find the number that appears once (others appear twice)
Approaches:
1. Brute Force
2. Better (Hashing)
3. Optimal (XOR)
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int OnceAppear(int arr[], int n){
    int xor1=0;
    for(int i=0; i<n; i++){
        xor1 ^= arr[i];
    }
    return xor1;
    
}
int main(){
    int n;
    cout<<"Enter the array size "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<OnceAppear(arr,n);
    
    return 0;
    
}