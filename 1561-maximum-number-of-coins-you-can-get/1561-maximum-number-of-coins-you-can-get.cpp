class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int me = 0;
        int n = piles.size();
        for(int i = n/3; i < n; i+=2){
                me += piles[i];   
        }
        return me;
    }
};