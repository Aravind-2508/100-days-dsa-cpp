#include<bits/stdc++.h>
using namespace std;
int power(int mid, int n, int m){
    long long ans = 1;
    for (int i = 0; i < n; i++){
        ans = ans * mid;
        if(ans > m)
            return 1;
    }
    if (ans == m)
        return 0;
    else
        return -1;
}
int findNthrootofM (int n, int m){
    int low = 1;
    int high = m;
    while (low <= high){
        int mid = (low + high) / 2;
        int x = power(mid, n, m);
        if (x == 0){
            return mid;
        }
        if (x == -1){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
  int n;
  int m;
  cin >> n >> m;
  cout << findNthrootofM(n,m);
  return 0;
}