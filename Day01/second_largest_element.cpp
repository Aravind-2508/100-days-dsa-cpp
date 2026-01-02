#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }
        if (arr[i]>second_largest && arr[i]<largest){
            second_largest = arr[i];
        }
    }
    cout<<"Second largest element is : "<<second_largest<<endl;

    return 0;
}
    


