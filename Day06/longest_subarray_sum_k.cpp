/*
Problem: Longest Subarray with Sum K
Approach:
1. Brute Force
2. Optimal using Prefix Sum + Hashing
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumMap;
    int sum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if (sum == k) {
            maxLen = i + 1;
        }
        
        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
            maxLen = max(maxLen, i - prefixSumMap[sum - k]);
        }
        
        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }
    
    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    
    int result = longestSubarrayWithSumK(arr, k);
    cout << "Length of longest subarray with sum " << k << ": " << result << endl;
    
    vector<int> arr2 = {-5, 8, -14, 2, 4, 12};
    k = -5;
    result = longestSubarrayWithSumK(arr2, k);
    cout << "Length of longest subarray with sum " << k << ": " << result << endl;
    
    return 0;
}