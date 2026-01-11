/*
Problem: Find the minimum in a rotated sorted array
Approach: Modified Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int minimun_element(int arr[], int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[low] <= arr[mid])
        {
            if(arr[low] < ans) ans = arr[low];
            low = mid+1;
        }
        else if (arr[mid] <= arr[high])
        {
            if(arr[mid] <= arr[high]) ans = arr[mid];
            high = mid -1;
        }
    }
    return ans;
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minimun_element(arr,n);

    return 0;
}