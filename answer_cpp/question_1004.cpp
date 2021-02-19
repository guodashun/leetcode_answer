class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if (A.empty()) return 0;
        vector<int> dp(K+1,0);
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < K+1; j++) {
                if (A[i] == 1) dp[j]++;
                if (A[i] == 0) {
                    if (j != 0) {
                        dp[j-1] = dp[j]+1;
                    }
                    dp[j] = 0;
                }
            }
            if (dp[0] > res) res = dp[0];
        }
        return res;
    }
};

// 动规解出来，但超时了

// 自己的滑动窗口
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if (A.empty()) return 0;
        int ans = 0;
        int left = -1, right = 0, zsum = 0;
        for (int i = 0; i < A.size(); i++) {
            right++;
            if (!A[i]) zsum++;
            while(zsum>K) {
                left++;
                if (!A[left]) zsum--;
            }

            ans = max(ans, right - left-1);
        }
        return ans;
    }
};

// right可以省略 用i+1代替
