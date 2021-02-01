#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int main(){
fast;
	/*
	 In this problem we are given a dictionary of words and a String is given
	 We have to determine wether the givne String can be constructed from the Dictionary.
    */

	int m;
	cin >> m ;
	
	vector<string> dict(m);
	
	for(int i =0 ; i < m ; i++)
		cin >> dict[i];

	string s;
	cin >> s;

	unordered_map<string , int> mp;

	// Here we mapped the dictionary words because we can start 
	// finding wether the word exists in ditcionary or not in the below code
	for(int i = 0 ; i < m ; i++)
		mp[dict[i]] = 1;

	
	int n = s.size();
	
	int dp[n+1] = {};
	dp[0] = 1;	// dp[0] denotes the empty string . Hence Empty string can be formed
				// from the dictionary by not choosing any word from the dictionary

	for(int i = 1; i <= n ; i++){
		for(int j = i-1 ; j>=0 ; j--){
			/*
			 We start breaking (from the back) the string we reached till ith position.
			 we check for the left part of the breaked string that wether we can make the 
			 left part or not usnig the DP table. This is because we have determined
			 already wether the left part can be formed or not(DP).Hence we can use this
			 information.

			 Now if the left part can be made then we check wether the right part exists
			 in the dictionary or not. if it does then we can make the string till ith
			 position and we will break(as we have formed the string form the dictionary
			 and hence no further checking is reuqired). 
			*/				
			if(dp[j]){

				string temp = s.substr(j , i-j);

				if(dict[temp])
					dp[i] = 1;

				break;
			}
		}
	}	

		cout << dp[n];
}