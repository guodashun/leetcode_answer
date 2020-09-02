class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob_sub(0, n-1, nums), rob_sub(1, n, nums));
    }
    int rob_sub(int start, int end, vector<int>& nums) {
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp = 0;
        for (int i = end - 1; i >= start; i--) {
            dp = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp;
        }
        return dp;
    }
};

// 环形数组 去头去尾
