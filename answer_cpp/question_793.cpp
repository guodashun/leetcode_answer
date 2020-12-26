class Solution {
public:
    auto f(long long n) {
        long long result = 0;
        for(int p = n / 5;p != 0;p /= 5)
            result += p;
        return result;
    }

    int preimageSizeFZF(int K) {
        auto r = 1 + 5ll * K;
        auto l = 4ll * K;
        while (l < r) {
            auto m = (l + r) / 2;
            if (f(m) < K) l = m + 1;
            else r = m;
        }
        return f(l) == K ? 5 : 0;
    }
};
