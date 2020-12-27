#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;


int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 

bool oneday(int ad , int am , int ay , int bd , int bm , int by){

	if(--bd == 0){
		if(--bm == 0){
			--by;
			bm = 12;
		}
		bd = months[bm-1];
		
		bool isleap = (by%4 && (by%100!=0 || by%400 == 0));
		if(bm == 2 && isleap)
			bd = 29;
	}

		return (ad == bd && bm == am && by == ay);
}

int main(){
fast;	
	
	int n , ad = 0 , am = 0 ,ay = 0 , ac = 0 ;
	int t;
	cin >> t;

	while(t--){
		int n ;
		cin >> n;
		int sum = 0, ans = 0;
		
		while(n--){
		int bm , bd , by , bc ;
		

		cin >> bd >> bm >> by >> bc;

		if(oneday(ad , am , ay , bd , bm , by )){
			sum+=bc - ac;
			ans++;
		}
		ad = bd; am = bm ; ay = by; ac = bc;
	
		}
		cout << ans << " " << sum << endl;
	}
}



