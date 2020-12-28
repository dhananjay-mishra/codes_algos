#include<bits/stdc++.h>
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define ll long long int
 
ll mod = 1e9+7;
const int N = 1e5+7;

// no to be sorted
int main(){
fast;	
	
	bool check(int arr[] , int n , int val , int m ){
    
    int c = 1 , sum = 0 ;
    
    for(int i = 0 ; i < n ;i++){
        
        // if current value of the number of pages in the current book is greater than 
        // the mid val(val) then we cant further allocate the books as contigous 
        // allocation is required hence we return false;
        if(arr[i] > val)
        return false;
        
        if(sum + arr[i] > val){
            c++;
            
            sum = arr[i];
        // if number of students become greater than the original number of students
            // given in the ques
            if(c > m)
            return false;
        }
        else
        sum+=arr[i];
    }    
    
        return true;
}

int findPages(int *arr, int n, int m) {
    
    //sort(arr , arr+n);// do not sort as contigous allocation is requiered
    // and if we sort than the original order of the array will be changed
    
    if( n < m )
    return -1;
    
    int low = 0 , high = 0 , ans = INT_MAX;
    
    for(int i = 0 ;i < n ;i++)
        high+=arr[i];
        
    while(low <= high){
        
        int mid = low + (high-low)/2;
        
        if(check(arr , n , mid , m)){
            ans = min(ans , mid);
            high = mid-1;
        }
        else
        low = mid+1;
    }    
    
        return ans;
}

}
