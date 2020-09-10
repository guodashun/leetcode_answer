class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j-coins[i]>=0)
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

// j循环 正序还是倒序？
// j的正序倒序就是子集背包和完全背包的区别！
// 压缩空间的理解
