/*
Problem: Count the number of subsequences
Approach: Recursion using return values
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int print_sub(int i, int sum, int n, int arr[], int k)
{
    //Base Case
    if(i>=n)
    {
        if(sum == k)
        {
            
            return 1;
        }
        return 0;
    }
    //Pick Case
    
    sum+=arr[i];
    int left = print_sub(i+1,sum,n,arr,k) ;
    
    //Not Pick Case
    
    sum-=arr[i];
    int right = print_sub(i+1,sum,n,arr,k);
    return left + right;
}
int main()
{
    int n,k;
    cout<<"Enter size of the array and k : \n";
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int sum =0;
    cout<<print_sub(0,sum,n,arr,k);
    
    
    
    return 0;
}