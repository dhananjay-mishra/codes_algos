#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;
 
 int parent[N];

// Find Parent using Path Compression
int find_par(int x){

	if(parent[x] == x)
		return x;

	return parent[x] = find_par(parent[x]);
}


int main(){
fast;

int n, m;
cin >> n >> m ;

vector<int> adj[n+1];
vector<pair<pair<int , int> , int>> arr;

priority_queue<pair<pair<int , int> , int>> pq;

// here we only take edges(**NOT GRAPH)
for(int i = 0 ; i < m ; i++){
	int x , y , wt;
	cin >> x >> y >> wt;

	arr.pb({{x , y} , wt});

	pq.push({{-wt , x} , y});
}
	
	for(int i = 0 ; i <=n ; i++)
		parent[i] = i;

	for(int i = 0 ; i < m ; i++){
		auto temp = pq.top();
		pq.pop();

		int a = temp.first.second;
		int b = temp.second;

		int x = find_par(a);
		int y = find_par(b);

		// here when we do UNION then we also make the MST simoultaneously
		if(x != y){
			parent[y] = x;

			adj[a].pb(b);
			adj[b].pb(a);
		}
	
	}

	// Printing the MST(here considered as UNDIRECTED GRAPH)
	for(int i = 0 ;i < n; i++){
		for(int j = 0 ; j < adj[i].size() ; j++)
			cout << i<<" --> "<<adj[i][j]<<endl;
	}
}
