//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int knapsack_brut(int weight[], int value[], int n, int W, int **output){
	if(n == 0 or W ==0){
		return 0;
	}
	if(output[n][W] != -1) return output[n][W];

	// Recursive Calls
	int ans;
	if(weight[0] > W){
		ans =  knapsack_brut(weight+1, value+1, n-1, W, output);
		output[n][W] = ans;
		return  output[n][W];
	}
	else{
		int x = knapsack_brut(weight+1, value+1, n-1, W - weight[0], output) + value[0];
		int y = knapsack_brut(weight+1, value+1, n-1, W, output);
		ans = max(x,y) ;
		output[n][W] = ans;
		return output[n][W];
	}
}

    
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int **out = new int*[n+1];
       for(int i = 0; i <= n; i++){
           out[i] = new int[W+1];
       }
       
       for(int i = 0; i <= n; i++){
           for(int j = 0; j <= W; j++){
               out[i][j] = -1;
           }
       }
       
       return knapsack_brut(wt,val, n, W, out);
       
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends