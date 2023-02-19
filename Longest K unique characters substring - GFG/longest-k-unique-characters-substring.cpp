//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        if(k > s.size()) return -1;
        int i = 0, j = 0; 
        int maxi = INT_MIN;
        unordered_map<char, int> mp;
        
        for(auto it : s){
            mp[it]++;
        }
        if(mp.size() < k) return -1;
        
        mp.clear();
        
        while(j < s.size()){
            mp[s[j]]++;
            if(mp.size() < k){
                j++;
            }
            else if(mp.size() == k){
                maxi = max(maxi, j-i+1);
                j++;
            }
            else{
                while(mp.size() > k){
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
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends