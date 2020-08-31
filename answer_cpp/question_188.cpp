class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k<1 || n < 1) return 0;
        if (k > n/2) return maxProfit_inf(prices);
        int dp[n][k+2][2];
        for (int i = 0; i < n; i++) {
            for (int j = k + 1; j > 0; j--) {
                dp[i][j][1] = INT_MIN;
                dp[i][j][0] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = k; j > 0; j--) {
                if (i == 0) {
                    dp[i][j][1] = -prices[i];
                    dp[i][j][0] = 0;
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j+1][0] - prices[i]);
                // cout << "i: " << i << " j: " << j << " 0: " << dp[i][j][0] << endl;
                // cout << "i: " << i << " j: " << j << " 1: " << dp[i][j][1] << endl;
            }
        }
        return dp[n-1][1][0];
    }
    int maxProfit_inf(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp-prices[i]);
        }
        return dp_i_0;
    }
};

// 刚开始做了两道股票题 just soso
// k变成指定值之后 too young too naive
// 1. c++ 数组创建以及初始化问题
// 2. i=0 初始化问题 （因为要continue 所以不是INT_MIN而是-pirces[i]）
// 3. j表示的含义 j+1还是j-1 数组初始化长度
// 4. 测试样例209很搞人，所以要判断k是否大于n/2 大于的话相当于k=inf
