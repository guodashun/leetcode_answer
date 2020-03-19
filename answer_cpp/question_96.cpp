class Solution {
public:
int numTrees(int n) {
    if (n == 0) return 0;

    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int end = 2; end <= n; end++) {
        for (int mid = 1; mid <= end; mid++) {
            dp[end] += dp[mid - 1] * dp[end - mid];
        }
    }

    return dp[n];
}
};
//卡特兰数的迭代表达式