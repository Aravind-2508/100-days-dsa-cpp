/*
Problem: Count digits in a number
Approach: Repeated division by 10
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits?stdc++.h>
using namespace std;

int countDigits(int n) {
    // Handle edge case for 0
    if (n == 0) return 1;
    
    // Handle negative numbers
    if (n < 0) n = -n;
    
    int count = 0;
    
    // Count digits by repeated division
    while (n > 0) {
        count++;
        n /= 10;
    }
    
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    int digits = countDigits(num);
    cout << "Number of digits in " << num << " is: " << digits << endl;
    
    return 0;
}