#include <bits/stdc++.h>
using namespace std;
int MaximumCon(int arr[], int n){
    
    int maxi =0;
    int count =0;
    for(int i=0; i<n; i++){
        if(arr[i] ==1 ){
            count++;
            maxi = max(maxi,count);
        }else count =0;
    }
    return maxi;
    
    
}
int main(){
    int n;
    cout<<"Enter the array size "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<MaximumCon(arr,n);
    
    return 0;
    
}