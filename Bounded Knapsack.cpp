#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

// recusive bounded-knapsack
int solve(int n , int w){

	// base condition
	if( n == 0 || w == 0)
		return 0;

	if(dp[n][w]!=-1)
		return dp[n][w];


	if(wt[n-1] <= w){

		dp[n][w] = max(solve(n-1 , w - wt[n-1]) + val[n-1] , solve(n-1 , w));
	}
	else
		dp[n][w] = solve(n-1 , w);

	
	return dp[n][w];
}

// iterative bounded-knapsack
	int dp[n+1][w+1];

	// base condition
	for(int i = 0 ;i <= w ; i++)
		dp[0][i] = 0;

	for(int i = 0 ; i <= n ; i++)
		dp[0][i] = 0;

	for(int i = 1; i <= n ;i ++){
		for(int j = 1 ; j <= w ; j++){

			if( wt[i-1] <= j)
						// included the current items      |	if we didnt took the 
						//hence now we will check for      |	current item then we   	
						// remaining items(i-1) and        |	will look for the optimum 
					// for the reamaining wieght(j-wt[i-1])|	ans with the remaining(i-1)
					// in the remaining items.Beacuse we   |	items and the same wiehght.
					// know that we have already computed  |
					// the optimum ans for the remaining   |
				// wiehgt and remaining items earlier.     |
			dp[i][j] = max(dp[i-1][j - wt[i-1]] + val[i-1] , dp[i-1][j]);
		}
	
		else
			dp[i][j] = dp[i-1][j]; // if our wieght of the current item 
								// exceeds the remaining weight than we will 
								// consider the ans when we didnt had this weight
								// that means (i-1)(j)--> reamingg items with same weight
	}

		return dp[n][w];

int main(){
fast;
	
	
}
