#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    if (s.length() <= 1) return s;
    int left = 0, right = 0;
    int max_len = 0;
    for (int i = 1; i <= 2 * (s.length() - 1); i++) {
        int l, r, len;
        len = 0;
        bool valid = false;
        if (i%2 == 0) {
            l = i / 2 - 1;
            r = i / 2;
        } else {
            l = r = i / 2;
        }
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            valid = true;
        }
        l++;
        r--;

        if (valid) len = r - l + 1;
        if (len > max_len){
            max_len = len;
            left = l;
            right = r;
        }
    }
    return s.substr(left, max_len);
    }

private:
};

int main() {
    Solution sol;
    string test = "abbbbssba";
    cout << sol.longestPalindrome(test) << endl;
    return 0;
}