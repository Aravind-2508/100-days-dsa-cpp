/*
Problem: Print numbers from N to 1 using recursion
Approach: Simple recursion
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
using namespace std;

void printNTo1(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    cout << n << " ";    
    printNTo1(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    printNTo1(n);
    cout << endl;
    
    return 0;
}