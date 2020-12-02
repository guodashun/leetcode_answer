class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> aMap;
        stack<int> aStack;

        // 输出第一个比x大的数 
        for (auto num2 : nums2) {
            while (!aStack.empty() && num2 > aStack.top()) {
                aMap[aStack.top()] = num2;
                aStack.pop();
            }
            // 每个数都要进栈
            aStack.emplace(num2);
        }

        // 没有更大的数
        // 清空栈
        while (!aStack.empty()) {
            aMap[aStack.top()] = -1;
            aStack.pop();
        }

        vector<int> ans;
        for (auto num1 : nums1)
            ans.emplace_back(aMap[num1]);

        return ans;
    }
};

// 单调栈
// 具体思路可以看官方题解的gif
