/*
Problem: Find Peak Element
Approach: Binary Search using neighbor comparison
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
// Brute force
int brute_peak(int arr[], int n)
{
    if(n==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-1]) return n-1;
    for(int i=1; i<n-1; i++)
    {
        if ( (arr[i]>arr[i-1]) && ( arr[i]>arr[i+1] ) ) return i;
    }
}



//optimal
int peak_element(int arr[], int n)
{
    if(n==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if( (arr[mid] > arr[mid-1] ) && ( arr[mid] > arr[mid +1] ) ) return mid;
        if(arr[mid] > arr[mid-1]) low = mid+1;
        else high = mid -1; 
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    //for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<peak_element(arr,n);
    cout<<brute_peak(arr,n);


    return 0;
}