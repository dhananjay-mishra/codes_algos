#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(string s , string temp , int ind){

	if(ind == s.size()){
		ans.push_back(temp);
		return ;
	}

	string temp1 = temp;
	string temp2 = temp;

	temp2.pb(s[ind]);//including the current character

	solve(s , temp1 , ind+1); 	// current character not included
	solve(s , temp2 , ind+1);	// current character included
}

int main(){
fast;
	
	string s;
	cin >> s;
	solve(s , "" , 0);

	for(int i = 0 ; i< ans.size() ; i++){
		cout << ans[i] <<endl;
	}
}	