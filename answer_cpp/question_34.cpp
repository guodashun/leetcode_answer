class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return vector<int>{left, right};
    }
    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) {
            return -1;
        }
        return left;
    }
    int findRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target) {
            return -1;
        }
        return right;
    }
};


// 判断条件大于小于 ** 最基础的条件 要想明白
// 左右边界缩放 else if 第三个条件 要写明白
// || 判断条件时，若前一个为真，则后一个条件判断不会执行
// 初始条件 empty不要漏掉
// -1的两个条件 [1,2,2,4]找6与找3
