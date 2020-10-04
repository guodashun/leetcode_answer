class Solution {
public:
    int minInsertions(string s) {

        int n = s.size();
        vector<int> dp(n, 0);

        int temp = 0;
        for (int i = n - 2; i >= 0; i--) {
            int pre = 0;
            for (int j = i + 1; j < n; j++) {
                temp = dp[j];

                if (s[i] == s[j]) {
                    // dp[i][j] = dp[i+1][j-1];
                    dp[j] = pre;
                } else {
                    // dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                    dp[j] = min(dp[j], dp[j - 1]) + 1;
                }

                pre = temp;
            }
        }

        return dp[n - 1];

    }
};

// 字符串一般用二维数组
