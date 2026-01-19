/*
Problem: Print one subsequence (count-based approach)
Approach: Recursion using a count variable
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
void print_sub(int &count, int i, vector<int>&v, int sum, int n, int arr[], int k){
    //Base Case
    if(i>=n){
        if(sum == k && count == 0){
            for(auto m : v) cout<<m<<" ";
            cout<<endl;
            count++;
        }
        return;
    }
    //Pick Case
    v.push_back(arr[i]);
    sum+=arr[i];
    print_sub(count, i+1, v, sum, n, arr, k);
    
    //Not Pick Case
    v.pop_back();
    sum-=arr[i];
    print_sub(count, i+1, v, sum, n, arr, k);
    
}

int main(){
    
    int n,k;
    cout<<"Enter n and k \n";
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> v;
    int count=0;
    int sum=0;
    print_sub(count,0,v,sum,n,arr,k);
    
    return 0;
}