#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

/*
 Shortest and Longest Path in a Directed Acyclic Graph
	
It can be done with Dijikstras too as we did in the case of undirected Graphs
But the Time Complexity will be ElogV(In case PQ is Used).

But in the case of Direceted Acyclic Graph this can be further Optimised to (V+E).
The reason is that : in case of Directed Acyclic Graph we have to maintain a proper order 
for Traversal of the DAG. If any vertex which is having a smaller value exists but 
if it cant be reached before a vertex which is having a greater weight , then
we cant pick that vertex with minimum weight . Hence we can only
Reach that vertex after the vertex having gretaer Weight is picked.
So we have to use Topological sorting for that. But in the case of Undirected Graph
we can reach any vertex as it is bidirecetional so we have to take the minimum weight
Vertex first. Hnece in the case of Undirected Graph we cant reduce the time COmplexity 
Lesser than E(logV). E(logV) because we update till all the vertex are reached from the 
source with the minimum possible value of that path. So what we basically do is that we 
POP_OUT every vertex form the Priority queue untill the PQ becomes empty. And for every
vertx we pick from the PQ we update all its adjacent Vertex this takes O(E) time.
and picking every minimum vertex form the PQ takes O(logV) time hence the Time complxity
becomes ---> O(Elog(V));
*/

int main(){
fast;
}
