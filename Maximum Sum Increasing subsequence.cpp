#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int main(){
fast;
	
	int n;
	cin >> n ;

	int dp[n];
	int arr[n];

	// here we initialise the DP array as the original array
	// as each element in itself is a increasing subsequence of length 1
	for(int i =0 ;i < n ;i++){
		cin >> arr[i];
		dp[i] = arr[i];
	}


	// similar appraoach as the longest increasing subsequence the only change is
	// in this ques dp[i] represents the maximum sum increasing subsequence till now
	// but in the eariler ques it was longest lentgh.
	for(int i =0 ; i < n ;i++)
		for(int j = 0 ;j <i ; j++){
			if(arr[j] < arr[i])
				dp[i] = max(dp[i] , dp[j] + arr[i]);
		}
	
	int ans = 0 ;

	for(int i = 0 ; i < n ;i++){
		ans = max(ans , dp[i]);
	}

	cout << ans;
}