class Solution {
public:
    int max_num = 0;
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) temp++;
            else temp = 0;
            if (temp > max_num) max_num = temp;
        }
        return max_num;
    }
};
