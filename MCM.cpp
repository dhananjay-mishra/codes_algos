#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int solve(int i , int j){

	// if we have only 1 size (i.e. i == j) then we cant place the brackets
	// Hence we return 0. This will be our base case
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;

	for(int k = i ; k < j ; k++){
				 // left part  |  right part       
		ans = min(solve(i , k) + solve(k+1 , j) + arr[i-1]*arr[k]*arr[j]);
	}

	dp[i][j] = ans;

	return dp[i][j];
}

int main(){
fast;
	
	/* MATRIX CHAIN MULTIPLICATION
	
	here we will take an array where ith index represents C and i-1 represent
	R of a matrix, Hence at ith index we have information of a a Matrix i.e R*C

	Now we can place brackets anywhere to find the final product of all the matrix.
	But the matrix product will be different depending upon the place we place the brackets.
	Hence we have to find the minimum cost of the matrix product.

	so we will place brackets at every index (i.e. Brute Force method) and
	take the minimum of the ans. That is when we place a bracket at a particular index
	then we will have two parts that is Left and Right part.lets take the example and Visualize
	
	(1 2 3 )| (5 5 6 6 7)
	
	In above exapmple we place the bracket at(|) hence we will have two parts.
	Now we will solve separatley the two parts and take the minimum of all the possible 
	Combinations from the left and right part and then Finally 
	multiply the left part and add it to the ans.(See the code for better understanding)
*/

	int n;
	cin >> n ;

	int arr[n+1];

	for(int i =0 ; i < n ; i++){
		cin >> arr[i];
	}

	cout << solve(1 , n-1);
}	
