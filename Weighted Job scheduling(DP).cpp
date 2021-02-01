#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int dp[N];
vector<pair<int , pair<int , int>>> arr;

bool comp(pair<int , pair<int , int>> a, pair<int , pair<int , int>> b){

	return (a.second.first < b.second.first);
}

int find(int idx){

	for(int i = idx ;i >= 0 ; i--){
		if(arr[i].second.first <= arr[idx].first)
			return i;
	}

	return -1;
}

int solve(int idx){

	if(idx < 0)
		return 0;

	if(dp[idx] != -1)
		return dp[idx];

	int ans = 0;

	// include the current job
	ans = arr[idx].second.second;
	int non_overlap_idx = find(idx);
	
	/*
		Adding the profits of all the jobs which we are including in our final ans.
		here we are passing the non_overlapping_idx which is the latest idx of the job
		which is non_overlapping with our currently included job.

		** WE ARE MOVING FROM RIGHT TO LEFT SIDE IN OUR RECURSIVE FUNCTION....
		   THAT IS WE ARE REDUCING THE SIZE OF OUR RECURSIVE CALL AS USUAL WE DO IN 
		   ALL THE QUESTIONS.	
	*/
	ans = ans + solve(non_overlap_idx); // 

	//not including the current job
	ans = max(ans , solve(idx-1));

	dp[idx] = ans;

		return dp[idx];
}

int main(){
fast;
/*
	In this ques we have to find the max profit we can get by including the jobs such 
	that no JOBS are overlapping.

	Approach-->
		Here we will first sort the given array according to the Finish time of the jobs.
		This is because after sorting ...->
		If we want to include any job named CUR... then we have to find the jobs that
		are non-overlapping with the job CUR. Hence with the help of sorting we can
		find the LATEST_JOB(moving left to the CUR job) which is non-overlapping , 
		and after find that LATEST_JOB we will recursively find the NEW_LATEST_JOB
		for our current LATEST_JOB. Finally we will add all the profit of the ALL the 
		JOBS INCLUDED such that no TWO jobs are OVERLAPPING.

		NORMAL APPROACH OF RECURSIVE PROBLEM---> i.e. either to inlclude a job or not.
		but the main issue was that when we include a job than we have to take the 
		remaining jobs which are non-overlapping with our currently included job.
		and then finally we will take sum of all the jobs included such that no 
		TWO jobs are OVERLAPPING. 
*/
	int n;
	cin >> n ;

	for(int i = 0 ; i < n ; i++){
		int x , y , z;
		cin >> x >> y>> z;

		arr.pb({x , {y , z}});
	}

	sort(arr.begin() , arr.end() , comp);

	memset(dp , -1 , sizeof(dp));

	cout << solve(n-1);
}#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const ll N = 1e5+7;

int dp[N];
vector<pair<int , pair<int , int>>> arr;

bool comp(pair<int , pair<int , int>> a, pair<int , pair<int , int>> b){

	return (a.second.first < b.second.first);
}

int find(int idx){

	for(int i = idx ;i >= 0 ; i--){
		if(arr[i].second.first <= arr[idx].first)
			return i;
	}

	return -1;
}

int solve(int idx){

	if(idx < 0)
		return 0;

	if(dp[idx] != -1)
		return dp[idx];

	int ans = 0;

	// include the current job
	ans = arr[idx].second.second;
	int non_overlap_idx = find(idx);
	
	/*
		Adding the profits of all the jobs which we are including in our final ans.
		here we are passing the non_overlapping_idx which is the latest idx of the job
		which is non_overlapping with our currently included job.

		** WE ARE MOVING FROM RIGHT TO LEFT SIDE IN OUR RECURSIVE FUNCTION....
		   THAT IS WE ARE REDUCING THE SIZE OF OUR RECURSIVE CALL AS USUAL WE DO IN 
		   ALL THE QUESTIONS.	
	*/
	ans = ans + solve(non_overlap_idx); // 

	//not including the current job
	ans = max(ans , solve(idx-1));

	dp[idx] = ans;

		return dp[idx];
}

int main(){
fast;
/*
	In this ques we have to find the max profit we can get by including the jobs such 
	that no JOBS are overlapping.

	Approach-->
		Here we will first sort the given array according to the Finish time of the jobs.
		This is because after sorting ...->
		If we want to include any job named CUR... then we have to find the jobs that
		are non-overlapping with the job CUR. Hence with the help of sorting we can
		find the LATEST_JOB(moving left to the CUR job) which is non-overlapping , 
		and after find that LATEST_JOB we will recursively find the NEW_LATEST_JOB
		for our current LATEST_JOB. Finally we will add all the profit of the ALL the 
		JOBS INCLUDED such that no TWO jobs are OVERLAPPING.

		NORMAL APPROACH OF RECURSIVE PROBLEM---> i.e. either to inlclude a job or not.
		but the main issue was that when we include a job than we have to take the 
		remaining jobs which are non-overlapping with our currently included job.
		and then finally we will take sum of all the jobs included such that no 
		TWO jobs are OVERLAPPING. 
*/
	int n;
	cin >> n ;

	for(int i = 0 ; i < n ; i++){
		int x , y , z;
		cin >> x >> y>> z;

		arr.pb({x , {y , z}});
	}

	sort(arr.begin() , arr.end() , comp);

	memset(dp , -1 , sizeof(dp));

	cout << "Total Profit : "<< solve(n-1);
}