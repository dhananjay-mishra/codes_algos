#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;
 
vector<int> adj[N];
int n , m ;
int color[N];

void solve(){

	color[0] = 0;
	int available[N];

	// initially all colors are available for colouring
	// at max we will need N colours in the worst case
	// as all vertex will have different COlours.
	for(int i = 0 ; i < n ;i++)
		available[i] = 1;

	// picking every Vertex and colouring it according to 
	// available COlours 
	for(int i = 1 ;i < n ;i++){

		// setting all the colors = 0(UNAVAILABLE) which are used in the adjacent vertex 
		// of the currently picked Vertex.
		for(auto it: adj[i]){
			if(color[it] != -1)
			available[color[it]] = 0;
		}
		
		//Now finding the first colour which is available for Colouring
		// and then colouring the current vertx with that colour
		for(int j = 0 ; j < n ; j++)
			if(available[j] == -1){
				color[i] = j;
				break;
			}
		
		// Now setting all the colours previously marked as Unavailable to 
			// available beacuse it maybe he case that the next vertex can lie 
			//somewhere else and hence the colours which are unavialble in the case of
			//curretnly picked Vertex can be available for the Remaining Vertex.
		for(auto it: adj[i]){
			available[color[it]] = 1;
		}
	}
}

int main(){
fast;
	
	
	cin >> n >> m;

	for(int i = 0 ; i < m ;i++){
		int x , y;
		cin >> x >>y;

		adj[x].pb(y);
		adj[y].pb(x);

	}

	for(int i = 0 ; i < n ;i++)
		color[i] = -1;

	solve();

	for(int i = 0 ; ;i < n ; i++)
		cout << color[i] <<" ";
}
