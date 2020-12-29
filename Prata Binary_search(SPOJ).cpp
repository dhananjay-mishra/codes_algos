#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int find(int a , int time){
	// for chef with rank = 1 the series formed will be:=
		//1 + (1+2) + (1+2+3) + (1+2+3+4)..... uptill nth time.
		// the last (Nth) term denote the total time...
	// each term in the above series denotes the Ath time
	//hence we have to find the Nth value not the sum
	// The Nth term of the above series is n*(n+1)/2. Now use the Shree dharacharya formula
	//of finding the root;
	int d = sqrt(a*a + 8*time*a);
	
	d-=a;

	d/= (2*a);

	return d;
}

bool solve(int arr[] , int time , int n , int parata){

	int sum = 0 ;

	for(int i = 0 ; i < n ; i++){

		sum+= find(arr[i] , time);

		if(sum >= parata)
			return true;
	}

	return false;
}

int main(){
fast;	
	
	int t;
	cin >> t;

	while(t--){
		int parata , chef;
		cin >> parata >> chef;

		int arr[chef];
		for(int i = 0 ; i < chef;i++){
			cin >> arr[i];
		}

		sort(arr , arr+chef);

		int ans = 0 ;
		int low = 0 , high = 10*(parata)*(parata+1)/2;

			while(low <= high){
			
			int mid = low + (high-low)/2;

				if(solve(arr , mid , chef , parata)){
					ans = mid;
					high = mid-1;
				}
				else
					low = mid+1;
		}

			cout << ans << endl;
	}
	
}
