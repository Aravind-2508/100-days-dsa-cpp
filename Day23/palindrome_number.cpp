/*
Problem: Check if a number is Palindrome
Approach: Reverse digits and compare
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n) {
    // Negative numbers are not palindromes
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    // Reverse the number
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    // Compare original with reversed
    return original == reversed;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (isPalindrome(num)) {
        cout << num << " is a palindrome" << endl;
    } else {
        cout << num << " is not a palindrome" << endl;
    }
    
    return 0;
}