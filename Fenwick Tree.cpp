#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

#include<bits/stdc++.h>
using namespace std;

int arr[N] , bit[N];
int n ;

void update(int ind , int val){

	for(int i = ind ; i <= n ; i+=i&(-i)){
		bit[i] += val;
	}
}

int query(int ind){

	int ans = 0 ;

	for(int i = ind ; i > 0 ;i-=i&(-i)){
		ans+=bit[i];
	}

		return ans;
}

int main(){
fast;
	
	
	cin >> n ;

	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i];
		update(i , arr[i]);
	}

	int t;
	cin >> t;
	while(t--){
		int choice;
		cin >> choice;
		if(choice == 1){
			int x , y;
			cin >> x >> y;
			cout << query(y) - query(x-1) << endl;
		}
		else{
			int x , y;
			cin >> x >> y;
			update(x , y) ;
			cout << query(5) << endl;
		}
	}



}	