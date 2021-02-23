class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int raw_sum = 0;
        int X_sum = 0;
        int temp = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) raw_sum += customers[i];
            else temp += customers[i];
            if ((i-X)>=0 && grumpy[i-X]) {
                temp -= customers[i-X];
            }
            if (temp > X_sum) X_sum = temp;
        }
        return raw_sum + X_sum;
    }
};

// 滑动窗口yyds
