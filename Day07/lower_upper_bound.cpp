/*
Problem: Lower Bound and Upper Bound
Approach: Modified Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1; // Move right
        } else {
            right = mid; // Move left
        }
    }

    return left; // Lower bound index
}
int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            left = mid + 1; // Move right
        } else {
            right = mid; // Move left
        }
    }

    return left; // Upper bound index
}
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int lower = lowerBound(arr, target);
    int upper = upperBound(arr, target);

    cout << "Lower Bound of " << target << " is at index: " << lower << endl;
    cout << "Upper Bound of " << target << " is at index: " << upper << endl;

    return 0;
}