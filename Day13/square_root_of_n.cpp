/*
Problem: Square Root of a Number
Approach: Binary Search on Answer Space
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <std/bits.h>
using namespace std;
int square_root_of_n(int n)
{
    int low = 0;
    int high = n;
    int ans = -1;
    while(low <= high)
    {
        long long mid = (low + high)/2;
        if(mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<square_root_of_n(n);
}