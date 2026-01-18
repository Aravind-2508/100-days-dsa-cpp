/*
Problem: Print only one subsequence
Approach: Recursion with early stopping
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
bool print_sub(int i, vector<int>&v, int sum, int n, int arr[], int k)
{
    //Base Case
    if(i>=n)
    {
        if(sum == k)
        {
            for(auto m: v) cout<<m<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    //Pick Case
    v.push_back(arr[i]);
    sum+=arr[i];
    if( print_sub(i+1,v,sum,n,arr,k) == true) return true;
    
    //Not Pick Case
    v.pop_back();
    sum-=arr[i];
    if( print_sub(i+1,v,sum,n,arr,k) == true ) return true;
    return false;
}
int main()
{
    int n,k;
    cout<<"Enter size of the array and k : \n";
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int sum =0;
    vector<int>v;
    print_sub(0,v,sum,n,arr,k);
    
    
    
    return 0;
}