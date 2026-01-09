/*
Problem: Find first and last occurrence in a sorted array
Approach: Modified Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
void brute_first_last_occ(int arr[], int n, int k){
    int first_occ =-1;
    int last_occ = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == k){
            if(first_occ == -1) {
            first_occ = i;
            }
            else last_occ = i;
        }
    }
    cout<<first_occ << " " << last_occ;
}
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
    cout<<firstOccurrence(arr,n,k)<<" ";
    cout<<lastOccurrence(arr,n,k)<<endl;
    brute_first_last_occ(arr,n,k);
    return 0;
}
