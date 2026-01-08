/*
Problem: Ceil and Floor in a Sorted Array
Approach: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int ceilInSortedArray(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int ceilIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ceilIndex = mid; // Potential ceil found
            right = mid - 1; // Move left to find a smaller ceil
        } else {
            left = mid + 1; // Move right
        }
    }

    return ceilIndex; // Ceil index or -1 if not found
}
int floorInSortedArray(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int floorIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            floorIndex = mid; // Potential floor found
            left = mid + 1; // Move right to find a larger floor
        } else {
            right = mid - 1; // Move left
        }
    }

    return floorIndex; // Floor index or -1 if not found
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ceilIndex = ceilInSortedArray(arr, k);
    int floorIndex = floorInSortedArray(arr, k);
    cout<<"Ceil index of "<<k<<" is: "<<ceilIndex<<endl;
    cout<<"Floor index of "<<k<<" is: "<<floorIndex<<endl;
}