/*
Problem: Search Insert Position
Approach: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Move right
        } else {
            right = mid - 1; // Move left
        }
    }

    return left; // Insert position
}
int main() {
    int n,k;
    cin>>n,k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int position = searchInsert(arr, k);
    cout << "The target " << k << " should be at index: " << position << endl;
    return 0;
}