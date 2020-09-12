class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum < S || (sum + S) % 2 == 1){
            return 0;
        }
        return subSets(nums, (sum + S) / 2);
    }

    // 满足要求的子集数
    int subSets(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for(auto& v : dp) v[0] = 1;

        for(int i = 1; i < n + 1; ++i)
        {
            int val = nums[i - 1];
            for(int j = 0; j <= sum; ++j)
            {
                // cout << "i: " << i << " j: " << j << " val: " << val << endl;
                
                if(j >= val)
                {
                    // 选择当前物品的组合数和不选择当前物品的组合数的和
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - val];
                }
                else{
                    // 只能选择不拿当前物品
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

// 简单的回溯会超时，需要转变为背包问题
