#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int i=0 ;
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout<<i+1;
    return 0;
}