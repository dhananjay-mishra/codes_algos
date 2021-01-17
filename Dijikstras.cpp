#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

vector<pair<int , int>> adj[N];

int dist[N];
int incl[N];

int n , m ;

int find_min(){

	int mini = INT_MAX;
	int ans = 0;

	for(int i = 0 ; i < n ; i++){
		if(!incl[i] && dist[i] < mini){
			mini = dist[i];
			ans = i;
		}
	}

		return ans;
}

void dij(int source){

	for(int i = 0 ; i < n ; i++){

		int node = find_min();

		incl[node] = 1;

		for(auto i : adj[node]){

			if(!incl[i.first] && dist[node] + i.second < dist[i.first])
				dist[i.first] = dist[node] + i.second;
		}
	}

}

int main(){
fast;
	
	// maintain a distance array and initialzie it with INT_MAX;
	// mark the source node's distance as 0; 
	// in the dij function ...untill all the nodes are include :
	// pick a node with minimum distance and which is also not included int he final ans set
	// update the distance for every nodes adjacent nodes.

	
	cin >> n >>  m;

	for(int i = 0 ; i < m ;i ++){

		int x , y , wt;
		cin >> x >>  y >> wt;

		adj[x].pb({y , wt});
		adj[y].pb({x , wt});
	}

	int source;
	cin >> source;

	for(int i = 0 ; i < n ; i++)
		dist[i] = INT_MAX;

	dist[source] = 0 ;

		dij(source);

	for(int i = 0 ;i < n ; i++)
		cout << source <<"--->" << i <<" " << dist[i]<<endl;
}

