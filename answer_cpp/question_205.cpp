class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map <char, char> map;
        int record[26]={0};
        for (int i = 0; i < s.size(); i++) {
            if (map.find(t[i]) != map.end()) {
                if (map[t[i]] != s[i]) return false;
            }else if (record[s[i]-'a'] == 1) return false;
            else {map[t[i]] = s[i]; record[s[i]-'a']=1;}
        }
        return true;
    }
};

// 没有考虑字符串里有数字的情况...


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};

// 老老实实用两个哈希
