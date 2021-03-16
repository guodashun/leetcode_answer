class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int sq = n;
        vector<vector<int>> res(sq, vector<int>(sq,0));
        int u= 0, d = sq-1, l = 0, r = sq-1;
        int count = 0;
        while(true) {
            for (int i = l; i <= r; i++) res[u][i] = ++count;
            if (++u > d) break;
            for (int i = u; i <= d; i++) res[i][r] = ++count;
            if (--r < l) break;
            for (int i = r; i >= l; i--) res[d][i] = ++count;
            if (--d < u) break;
            for (int i = d; i >= u; i--) res[i][l] = ++count;
            if (++l > r) break;
        }
        return res;
    }
};

// same to 54
