#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int dp[1001][1001];
/*
	Here in the input we have floors that means the remaining NUMBER(Quantity) 
	of floors not the Floor Number(i.e. 1st , 2nd floor.....) and the remaining Eggs
*/

int solve(int floors , int eggs){

	if(floors == 0 || floors == 1)
		return floors;
	if(eggs == 1)
		return floors;

	if(dp[floors][eggs] != -1)
		return dp[floors][eggs];

	int ans = INT_MAX;

	for(int i = 1 ; i<= floors ; i++){
	/*
		If the egg breaks --->
		than we have i-1 floors(number-->quantity) remaining to check and eggs-1

		If the egg doesnt Breaks ---> 
		than we have to check for the upper remaining floors i.e. floors - i
		with the same number of eggs.
	*/	
		int temp = 1 + max(solve(i-1 , eggs-1) , solve(floors-i , eggs));
		ans = min(ans , temp);

	}

	dp[floors][eggs] = ans;

	return ans;
}

int main(){
fast;
	/*
	Time comlepxity of this Code is:
		O(eggs*floors*floors)

	This is becuase we are traversing(FOR LOOP) in the recursive function
	and in the worst case the total number of floors could be the Maximum(i.e. total Hieght)
	now the remaining complexity i.e. egges*floors comes from the Size of the Dp table
	i.e. floors*eggs.
	*/

	int floors , eggs;
	cin >> floors >> eggs;

	memset(dp , -1 , sizeof(dp));

	cout << solve(floors , eggs);	
}