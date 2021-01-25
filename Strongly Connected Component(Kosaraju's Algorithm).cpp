#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int visited[N];
stack<int> st;
vector<int> adj[N];

void dfs_stack(int node){

	visited[node] = 1;

	for(auto it : adj[node]){

		if(!visited[it])
			dfs_stack(it);
	}

	st.push(node);
}

void dfs(int node){

	visited[node] = 1;

	for(auto i : adj[node]){
		if(!visited[i])
			dfs(i);
	}
}


int main(){
fast;
	
	// Read the Hackerearth Article on Strongly Connecte Components
	int n , m ;
	cin >> n >> m ;

	vector<pair<int,int>> arr;

	for(int i = 0 ; i < m; i++){
		int x , y;
		cin >> x >> y;
		arr.pb({x , y});
	}

	for(auto i : arr){
		int x = i.first;
		int y = i.second;

		adj[x].pb(y);
	}

	dfs_stack(0);

	// Now we will reverse the graph and clear the previous Graph
	for(int i = 0; i < N ;i++){
		adj[i].clear();
	}
	
	// Done because the new Reversed graph traversal will be done
	memset(visited , 0 , sizeof(visited));

	for(int i = 0 ; i < arr.size() ; i++){

		int x = arr[i].first;
		int y = arr[i].second;

		adj[y].pb(x);	// reversing the Graph
	}

	// Now We will count the total Number of the Strongly Connected Components

	int ans = 0;

	while(!st.empty()){
		if(!visited[st.top()]){
			dfs(st.top());
			ans++;
		}

		st.pop();
	}

	cout << ans;
}
