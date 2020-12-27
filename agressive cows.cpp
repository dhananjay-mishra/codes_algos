#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

bool check(int ans , vector<int>& arr , int cows){

	int n = arr.size();
	int c = 1 , idx = 0;

		while(idx < n && c < cows){

		int val = arr[idx] + ans; 
		
		 idx = lower_bound(arr.begin() , arr.end() , val) - arr.begin();
		
		if(idx < n){
			c++;
		}
	}

	if(c == cows)
		return true;

		return false;
}

int main(){
fast;	
	
	int t;
	cin >> t;

	while(t--){
		int n , cows;
		cin >> n >> cows;

		vector<int> arr(n);

		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];
		
		sort(arr.begin() , arr.end());

		int low = 0 , high = 1000000000;
		int ans = 0 ;

			while(low <= high){

				int mid = low + (high-low)/2;

				if(check(mid , arr , cows)){
					ans = mid;
					low = mid+1;
				}
				else
					high = mid-1;
			}

			cout << ans << endl;
	}

}
