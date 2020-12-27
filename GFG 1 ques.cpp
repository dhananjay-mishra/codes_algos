#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

//finding the distance of the node a and b form the calculated ancestor

int find(int node , int val , int c ){

	if(node > val)
		return INT_MAX;

	if(node == val)
		return c;

	int left = find(node*2 , val , c+1);
	int right = find(node*2 + 1 , val , c+1);

	return min(left , right);
}

// finding the ancestor of both the nodes

int solve(int node , int a , int b){

	if(node > a && node > b)
		return INT_MAX;

	if(node == a || node == b)
		return node;

	int left = solve(node*2 , a , b);
	int right = solve(node*2 + 1 , a, b);

	if(left == INT_MAX && right == INT_MAX)
		return INT_MAX;
	
	if(left != INT_MAX && right != INT_MAX)
		return node;

	return left!=INT_MAX ? left : right;

}

int main(){
fast;

	int t ;
	cin >> t;

	while(t--){
		int a ,b;
		cin >> a >> b;

		int anc = solve(1 , a , b);	// finding the ancestor
			

		int dist_a = find(anc , a , 0);	// finding the distance of node a from the ancestor
		int dist_b = find(anc , b , 0);	// finding the distance of node b form the ancestor

		cout << (dist_b + dist_a) << endl;	
	}
}