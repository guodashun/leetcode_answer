class Solution {
public:
    static bool sortEnd(vector<int> &a, vector<int> &b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        return n - findMaxIntervals(intervals);
    }
    int findMaxIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n==0) return 0;
        sort(intervals.begin(), intervals.end(), sortEnd);
        int count = 1;
        // 排序后，第一个区间就是 x
        int x_end = intervals[0][1];
        for (auto& interval : intervals) {
            int start = interval[0];
            if (start >= x_end) {
                // 找到下一个选择的区间了
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
};

// sort函数写法
