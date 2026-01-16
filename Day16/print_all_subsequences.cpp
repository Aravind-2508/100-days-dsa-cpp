/*
Problem: Printing All Subsequences
Approach: Recursion (Include / Exclude)
Time Complexity: O(2^n)
Space Complexity: O(n) (recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;
void print_all_subsequences(int i, vector<int> &v, int arr[], int n)
{
    //base case
    if(i >= n)
    {
        for(auto k: v) cout<<k<<" ";
        cout<<endl;
        return;
    }
    //pick
    v.emplace_back(arr[i]);
    print_all_subsequences(i+1, v, arr, n);

    // Not pick
    v.pop_back();
    print_all_subsequences(i+1,v, arr, n);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int>v;
    print_all_subsequences(0,v,arr,n);



    return 0;
}