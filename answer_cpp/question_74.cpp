class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int min_m = m - 1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == target) return true;
            else if (matrix[i][0] > target) {
                min_m = i - 1;
                break;
            }
        }
        if (min_m >= 0) {
            for (int j = 0; j < n; j++) {
                if (matrix[min_m][j] == target) return true;
                else if (matrix[min_m][j] >  target) return false;
            }
        }
        return false;
    }
};

// 想到了从mn变成m+n的方法，其实还有logmn的方法（二分）
// 可以两次二分（每行每列都二分），也可以直接一次二分


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];
            if (x < target) {
                low = mid + 1;
            } else if (x > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

