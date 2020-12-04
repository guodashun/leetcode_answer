class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> s;
        for (int i = T.size() - 1; i >= 0; i--) {
            while (!s.empty() && T[s.top()] <= T[i]) {
                s.pop();
            }
            // 得到索引间距
            res[i] = s.empty() ? 0 : (s.top() - i); 
            // 将索引入栈，而不是元素
            s.push(i); 
        }
        return res;
    }
};

// 思路在于  要求的不是下一个最大数  而是最大的索引
// 所以栈里存索引而不是数字
// 存索引同样能拿到最大值，同样能比较
// 正向反向的思路

