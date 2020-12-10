class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> route;
        backtrack(route, nums);
        return res;
    }
    void backtrack(vector<int> route, vector<int>& nums) {
        if (route.size() == nums.size()) {
            res.push_back(route);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(route.begin(), route.end(), nums[i]) != route.end()) {
                continue;
            }
            route.push_back(nums[i]);
            backtrack(route, nums);
            route.pop_back();
        }
    }
    vector<vector<int>> res;
};

// 回溯算法
// 选择路径，撤回路径的方法（迭代、route.pop_back()）
