/*
Problem: Count subsequences using count variable
Approach: Recursion with parameter tracking
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int print_sub(int &count, int i, int sum, int n, int arr[], int k){
    //Base Case
    if(i>=n){
        if(sum == k ){
            count++;
        }
        return count;
    }
    //Pick Case
   // v.push_back(arr[i]);
    sum+=arr[i];
    print_sub(count, i+1, sum, n, arr, k);
    
    //Not Pick Case
   // v.pop_back();
    sum-=arr[i];
    print_sub(count, i+1, sum, n, arr, k);
    return count;
    
}

int main(){
    
    int n,k;
    cout<<"Enter n and k \n";
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    //vector<int> v;
    int count=0;
    int sum=0;
    cout<<print_sub(count,0,sum,n,arr,k);
    
    return 0;
}