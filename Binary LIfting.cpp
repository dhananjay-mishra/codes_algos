#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

#include<bits/stdc++.h>
using namespace std;

int sparse[N][30];
int level[N];

void dfs(int node , int par , int lvl){
	
	sparse[node][0] = par;
	level[node] = lvl;

	for(auto i: adj[node]){
		if(par != i){
			dfs(i , node , lvl+1);
		}
	}
}

void sparse(){

	dfs(1 , -1 , 0);

	memset(sparse , -1 , sizeof(sparse));

	for(int j = 1 ; j <= log2(n) ;j++){
		for(int i = 1 ;i <=n ; i++){
			if(sparse[i][j-1] != -1){
				
				int par = sparse[i][j-1];

				sparse[i][j] = sparse[par][j-1];
			}
		}
	}
}

int lcs(int a, int b){

	sparse();
	
	if(level[a] > level[b])
		swap(a , b);

	int d = level[b] - level[a];

	while(d > 0){
		
		int jump = log2(d);
		b = sparse[b][jump];

		d-=(1 << jump);
	}

	if(a == b)
		return a;

	for(int i = log2(n) ; i>= 0 ;i--){
		if(sparse[a][i]!=-1 && (sparse[a][i] != sparse[b][i])){
			a = sparse[a][i];
			b = sparse[b][i];
		}
	}

		return par[a];
}

int main(){
fast;
	
	int n , m;
	cin >> n >> m;

	while(m--){
		int x , y;
		cin >> x >> y;

		adj[x].pb(y);
		adj[y].pb(x);
		
		dfs(1 , -1 , 0);
		
		int a , b;
		cin >> a >> b;
		
		int ans = lca(a , b);

		cout << ans;
	}
}	