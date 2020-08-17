#include <vector>

class Violent {
public:
    int fib(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    };
};

class DP {
public:
    int fib(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        std::vector<int> fib_vec(n + 1, 0);
        fib_vec[1] = fib_vec[2] = 1;
        for (int i = 3; i < n; i++) {
            fib_vec[i] = fib_vec[i - 1] + fib_vec[i - 2];
        }
        return fib_vec[n];
    };
};

class DPLessSpace {
public:
    int fib(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        int pre = 1, cur = 1;
        for (int i = 3; i <= n; i ++) {
            int sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};
