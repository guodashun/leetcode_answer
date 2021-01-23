class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> temp;
        vector<int> res;
        int up = 0;
        for (int i = A.size()-1; i >= 0 ; i--) {
            int sum = A[i] + up + K % 10;
            temp.push_back(sum % 10);
            up = sum / 10;
            K /= 10;
        }
        if (up == 1) temp.push_back(1);
        for (int i = temp.size()-1; i >=0 ; i--) {
            res.push_back(temp[i]);
        }
        return res;
    }
};

// 错误 没有考虑K位数比A大的情况

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res;
        int n = A.size();
        for (int i = n - 1; i >= 0; --i) {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10) {
                K++;
                sum -= 10;
            }
            res.push_back(sum);
        }
        for (; K > 0; K /= 10) {
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 把进位给K 合并在一起，然后判断K是否为0来完成最后的运算
// 翻转vector用reverse
