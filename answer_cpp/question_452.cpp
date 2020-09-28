class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0 || n == 1) return n;
        int res = 1;
        sort(points.begin(), points.end(), sortEnd);
        int x_end = points[0][1];
        for (auto& point : points) {
            int start = point[0];
            if (start > x_end) {
                // 找到下一个选择的区间了
                res++;
                x_end = point[1];
            }
        }
        return res;
    }
    static bool sortEnd(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
};

// start >= end or start > end
// 边界问题
