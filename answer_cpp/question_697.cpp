class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> hash, first_pos;
        int max_num = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (first_pos.count(nums[i]) == 0) first_pos[nums[i]] = i;
            hash[nums[i]]++;
            if (hash[nums[i]] > max_num) {
                max_num = hash[nums[i]];
                res = i - first_pos[nums[i]] + 1;
            } else if (hash[nums[i]] == max_num) {
                res = min(res, i - first_pos[nums[i]] + 1);
            }
        }
        return res;
    }
};

// 首先想到用滑动窗口做，但分析题目可以看出存在多个数值出现次数相同的情况，这种情况需要比较这些数各自的长度
// 大神的方法，用两个哈希表存次数，一次遍历搞定
