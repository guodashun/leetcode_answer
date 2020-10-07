class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        int slow = 0, fast = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[slow] != nums[i]) {
                nums[++slow] = nums[i];
            }
        }
        return slow+1;
    }
};

// 双指针解法
// 需要对原数组进行操作
