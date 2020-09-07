class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        vector<bool> dp(sum+1, false);
        sum = sum / 2; // 重要
        dp[0] = true;
        for(int i = 0; i<nums.size(); i++) {
            for(int j = sum; j >=0; j--) {
                if (j-nums[i]>=0)
                    dp[j] = dp[j] || dp[j-nums[i]]; 
            }
        }
        return dp[sum];
    }
};

// 背包问题，状态压缩后的情况
