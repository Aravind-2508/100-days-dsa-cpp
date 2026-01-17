/*
Problem: Print numbers from 1 to N using recursion
Approach: Simple recursion
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
using namespace std;

void print1ToN(int i, int n) {
    // Base case
    if (i > n) {
        return;
    }
    cout << i << " ";
    print1ToN(i + 1, n);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    print1ToN(1, n);
    cout << endl;
    
    return 0;
}