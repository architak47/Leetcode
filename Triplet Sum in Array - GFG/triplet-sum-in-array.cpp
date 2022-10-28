//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        if(n < 3) return false;
        for(int i = 0; i < n-2; i++){
            unordered_set<int> st;
            int sum = X - A[i];
            
            for(int j = i+1; j <n; j++){
                if(st.find(sum - A[j]) != st.end()) return true;
                st.insert(A[j]);
            }
        }
        return  false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends