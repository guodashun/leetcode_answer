class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c/2; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][c-j-1] ? 0 : 1;
                A[i][c-j-1] = temp ? 0 : 1;
            }
            if (c % 2 != 0) A[i][c/2] = A[i][c/2] ? 0 : 1;
        }
        return A;
    }
};

// 原版

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c/2; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][c-j-1] ^= 1;
                A[i][c-j-1] = temp ^= 1;
            }
            if (c % 2 != 0) A[i][c/2] = A[i][c/2] ^= 1;
        }
        return A;
    }
};

// 利用位运算改进版
