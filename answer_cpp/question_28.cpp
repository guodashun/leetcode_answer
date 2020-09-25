class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m==0) {
            return 0;
        } else if(n ==0) return -1;
        int dp[m][256];
        int x = 0;
        for (int i = 0; i<m; i++) {
            for (int c = 0; c<256; c++) {
                dp[i][c] = 0;
            }
        }
        dp[0][needle[0]]=1;
        for (int i = 1; i<m; i++) {
            for (int c = 0; c<256; c++) {
                dp[i][c] = dp[x][c];
            }
            dp[i][needle[i]] = i+1;
            x = dp[x][needle[i]];
        }
        int now = 0;
        for (int i = 0; i<n; i++) {
            now = dp[now][haystack[i]];
            if (now == m) return i-m+1;
        }
        return -1;
    }

};

// 初始化条件:1. 有效性判断 2. dp数组初始化与base case的顺序
// 影子状态，状态转移，dp的值的含义
