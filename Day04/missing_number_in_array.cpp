/*
Problem: Find the missing number in an array
Approach: Sum formula / XOR
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter size of the array : \n";
    cin>>n;
    int arr[n];
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    int s1 = (n * (n+1)) / 2; 
    int s2 =0;
    for(int i=0; i<n-1; i++){
        s2 += arr[i];
    }
    cout<<"missing number is : " << s1-s2;
    
    
    return 0;
}