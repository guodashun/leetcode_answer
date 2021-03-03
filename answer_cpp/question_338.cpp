
class Solution {
public:
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 0; i <= num; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};

// 最原始方法，关键：i & (i-1) 求解1的个数

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        int highBit = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};

// 最简单动规，有了以上关键计算方法这个也不难想到

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};

// 去尾法，去掉最后一位的数(x/2)再加上(x&1)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};

// 去尾1法，去掉尾部最后一个1(i &(i-1))再加上1
