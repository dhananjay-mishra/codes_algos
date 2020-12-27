#include<bits/stdc++.h>
using namespace std; 

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long int

ll mod = 1e9+7;
const int N = 1e5+7;
int dp[1001][1001];

long long int count( int S[], int m, int n )
    {
       long long int ans;
       // this conditions is hit , that means 1 way is completed as we have reached to the target money
       if(n == 0)
         	return 1;

       if(m == 0 || n < 0)
       return 0;
       
       if(dp[m][n] != -1)
       return dp[m][n];
       
       if(S[m-1] <= n)
       ans = count(S , m ,n-S[m-1]) + count(S , m-1 ,n);// it is asking the number of ways (NOT NUMBER OF COINS)
   							// hence 1 way is completed when we have hit the base condtion
       else
       ans = count(S ,m-1 , n);
       
       dp[m][n] = ans;
       return dp[m][n];
    }

int main(){
fast;
	int t;
	cin >> t;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int arr[m];
		for(int i = 0 ; i < m; i++)
			cin >> arr[i];
		
		memset(dp , -1 , sizeof(dp));

		cout << count(arr , m , n) << endl;
	}
	
}

