#include<bits/stdc++.h>
using namespace std; 

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int

ll mod = 1e9+7;
const int N = 1e5+7;

// Minimum Swaps and K together.{PURE SLIDING WINDOW}

int main(){
fast;
	int t;
	cin >> t;
	while(t--){
		int n , k;
		cin >> n;
		int arr[n];
		for(int i = 0 ;i <n ; i++)
			cin >> arr[i];
		
		cin >> k;
		int cnt = 0 ;

		
		for( int i = 0 ; i < n ;i++)
			if(arr[i] <= k)
				cnt++;
		
		int bad = 0 , ans = INT_MAX;
		int i = 0 ;

		
		//Intialised a window of size cnt
		while(i < cnt){
			if(arr[i] > k)
				bad++;

			i++;
		}

			// Storing the ans For the First initialised Window
			ans = min(ans , bad);

			// Checking all Windows {Including the lastest window of size cnt}
			while(i < n){
				
				// Standing at the next element Out of the window Size { * * . . . _}
				//"Here DOTS represent the Window and the '_' Represents the Current Element we are satnding at
				// '*' Represents the element We have checked or included earlier in the PAST windows"
				if(arr[i] > k){
					bad++;
				}

				// Including the Current Element We are Standing at in the Window 
				//by DECREASINGthe count of bad elements(Which was having all the bad elements in the LAST passed window)
				if(arr[i - cnt] > k)
					bad--;

				// updating the answer for the NEW window 
				ans = min(ans , bad);
				
			i++;
		}

			cout << ans << endl;
	}
}

