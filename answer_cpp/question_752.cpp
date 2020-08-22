class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> que;
        unordered_set<string> dead;
        for (auto& deadend : deadends) dead.insert(deadend);
        unordered_set<string> visited;
        int step = 0;
        que.push("0000");
        visited.insert("0000");
        while(!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; i++) {
                string cur = que.front();
                que.pop();
                if (cur == target) {
                    return step;
                }
                if (dead.count(cur)) {
                    continue;
                }
                for (int j = 0; j < 4; j++) {
                    string up = clockUp(cur, j);
                    string down = clockDown(cur, j);
                    if (!visited.count(up)) {
                        que.push(up);
                        visited.insert(up);
                    }
                    if (!visited.count(down)) {
                        que.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    string clockUp(string s, int i) {
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            s[i]++;
        }
        return s;
    }
    string clockDown(string s, int i) {
        if (s[i] == '0') {
            s[i] = '9';
        } else {
            s[i]--;
        }
        return s;
    }
};

// vector 就是个废物 效率差unordered_set 老远了
// step = 0
// visited 使用