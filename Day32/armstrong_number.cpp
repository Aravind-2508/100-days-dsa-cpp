#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        long long reversed = 0;
        int original = x;
        
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return original == reversed;
    }
};

int main() {
    Solution solution;
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (solution.isPalindrome(num)) {
        cout << num << " is a palindrome" << endl;
    } else {
        cout << num << " is not a palindrome" << endl;
    }
    
    return 0;
}