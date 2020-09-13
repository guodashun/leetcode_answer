class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n+1, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 较为经典的动归算法，难点在于如何确定dp[i]，如何从dp[i-1]得到dp[i]
// 有更快的nlogn算法，但比较难
