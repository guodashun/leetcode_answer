class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c:s1) need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int len = 0;
        while(right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]){
                    valid++;
                }
            }
            while (valid == need.size()) {
                len = right - left;
                if (len == s1.size()) return true;
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};

// 记牢框架
