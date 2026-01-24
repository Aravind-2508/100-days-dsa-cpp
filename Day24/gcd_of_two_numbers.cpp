/*
Problem: GCD (HCF) of Two Numbers
Approach: Euclidean Algorithm
Time Complexity: O(log(min(a,b)))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
        int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
   
    return 0;
}