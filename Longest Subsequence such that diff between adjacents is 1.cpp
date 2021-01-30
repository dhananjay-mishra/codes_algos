#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

// similar approach as Longest Increasing Subsequence Except for the conditi0n
int main(){
fast;
	
	int n ;
	cin >> n ;

	int arr[n] , dp[n];

	for(int i =0 ;i < n ;i ++){
		cin >> arr[i];
		dp[i] = 1;
	}

	for(int i = 0; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(abs(arr[i] - arr[j]) == 1)	// Difference
				dp[i] = max(dp[i] , dp[j] + 1);
		}
	}

	int ans = 0;
	for(int i = 0 ; i < n ; i++)
		ans = max(ans , dp[i]);

	cout << ans;

}