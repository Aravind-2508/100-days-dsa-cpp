#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, original, remainder, digits = 0;
    double result = 0;
    cout << "Enter a number: ";
    cin >> n;
    original = n;
    int temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, digits);
        temp /= 10;
    }
    if ((int)result == original)
        cout << original << " is an Armstrong number." << endl;
    else
        cout << original << " is not an Armstrong number." << endl;
    return 0;
}