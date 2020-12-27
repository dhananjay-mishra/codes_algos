#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;
 // watch CODENCODE video
bool dfs(int node , int c){

	visited[node] = 1;
	col[node] = c;

		for(auto i : adj[node]){
			if(!visited[i]){
				if(dfs(i , c^1) == false)
					return false;
			}
			else{
				if(col[i] == col[node])
					return false;
			}
		}

			return true;
}


int main(){
fast;
	int n , m ;
	cin >> n >> m ;
	while(m--){
		int x , y;
		cin >>x >>y;
		
		adj[x].pb(y);
		adj[y].pb(x);

	}

	for(int i = 1 ;i <=n ; i++){
		if(!visited[i])
			if(dfs(i , 1) == false){
				cout << "NO" << endl;
				break;
			}
	}
}	