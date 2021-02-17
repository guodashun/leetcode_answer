class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rr = nums.size(), rc = nums[0].size();
        if (rr * rc != r * c) return nums;
        vector <vector<int>> res;
        for (int i = 0; i < r; i++) {
            vector <int> nc;
            for (int j = 0; j < c; j++) {
                int idx = i*c + j;
                nc.push_back(nums[idx/rc][idx%rc]);
            }
            res.push_back(nc);
        }
        return res;
    }
};

// 矩阵行列关系要搞清楚
// vector<vector<int>> res(r, vector<int>(c, 0));向量初始化方法
