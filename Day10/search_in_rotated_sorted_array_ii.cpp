/*
Problem: Search in Rotated Sorted Array II
Approach: Modified Binary Search (handling duplicates)
Time Complexity: O(log n) average, O(n) worst-case
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int rotated_sorted_array_1(int arr[], int n, int k)
{
    int low =0;
    int high = n-1;
    while(low <= high)
    {
        int mid= (low+high) / 2;
        if(arr[mid] == k) return mid;
        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= k && k <= arr[mid])
                high = mid -1;
            else low = mid + 1;
        }
        else 
        {
            if(arr[mid] <= k && k<= arr[high])
            
                low = mid + 1;
            else high = mid -1;
        }
    }
        return -1;
}

int main(){

    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<rotated_sorted_array_1(arr,n,k);


    return 0;
}