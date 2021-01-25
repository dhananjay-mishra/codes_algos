#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;


int main(){
fast;
	
	string a , b;
	cin >> a >> b;

	int dp[a.size()+1][b.size()+1];

	for(int i = 0 ; i <= a.size() ; i++)
		dp[i][0] = i;

	for(int i = 0 ; i <= b.size() ; i++)
		dp[0][i] = i;

	for(int i = 1 ; i <= a.size() ; i++)
		for(int j = 1 ; j <= b.size() ; j++){
		/* if both the characters are equal then we dont have to 
		   remove , replace , add any character. Hence we will take the 
		   minimum edit distance when both the current characters were not present	*/
			if(a[i-1] == b[i-1])
				dp[i][j] = dp[i-1][j-1];	
			else
				dp[i][j] = 1 + min({dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]});
			/* if both the current characters aren't equal then we will either insert , 
			remove or update . Hence we will pick the minimum of previously done operations
			that is when either 1 of the characters were not present i.e(i-1 & j-1) or when
			both of them were not present. In either of the case we have to perform 1 operation
			therefore we add 1 to the minimum of all the previously taken ans.   */ 
		}

		cout << dp[a.size()][b.size()];
}	
