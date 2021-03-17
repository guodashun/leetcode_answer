class Solution {
public:
    int res = 0;
    int numDistinct(string s, string t) {
        backward(s,t,0,0);
        return res;
    }
    void backward(string s, string t, int begin, int idx) {
        if (idx >= t.size()) {
            res++;
            return;
        }
        if (begin >= s.size()) return;
        
        for (int i = begin; i < s.size(); i++) {
            if (s[i] == t[idx]) backward(s, t, i+1, idx+1);
        }
    }
};

//dfs 超时

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1));
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for (int j = 1; j <= t.size(); j++) dp[0][j] = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

// 超时想dp，dp想base and transfer
