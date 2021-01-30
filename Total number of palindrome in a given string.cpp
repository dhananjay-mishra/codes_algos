#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

string s;
int ans = 0;

void solve(int start , int end){
	
	int n = s.size();

	while(start>=0 && end < n){

		if(s[start--] == s[end++])
			 ans++;
		else
			break;
	}	
}

int main(){
fast;
	
	cin >> s;

	// using expanding from the centre technique
	for(int i =0 ; i < s.size() ;i++){

		solve(i , i); // for strings of odd lentgh(eg : A B A)

		solve(i , i+1);	// for strings of even lenthg(eg: A B B A)
	}

		cout << ans;
}