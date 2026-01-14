/*
Problem: Finding the Minimum Positive Divisor
Approach: Binary Search on Answer Space
Time Complexity: O(n log m)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
long long sum_division(int arr[], int n, int x){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += ceil( (double)arr[i] / (double) x);
    }
    return sum;
}
int minimum_positive_divisor (int arr[], int n, int limit){
    int max_element = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max_element){
            max_element = arr[i];
        }
    }
    int low = 1, high = max_element;
    int ans = max_element;
    while(low <= high){
        int mid = (low + high) / 2;
        if(sum_division(arr, n, mid) <= limit){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
  int n;
  int x;
  int arr[n];
  cin >> n >> x;
  for(int i = 0; i < n;i++){
      cin >> arr[i];
  }
  cout << minimum_positive_divisor(arr,n,x);
  return 0;
}