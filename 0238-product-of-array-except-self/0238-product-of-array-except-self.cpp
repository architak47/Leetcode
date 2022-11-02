class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        int leftmul = 1;
        vector<int> ans(n,1);

        for(int i = 0; i < n; i++){
            ans.at(i) = leftmul;
            leftmul = leftmul * nums[i];
        }
        int rightmul = 1;
        for(int i = n-1; i >=0; i--){
            ans[i] = rightmul * ans[i];
            rightmul = rightmul * nums[i];
        }
        return ans;
    }
};