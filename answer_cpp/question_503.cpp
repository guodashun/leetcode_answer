vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n); // 存放结果
    stack<int> s;
    // 假装这个数组长度翻倍了
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i % n])
            s.pop();
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    return res;
}

// 倒着排更好，更符合题意要求

// 错误解法：
// 原因：元素是重复的，不能使用hash表

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, int>map;
        stack<int> aStack;
        for (int i = 0; i < nums.size()*2; i ++) {
            int temp = i;
            if (i >= nums.size()) temp = i - nums.size(); 
            while(!aStack.empty() && nums[temp] > aStack.top()) {
                map[aStack.top()] = nums[temp];
                aStack.pop();
            }
            aStack.emplace(nums[temp]);
        }
        // while (!aStack.empty()) {
        //     map[aStack.top()] = -1;
        //     aStack.pop();
        // }

        vector<int> res;
        for (auto num : nums) {
            res.push_back(map.find(num) == map.end() ? -1 : map[num]);
        }
        return res;
    }
};