class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums= nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int idx = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) {
                cnt++;
                if (rand() % cnt == 0) idx = i;
            }
        }
        return idx;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// rand() % cnt ==0 -> 1/cnt 概率为 true
