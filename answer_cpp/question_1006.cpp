class Solution {
public:
    int clumsy(int N) {
        int res = N;
        N--;
        if (N <= 0) return res;
        res *= N;
        N--;
        if (N <= 0) return res;
        res /= N;
        N--;
        if (N <= 0) return res;
        res += N;
        return helper(N-1, res);
    }
    int helper(int N, int res) {
        if (N == 0) return res;
        int temp = N;
        N--;
        if (N <= 0) return res - temp;
        temp *= N;
        N--;
        if (N <= 0) return res - temp;
        temp /= N;
        N--;
        if (N <= 0) return res - temp;
        temp -= N;
        res -= temp;
        return helper(N-1, res);
    }
};

// 丑陋递归

