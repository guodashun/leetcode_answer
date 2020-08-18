class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin < 0) 
                    continue;
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
        return (dp[amount] < amount + 1) ? dp[amount] : -1;
    }
};

// 1. base case
// 2. vector 初值选择
// 3. -1的处理（不应该给dp赋值，会导致coin大于i时把dp值刷掉）