//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int helper(int n, vector<int> &ans){
	if(n == 1) return 0;

	if(ans[n] != -1){
		return ans[n];
	}

	int temp = helper(n-1, ans);
	if(n % 3 == 0)
          temp = min(temp, helper(n / 3, ans));

        if(n% 2 == 0) 
			temp = min(temp, helper(n/2, ans));

        ans[n] = 1 + temp;

	return ans[n];
}
	public:
	int minSteps(int n) 
	{ 
	    vector<int> ans(n+1, -1);
    	return helper(n, ans); 
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends