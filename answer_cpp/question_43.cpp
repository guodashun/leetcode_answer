class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);
        for (int i = num1.size() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--) b.push_back(num2[i] - '0');
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        int k = 0;
        for (int i = 0; i < c.size(); i++) {
            k += c[i];
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (k) {
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};
