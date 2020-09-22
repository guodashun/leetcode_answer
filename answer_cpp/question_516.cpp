class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
                if (i == j) dp[i][j] = 1;
            }
        }
        for (int i = n - 2; i>=0; i--) {
            for (int j = i+1; j <n; j++) {
                if (s[i]==s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

// 为什么在max的时候不+1
// 在判断目前的两头不相等时，他们俩一定不会同时出现在同一子序列中，所以最大值为长度-1的值，不需要+1
// 理解dp的含义
