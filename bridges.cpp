#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;
 
 vector<int> adj[N];

 int vis[N];// maintained for ancestors checking(NOTE : Different from the par variable)
 int low[N] ;
 int  in[N];
 int timer = 0;

 void dfs(int src , int par){
 		 
 		 vis[src] = 1;
 		 
 		 low[src] = in[src] = timer++;

 		for(auto it: adj[src]){

 			if(it == par){
 				// direct parent of the src , since it is an undirected graph
 				continue;
 			}

 			if(vis[it] == 1){// this denotes the ancestor(NOTE: Not the direct parent)
 				// current edge is back-edge and hence will not be a candidate for the bridge
 				// Hence we only update its low
 				low[src] = min(low[src] , in[it]); 
 			}
 			else{
 				// current edge is a forward edge and can be a candidate for the bridge
 				// hence will move forward in the graph
 				dfs(it , src);
 				// if low of the child(it) is less than the intime of the current(src) 
 				// than it means  that we can reach the child node via some other node which is having its 
 				//intime less than the src(current) node hence removing the current edge wont affect
 				// the count of connected components.
 				if(low[it] > in[src]){
 					cout << src <<" -> "<<it<<" is a bridge"<<endl;
 				}
 				//now we have to update the low of the current edge as if we can reach the 
 				//child node via a node with lesser intime than we can also rech the current node throyugh that also
 				low[src] = min(low[src] , low[it]);
 			}
 		}
 }

int main(){
fast;
	
		int n , m ; 
		cin >> n >> m ;
		while(m--){
			int x , y;
			cin >> x >> y;

			adj[x].pb(y);
			adj[y].pb(x);

			dfs(1 , -1);
		}
}	