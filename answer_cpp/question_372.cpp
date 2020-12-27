class Solution {
public:
    int base = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int past1 = mypow(a, last);
        int past2 = mypow(superPow(a, b), 10);
        return (past1 * past2) % base;
    }
    int mypow(int a, int k) {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; i++) {
            res *= a;
            res %= base;
        }
        return res;
    }
};

// (a*b) % c = (a%c)*(b%c) %c
// b.empty() return 1; 递归情况 base的处理
