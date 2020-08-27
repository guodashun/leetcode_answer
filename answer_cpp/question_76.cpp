    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char i : t) need[i]++;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while(right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while(valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)){
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }

// 首先套模板
// 利用哈希表比较是否满足题目要求
// 由于c++会在key值不存在时，map[key]自动赋值为0，利用这一特点，可以通过key对应值来判断字母的数量（数量-1）
// 利用valid来判断目前窗口是否满足要求，即window needs shrink
// 这个while写在第一个while循环里是因为要保证将整个字符串判断完
