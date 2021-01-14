class Solution {
public:
    bool isValid(string s) {
        int sz = s.size();
        if (sz == 0) return true;
        stack <char> sk;
        for (int i = 0; i < sz; i++) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (sk.empty()) return false;
                char temp = sk.top();
                sk.pop();
                if ((s[i] == ')' && temp != '(') || (s[i] == ']' && temp != '[') || (s[i] == '}' && temp != '{')) {
                    return false;
                }
            } else {
                sk.push(s[i]);
            }
        }
        return sk.empty();
    }
};

// 最后return要注意
// c++ 单双引号有区别  要注意
