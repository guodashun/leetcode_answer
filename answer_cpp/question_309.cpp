class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i0 = 0, dp_i1 = INT_MIN;
        int temp = 0;
        int dp_pre_0 = 0;
        for (int i = 0; i < n; i++) {
            dp_pre_0 = temp;
            temp = dp_i0;
            dp_i0 = max(dp_i0, dp_i1 + prices[i]);
            dp_i1 = max(dp_i1, dp_pre_0 - prices[i]);
        }
        return dp_i0;
    }
};

// 有冻结期的股票交易
// 需要i-2时刻的值
// 延时记忆 a=b b=c c=i 可达到i-2的效果
