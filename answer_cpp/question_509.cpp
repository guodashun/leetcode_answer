class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1) {
            return N;
        }
        int pre = 0, cur = 1;
        for (int i = 2; i <= N; i ++) {
            int sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};