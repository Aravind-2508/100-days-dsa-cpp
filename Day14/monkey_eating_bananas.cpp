/*
Problem: Monkey Eating Bananas
Approach: Binary Search on Answer Space
Time Complexity: O(n log m)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int time_to_eat(int arr[], int n, int mid)
{
    long long total_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_time += ceil((double)arr[i] / (double)mid);
    }
    return total_time;
}

int minimum_bananas(int arr[], int n, int h)
{
    int low = 1;
    int high = *max_element(arr, arr + n);
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (time_to_eat(arr, n, mid) <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, h;
    cin >> n >> h;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimum_bananas(arr, n, h);
    return 0;
}