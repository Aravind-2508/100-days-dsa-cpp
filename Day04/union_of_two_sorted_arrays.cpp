/*
Problem: Find the union of two sorted arrays
Approach: Two pointers
Time Complexity: O(n + m)
Space Complexity: O(1) (excluding output)
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n1,n2;
	cout<<"enter n1 and n2 \n";
	cin>>n1>>n2;
	int arr1[n1];
	int arr2[n2];
	cout<<"enter array 1 elements \n";
	for(int i=0; i<n1; i++){
		cin>>arr1[i];
	}
	cout<<"enter array 2 elements \n";
	for(int i=0; i<n2; i++){
		cin>>arr2[i];
	}
	vector <int> v;
	
	int i=0, j=0;
	
	
	while(i<n1 && j<n2){
		if(arr1[i] < arr2[j]){
			if(v.empty() || v.back() != arr1[i]){
				v.push_back(arr1[i]);
			}
			i++;
		}
		else if(arr1[i] > arr2[j]){
			if(v.empty() || v.back() != arr2[j]){
				v.push_back(arr2[j]);
			}
			j++;
		}
		else{  // arr1[i] == arr2[j]
			if(v.empty() || v.back() != arr1[i]){
				v.push_back(arr1[i]);
			}
			i++;
			j++;
		}
	}
	
	
	while(i < n1){
		if(v.empty() || v.back() != arr1[i]){
			v.push_back(arr1[i]);
		}
		i++;
	}
	
	
	while(j < n2){
		if(v.empty() || v.back() != arr2[j]){
			v.push_back(arr2[j]);
		}
		j++;
	}
	
	cout<<v.size()<<"\n";
	
	for(auto k : v){
		cout<<k<<" ";
	}
	
	return 0;
}