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

void solve(string s , int start , int end){

	if( start == end){
		ans.push_back(s);//changing the original string so the final ans is the changed string
		return ;
	}

	//fixing one character at a time and swapping the other characters
	// Take and example of ABC and dry run
	for(int i = start ; i <= end ; i++){

		swap(s[i] , s[start]);
		
		solve(s , start+1 , end);

		swap(s[i] , s[start]);	// backtracking
	}

}

int main(){
fast;
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		//for every testcase  our ans vector should be Empty
		ans.clear();

		int n = s.size();

		solve(s , 0 , n-1);

		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i] << " ";

		cout << endl;

	}
}	