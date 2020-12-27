#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

int arr[101][101];
int visited[101][101];

int n , m ;

// Connected components count in a 2D grid (square matrix in this case) using DFS
// In this question we can only traverse in the cells whose value is 1

//is valid returns wether a cell is valid for traversal or not
// by checking if the value in the cell is 1 || is it out of matrix || is it visited
bool isvalid(int row , int col){
	if(row < 0 || row >=n || col < 0 || col >=n || visited[row][col] == true || arr[row][col] == 0)
		return false;

	return true;
}

void dfs(int row , int col){

	visited[row][col] = 1;

	if(isvalid(row+1 , col)){
		dfs(row+1 , col);
	}

	if(isvalid(row-1, col)){
		dfs(row-1 , col);
	}

	if(isvalid(row , col+1)){
		dfs(row , col+1);
	}

	if(isvalid(row , col-1)){
		dfs(row , col-1);
	}

}

int main(){
fast;
	
	cin >> n ;

	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ;j < n ; j++)
			cin >> arr[i][j];

		int cnt = 0 ;

	for(int i = 0 ; i < n ;i ++)
		for(int j = 0 ;j < n ; j++){
			if(arr[i][j] == 1 && visited[i][j] == 0){
				dfs(i , j);
				cnt++;
			}
		}

			cout << cnt;
}	