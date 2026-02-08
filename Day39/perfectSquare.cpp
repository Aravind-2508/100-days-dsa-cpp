#include <bits/stdc++.h>
using namespace std;

bool isPerfectNumber(int num) {
    // Perfect numbers are positive
    if (num <= 1) {
        return false;
    }
    
    int sum = 0;
    
    // Find all divisors (excluding the number itself)
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    // Check if sum of divisors equals the number
    return sum == num;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPerfectNumber(number)) {
        cout << number << " is a Perfect Number!" << endl;
    } else {
        cout << number << " is NOT a Perfect Number." << endl;
    }
    
    return 0;
}
```

**How it works:**
- A perfect number equals the sum of its proper divisors (excluding itself)
- Examples: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14
- Loop through numbers from 1 to num/2 to find divisors
- Check if each number divides evenly using modulo

---

## Sample Output

**Sum of Digits:**
```
Enter a number: 12345
Sum of digits: 15
```

**Perfect Number:**
```
Enter a number: 28
28 is a Perfect Number!

Enter a number: 12
12 is NOT a Perfect Number.