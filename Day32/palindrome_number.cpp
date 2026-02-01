#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = 0;
        int temp = n;
        
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        
        int sum = 0;
        temp = n;
        
        while (temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        
        return sum == original;
    }
};

int main() {
    Solution solution;
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (solution.isArmstrong(num)) {
        cout << num << " is an Armstrong number" << endl;
    } else {
        cout << num << " is not an Armstrong number" << endl;
    }
    
    return 0;
}