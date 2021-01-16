class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = 0, n = 0;
        int res = 0;
        while(m < g.size() && n < s.size()) {
            if (g[m] <= s[n]) {
                m++;
                n++;
                res++;
            } else {
                n++;
            }
        }
        return res;
    }
};

// 优化 m和res是一个值，可以重用
