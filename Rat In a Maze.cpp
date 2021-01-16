#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int n;
int vis[101][101];
int arr[101][101];

vector<string> ans;

bool isSafe(int i , int j){

	if(i < 0 || i == n || j < 0 || j == n || vis[i][j] == 1 || arr[i][j] == 0)
		return false;

	return true;
}

void solve(int i , int j , string &temp){

	if(i == n-1 && j == n-1){
		ans.pb(temp);
		return;
	}

	
	vis[i][j] = 1;

	if(isSafe(i+1 , j)){
		temp.pb('D');
		solve(i+1 , j , temp);

		temp.pop_back();
	}

	if(isSafe(i-1 , j)){
		temp.pb('U');
		solve(i-1 , j , temp);
		
		temp.pop_back();
	}

	if(isSafe(i , j+1)){
		temp.pb('R');
		solve(i , j+1 , temp);

		temp.pop_back();
	}

	if(isSafe(i , j-1)){
		temp.pb('L');
		solve(i , j-1 , temp);

		temp.pop_back();
	}

	vis[i][j] = 0;
}

int main(){
fast;
	
	/* 
	1- start from the 0 , 0 cell..
	2- visit all the cells which have 1 and apply dfs to all the four directions
	3 - once a dfs to all the 4 directions from the current node is done 
		then we will backtrack and mark the current node as unvisited
		as the work form the current node is done and it can be included in some other path too
	4- create an visited array for marking the visitaions of the cells
	*/

	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cin >> arr[i][j];
	} 

	string temp = "";

	solve(0 , 0 , temp);

	for(int i = 0 ; i < ans.size() ; i++)
		cout << ans[i] << endl;
	
}
