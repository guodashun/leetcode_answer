class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i10 = 0, dp_i20 = 0;
        int dp_i11 = INT_MIN, dp_i21 = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp_i10 = max(dp_i10, dp_i11 + prices[i]);
            dp_i11 = max(dp_i11, dp_i20 - prices[i]);
            dp_i20 = max(dp_i20, dp_i21 + prices[i]);
            dp_i21 = max(dp_i21, -prices[i]);
        }
        return dp_i10;
    }
};

// 初值设置
// i后面数字表示*剩余购买次数*
