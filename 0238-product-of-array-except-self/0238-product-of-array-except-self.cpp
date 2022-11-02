class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        int leftmul = 1;
        int rightmul = 1;
        vector<int> ans(n,1);

        for(int i = 0, j = n-1; i < n; i++,j--){
            ans.at(i) = leftmul * ans.at(i);
            leftmul = leftmul * nums[i];
            ans.at(j) = rightmul * ans.at(j);
            rightmul = rightmul * nums[j];
        }
        return ans;
    }
};