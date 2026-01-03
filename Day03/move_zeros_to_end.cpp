// Move all zeros to the end of the array
#include <bits/stdc++.h>
using namespace std;
void removingZeros(int arr[], int n){
	int j=-1;
	for(int i=0; i<n; i++){
		if(arr[i] ==0){
			j =i;
			break;
		}
	}
	if(j == -1) return ;
	for(int i=j+1; i<n; i++){
		if(arr[i] != 0){
			swap(arr[i],arr[j]);
			j++;
		}
	}
}
int main(){
	
	int n;
	cout<<"Enter the size of the array : " <<endl;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	removingZeros(arr,n);
	for(int i=0; i<n; i++){
		cout<<arr[i] <<' ';
	}
	
	return 0;
}