#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

#include<bits/stdc++.h>
using namespace std;

int level[N];
int parent[N];
int visited[N];

void dfs(int node , int par , int lvl){

	visited[node] = 1;
	level[node] = lvl;
	parent[node] = par;

	for(auto i: adj[node]){
		if(!visited[i]){
			dfs(i , node , lvl+1);
		}
	}
}

int lca(int a, int b){

	// keeping level of b always greater
	if(level[a] > level[b])
		swap(a , b);

	int d = level[b] - level[a];

	while(d!=0){
		// moving 1 step above in the tree
		b = par[b];
		d--;
	}

	// this may happen that both a and b are on the same path
	if(a == b)
		return a;

	//else we will move a and b 1 step above simoultaneously till both of them become equal

	while(a!=b){
		a = par[a];
		b = pa[b];
	}

	return a;
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