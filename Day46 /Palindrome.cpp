#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome1(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

bool isPalindrome2(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isPalindrome3(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string str1 = "racecar";
    string str2 = "hello";
    string str3 = "A man, a plan, a canal: Panama";
    
    cout << str1 << " is palindrome? " << isPalindrome2(str1) << endl;
    cout << str2 << " is palindrome? " << isPalindrome2(str2) << endl;
    cout << str3 << " is palindrome? " << isPalindrome3(str3) << endl;
    
    return 0;
}