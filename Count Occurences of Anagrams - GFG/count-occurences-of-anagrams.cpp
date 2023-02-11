//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) {
	    int k = p.size();
        int ans = 0;
        unordered_map<char, int> mp;

        for(auto it : p) mp[it]++;

        int i = 0, j = 0;
        int cnt = mp.size();
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    cnt--;
                }
            }
            if(j-i+1 != k){
                j++;
            }
            else if(j-i+1 == k){
                if(cnt == 0){
                    ans++;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        cnt++;
                    }
                }
                i++,j++;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends