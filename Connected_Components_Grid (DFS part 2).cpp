#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

int n ;
int arr[101][101];
int vis[101][101];

// did this to prevent the dfs calls done manually as in part 1 of This Question(See The Code)
int x_dir[] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};
int y_dir[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , 1};

bool isSafe(int row , int col){

	if(row < 0 || row == n || col < 0 || col == n || vis[row][col] == true || arr[row][col] == 0)
		return false;

	return true;
}

void dfs(int i , int j){

	vis[i][j] = 1;
		
	// for Each cell , we are checking its neighbouring 8 Cells using the X_dir and Y_dir array created above
	for(int it = 0 ;it < 8 ;it++){
		if(isSafe(x_dir[it] + i , y_dir[it] + j))
			dfs(x_dir[it] + i , y_dir[it] + j);
	}
}

int main(){
fast;	
	
	cin >> n ;

	for(int i = 0; i < n ; i++){
		for(int j = 0 ;j < n ;j++)
			cin >> arr[i][j];
	}

	int ans = 0;

	for(int i = 0; i < n ; i++)
		for(int j = 0 ;j < n ; j++){
			if(arr[i][j] == 1 && vis[i][j] == false){
				dfs(i , j);
				ans++;
			}
		}

		return cout << ans , 0;
}
 