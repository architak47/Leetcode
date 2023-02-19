//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
     if (s.size() == 0) return 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0, maxi = INT_MIN;        
        
        while(j < s.size()){
            mp[s[j]]++;
            if(mp.size() == j-i+1){
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
      
        return maxi;
}