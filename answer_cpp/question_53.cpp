// 原答案
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];
        int sum = 0;
        int max_sum = nums[0];
        for (auto num : nums) {
            sum += num;
            if (sum < num) sum = num;
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};


// 耗时更小的答案
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return result;
    }
};

/* 分析
1. if (nums.size() <= 1) return nums[0]; 多余，可省去；
2. 使用auto num后 过多的对num的索引会增加耗时； 
*/

// 动归解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // base case
        int dp_0 = nums[0];
        int dp_1 = 0, res = dp_0;

        for (int i = 1; i < n; i++) {
            // dp[i] = max(nums[i], nums[i] + dp[i-1])
            dp_1 = max(nums[i], nums[i] + dp_0);
            dp_0 = dp_1;
            // 顺便计算最大的结果
            res = max(res, dp_1);
        }

        return res;
    }
};

// 时间啥的无所谓，只要复杂度够小就行，太追求耗时和内存只会让代码看起来更难懂
