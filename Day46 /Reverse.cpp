#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Method 1: Using built-in reverse function
string reverseString1(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Method 2: Two-pointer swap approach
string reverseString2(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

// Method 3: Manual character-by-character
string reverseString3(string s) {
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    return reversed;
}

int main() {
    string str = "hello";
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString1(str) << endl;
    return 0;
}