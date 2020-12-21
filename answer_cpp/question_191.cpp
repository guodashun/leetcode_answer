class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            if (n % 2 != 0) res++;
            n = n >> 1;
        }
        return res;
    }
};

// 常规操作


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0)
        {
            count ++;
            n = n & (n - 1);
        }
        return count;
    }
};

// 进阶操作
