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

	// this is beacuse if we have 0 coins and we have to make some amount of money
	// then we cant do it .Hence 0 no. of ways
	for(int i = 0 ;i <= amt ; i++)
		dp[0][i] = 0 ;

	//this is because if we dont take any coin and we have to make 0 money
	// then this could be done if we dont take any coin.Hence 1 way
	for(int i = 0;i <= n ;i++)
		dp[i][0] = 1;

	for(int i =1 ; i<= n ;i++){
		for(int j = 1 ;j <= amt ; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
			else
			dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][amt];
}
