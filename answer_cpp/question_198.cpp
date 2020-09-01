class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp = 0;
        for (int i = n-1; i >=0; i--) {
            dp = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp;
        }
        return dp;
    }
};
