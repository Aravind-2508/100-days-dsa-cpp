#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int num) {
    // Handle negative numbers
    num = abs(num);
    
    int sum = 0;
    while (num > 0) {
        sum += num % 10;  // Extract last digit and add to sum
        num /= 10;        // Remove last digit
    }
    return sum;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    int result = sumOfDigits(number);
    cout << "Sum of digits: " << result << endl;
    
    return 0;
}