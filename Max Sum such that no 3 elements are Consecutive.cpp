#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;


int main(){
fast;
	
	int n ;
	cin >> n;

	int arr[n] , sum[n];

	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	// Here sum[i] denotes the maximum sum of  0....i such that no 3 elements are consecutive. 
	sum[0] = 0;
	sum[1] = arr[0] + arr[2];
	sum[2] = max({arr[2] , arr[0] + arr[1] , arr[0] + arr[2]});

	for(int i = 3 ; i < n ;i++){

		int sum1 = sum[i-1];	// excluding arr[i]
		int sum2 = sum[i-2] + arr[i]; // excluding arr[i-1];
		int sum3 = sum[i-3] + arr[i-1] + arr[i];// excluding arr[i-2];

		sum[i] = max({sum1 , sum2 , sum3});					 
	}

	cout << sum[n-1];
}