/*
Problem: Count occurrences of a number in a sorted array
Approach: Binary Search using first and last occurrence
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int k) {
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(arr[mid] == k){
                ans = mid ;
                high = mid -1;
            }
            else if(arr[mid] > k) high = mid -1;
            else low = mid + 1;
        }
        return ans;
    }
int lastOccurrence(int arr[], int n, int k) {
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == k){
                ans = mid ;
                low = mid +1;
            }
            else if(arr[mid] > k) high = mid-1;
            else low = mid + 1;
        }
        return ans;
        
    }
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int i = firstOccurrence(arr,n,k);
    if(i == -1) cout<<0;
    else{
        int j = lastOccurrence(arr,n,k);
        cout<<j-i+1;
    }
    return 0;
}