//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int i = 0, j = 0;
        long long sum = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == k){
                maxi =  i+1;
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            if(mp.find(sum-k) != mp.end()){
                maxi = max(maxi, i - mp[sum - k]);
            }
        }
        
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends