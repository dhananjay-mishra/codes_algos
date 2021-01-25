#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int dp[10001][10001];

int solve(int n , int r){

	if( r == 0)
		return 1;

	if(n < r)
		return 0 ;
	if( n == r)
	return 1;

	if(dp[n][r] != -1)
		return dp[n][r];

	// nCr = n-1Cr-1 + n-1Cr;

	dp[n][r] = (solve(n-1 , r-1)%mod + solve(n-1 , r)%mod)%mod;

	return dp[n][r]; 
}

int main(){
fast;
	
	int n , r;
	cin >> n >> r;

	memset(dp , -1 , sizeof(dp));

	cout << solve(n , r);
}	
