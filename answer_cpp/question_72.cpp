class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};

// 增加：dp[i][j] = dp[i][j-1]+1
// 删除：dp[i][j] = dp[i-1][j]+1
// 修改：dp[i][j] = dp[i-1][j-1]+1
// 特殊情况：word1[i]=word2[j] dp[i][j] = dp[i-1][j-1]
// 本质上还是一个动态规划问题，需要暴搜
// 详解参考链接：https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/
