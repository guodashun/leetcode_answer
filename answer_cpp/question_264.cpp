class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp (n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        // 维护了四个列表 p2, p3, p5, dp
        // 实际值仅用dp来存储, 其余通过index获取当前值
        for (int i = 2; i <= n; i++) {
            int n2 = dp[p2] * 2, n3 = dp[p3] * 3, n5 = dp[p5] * 5;
            // 这里相当于所有列表共用值（merge）
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2) p2++;
            if (dp[i] == n3) p3++;
            if (dp[i] == n5) p5++;
            // 注意 这里的关系不是if else的关系（switch case）因为有的数既是2又是3的倍数，所以要全部判断一遍
        }
        return dp[n];

    }
};

// 三个列表融合的dp
