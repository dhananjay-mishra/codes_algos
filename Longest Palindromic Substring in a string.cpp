#include<bits/stdc++.h>
using namespace std; 

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int

ll mod = 1e9+7;
const int N = 1e5+7;

	string solve(string &s , int l , int r){

			int n = s.size();

			while(l >=0 && r < n){
				if(s[l] == s[r]){
					l--; 	
					r++;
				}
				else
					break;
			}
                                //index
			string res = s.substr(l+1 , (r-1) - (l+1)  + 1);
			                                // size
			return res;

	}

int main(){
fast;
	
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		int n = s.size();
		int sz = 0;
		
		string ans;

		for(int i = 0 ; i < n ; i++){

			// odd lenghts palindromes
			string temp = solve(s , i , i);
			
			if(temp.size() > sz){
				sz = temp.size();
				ans = temp;
			}

			// even lengths palindromes
			temp = solve(s , i , i + 1);

			if(temp.size() > sz){
				sz = temp.size();
				ans = temp;
			}
		}
	
			cout << ans << endl;
	}
}
