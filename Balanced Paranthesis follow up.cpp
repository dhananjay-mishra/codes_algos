#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

// Nice ques ... follow up of the balanced paranthesis ques.....
// look at the sample testcase to understand better(GFG)
int main(){
fast;	
	int t;
	cin >> t;

	while(t--){
	string s;
	cin >> s;

	stack<char> st;

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '{')
			st.push(s[i]);
		else {
			if(st.size()!=0 && st.top() == '{')
				st.pop();
			else	
			st.push(s[i]);
		}
	}

	if(st.size() == 0 ){
		cout << 0 << endl;
		continue;
	}

	int open = 0 , close = 0 ;

	while(!st.empty()){
		if(st.top() == '{')
			open++;
		else
			close++;

		st.pop();
	}

	int self_open = open/2 , self_close = close/2;

	int open_left = open - (self_open)*2;
	int close_left = close - (self_close)*2;

	if(open_left != close_left){
		 cout << - 1 << endl;
		 continue;
		}

	int ans = self_open + self_close + open_left + close_left;

	cout << ans <<endl;
	
	}

}
