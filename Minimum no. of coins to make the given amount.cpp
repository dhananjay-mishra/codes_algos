#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int main(){
fast;

	int amt , n;

	cin >> amt >> n;

	int arr[n];

	for(int i = 0 ; i < n ;i++)
		cin >> arr[i];

	int dp[n+1][amt+1];

	// This is beacuse if we have to make some anount of money 
	// and we dont have any coin then we can take INFINITE no. of coins of value 0
	// in the hope that we can somehow make that amount of money.. Hence INT_MAX
	for(int i = 0 ;i <=n ; i++)
		for(int j =0 ;j <= amt ; j++)
			dp[i][j] = INT_MAX;

	// this is beacause when we have to make 0 amt of money
	// then it can be done only when we dont take any coin. Hence 0 no. of coins
	for(int i = 0 ;i <=n ;i++)
		dp[i][0] = 0;	

	for(int i = 1 ;i <=n ; i++)
		for(int j = 1 ; j<= amt ; j++){
			if(arr[i-1] <= j)
				dp[i][j] = min(1 + dp[i][j-arr[i-1]] , dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}

	if(dp[n][amt] == INT_MAX)
		cout <<"WE cant make this amount of money with the given coins" ;
	else
		cout << dp[n][amt];
}
