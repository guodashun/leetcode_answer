vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, int target) {
    int sz = nums.size();
    vector<vector<int>> res;
    if (n < 2 || sz < n) return res;
    if (n == 2) {
        int l = start, r = sz - 1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target) {
                while(l < r && nums[l] == nums[l+1]) l++;
            } else if (sum > target) {
                while(l < r && nums[r] == nums[r-1]) r--;
            } else {
                res.push_back({l, r});
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
            }
        }
    } else {
        for (int i = start; i < sz; i++) {
            vector<vector<int>> sub = nSumTarget(nums, n-1, i+1, target - nums[i]); // 重点
            for (vector<int>& arr : sub) {
                arr.push_back(nums[i]);
                res.push_back(arr);
            }
            while(i < sz - 1 && nums[i] == nums[i+1]) i++; // 这一步不能省
        }
    }
    return res;
}

// 大致思路是迭代,但是总会有超时的问题
